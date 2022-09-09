/******************************************************
** Program: Bear.cpp
** Author: Parker Choc
** Date: 05/09/2021
** Description: Bear class functions
** Input: depends
** Output: depends
******************************************************/

#include <iostream>
#include "Bear.h"

using namespace std;

/*********************************************************************  
** Functions: Bear() 2 overloaded functions
** Description: constructs the bear class using either no prarameters
**      or an int starting age parameter
** Parameters: none or int strating age
** Pre-Conditions: none or the specific starting age the constructed
**      animal should be
** Post-Conditions: constructs a bear class
*********************************************************************/
Bear::Bear()
{
    name = 'B';
    cost = 5000;
    food_cost_multiplier = 3;
    baby_rate = 2;
}

Bear::Bear(int starting_age)
{
    name = 'B';
    cost = 5000;
    food_cost_multiplier = 3;
    baby_rate = 2;
    age = starting_age;
}

/*********************************************************************  
** Functions: get_age()
** Description: returns the age
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the age
*********************************************************************/
int Bear::get_age()
{
	return age;
}