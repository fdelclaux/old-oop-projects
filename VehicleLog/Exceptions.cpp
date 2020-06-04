/*
*  Exceptions.cpp
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

#include "Exceptions.h"

too_many_passengers::too_many_passengers(string msg) : invalid_argument(msg)
{
    
}

bad_vehicle_code::bad_vehicle_code(string msg) : invalid_argument(msg)
{
    
}

too_much_cargo::too_much_cargo(string msg) : invalid_argument(msg)
{
    
}