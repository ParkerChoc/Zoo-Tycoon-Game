/******************************************************
** Program: Animal.h
** Author: Parker Choc
** Date: 05/09/2021
** Description: Animal class header
** Input: depends
** Output: depends
******************************************************/

#ifndef H_Tips
#define H_Tips

using namespace std;

#include <iostream>

class Animal
{
    protected:  //derived classes can access
        char name;  //L for lion, T for tiger, B for bear
        int food_cost_multiplier;
        int baby_rate;
        int revenue;
        int age;
        int cost;
    private:
        
    public:
    //Constructors
        Animal();
        Animal(int);
    //Getters
        char get_name();
        int get_cost();
        int get_age();
        int get_baby_rate();
        int get_food_multiplier();
    //Setters
        void set_age(const int&);
    //Other functions
        Animal& operator++(int);
        
        void print_animal();
        bool is_a_baby();
};

#endif