/*
 *  PHMSA7000.cpp
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

#include "PHMSA7000.h"

    HazMat7k::HazMat7k()
    {
    	reportReceivedDate.setDate(MIN_YYYY, MIN_MM, MIN_DD);
    	reportNumber = " ";
    	supplementalNumber = " ";
    	reportType = " ";
    	operatorID = " ";
    	name = " ";
    	operatorStreetAddress = " ";
    	operatorCityName = " ";
    	operatorStateAbbreviation = " ";
    	operatorPostalCode = " ";
    	localDate.setDate(MIN_YYYY, MIN_MM, MIN_DD);
    	localTime.setTime(MAX_HOUR, DEFAULT_MINUTE);
    	commodityReleasedType = " ";
    	unintentionalReleaseBbls = 0.0;
    	intentionalReleaseBbls = 0.0;
    	recoveredBbls = 0.0;
    	fatal = 0;
    	injure = 0;
    	igniteInd = " ";
    	explodeInd = " ";
    	preparedDate.setDate(MIN_YYYY, MIN_MM, MIN_DD);
    	authorizerName = " ";
    	authorizerEmail = " ";
    	narrative = " ";
    }

    HazMat7k::~HazMat7k()
    {

    }
    
    //convert constructor
    HazMat7k::HazMat7k( const HazMatData &hzData )
    {
    	reportReceivedDate = hzData.report_received_date;           
    	reportNumber = hzData.report_number;              
    	supplementalNumber = hzData.supplemental_number;      
    	reportType = hzData.report_type;        
    	operatorID = hzData.operator_id;   
    	name = hzData.name;   
    	operatorStreetAddress = hzData.operator_street_address;      
    	operatorCityName = hzData.operator_city_name;
    	operatorStateAbbreviation = hzData.operator_state_abbreviation;
    	operatorPostalCode = hzData.operator_postal_code;
    	localDate = hzData.local_date;
    	localTime = hzData.local_time;     
    	commodityReleasedType = hzData.commodity_released_type;
     	unintentionalReleaseBbls = hzData.unintentional_release_bbls;
        intentionalReleaseBbls = hzData.intentional_release_bbls;
        recoveredBbls = hzData.recovered_bbls;

        fatal = hzData.fatal;
        injure = hzData.injure; 
        igniteInd = hzData.ignite_ind;
        explodeInd = hzData.explode_ind;
        preparedDate = hzData.prepared_date;
        authorizerName = hzData.authorizer_name;
        authorizerEmail = hzData.authorizer_email;
        narrative = hzData.narrative;

    }

    ostream& operator<<(ostream &os, const HazMat7k &rhsObj)
    {
    	string streamFail = "ERROR: Stream failure ";

    	if (!os)
    	{
    		throw invalid_argument(streamFail);
    		cout << streamFail << endl;
    	}

    	os << setw(4) << rhsObj.reportReceivedDate.getYear() << "/";
    	os << setw(2) << setfill('0') << rhsObj.reportReceivedDate.getMonth() << "/";
    	os << setw(2) << setfill('0') << rhsObj.reportReceivedDate.getDay() << " ";

    	os << rhsObj.reportNumber << " ";
    	os << rhsObj.supplementalNumber << " ";
    	os << "\"" << rhsObj.reportType << "\"" << " ";
    	os << rhsObj.operatorID << " ";
    	os << "\"" << rhsObj.name << "\"" << " ";
    	os << "\"" << rhsObj.operatorStreetAddress << "\"" << " ";
    	os << "\"" << rhsObj.operatorCityName << "\"" << " ";
    	os << rhsObj.operatorStateAbbreviation << " ";
    	os << "\"" << rhsObj.operatorPostalCode << "\"" << " ";

    	os << setw(4) << rhsObj.localDate.getYear() << "/";
    	os << setw(2) << setfill('0') << rhsObj.localDate.getMonth() << "/";
    	os << setw(2) << setfill('0') << rhsObj.localDate.getDay() << " ";
    	os << setw(2) << setfill('0') << rhsObj.localTime.getHour() << ":";
    	os << setw(2) << setfill('0') << rhsObj.localTime.getMinute() << " ";

    	os << rhsObj.commodityReleasedType << " ";
    	os << rhsObj.unintentionalReleaseBbls << " ";
    	os << rhsObj.intentionalReleaseBbls << " ";
    	os << rhsObj.recoveredBbls << " ";

    	os << rhsObj.fatal << " ";
    	os << rhsObj.igniteInd << " ";
    	os << rhsObj.explodeInd << " ";

    	os << setw(4) << rhsObj.preparedDate.getYear() << "/";
    	os << setw(2) << setfill('0') << rhsObj.preparedDate.getMonth() << "/";
    	os << setw(2) << setfill('0') << rhsObj.preparedDate.getDay() << " ";
    	os << "\"" << rhsObj.authorizerName << "\"" << " ";
    	os << rhsObj.authorizerEmail << " ";
    	os << rhsObj.narrative << endl;

    	return os;

    }

    istream& operator>>(istream &is, HazMat7k &rhsObj)
    {
    	string streamFail = "ERROR: Stream failure ";

    	if (!is) 
    	{
    		throw invalid_argument(streamFail);
    		cout << streamFail << endl;
    	}

 		Date  reportReceivedDate;   

    	string  reportNumber;               
    	string  supplementalNumber;         
    	string  reportType;                 
    	string  operatorID;                 
    	string  name;                       
    	string  operatorStreetAddress;      
    	string  operatorCityName;           
    	string  operatorStateAbbreviation;  
    	string  operatorPostalCode;                      

    	Date  localDate;                    
    	Time  localTime;   

    	string  commodityReleasedType;      
    
	    double  unintentionalReleaseBbls;
	    double  intentionalReleaseBbls;
	    double  recoveredBbls;
    
	    int  fatal;                
	    int  injure;               
	    string  igniteInd;         
	    string  explodeInd;        

		Date  preparedDate; 

	    string  authorizerName;    
	    string  authorizerEmail;   
	    string  narrative; 

	    string ignore = " ";  

	    try{
	    
		    is >> reportReceivedDate ;
	
			is >> reportNumber >> supplementalNumber;
		    reportType = readDoubleQuotedString(is);
		    is >> operatorID;
		    name = readDoubleQuotedString(is);
		    operatorStreetAddress = readDoubleQuotedString(is);
		    operatorCityName =  readDoubleQuotedString(is);
		    is >> operatorStateAbbreviation;
		    operatorPostalCode = readDoubleQuotedString(is);
		    is >> localDate >> localTime;
	
		    commodityReleasedType = readDoubleQuotedString(is);
	
		    is >> unintentionalReleaseBbls;
		    is >> intentionalReleaseBbls;
		    is >> recoveredBbls;
		    is >> fatal;
		    is >> injure;
		    is >> igniteInd >> explodeInd;
	
		  	is >> preparedDate;

		    authorizerName =  readDoubleQuotedString(is);
		    
		    is >> authorizerEmail;
		    getline(is, narrative);
		}
		catch (invalid_argument &e)
		{
			getline(is, ignore);
			throw invalid_argument(e); 
			//return is;
			//cout << ignore << endl;
		}


	    rhsObj.setReportReceivedDate(reportReceivedDate);
	    rhsObj.setReportNumber(reportNumber);
	    rhsObj.setSupplementalNumber(supplementalNumber);
	    rhsObj.setReportType(reportType);
	    rhsObj.setOperatorID(operatorID);
	    rhsObj.setName(name);
	    rhsObj.setOperatorStreetAddress(operatorStreetAddress);
	    rhsObj.setOperatorCityName(operatorCityName);
	    rhsObj.setOperatorStateAbbreviation(operatorStateAbbreviation);
	    rhsObj.setOperatorPostalCode(operatorPostalCode);
	    rhsObj.setLocalDate(localDate);
	    rhsObj.setLocalTime(localTime);
	    rhsObj.setCommodityReleasedType(commodityReleasedType);
	    rhsObj.setUnintentionalReleaseBbls(unintentionalReleaseBbls);
	    rhsObj.setUnintentionalReleaseBbls(intentionalReleaseBbls);
	    rhsObj.setRecoveredBbls(recoveredBbls);
	    rhsObj.setFatal(fatal);
	    rhsObj.setInjure(injure);
	    rhsObj.setIgniteInd(igniteInd);
	    rhsObj.setExplodeInd(explodeInd);
	    rhsObj.setPreparedDate(preparedDate);
	    rhsObj.setAuthorizerName(authorizerName);
	    rhsObj.setAuthorizerEmail(authorizerEmail);
	    rhsObj.setNarrative(narrative);


	    return is;
    }
     
    void HazMat7k::summaryReport(ostream &os ) const
	{
		
		string streamFail = "ERROR: Stream failure ";

		if (!os)
		{
			throw invalid_argument(streamFail);
			cout << streamFail << endl;

		}

		os << "Report Number and Date: ";
		os << reportNumber << " ";
		os << setfill('0') << setw(4) << reportReceivedDate.getYear() << "/"; 
		os << setfill('0') << setw(2) << reportReceivedDate.getMonth() << "/";
		os << setfill('0') << setw(2) << reportReceivedDate.getDay() << endl;

		os << "Local Date and Time: ";
		os << setfill('0') << setw(4) << localDate.getYear() << "/";
		os << setfill('0') << setw(2) << localDate.getMonth() << "/";
		os << setfill('0') << setw(2) << localDate.getDay() << " ";
		os << setfill('0') << setw(2) << localTime.getHour() << ":";
		os << setfill('0') << setw(2) << localTime.getMinute() << endl;
		os << "Number of Injuries: " << injure << endl;
		os << "Number of Fatalities: " << fatal << endl;
		os << "Narrative Length: " << narrative.length() << endl;
		os << "Narrative: " << narrative << endl;

		os << endl;

	}
    
    // this mutator functions may not be implemented in-line (requires more than one statement)
    void HazMat7k::setReportNumber(string value)
    {
    	string invalidSize = "ERROR: Invalid argument size ";
    	string invalidStart = "ERROR: Invalid argument start ";
    	
    	if(value.length() != 8)
    	{
    		throw invalid_argument(invalidSize);
    	}

    	string year = std::to_string(reportReceivedDate.getYear());

    	if(value.substr(0,4) != year)
    	{
    		throw invalid_argument(invalidStart);
    	}

    	reportNumber = value;

    }

    
    // this mutator functions may not be implemented in-line (requires more than one statement)
    void HazMat7k::setReportType(string value)
    {
    	string validationFail = "ERROR: Report Type validation failure ";

    	if (!(value == "ORIGINAL" || value == "ORIGINAL FINAL" || value == "SUPPLEMENTAL" 
    		|| value == "SUPPLEMENTAL FINAL"))
    	{
    		throw invalid_argument(validationFail);
    	}
    	else
    	{
    		reportType = value;
    	}

    	
    }
    
      
