/******************************************************
** Program: Bear.h
** Author: Parker Choc
** Date: 05/09/2021
** Description: Bear class header
** Input: depends
** Output: depends
******************************************************/

#ifndef H_Bear
#define H_Bear

#include <iostream>
#include "Animal.h"

using namespace std;

class Bear : public Animal 
{
    private:
        //stuff
    
    public:
	    Bear();
        Bear(int);
	    int get_age();
};
#endif