/*
 *  PHMSA7000.h
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

/****************************************************************************
 ****************************************************************************                                                                       
 **                                                                        **
 **               struct HazMatData declaration                            **
 **                                                                        **
 **            This code is provided to students                           **
 **            in COSC 052 Fall 2019 to use in part                        **
 **            or in total for class projects.                             **
 **            Students may use this code as their                         **
 **            own, without any attribution.                               **
 **                                                                        **
 ****************************************************************************                                                                       
 ****************************************************************************/


/**
 * A struct for storing one hazardous liquid incident report from a binary input file.
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1.1, 2019/07/12
 * @version 1.1.2, 2019/08/04
 * @version 1.1.3, 2019/08/09
 * @version 1.1.4, 2019/08/16
 * @version 1.2.0, 2019/08/20
 *
 */

#ifndef _P1_PHMSA7000_H_
#define _P1_PHMSA7000_H_

#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

#include "Resources.h"


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
using std::istream;
using std::cin;
using std::vector;
using std::istringstream;
using std::ostringstream;
using std::logic_error;
using std::setw;
using std::setfill;

const int FIELD_COUNT = 24;

const int FIELD_WIDTH[FIELD_COUNT] = {16,10,7,20,7,55,57,18,4,12,16,8,84,10,10,10,
    6,6,5,5,16,45,42,4000};

const int NUM_REPORT_TYPES = 4;
const string VALID_REPORT_TYPE[] = {
                                    "ORIGINAL",
                                    "ORIGINAL FINAL",
                                    "SUPPLEMENTAL",
                                    "SUPPLEMENTAL FINAL"
                                    };

enum {REPORT_RECEIVED_DATE,
    REPORT_NUMBER,
    SUPPLEMENTAL_NUMBER,
    REPORT_TYPE,
    OPERATOR_ID,
    NAME,
    STREET_ADDRESS,
    CITY_NAME,
    STATE_ABBR,
    POSTAL_CODE,
    LOCAL_DATE,
    LOCAL_TIME,
    COMMODITY_TYPE,
    UNINTENTIONAL_BBLS,
    INTENTIONAL_BBLS,
    RECOVERED_BBLS,
    FATAL,
    INJURE,
    IGNITE,
    EXPLODE,
    PREPARED_DATE,
    AUTH_NAME,
    AUTH_EMAIL,
    NARRATIVE};

struct HazMatData
{
    Date report_received_date;
    char report_number[10+1];
    char supplemental_number[7+1];
    char report_type[20+1];
    char operator_id[7+1];
    char name[55+1];
    char operator_street_address[57+1];
    char operator_city_name[18+1];
    char operator_state_abbreviation[4+1];
    char operator_postal_code[12+1];
    Date local_date;
    Time local_time;
    char commodity_released_type[84+1];
    double unintentional_release_bbls;
    double intentional_release_bbls;
    double recovered_bbls;
    int fatal;
    int injure;
    char ignite_ind[5+1];
    char explode_ind[5+1];
    Date prepared_date;
    char authorizer_name[45+1];
    char authorizer_email[42+1];
    char narrative[4000+1];
    
}; //END struct HazMatData declaration



/****************************************************************************
 ****************************************************************************                                                                       
 **                                                                        **
 **                   class HazMat7k declaration                           **
 **                                                                        **
 **            This code is provided to students                           **
 **            in COSC 052 Fall 2019 to use in part                        **
 **            or in total for class projects.                             **
 **            Students may use this code as their                         **
 **            own, without any attribution.                               **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/


/**
 * A class for storing one hazardous liquid incident report.
 * Methods exist to read incident details from a text file or to
 * convert a HazMatData struct to a class object.
 * Methods exist to write incidents to text files in a format
 * similar to the input format.  A find method searches for
 * incidents based on the report number.
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1.1, 2019/07/12
 * @version 1.2.1, 2019/08/04
 * @version 1.3.1, 2019/08/17
 * @version 1.3.2, 2019/08/19
 * @version 1.3.3, 2019/08/20
 *
 */


class HazMat7k
{
    friend ostream& operator<<(ostream &os, const HazMat7k &rhsObj);
    friend istream& operator>>(istream &is, HazMat7k &rhsObj);
    
private:
    Date  reportReceivedDate;           /*!< the date the report was received */
    string  reportNumber;               /*!< the report number */
    string  supplementalNumber;         /*!< the supplemental report number, if any */
    string  reportType;                 /*!< the report type */
    string  operatorID;                 /*!< the operator ID */
    string  name;                       /*!< the operator name */
    string  operatorStreetAddress;      /*!< the operator address: street */
    string  operatorCityName;           /*!< the operator address: city name */
    string  operatorStateAbbreviation;  /*!< the operator address: state abbreviation */
    string  operatorPostalCode;         /*!< the operator address: zip code */
    Date  localDate;                    /*!< the local time of incident */
    Time  localTime;                    /*!< the local date of incident */
    string  commodityReleasedType;      /*!< the type of hazardous liquid released  */
    
    /** the quantity of hazardous liquid released un-intentionally  */
    double  unintentionalReleaseBbls;
    /** the quantity of hazardous liquid released intentionally  */
    double  intentionalReleaseBbls;
    /** the quantity of hazardous liquid recovered  */
    double  recoveredBbls;
    
    int  fatal;                /*!< the number of fatalities */
    int  injure;               /*!< the number of injuries */
    string  igniteInd;         /*!< did the hazardous liquid ignite? */
    string  explodeInd;        /*!< did the hazardous liquid explode? */
    Date  preparedDate;        /*!< the date the report was prepared  */
    string  authorizerName;    /*!< the name of the official authorizing the report  */
    string  authorizerEmail;   /*!< the email address of the official authorizing the report  */
    string  narrative;         /*!< the detailed narrative description of the incident  */
    
public:
    
     // default constructor
    HazMat7k();
    ~HazMat7k();
   
    
    void summaryReport(ostream &os = cout) const;
    
    //convert constructor
    HazMat7k( const HazMatData &hzData );
    
    // simple accessor functions for each data member (all may be implemented in-line)
    
    Date getReportReceivedDate() const { return reportReceivedDate; } /*!< in-line accessor  */
    string getReportNumber() const { return reportNumber; } /*!< in-line accessor  */
    string getSupplementalNumber() const { return supplementalNumber; } /*!< in-line accessor  */
    string getReportType() const { return reportType; } /*!< in-line accessor  */
    string getOperatorID() const { return operatorID; } /*!< in-line accessor  */
    string getName() const { return name; } /*!< in-line accessor  */
    /** in-line accessor  */
    string getOperatorStreetAddress() const { return operatorStreetAddress; }
    string getOperatorCityName() const { return operatorCityName; } /*!< in-line accessor  */
    /** in-line accessor  */
    string getOperatorStateAbbreviation() const { return operatorStateAbbreviation; }
    string getOperatorPostalCode() const { return operatorPostalCode; } /*!< in-line accessor  */
    Date getLocalDate() const { return localDate; } /*!< in-line accessor  */
    Time getLocalTime() const { return localTime; } /*!< in-line accessor  */
    /** in-line accessor  */
    string getCommodityReleasedType() const { return commodityReleasedType; }
    /** in-line accessor  */
    double getUnintentionalReleaseBbls() const { return unintentionalReleaseBbls; }
    /** in-line accessor  */
    double getIntentionalReleaseBbls() const { return intentionalReleaseBbls; } 
    double getRecoveredBbls() const { return recoveredBbls; } /*!< in-line accessor  */
    int getFatal() const { return fatal; } /*!< in-line accessor  */
    int getInjure() const { return injure; } /*!< in-line accessor  */
    string getIgniteInd() const { return igniteInd; } /*!< in-line accessor  */
    string getExplodeInd() const { return explodeInd; } /*!< in-line accessor  */
    Date getPreparedDate() const { return preparedDate; } /*!< in-line accessor  */
    string getAuthorizerName() const { return authorizerName; } /*!< in-line accessor  */
    string getAuthorizerEmail() const { return authorizerEmail; } /*!< in-line accessor  */
    string getNarrative() const { return narrative; } /*!< in-line accessor  */

    
    
    // simple mutator functions for each data member (most may be implemented in-line)
    
    void setReportReceivedDate(Date value) { reportReceivedDate.setDate(value); }
    
    // this mutator functions may not be implemented in-line (requires more than one statement)
    void setReportNumber(string value);

    
    void setSupplementalNumber(string value) { supplementalNumber = value; }
    
    // this mutator functions may not be implemented in-line (requires more than one statement)
    void setReportType(string value);
    
    void setOperatorID(string value) { operatorID = value; }
    void setName(string value) { name = value; }
    void setOperatorStreetAddress(string value) { operatorStreetAddress = value; }
    void setOperatorCityName(string value) { operatorCityName = value; }
    void setOperatorStateAbbreviation(string value) { operatorStateAbbreviation = value; }
    void setOperatorPostalCode(string value) { operatorPostalCode = value; }
    
    void setLocalDate(Date value) { localDate.setDate(value); }
    void setLocalTime(Time value) { localTime.setTime(value.getHour(), value.getMinute()); }
    
    void setCommodityReleasedType(string value) { commodityReleasedType = value; }
    void setUnintentionalReleaseBbls(double value) { unintentionalReleaseBbls = value; }
    void setIntentionalReleaseBbls(double value) { intentionalReleaseBbls = value; }
    void setRecoveredBbls(double value) { recoveredBbls = value; }
    void setFatal(int value) { fatal = value; }
    void setInjure(int value) { injure = value; }
    void setIgniteInd(string value) { igniteInd = value; }
    void setExplodeInd(string value) { explodeInd = value; }
    
    void setPreparedDate(Date value) { preparedDate.setDate(value); }
    
    void setAuthorizerName(string value) { authorizerName = value; }
    void setAuthorizerEmail(string value) { authorizerEmail = value; }
    void setNarrative(string value) { narrative = value; }
    
}; // class HazMat7k declaration

#endif //_P1_PHMSA7000_H_