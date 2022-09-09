/******************************************************
** Program: Zookeeper.h
** Author: Parker Choc
** Date: 05/09/2021
** Description: Zookeeper class header
** Input: depends
** Output: depends
******************************************************/

#ifndef H_Zookeeper
#define H_Zookeeper

using namespace std;

#include <iostream>
#include "Zoo.h"

class Zookeeper
{
    private:
        int month;
        int money;
        Zoo my_zoo;
        int sickness_odds;
        int food_base_cost;
    public:
    //Constructors
        Zookeeper();
    //Getters
        int get_money();
        Zoo* get_zoo();
    //Other functions
        bool check_game_end();
        char display_info();
        void execute_option(char&);
        void gain_money();
        void random_event();
        void game_flow();
        void feeding_time();

};

#endif