/******************************************************
** Program: Zoo.h
** Author: Parker Choc
** Date: 05/09/2021
** Description: Zoo class header
** Input: depends
** Output: depends
******************************************************/

#ifndef H_Zoo
#define H_Zoo

#include "./Sea_Lion.h"
#include "./Tiger.h"
#include "./Bear.h"
#include "./Animal.h"

class Zoo
{
    private:
        int n_lions;
        int n_tigers;
        int n_bears;
        int n_total;
        Sea_Lion* l_cage;
        Tiger* t_cage;
        Bear* b_cage;
    public:
    //Constructors
        Zoo();
        Zoo(const Zoo&);
    //Assignment Operator Overload
        Zoo& operator=(const Zoo&);
    //Destructor 
        ~Zoo();
    //Getters
        int get_n_total();
    //Other
        void print_zoo();
        
        void add_animal(Sea_Lion);
        void add_animal(Tiger);
        void add_animal(Bear);
        
        int generate_revenue();
        char decode_index(const int&);
        
        void kill_sea_lion(const int&);
        void kill_tiger(const int&);
        void kill_bear(const int&);
        
        void animal_dies(const int&);
        void animal_gets_sick(int&);

        void age_all_animals();

        void baby_lions();
        void baby_tigers();
        void baby_bears();

        int special_lion_income();
        void animal_gives_birth();

        int cost_for_food(int&);
        
};

#endif