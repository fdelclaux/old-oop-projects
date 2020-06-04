/*
 *  IncidentLog.h
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
 **                 class IncidentLog declaration                          **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2019 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

/**
 * <P>A class for storing hazardous liquid incident reports.</P>
 * <P>Methods exist to read incident details from various file types.</P>
 * <P>Methods exist to write incidents to text files in a format
 * similar to the input format.  </P>
 * <P>A find method searches for
 * incidents based on the report number.</P>
 *
 * @author W. A. Woods (waw23 at georgetown dot edu)
 * @version 1.1.0, 2019/08/12
 * @version 1.2.0, 2019/08/18
 * @version 1.3.0, 2019/08/19
 * @version 1.4.0, 2019/08/20
 *
 */

#ifndef _P1_INCIDENT_LOG_H
#define _P1_INCIDENT_LOG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>

#include "PHMSA7000.h"
#include "Resources.h"

using std::ostream;
using std::cout;
using std::logic_error;


class IncidentLog
{
private:
    
    vector<HazMat7k> allIncidents; /*!< the incidents for this log */
    
public:
    
    IncidentLog();
    ~IncidentLog();
    
    void displayReports(string outputFileName) const;
    void displayReports(ostream &os = cout) const;
    
    HazMat7k& find(string incidentNum);
    
    void read( string inputFileName, char fileFormat );
    void read( istream& in, char fileFormat );
    
    void write( string outputFileName ) const;
    void write( ostream& out = cout ) const;
    
    /** accessor method returns size of vector data member, implemented in-line  */
    unsigned long size() const { return allIncidents.size(); }
    
}; //END class IncidentLog declaration

#endif 