/******************************************************
** Program: Sea_Lion.cpp
** Author: Parker Choc
** Date: 05/09/2021
** Description: Sea_Lion class functions
** Input: depends
** Output: depends
******************************************************/

#include <iostream>
#include "Sea_Lion.h"

using namespace std;

/*********************************************************************  
** Functions: Sea_Lion() 2 overloaded functions
** Description: constructs the sea lion class using either no prarameters
**      or an int starting age parameter
** Parameters: none or int strating age
** Pre-Conditions: none or the specific starting age the constructed
**      animal should be
** Post-Conditions: constructs a sea lion class
*********************************************************************/
Sea_Lion::Sea_Lion()
{
    name = 'L';
    cost = 800;
    //food costs and baby rates are the same as the default
}

Sea_Lion::Sea_Lion(int starting_age)
{
    name = 'L';
    cost = 800;
    age = starting_age;
    //food costs and baby rates are the same as the default
}

/*********************************************************************  
** Functions: get_age()
** Description: returns the age
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the age
*********************************************************************/
int Sea_Lion::get_age()
{
	return age;
}
