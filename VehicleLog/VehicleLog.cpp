/*
*  VehicleLog.cpp
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

#include "VehicleLog.h"


VehicleLog::VehicleLog()
{
    
}
    
int VehicleLog::getTotalPassengerCapacity() const
{
    int totalPassengers = 0;
    
    for(int i = 0; i <vehicles.size(); i++ )
    {
        Passenger *ptr = dynamic_cast<Passenger*>(vehicles.at(i));
        
        if(ptr)
        {
            totalPassengers += ptr->getCapacity();
        }
    }
    
    return totalPassengers;
}
double VehicleLog::getTotalCargoCapacity() const
{
    double totalCargo = 0.0;
    
    for(int i = 0; i < vehicles.size(); i++ )
    {
        Cargo *ptr = dynamic_cast<Cargo*>(vehicles.at(i));
        
        if(ptr)
        {
            totalCargo += ptr->getCapacity();
            
        }
    }
    
    return totalCargo;
}
    
void VehicleLog::print( ostream& os ) const
{
    string failedOS = "Output stream is in a failed state in VehicleLog::print";
    if(!os)
    {
        throw invalid_argument(failedOS); 
    }
    
    for(int i = 0; i < vehicles.size();i++)
    {
        vehicles.at(i)->print(os);
    }
}
void VehicleLog::read( string fileName )
{
    std::ifstream inFile;
    
    inFile.open(fileName.c_str());
    
    string failedFile = "Failed to open file";
    
    string id = " ";
    string exclude = " ";
    char vehicleCode = ' ';
    

    if(!inFile)
    {
        throw invalid_argument(failedFile);
    }
    else
    {
        while(inFile >> id)
        {
            vehicleCode = id.at(0);
            
            
            try
            {
                if(!(vehicleCode == 'c' || vehicleCode == 'i' || vehicleCode == 'p'))
                {
                    throw bad_vehicle_code("Invalid vehicle code in VehicleLog::read");
                }
                else
                {
                    
                    bool valid = true;
                    
                    Vehicle *ptr;

                    if(vehicleCode == 'c')
                    {   
                        ptr =  new Cargo;
                    }
                    else if(vehicleCode == 'p')
                    {
                        ptr = new Passenger;
                    }
                    else
                    {
                        ptr = new Individual;
                    }
                    try
                    {
                        ptr->setID(id);
                        ptr->read(inFile); 
                        ptr->print();
                        cout << endl;
                    }
                    catch(invalid_argument &e)
                    {
                        getline(inFile, exclude);
                        valid = false;
                        cout << e.what() << "\n" << endl;
                    }
                    if(valid)
                    {
                        vehicles.push_back(ptr);
                    }
                }
           
            }
            catch(bad_vehicle_code &e)
            {
                getline(inFile, exclude);
                cout << e.what() << "\n" << endl;
            }
            
        }
        
        
    }
    
    
    
    
    
    
}
    
unsigned long VehicleLog::size() const
{
    return vehicles.size();
}
    
Vehicle& VehicleLog::at(unsigned long ndx)
{
    if(ndx >= vehicles.size())
    {
        throw std::out_of_range("Index passed not valid in VehicleLog::at");
    }
    return *vehicles.at(ndx);
}
    
VehicleLog::~VehicleLog()
{
    for(int i = 0; i < vehicles.size(); i++)
    {
        delete vehicles.at(i);
    }
    
}