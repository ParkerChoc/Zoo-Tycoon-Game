/******************************************************
** Program: Tiger.h
** Author: Parker Choc
** Date: 05/09/2021
** Description: Tiger class header
** Input: depends
** Output: depends
******************************************************/

#ifndef H_Tiger
#define H_Tiger

#include <iostream>
#include "Animal.h"

using namespace std;

class Tiger : public Animal 
{
    private:
        //stuff
    
    public:
	    Tiger();
        Tiger(int);
	    int get_age();

};
#endif