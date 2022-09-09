/******************************************************
** Program: Zoo.cpp
** Author: Parker Choc
** Date: 05/09/2021
** Description: Zoo class functions
** Input: depends
** Output: depends
******************************************************/

#include "./Animal.h"
#include "./Sea_Lion.h"
#include "./Tiger.h"
#include "./Bear.h"
#include "./Zoo.h"

/*********************************************************************  
** Functions: Zoo() (overloaded for copy constructor)
** Description: constructs the zoo class
** Parameters: none, old zoo
** Pre-Conditions: none
** Post-Conditions: zoo class created
*********************************************************************/
//Constructor
    Zoo::Zoo()
    {
        n_lions = 0;
        n_tigers = 0;
        n_bears = 0;
        n_total = n_lions + n_tigers + n_bears;

        l_cage = new Sea_Lion[0];
        t_cage = new Tiger[0];
        b_cage = new Bear[0];
    }

//Copy Constructor
    Zoo::Zoo(const Zoo& old_zoo)
    {
        n_lions = old_zoo.n_lions;
        l_cage = new Sea_Lion[n_lions];
        for (int i = 0; i < n_lions; i++)
        {
            l_cage[i] = old_zoo.l_cage[i];
        }

        n_tigers = old_zoo.n_tigers;
        t_cage = new Tiger[n_tigers];
        for (int i = 0; i < n_tigers; i++)
        {
            t_cage[i] = old_zoo.t_cage[i];
        }

        n_bears = old_zoo.n_bears;
        b_cage = new Bear[n_bears];
        for (int i = 0; i < n_bears; i++)
        {
            b_cage[i] = old_zoo.b_cage[i];
        }
        //cout << "Copy Contructor\n"
    }

/*********************************************************************  
** Functions: operator=()
** Description: overlaods the = operator to assign a zoo to another
** Parameters: const Zoo& old_zoo
** Pre-Conditions: a zoo to be copied from
** Post-Conditions: a new zoo constructed from the old one
*********************************************************************/
    Zoo& Zoo::operator=(const Zoo& old_zoo)
    {
        n_lions = old_zoo.n_lions;
        delete[] l_cage;
        l_cage = new Sea_Lion[n_lions];
        for (int i = 0; i < n_lions; i++)
        {
            l_cage[i] = old_zoo.l_cage[i];
        }
        
        n_bears = old_zoo.n_bears;
        delete[] b_cage;
        b_cage = new Bear[n_bears];
        for (int i = 0; i < n_bears; i++)
        {
            b_cage[i] = old_zoo.b_cage[i];
        }

        n_tigers = old_zoo.n_tigers;
        delete[] t_cage;
        t_cage = new Tiger[n_tigers];
        for (int i = 0; i < n_tigers; i++)
        {
            t_cage[i] = old_zoo.t_cage[i];
        }
        return *this;
    }

/*********************************************************************  
** Functions: ~Zoo()
** Description: frees all dynamically allocated memory
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all dynamically allocated memory released
*********************************************************************/
    Zoo::~Zoo()
    {
        delete [] l_cage;
        delete [] t_cage;
        delete [] b_cage;
    }

/*********************************************************************  
** Functions: get_n_total()
** Description: returns the total number of animals in the zoo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the total number of animals in the zoo
*********************************************************************/
    int Zoo::get_n_total()
    {
        return n_total;
    }

/*********************************************************************  
** Functions: print_zoo()
** Description: prints out the zoo information
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: prints out the zoo information
*********************************************************************/
    void Zoo::print_zoo()
    {
        cout << "\nThe ages displayed are in months\n";
        cout << "Adults are 48 months and older.\n";
        cout << "Babies are less than 6 months  old.\n";
        cout << "Sea Lions: (" << n_lions << ")\n";
        for (int i = 0; i < n_lions; i++)
        {
            cout << "age: ";
            l_cage[i].print_animal();
        }
        
        cout << "Tigers: (" << n_tigers << ")\n";
        for (int i = 0; i < n_tigers; i++)
        {
            cout << "age: ";
            t_cage[i].print_animal();
        }
        
        cout << "Black Bears: (" << n_bears << ")\n";
        for (int i = 0; i < n_bears; i++)
        {
            cout << "age: ";
            b_cage[i].print_animal();
        }
    }

/*********************************************************************  
** Functions: add_animal() (overloaded for each species)
** Description: adds an animal of that species to the zoo
** Parameters: animal
** Pre-Conditions: an animal species to be added to the zoo
** Post-Conditions: one animal added to the zoo
*********************************************************************/
//adds a sea lion to the zoo
    void Zoo::add_animal(Sea_Lion addition)
    {
        //temp cage holds 1 more animal
        Sea_Lion* temp = new Sea_Lion[n_lions + 1];   

        int counter = 0;
        for (int i = 0; i < n_lions; i++)
        {
            temp[i] = l_cage[i];
            counter++;
        }
        temp[counter] = addition;    
        //temp cage is now what the new cage should be

        delete[] l_cage;
        n_lions += 1;
        n_total += 1;
        l_cage = new Sea_Lion[n_lions];

        //copy all of temp into the new cage
        for (int i = 0; i < n_lions; i++)
            l_cage[i] = temp[i];
        delete[] temp;
    }

//adds a tiger to the zoo
    void Zoo::add_animal(Tiger addition)
    {
        //temp cage holds 1 more animal
        Tiger* temp = new Tiger[n_tigers + 1];   

        int counter = 0;
        for (int i = 0; i < n_tigers; i++)
        {
            temp[i] = t_cage[i];
            counter++;
        }
        temp[counter] = addition;    
        //temp hand is now what the new cage should be

        delete[] t_cage;
        n_tigers += 1;
        n_total += 1;
        t_cage = new Tiger[n_tigers];

        //copy all of temp into the new cage
        for (int i = 0; i < n_tigers; i++)
            t_cage[i] = temp[i];
        delete[] temp;
    }

//adds a bear to the zoo
    void Zoo::add_animal(Bear addition)
    {
        //temp cage holds 1 more animal
        Bear* temp = new Bear[n_bears + 1];   

        int counter = 0;
        for (int i = 0; i < n_bears; i++)
        {
            temp[i] = b_cage[i];
            counter++;
        }
        temp[counter] = addition;    
        //temp hand is now what the new cage should be

        delete[] b_cage;
        n_bears += 1;
        n_total += 1;
        b_cage = new Bear[n_bears];

        //copy all of temp into the new cage
        for (int i = 0; i < n_bears; i++)
            b_cage[i] = temp[i];
        delete[] temp;
    }

/*********************************************************************  
** Functions: generate_revenue()
** Description: calculates and returns the zoo's revenue
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the zoo's revenue
*********************************************************************/
    int Zoo::generate_revenue()
    {
        int revenue = 0;
        
        for (int i = 0; i < n_lions; i++)   
        {
            if (l_cage[i].is_a_baby())  //baby generates twice as much
                revenue += l_cage[i].get_cost() * 0.40;
            else
                revenue += l_cage[i].get_cost() * 0.20;
        }

        for (int i = 0; i < n_tigers; i++)
        {
            if (t_cage[i].is_a_baby())  //baby generates twice as much
                revenue += t_cage[i].get_cost() * 0.20;
            else
                revenue += t_cage[i].get_cost() * 0.10;
        }
        
        for (int i = 0; i < n_bears; i++)
        {
            if (b_cage[i].is_a_baby())  //baby generates twice as much
                revenue += b_cage[i].get_cost() * 0.20;
            else
                revenue += b_cage[i].get_cost() * 0.10;
        }
        return revenue;
    }

/*********************************************************************  
** Functions: decode_index()
** Description: calculates what species an animal is given its index value
** Parameters: int &index
** Pre-Conditions: an integer index value
** Post-Conditions: returns a char representing the animal's species
*********************************************************************/
    char Zoo::decode_index(const int &index)
    {
        if (index <= n_lions)
            return 'l';
        if (index <= n_lions + n_tigers)
            return 't';
        if (index <= n_lions + n_tigers + n_bears)
            return 'b';
        return '!';
    }

/*********************************************************************  
** Functions: kill_sea_lion(), kill_tiger(), kill_bear()
** Description: removes the animal from the array given its index
** Parameters: int &index
** Pre-Conditions: the index value of the animal to be removed
** Post-Conditions: an array with the specified animal removed
*********************************************************************/

//removes the index sea lion from the zoo
    void Zoo::kill_sea_lion(const int &index)
    {
        int counter = 0;
        //temp cage holds 1 fewer animal
        Sea_Lion* temp = new Sea_Lion[n_lions - 1];   

        for (int i = 0; i < n_lions; i++)
            if (i != index)
            {
                temp[counter] = l_cage[i];
                counter++;
            }
        //temp cage is now what the cage should be

        delete[] l_cage;
        n_lions -= 1;
        l_cage = new Sea_Lion[n_lions];

        //copy all of temp into the cage
        for (int i = 0; i < n_lions; i++)
            l_cage[i] = temp[i];
        delete[] temp;
    }

//removes the index tiger from the zoo
    void Zoo::kill_tiger(const int &index)
    {
        int counter = 0;
        //temp cage holds 1 fewer animal
        Tiger* temp = new Tiger[n_tigers - 1];   

        for (int i = 0; i < n_tigers; i++)
            if (i != index)
            {
                temp[counter] = t_cage[i];
                counter++;
            } 
        //temp cage is now what the cage should be

        delete[] t_cage;
        n_tigers -= 1;
        t_cage = new Tiger[n_tigers];

        //copy all of temp into the cage
        for (int i = 0; i < n_tigers; i++)
            t_cage[i] = temp[i];
        delete[] temp;
    }

//removes the index bear from the zoo
    void Zoo::kill_bear(const int &index)
    {
        int counter = 0;
        //temp cage holds 1 fewer animal
        Bear* temp = new Bear[n_bears - 1];   

        for (int i = 0; i < n_bears; i++)
            if (i != index)
            {
                temp[counter] = b_cage[i];
                counter++;
            } 
        //temp cage is now what the cage should be

        delete[] b_cage;
        n_bears -= 1;
        b_cage = new Bear[n_bears];

        //copy all of temp into the cage
        for (int i = 0; i < n_bears; i++)
            b_cage[i] = temp[i];
        delete[] temp;
    }

/*********************************************************************  
** Functions: animal_dies()
** Description: calls the correct species kill function based on what
**      species the given animal index is
** Parameters: int &index
** Pre-Conditions: the index value of the animal to be removed
** Post-Conditions: functions called to remove the animal
*********************************************************************/
    void Zoo::animal_dies(const int &index)
    {
        if (decode_index(index) == 'l')
            kill_sea_lion(index - 1);
        
        if (decode_index(index) == 't')
            kill_tiger(index - 1);

        if (decode_index(index) == 'b')
            kill_bear(index - 1);
    }

/*********************************************************************  
** Functions: animal_gets_sick()
** Description: calculates the sick cost of a random animal getting sick.
**      modifies the money integer passed to it and calls the correct 
**      function for the specific animal getting sick
** Parameters: int &money
** Pre-Conditions: the amount of money the zookeeper has
** Post-Conditions: money variable modified, corrent function called
*********************************************************************/
    void Zoo::animal_gets_sick(int &money)
    {
        srand(time(NULL));
        int rand_animal = 1 + rand() % (n_total);
        int sick_cost = 0;

        if (decode_index(rand_animal) == 'l')
        {
            if (l_cage[rand_animal - 1].is_a_baby())
            {
                //sick baby costs twice as much
                sick_cost = l_cage[rand_animal - 1].get_cost();
                cout << "A baby Sea Lion got sick!\n";
            }    
            else
            {
                sick_cost = l_cage[rand_animal - 1].get_cost() * 0.5;
                cout << "A Sea Lion got sick!\n";
            }
        }
        if (decode_index(rand_animal) == 't')
        {
            if (t_cage[rand_animal - n_lions - 1].is_a_baby())
            {
                //sick baby costs twice as much
                sick_cost = t_cage[rand_animal - n_lions - 1].get_cost();
                cout << "A baby Tiger got sick!\n";
            }    
            else
            {
                sick_cost = t_cage[rand_animal - n_lions - 1].get_cost() * 0.5;
                cout << "A Tiger got sick!\n";
            }
        }
        if (decode_index(rand_animal) == 'b')
        {
            if (b_cage[rand_animal - n_lions - n_tigers - 1].is_a_baby())
            {
                //sick baby costs twice as much
                sick_cost = b_cage[rand_animal - n_lions - n_tigers - 1].get_cost();
                cout << "A baby Black Bear got sick!\n";
            }    
            else
            {
                sick_cost = b_cage[rand_animal - n_lions - n_tigers - 1].get_cost() * 0.5;
                cout << "A Black Bear got sick!\n";
            }
        }

        if (sick_cost > money)
        {
            cout << "You do not have enough moeny for medicine.\n";
            cout << "This poor animal dies :(\n";
            animal_dies(rand_animal);
        }
        else
        {
            cout << "This will set you back $" << sick_cost << "\n";
            money -= sick_cost;
        }
    }

/*********************************************************************  
** Functions: age_all_animals()
** Description: adds 1 to the age of each animal
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all animals aged 1 month
*********************************************************************/
    void Zoo::age_all_animals()
    {
        char type;
        for (int i = 0; i < n_total; i++)
        {
            type = decode_index(i + 1);
            switch(type)
            {
                case 'l' :
                    l_cage[i]++;
                    break;
                case 't' :
                    t_cage[i - n_lions]++;
                    break;
                case 'b' :
                    b_cage[i - n_lions - n_tigers]++;
                    break;
                default :
                    break;
            }
        }
    }

/*********************************************************************  
** Functions: baby_lions(), baby_tigers(), baby_bears()
** Description: the specified animal has a number of babies equal to its
**      rate of baby production
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: number of babies added to the specified animal cage 
*********************************************************************/
    void Zoo::baby_lions()
    {
        Sea_Lion example;
        cout << "A Sea Lion gave birth to " << example.get_baby_rate() << " babies!\n";
        for (int i = 0; i < example.get_baby_rate(); i++)
        {
            Sea_Lion addition(0);
            add_animal(addition);
        }
    }

    void Zoo::baby_tigers()
    {
        Tiger addition;
        cout << "A tiger gave birth to " << addition.get_baby_rate() << " babies!\n";
        for (int i = 0; i < addition.get_baby_rate(); i++)
        {
            Tiger addition(0);
            add_animal(addition);
        }
    }

    void Zoo::baby_bears()
    {
        Bear addition;
        cout << "A Bear gave birth to " << addition.get_baby_rate() << " babies!\n";
        for (int i = 0; i < addition.get_baby_rate(); i++)
        {
            Bear addition(0);
            add_animal(addition);
        }
    }

/*********************************************************************  
** Functions: special_lion_income()
** Description: calculates the bonus income for sea lions
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the bonus income made by the sea lions 
*********************************************************************/
    int Zoo::special_lion_income()
    {
        srand(time(NULL));
        int income = 0;

        for (int i = 0; i < n_lions; i++)
        {
            //picks random number between 150 and 400
            income += 150 + rand() % (250);
        }
        cout << "You made an extra $" << income << " from your sea linos!\n";
        return income;
    }

/*********************************************************************  
** Functions: animal_gives_birth()
** Description: picks a random index number and then determines what
**      animal that index number is. Calls the corresponding animal
**      birth function if the animal is an adult
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: calls specified function corresponding to the 
**      randomly called animal 
*********************************************************************/
    void Zoo::animal_gives_birth()
    {
        srand(time(NULL));
        int rand_animal = 1 + rand() % (n_total);
        char decoded_index = decode_index(rand_animal);
        int counter = 0;

        do
        {
            if (decoded_index == 'l')
            {
                for (int i = 0; i < n_lions; i++)
                {
                    if (l_cage[i].get_age() >= 48)
                    {
                        baby_lions();
                        return;
                    }
                }
                //There are no adult sea lions
                counter++;
                if (counter >= 3)
                    break;
                decoded_index = 't';
            }

            if (decoded_index == 't')
            {
                for (int i = 0; i < n_tigers; i++)
                {
                    if (t_cage[i].get_age() >= 48)
                    {
                        baby_tigers();
                        return;
                    }
                }
                //There are no adult tigers
                counter++;
                if (counter >= 3)
                    break;
                decoded_index = 'b';
            }

            if (decoded_index == 'b')
            {
                for (int i = 0; i < n_bears; i++)
                {
                    if (b_cage[i].get_age() >= 48)
                    {
                        baby_bears();
                        return;
                    }
                }
                //There are no adult bears
                counter++;
                if (counter >= 3)
                    break;
                decoded_index = 'l';
            }
        } while (counter >= 3);
        cout << "You do not have any adult animals to give birth.\n";
    }

/*********************************************************************  
** Functions: cost_for_food()
** Description: calculates the total cost of food
** Parameters: int &base_cost
** Pre-Conditions: the zookeeper's base food cost
** Post-Conditions: returns the total amount of money it will cost to
**      feed all of the animals 
*********************************************************************/
    int Zoo::cost_for_food(int &base_cost)
    {
        //loop through all animals and apply their food costs
        char type;
        int cost = 0;
        for (int i = 0; i < n_total; i++)
        {
            type = decode_index(i + 1);
            switch(type)
            {
                case 'l' :
                    cost += l_cage[i].get_food_multiplier() * base_cost;
                    break;
                case 't' :
                    cost += t_cage[i - n_lions].get_food_multiplier() * base_cost;
                    break;
                case 'b' :
                    cost += b_cage[i-n_lions-n_tigers].get_food_multiplier() * base_cost;
                    break;
                default :
                    cout << "Error!\n";
                    break;
            }
        }
        return cost;
    }