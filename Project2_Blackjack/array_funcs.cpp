#include <iostream>
#include "card.h"
#include "array_funcs.h"

/*Returns a card popped from the deck*/
class Cards deck_card_pop(class Cards *input_array, int *position, int *input_array_size){
    *position = rand()%*input_array_size;
    class Cards *temp_array;
    class Cards removed_one = input_array[*position-1];
    //n-1 4

    temp_array = new class Cards[*input_array_size-1];
    for(int i = 0; i<*position-1;i++){     //pos-1 because index from 0 
        temp_array[i] = input_array[i];    //here i ends at pos-2
        //temp_array[0].get_name_of_card();
    }
    for(int i = *position-1;i<*input_array_size-1;i++){   
        temp_array[i] = input_array[i + 1];
        //temp_array[position-1].get_name_of_card();
    }

    *input_array_size = *input_array_size-1; //new array length
    
    for(int i=0;i<*input_array_size;i++){  //copying from temp to deck array,card by card
        *(input_array+i) = *(temp_array+i);
    }

    delete[] temp_array;
 

    return removed_one;   //this will give the popped card from deck
}


/*Adds a new card to the hand*/
class Cards* add_to_hand(class Cards *input_array, class Cards input_card, int *input_array_size){    
        //add elements
    
    
    class Cards *temp_array = new class Cards[*input_array_size+1]; 
    
    for(int i=0;i<*input_array_size;i++){
        temp_array[i] = input_array[i];
    }
    *input_array_size = *input_array_size+1; //new size
    
    temp_array[*input_array_size-1] = input_card; //appending on last position
    
    input_array = temp_array;  
    
    return input_array;
 
}

/*Gives the sum of values of all cards inside a hand*/
int sum_of_cards(class Cards *hand, int hand_size){
    int sum = 0;
    for(int i = 0;i<hand_size;i++){
        sum+= hand[i].get_value();
        
        if(sum<21 && hand[i].name == "ace"){ //ace default value is 1, so first adding 10 to get value 11
            sum+=10;                                
        }
        if(sum>21 && hand[i].name == "ace"){ //now checking if the value is not over 21 with 11 value
            sum-=10;                         //if its above 21 changing to value 1
        }
    }
    return sum;
}
/*Prints all cards inside player hand*/
void print_player_cards(class Cards *player_hand, int player_hand_size, int player_sum){
    std::cout<<'\n'<<std::endl;
    for(int i = 0;i<player_hand_size;i++){  //printing player hand
    std::cout<<"Player card "<<i+1<<std::endl;
    player_hand[i].get_name_of_card();
    }
    std::cout<<"Player card sum = "<<player_sum<<std::endl;
}
/*Prints all cards inside dealer hand*/
void print_dealer_cards(class Cards *dealer_hand, int dealer_hand_size, int dealer_sum){
    for(int i = 0;i<dealer_hand_size;i++){  //printing player hand
    std::cout<<"Dealer card "<<i+1<<std::endl;
    dealer_hand[i].get_name_of_card();
    }
    std::cout<<"Dealer card sum = "<<dealer_sum<<std::endl;
}
