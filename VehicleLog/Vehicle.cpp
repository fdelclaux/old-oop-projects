/*
*  Vehicle.cpp
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

#include "Vehicle.h"

    /****************************
     **                        **
     **     Vehicle Class      **
     **                        **
     ****************************/

    Vehicle::Vehicle()
    {
        
        setID(DEFAULT_ID);
        setName(DEFAULT_NAME);
        Date d;
        d.setDate(MIN_YYYY, MIN_MM, MIN_DD);
        setInspectionDate(d);
        setStatus(DEFAULT_STATUS);
        
    }
    
    Vehicle::Vehicle( string id, string name, Date iDate, char status )
    {
        
        setID(id);
        setName(name);
        setInspectionDate(iDate);
        setStatus(status);
        
    }
    
    string Vehicle::getID() const
    {
        return id;   
    }
    
    string Vehicle::getName() const
    {
        return name;
    }
    
    Date Vehicle::getInspectionDate() const
    {
        return inspectionDate;
    }
    
    char Vehicle::getStatus() const
    {
        return status;
    }
    
    void Vehicle::setID( string id )
    {
        string invalidIDlength = "Invalid ID length";
        string invalidChar = "Invalid vehicle type code";
        string nonAlfaNum = "The ID has non-alfanumeric components";
        
        if(!(id.length() == 17))
        {
            throw invalid_argument(invalidIDlength);
        }
        
        if(!(id.at(0) == 'i' || id.at(0) == 'p' || id.at(0) == 'c'))
        {
            throw invalid_argument(invalidChar); 
        }
        
        for( int i = 0;i < id.length();i++)
        {
            if( isalnum(id.at(i)) == false)
            {
                throw invalid_argument(nonAlfaNum);
            }
        }
        
        this->id = id;
    }
    
    void Vehicle::setName( string n )
    {
        name = n;
    }
    
    void Vehicle::setInspectionDate( Date iDate )
    {
        inspectionDate.setDate(iDate);
    }
    
    void Vehicle::setStatus( char status )
    {
        string invalidStatus = "Invalid Status Character";
        
        if(!(status == 'm' || status == 's' || status == 'a'))
        {
            throw invalid_argument(invalidStatus);
        }
        
        this->status = status;
    }
    
    void Vehicle::print( ostream& os ) const
    {
        
        string failedOS = "The Output Stream is in a failed state";
        
        if(!os)
        {
            throw invalid_argument(failedOS);
        }
        
        os << "Vehicle ID: " << getID() << endl;
        os << "Make/Model: " << getName() << endl;
        os << "Last Inspection: " << getInspectionDate() << endl;
        if(getStatus() == 's')
        {
            os << "Current Status: In Service" << endl;
        }
        else if(getStatus() == 'm')
        {
            os << "Current Status: In maintenance" << endl;
        }
        else
        {
            os << "Current Status: Available"  << endl;
        }
        
        
    }
    
    void Vehicle::read( istream& is )
    {
        
        string failedIS = "This Input Stream is in a failed state";
        if(!is)
        {
            throw invalid_argument(failedIS);
        }
        
        string n;
        Date inspecDate;
        char stat;
        
        
        n = readDoubleQuotedString(is);
        setName(n);
        
        is >> inspecDate;
        setInspectionDate(inspecDate);
                
        is >> stat;
        setStatus(stat);
                 
    }
    
    Vehicle::~Vehicle()
    {
        
    }
    
    
    
    /****************************
     **                        **
     **     Individual Class   **
     **                        **
     ****************************/
    
    Individual::Individual()
    {
        
    }
    
    Individual::Individual(string id, string name, 
                            Date inspectionDate, char status)
    {
        
    }
    
    
    
    
    /****************************
     **                        **
     **     Passenger Class    **
     **                        **
     ****************************/
    
    Passenger::Passenger(unsigned short c )
    {
        setCapacity(c);
    }
    Passenger::Passenger(string id, string name, Date inspectionDate, 
                    char status, unsigned short cap)
    {
        setCapacity(cap);
    }
    
    unsigned short Passenger::getCapacity() const
    {
        return capacity;
    }
    
    void Passenger::setCapacity(unsigned short cap)
    {
        string tooMany = "Invalid Passenger capacity in Passenger::setCapacity";
        
        if(cap > 250 || cap < 0 )
        {
            throw too_many_passengers(tooMany);
        }
        
        capacity = cap;
    }

    void Passenger::print( ostream& os ) const
    {
        string failedOS = "The output stream is in a failed state in "
                "Passenger::print";
        
        if(!os)
        {
            throw invalid_argument(failedOS);
        }
        
        Vehicle::print(os);
        cout << "Max. Passengers: " << getCapacity() << endl;
    }
    
    void Passenger::read( istream& is )
    {
        string failedIS = "The input stream is in a failed state in " 
                "Passenger::read";
        
        if(!is)
        {
            throw invalid_argument(failedIS);
        }
        
        int capacity;
        Vehicle::read(is);
        
        is >> capacity;
        setCapacity(capacity);
    }
    
    
    
    
    /****************************
     **                        **
     **     Cargo Class        **
     **                        **
     ****************************/
    
    Cargo::Cargo(double c)
    {
        setCapacity(c);
    }
    
    Cargo::Cargo(string id, string name, Date inspectionDate, 
                                        char status, double cap)
    {
        setCapacity(cap);
    }
    
    double Cargo::getCapacity() const
    {
        return capacity;
    }
    
    void Cargo::setCapacity(double cap)
    {
        string tooMuch = "Cargo capacity is invalid in Cargo::setCapacity";
        
        if(cap < 0.0 || cap > 25.0)
        {
            throw too_much_cargo(tooMuch);
        }
        
        capacity = cap;
            
    }
    
    void Cargo::print( ostream& os ) const
    {
        string failedOS = "The output stream is in a failed state in "
                "Cargo::print";
        
        if(!os)
        {
            throw invalid_argument(failedOS);
        }
        
        Vehicle::print(os);
        cout << "Max. Payload: " << getCapacity() << " tons" << endl;
        
    }
    void Cargo::read( istream& is )
    {
        string failedIS = "The input stream is in a failed state";
        
        if(!is)
        {
            throw invalid_argument(failedIS);
        }
        
        double capacity;
        Vehicle::read(is);
        
        is >> capacity;
        
        setCapacity(capacity);
    }
    