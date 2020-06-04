/*
*  main.cpp
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

#include "main.h"
#include <string>

int main(int argc, const char* argv[])
{
    try
    {
        if(argc < 2)
	{
            cout << "Not enough command line arguments, please pass the complete path and name of ";
            cout << "the input data file as a command line argument.\n";
            cout << "Please try again." << endl;
	}
        else
        {
                string fileName = argv[1];

                VehicleLog vL1; 

                vL1.read(fileName);

                cout << "Total Cargo Capacity: " << vL1.getTotalCargoCapacity() << endl;

                cout << "Total Passenger Capacity: " << vL1.getTotalPassengerCapacity() << endl;
        }
        
    }
    catch(invalid_argument &e)
    {
       cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "Unknown Exception caught" << endl;
    }

   
    return 0;
}