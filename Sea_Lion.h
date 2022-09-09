/******************************************************
** Program: Sea_Lion.h
** Author: Parker Choc
** Date: 05/09/2021
** Description: Sea Lion class header
** Input: depends
** Output: depends
******************************************************/

#ifndef H_Sea_Lion
#define H_Sea_Lion

#include <iostream>
#include "Animal.h"

using namespace std;

class Sea_Lion : public Animal 
{
    private:
        //stuff
    
    public:
	    Sea_Lion();
        Sea_Lion(int);
	    int get_age();
};
#endif