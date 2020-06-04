/*
 *  IncidentLog.cpp
 *
 *  COSC 052 Fall 2019
 *  Project 1
 *
 *  Due on: SEP 19, 2019
 *  Author: fsd7
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 */

#include "IncidentLog.h"

IncidentLog::IncidentLog()
{

}

IncidentLog::~IncidentLog()
{
	
}

void IncidentLog::displayReports(string outputFileName) const
{
	try
	{
		string openFailure = "ERROR: File failed to open\n";
	
		std::ofstream outFile;
		outFile.open(outputFileName.c_str());
	
		if(!outFile)
		{
			throw logic_error(openFailure);
			cout << openFailure << endl;
		}	
	
		for(int i = 0; i < allIncidents.size();i++)
		{
			allIncidents.at(i).summaryReport(outFile);
		}
	
		outFile.close();

	}
	catch(logic_error e)
	{
		cout << e.what() << endl;
	}
	
}

void IncidentLog::displayReports(ostream &os) const
{

	try{
		string streamFail = "ERROR: Stream failure \n";

		if(!os)
		{
			throw invalid_argument(streamFail);
			cout << streamFail << endl;
		}
	
		for(int i = 0; i < allIncidents.size(); i++)
		{
			allIncidents.at(i).summaryReport(os);
			cout << "\n" << endl;
		}

		cout <<  "Number of valid Records: " << allIncidents.size() << endl;

	}
	catch(invalid_argument e)
	{
		cout << e.what() << endl;
	}
	catch(std::out_of_range e)
	{
		cout << e.what() << endl;
	}

}

HazMat7k& IncidentLog::find(string incidentNum)
{

	try
	{
		for(int i = 0; i < allIncidents.size(); i++)
		{
			if(incidentNum == allIncidents.at(i).getReportNumber())
			{
				return allIncidents.at(i);
			}
		}
	}
	catch(logic_error e)
	{
		cout << e.what() << endl;
	}

	

}

void IncidentLog::read( string inputFileName, char fileFormat )
{
	

	string fileFormatError = "ERROR: The given file format is not valid\n";
	string fileOpenError = "ERROR: File could not be opened, please check path and name:\n";

	if( fileFormat == 'b')
	{
		ifstream inFile(inputFileName.c_str(), std::ios::binary | std::ios::in);
		if (!inFile)
			throw logic_error(fileOpenError + inputFileName);

		try
		{	

			read(inFile, fileFormat);

			inFile.close();
		}
		catch(invalid_argument &e)
		{
			cout << e.what() << endl;
		}
		catch(logic_error &e)
		{
			cout << e.what() << endl;
		}

		
	}

	else if(fileFormat == 'q')
	{
		ifstream inFile (inputFileName.c_str());
		if(!inFile)
			throw logic_error(fileOpenError + inputFileName );
		try
		{
		
			read(inFile, fileFormat);
			
			inFile.close();

		}
		catch(invalid_argument &e)
		{
			cout << e.what() << endl;
		}
		catch(logic_error &e)
		{
			cout << e.what() << endl;
		}


		
	}

	else
	{
		throw invalid_argument(fileFormatError);
		cout << fileFormatError << endl;
	
}
}

void IncidentLog::read( istream& in, char fileFormat )
{
	if(!in)
		throw invalid_argument("ERROR: Stream failure");

	if(fileFormat == 'b')
	{
		HazMatData h1s;
		bool valid = true;
		int count = 1;
		try
		{
			valid = true;
			in.read(reinterpret_cast<char*>(&h1s), sizeof(h1s));
			count++;
		}
		catch(invalid_argument &e)
		{
			cout << e.what() << "in row " << count << endl;
			valid = false;
		}
		catch(logic_error &e)
		{
			cout << e.what() << "in row " << count << endl;
			valid = false;
		}
		catch(...)
		{
			cout << "Exception caught in row " << count << endl;
			valid = false;
		}
		
		while(in)
		{
			try
			{
				if(valid)
				{
					HazMat7k h1(h1s);
					allIncidents.push_back(h1);
				}	
				valid = true;
				in.read(reinterpret_cast<char*>(&h1s), sizeof(h1s));
				count++;
			}
			catch(invalid_argument &e)
			{
				cout << e.what() << "in row " << count << endl;
				valid = false;
			}
			catch(logic_error &e)
			{
				cout << e.what() << "in row " << count << endl;
				valid = false;
			}

			catch(...)
			{
				cout << "Exception caught in row " << count << endl;
				valid = false;
			}
		}

	}

	if( fileFormat == 'q' )
	{
		HazMat7k h1;
		bool valid = true;
		int count = 1;

		string ignore = " ";

		try
		{
			valid = true;
			in >> h1;
			count++;
		}
		catch(invalid_argument &e)
		{
			valid = false;
			cout << e.what() << "in row " << count << endl;
			getline(in, ignore);
			count++;
		}
		catch(logic_error &e)
		{
			valid = false;
			cout << e.what() << "in row " << count << endl;
		}
		catch(...)
		{
			valid = false;
			cout << "Exception caught in row " << count << endl;
		}

		while(in)
		{
			
			try 
			{
				if(valid)
					allIncidents.push_back(h1);
				valid = true;
				in >> h1;
				count++;
				
			}
			catch(invalid_argument &e)
			{
				valid = false;
				cout << e.what() << "in row " << count << endl;
				//getline(in, ignore);
				count++;
			}
			catch(logic_error &e)
			{
				valid = false;
				cout << e.what() << "in row " << count << endl;
			}
			catch(...)
			{
				valid = false;
				cout << "Exception caught in row " << count << endl;
			}

		
		}

	}
}

void IncidentLog::write( string outputFileName ) const
{
	try
	{
		string fileOpenError = "ERROR: File could not be opened, please check path and name:\n";

		std::ofstream outFile (outputFileName.c_str());

		if(!outFile)
			throw logic_error(fileOpenError);

		write(outFile);

		outFile.close();

	}
	catch(invalid_argument e)
	{
		cout << e.what() << endl;
	}
	catch(logic_error e)
	{
		cout << e.what() << endl;
	}
	catch(...)
	{
		cout << "Exception found" << endl;
	}

}

void IncidentLog::write( ostream& out) const
{
	if(!out)
		throw invalid_argument("ERROR: Stream Failure");

	for(int i = 0; i < allIncidents.size(); i++)
		{
			out << allIncidents.at(i);
		}
}