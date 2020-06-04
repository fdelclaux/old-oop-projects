/*
 *  main.cpp
 *
 *  COSC 052 Fall 2019
 *  Project #1
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

#include "main.h"

int main( int argc, const char* argv[])
{
	try
	{
		string inputFileName = "";
		IncidentLog log1;
		char fileType = ' ';


		if(argc < 2)
		{
			cout << "Not enough command line arguments, please pass the complete path and name of ";
			cout << "the input data file and the type of file it is ( q - quoted file, b - binary ";
			cout << "file) as command line arguments.\n";
			cout << "Please try again." << endl;
		}
		else
		{
			inputFileName = argv[1];
			fileType = argv[2][0];
			fileType = tolower(fileType);

			log1.read(inputFileName, fileType);

			log1.displayReports();
		}

	}
	catch(invalid_argument &e)
	{
		cout << e.what() << endl;
	}
	catch(logic_error &e)
	{
		cout << e.what() << endl;
	}
	catch(...)
	{
		cout << "Exception caught." << endl;
	}

	return 0;
}
