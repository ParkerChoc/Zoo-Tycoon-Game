/******************************************************
** Program: Zookeeper.cpp
** Author: Parker Choc
** Date: 05/09/2021
** Description: Zookeeper class functions
** Input: depends
** Output: depends
******************************************************/

#include "./Animal.h"
#include "./Sea_Lion.h"
#include "./Tiger.h"
#include "./Bear.h"
#include "./Zoo.h"
#include "./Zookeeper.h"

#include <cctype>   //used for toupper()
#include <stdlib.h> // Used for rand

/*********************************************************************  
** Functions: Zookeeper()
** Description: constructs the zookeeper class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: zookeeper class created
*********************************************************************/
    Zookeeper::Zookeeper()
    {
        Zoo z1;
        my_zoo = z1;
        month = 0;
        money = 100000;
        sickness_odds = 2;
        food_base_cost = 80;
    }

/*********************************************************************  
** Functions: get_money()
** Description: returns the amount of money the zookeeper has
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns money
*********************************************************************/
    int Zookeeper::get_money()
    {
        return money;
    }

/*********************************************************************  
** Functions: get_zoo()
** Description: returns the zookeeper's zoo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the zookeeper's zoo
*********************************************************************/
    Zoo* Zookeeper::get_zoo()
    {
        return &my_zoo;
    }

/*********************************************************************  
** Functions: check_game_end()
** Description: checks to see if the player has run out of money
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true or false depending on if the player
**      is out of money
*********************************************************************/
    bool Zookeeper::check_game_end()
    {
        //return true if the game is over
        //return false if the game is not over yet
        if(money < 0)
        {
            cout << "You have run out of money and your zoo has gone bankrupt\n";
            cout << "\tGame Over\n";
            return true;
        }

        return false;
    }

/*********************************************************************  
** Functions: display_info()
** Description: displays the menu for the user options and returns their
**      choice of what to do
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the user's choice in the form of a char
*********************************************************************/
    char Zookeeper::display_info()
    {
        char answer;
        do
        {
            cout << "\n\tMonth: " << month << "\n";
            cout << "\tMoney: $" << money << "\n\n";

            cout << "Select an option: (L, T, B, P, Q)\n";
            cout << "(L) buy up to two sea lions  \t(cost $800 each)\n";
            cout << "(T) buy up to two tigers     \t(cost $10000 each)\n";
            cout << "(B) buy up to two black bears\t(cost $5000 each)\n";
            cout << "(P) pass - buy nothing\n";
            cout << "(D) display my animals\n";
            cout << "(Q) Quit the game\n";

            cin >> answer;
            answer = toupper(answer);
            
            if ((answer == 'L') 
                || (answer == 'T') 
                || (answer == 'B') 
                || (answer == 'P') 
                || (answer == 'Q'))
            {
                return answer;
            }
            
            if (answer == 'D')
                my_zoo.print_zoo();
            
            //I want this loop to run forever until user enters correct value.
        } while (0 == 0);
    }

/*********************************************************************  
** Functions: execute_option()
** Description: allows the user to buy up to two animals of the same
**      class, checks to see if the user has enough moeny and calls the
**      right function to add animals
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: either returns with nothing or charges the cost of
**      the animals and adds them
*********************************************************************/
    void Zookeeper::execute_option(char &answer)
    {
        int number;
        do 
        {
            cout << "How many do you wish to buy? (1 or 2):";
            cin >> number;
        } while ((number != 1) && (number != 2));
        
        switch(answer)
        {
            case 'L' :
                {
                    Sea_Lion s1;
                    if (number * s1.get_cost() > money)
                    {
                        cout << "You do not have enough money\n";
                        return;
                    }
                    for (int i = 0; i < number; i++)
                    {
                        Sea_Lion s1;
                        my_zoo.add_animal(s1);
                        money -= s1.get_cost();    
                    }  
                    break;
                }
            case 'T' :
                {
                    Tiger t1;
                    if (number * t1.get_cost() > money)
                    {
                        cout << "You do not have enough money\n";
                        return;
                    }
                    for (int i = 0; i < number; i++)
                    {
                        Tiger t1;
                        my_zoo.add_animal(t1);
                        money -= t1.get_cost();    
                    }
                    break;
                }
            case 'B' :
                {
                    Bear b1;
                    if (number * b1.get_cost() > money)
                    {
                        cout << "You do not have enough money\n";
                        return;
                    }
                    for (int i = 0; i < number; i++)
                    {
                        Bear b1;
                        my_zoo.add_animal(b1);
                        money -= b1.get_cost();    
                    }
                    break;
                }
            default :
                break;
        }
        answer = '@';
    }

/*********************************************************************  
** Functions: gain_money()
** Description: adds revenue to the amount of money the zookeeper has
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: modified money value
*********************************************************************/
    void Zookeeper::gain_money()
    {
        int revenue = my_zoo.generate_revenue();
        money += revenue;
        if (month > 1)
            cout << "\nYou generated $" << revenue << " in revenue!\n";
    }

/*********************************************************************  
** Functions: random_enent()
** Description: determines a random event to be called and then calls
**      an appropriate function
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: random event function called
*********************************************************************/
    void Zookeeper::random_event()
    {
        srand(time(NULL));
        int event = 1 + rand() % (sickness_odds + 6);
        
        //sickness odds can be 1, 2, or 4 depending on the feed used.

        if ((event <= sickness_odds) && (my_zoo.get_n_total() > 0))
        {
            cout << "Oh no! One of your animals got sick!\n";
            my_zoo.animal_gets_sick(money);
            return;
        }
        
        if ((event > sickness_odds) 
            && (event <= sickness_odds + 2) 
            && (my_zoo.get_n_total() > 0))
        {
            cout << "Animal gives birth\n";
            my_zoo.animal_gives_birth();
            return;
        }
        
        if ((event > sickness_odds + 2) && (event <= sickness_odds + 4))
        {
            cout << "There has been a boon in zoo attendance!\n";
            money += my_zoo.special_lion_income();
            return;
        }

        cout << "There is no special event this month.\n";
    }

/*********************************************************************  
** Functions: feeding_time()
** Description: displays food options and charges the user based on the
**      option they choose
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: moeny modified after paying for feed and sickness
**      odds potentially modified based on the selected food
*********************************************************************/
    void Zookeeper::feeding_time()
    {
        srand(time(NULL));
        int rand_multiplier = 80 + rand() % 40; //number between 80 and 120
        food_base_cost *= rand_multiplier * 0.01;   //modify base cost
        cout << "This month, the food base cost is: $" << food_base_cost << "\n";

        int cost = my_zoo.cost_for_food(food_base_cost);
        int choice;

        cout << "You have four food options: \n";
        cout << "\t(1) cheap food: sickness odds doubled         \t$" << cost * 0.5 << "\n";
        cout << "\t(2) regular food: normal sickness odds        \t$" << cost << "\n";
        cout << "\t(3) premium food: sickness odds halfed        \t$" << cost * 2 << "\n";
        cout << "\t(4) magic unicorn food: no chance of sickness \t$" << cost * 3 << "\n";
        cout << "Please enter your food choice (1, 2, 3, or 4):";
        cin >> choice;

        if (choice == 1)
            {
                sickness_odds = 4;
                money -= (cost * 0.5);
            }
        if (choice == 2)
            {
                sickness_odds = 2;
                money -= cost;
            }
        if (choice == 3)
            {
                sickness_odds = 1;
                money -= (cost * 2);
            }
        if (choice == 4)
            {
                sickness_odds = 0;
                money -= (cost * 3);
            }
    }

/*********************************************************************  
** Functions: game_flow()
** Description: calls all functions needed to run the game unitl the 
**      user runs out of moeny or select to quit
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: runs the game and returns nothing
*********************************************************************/
    void Zookeeper::game_flow()
    {
        char answer;
        do 
        {
            month++;
            my_zoo.age_all_animals();
            gain_money();
            random_event();
            if (check_game_end())
                return;
            do
            {
                answer = display_info();
                if (answer == 'Q')
                    return;
                if (answer != 'P')
                    execute_option(answer);
                //the @ is assigned to answer if the user made a purchase
                //this will loop until the user has passed or bought an animal
            } while ((answer != 'P') && (answer != '@'));
            feeding_time();
        } while (!check_game_end());
    }