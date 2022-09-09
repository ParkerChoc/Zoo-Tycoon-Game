/******************************************************
** Program: Tiger.cpp
** Author: Parker Choc
** Date: 05/09/2021
** Description: Tiger class functions
** Input: depends
** Output: depends
******************************************************/

#include <iostream>
#include "Tiger.h"

using namespace std;

/*********************************************************************  
** Functions: Tiger() 2 overloaded functions
** Description: constructs the tiger class using either no prarameters
**      or an int starting age parameter
** Parameters: none or int strating age
** Pre-Conditions: none or the specific starting age the constructed
**      animal should be
** Post-Conditions: constructs a tiger class
*********************************************************************/
Tiger::Tiger()
{
    name = 'T';
    cost = 10000;
    food_cost_multiplier = 5;
    baby_rate = 3;
}

Tiger::Tiger(int starting_age)
{
    name = 'T';
    cost = 10000;
    food_cost_multiplier = 5;
    baby_rate = 3;
    age = starting_age;
}

/*********************************************************************  
** Functions: get_age()
** Description: returns the age
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the age
*********************************************************************/
int Tiger::get_age()
{
	return age;
}