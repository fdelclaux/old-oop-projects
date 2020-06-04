/*
*  Vehicle.h
*
*  COSC 052 Fall 2019
*  Project #2
*
*  Due on: OCT 10, 2019
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

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>

#include "Resources.h"
#include "Exceptions.h"

using std::string;
using std::invalid_argument;
using std::logic_error;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::ostringstream;
using std::istringstream;


const int DERIVED_CLASS_COUNT = 3;
const int STATUS_CODE_COUNT = 3;
const int ID_REQUIRED_LENGTH = 17;

const string DEFAULT_ID = "p0000000000000000";
const string DEFAULT_NAME = "none";
const char DEFAULT_STATUS = 'm';

enum DerivedNames { _INDIVIDUAL_, _PASSENGER_, _CARGO_ };
enum StatusNames { _IN_MAINTENANCE_, _IN_SERVICE_, _AVAILABLE_ };

const char TYPE_CODES[DERIVED_CLASS_COUNT + 1] = {'i', 'p', 'c', '\0'};
const char STATUS_CODES[STATUS_CODE_COUNT + 1] = {'m', 's', 'a', '\0'};

const int MIN_PASSENGER_CAPACITY = 0;
const int MAX_PASSENGER_CAPACITY = 250;
const int MIN_CARGO_CAPACITY = 0.0;
const int MAX_CARGO_CAPACITY = 25.0;


class Vehicle
{
protected:
    string id;            /*!< Vehicle Identification Number (VIN) (with vehicle type prefix) */
    string name;          /*!< vehicle make and model */
    Date inspectionDate;  /*!< last comprehensive mechanical, operational, safety inspection */
    char status;          /*!< code indicating current status/available */
    
    
public:
    Vehicle();
    Vehicle( string id, string name, Date iDate, char status );
    
    string getID() const;
    string getName() const;
    Date getInspectionDate() const;
    char getStatus() const;
    
    void setID( string id );
    void setName( string name );
    void setInspectionDate( Date iDate );
    void setStatus( char status );
    
    virtual void print( ostream& os = cout ) const;
    virtual void read( istream& is );
    
    virtual ~Vehicle();
    
}; // END Vehicle class declaration



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Individual declaration                           **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2019 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class Individual : public Vehicle
{
public:
    
    Individual();
    Individual(string id, string name, Date inspectionDate, char status);
    
}; // END class Individual declaration



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Passenger declaration                            **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2019 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class Passenger : public Vehicle
{
private:
    
    int capacity; /*!< maximum passenger transport capacity */
    
public:
    
    Passenger(unsigned short = MIN_PASSENGER_CAPACITY);
    Passenger(string id, string name, Date inspectionDate, char status, unsigned short cap);
    
    unsigned short getCapacity() const;
    
    void setCapacity(unsigned short cap);

    virtual void print( ostream& os = cout ) const;
    virtual void read( istream& is );
    
}; // END class Passenger declaration



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Cargo declaration                                **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2019 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class Cargo : public Vehicle
{
private:
    
    double capacity;  /*!< maximum payload hauling capacity (in tons) */
    
public:
    
    Cargo(double = MIN_CARGO_CAPACITY);
    Cargo(string id, string name, Date inspectionDate, char status, double cap);
    
    double getCapacity() const;
    
    void setCapacity(double cap);
    
    virtual void print( ostream& os = cout ) const;
    virtual void read( istream& is );
    
}; // END class Cargo declaration

#endif /* VEHICLE_H */





