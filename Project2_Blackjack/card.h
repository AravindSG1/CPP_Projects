#ifndef CARD_H
#define CARD_H

#include <iostream>

/*Creates the card objects that is every kind of card in the deck*/
class Cards{
    public:
        const char *name;
        const char *suit;
        int rank;

        Cards() = default;

        //setters
        void set_name(const char *name){
            this->name = name;
        }

        void set_suit(const char *suit){
            this->suit = suit;
        }

        void set_rank(int rank){
            if(rank>10){
               this->rank = 10; 
            }
            else{
                this->rank = rank;
            }            
        }
        
        //getters
        void get_name_of_card(){
            std::cout<<name<<" of "<<suit<<std::endl;
        }
        int get_value(){
            return rank;
        }
        const char* get_name(){
            return name;
        }
        
};


class chips{
    public:
        int chip_value;

        //constructors
        chips() = default;
        chips(int chip_value){
           this->chip_value = chip_value; 
        }
        //setters
        void set_chip_value(int chip_value){
            this->chip_value = chip_value;
        }
        void set_change_chip_value(int chip_value){
            this->chip_value+=chip_value;
        }

        //getters
        int get_chip_value(){
            return chip_value;
        }
};

#endif
