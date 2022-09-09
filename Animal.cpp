/******************************************************
** Program: Animal.cpp
** Author: Parker Choc
** Date: 05/09/2021
** Description: Animal class functions
** Input: depends
** Output: depends
******************************************************/

#include "Animal.h"

/*********************************************************************  
** Functions: Animal() (overloaded for other constructor)
** Description: constructs the animal class
** Parameters: none, starting age
** Pre-Conditions: none or the starting age of the animal
** Post-Conditions: animal class created
*********************************************************************/
Animal::Animal()
{
    this->name = 'Z';
    this->cost = 0;
    this->food_cost_multiplier = 1;
    this->baby_rate = 1;
    this->revenue = cost / 10;
    this->age = 48; //months old when bought
}

Animal::Animal(int starting_age)
{
    this->name = 'Z';
    this->cost = 0;
    this->food_cost_multiplier = 1;
    this->baby_rate = 1;
    this->revenue = cost / 10;
    this->age = starting_age; //months old when bought
}

/*********************************************************************  
** Functions: get_name(), get_age(), get_cost(), get_baby_rate(),
**      get_food_multiplier()
** Description: getters for the animal class. they all return the value
**      specified in thier name
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returned value from the animal class
*********************************************************************/
char Animal::get_name() 
{
	return name;
}

//Getter
int Animal::get_age()
{
	return age;
}

//Getter
int Animal::get_cost()
{
    return cost;
}

//Getter
int Animal::get_baby_rate()
{
    return baby_rate;
}

//Getter
int Animal::get_food_multiplier()
{
    return food_cost_multiplier;
}

/*********************************************************************  
** Functions: set_age()
** Description: sets the age of the animal to a specific value
** Parameters: const int &age
** Pre-Conditions: an age to set the animal to
** Post-Conditions: animal age modified
*********************************************************************/
void Animal::set_age(const int &age)
{
    this->age = age;
}

/*********************************************************************  
** Functions: operator++()
** Description: adds one to the age of the animal
** Parameters: integer
** Pre-Conditions: none
** Post-Conditions: adds one to the age of the animal
*********************************************************************/
Animal& Animal::operator++(int)
{
   age++;
   return *this;
}

/*********************************************************************  
** Functions: print_animal()
** Description: prints the animal's age
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: prints to screen the animal's age
*********************************************************************/
void Animal::print_animal()
{
    cout << " " << age << "\n";
}

/*********************************************************************  
** Functions: is_a_baby()
** Description: returns true if the animal is a baby. False otherwise
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: true or false value
*********************************************************************/
bool Animal::is_a_baby()
{
    if (age <= 6)
        return true;
    return false;
}