#include <iostream>
#include <cstdlib>  //for random number generator rand()%52 to generate between 1-52
#include "card.h"
#include "array_funcs.h"


int main()
{
    const char *Suits[] = {"Club", "Diamond", "Heart", "Spades"};
    const char *Ranks[]{"ace", "two", "three", "four", "five", "six", "seven",
                        "eight", "nine", "ten", "King", "Jack", "Queen"};   

    //the deck size should be kept track to generate random number accordingly  deck_size  
    class Cards *Deck = new class Cards[52];
    class Cards *player_hand;// = new class Cards[2];
    class Cards *dealer_hand;// = new class Cards[2];

    int deck_size = 52; //no of cards in deck
    int player_hand_size = 0; //stores the number of cards in player hand
    int dealer_hand_size = 0; //stores the number of cards in dealer hand
    int position; //gives the position to pop according to deck size
    int dealer_win_flag = 0;  //1 for win, helps to exit main while loop while dealer wins on a hit
    int player_sum = 0; //stores the current sum of player hand
    int dealer_sum = 0; //stores the current sum of dealer hand

    class chips player_chip(1000);  //class which holds chips for player
    class chips dealer_chip(1000);  //class which holds chips for dealer
    int bet_amount = 0;           //stores the bet amount of chips
    int winner_flag = 0;     //if player wins 0 else 1

    //Below code is deck creation
    for(int i= 0;i<sizeof(Suits)/sizeof(char*);i++){              //int index = i*13 + j
        for(int j= 0;j<sizeof(Ranks)/sizeof(char*);j++){        
        int index = i*(sizeof(Ranks)/sizeof(char*)) +j;
        Deck[index].set_name(Ranks[j]);
        Deck[index].set_suit(Suits[i]);
        Deck[index].set_rank(j+1);
        }
    }

    //initialising player hand
    player_hand = add_to_hand(player_hand, deck_card_pop(Deck, &position, &deck_size), &player_hand_size);
    player_hand = add_to_hand(player_hand, deck_card_pop(Deck, &position, &deck_size), &player_hand_size);

    //initialising dealer hand
    dealer_hand = add_to_hand(dealer_hand, deck_card_pop(Deck, &position, &deck_size), &dealer_hand_size);
    dealer_hand = add_to_hand(dealer_hand, deck_card_pop(Deck, &position, &deck_size), &dealer_hand_size); 
 
    player_sum = sum_of_cards(player_hand, player_hand_size); //gives the sum of cards inside a hand
    dealer_sum = sum_of_cards(dealer_hand, dealer_hand_size);

    std::cout<<"Welcome to Blackjack"<<std::endl;
    std::cout<<"Enter number of chips to bet"<<std::endl;
    std::cin>>bet_amount;  //inputing the bet amount
    //printing card values
    for(int i = 0;i<player_hand_size;i++){  //printing player hand
        std::cout<<"Player card "<<i+1<<std::endl;
        player_hand[i].get_name_of_card();
    }
    std::cout<<"Player card sum = "<<player_sum<<std::endl;
    //dealer hand with hidden card
    std::cout<<"Dealer card 1"<<std::endl;
    dealer_hand[0].get_name_of_card();   //dealer hand
    std::cout<<"Dealer card 2"<<std::endl;
    std::cout<<"Hidden card"<<std::endl;
    //printing codes upto here

    while(!dealer_win_flag){
        if(player_sum<21){

            std::cout<<"Would you like to hit or stay, h for hit and s for stay"<<std::endl;
            char choice;
            std::cin>>choice;
            if(choice == 'h'){
                player_hand = add_to_hand(player_hand, deck_card_pop(Deck, &position, &deck_size), &player_hand_size);
                player_sum = sum_of_cards(player_hand, player_hand_size);
                print_player_cards(player_hand, player_hand_size, player_sum);
                std::cout<<"Dealer card 1"<<std::endl;
                dealer_hand[0].get_name_of_card();   //dealer hand
                std::cout<<"Dealer card 2"<<std::endl;
                std::cout<<"Hidden card"<<std::endl;
                continue;
            }
            else{
                std::cout<<"Now dealer hits"<<std::endl;
                if(dealer_sum>player_sum){  //this code works when player directly stay wit 0 hits
                    print_player_cards(player_hand, player_hand_size, player_sum);
                    print_dealer_cards(dealer_hand, dealer_hand_size, dealer_sum);
                    std::cout<<"Dealer wins"<<std::endl;
                    winner_flag = 1;  //to give chips to dealer
                    break;
                }
                while(1){
                    dealer_hand = add_to_hand(dealer_hand, deck_card_pop(Deck, &position, &deck_size), &dealer_hand_size);
                    dealer_sum = sum_of_cards(dealer_hand, dealer_hand_size);
                    
                    if(dealer_sum>21){                            
                        print_player_cards(player_hand, player_hand_size, player_sum);
                        print_dealer_cards(dealer_hand, dealer_hand_size, dealer_sum);
                        std::cout<<"Dealer bust Player wins"<<std::endl;
                        dealer_win_flag = 1; //to exit main while loop
                        break; 
                    }
                    else if(dealer_sum>player_sum){                            
                        print_player_cards(player_hand, player_hand_size, player_sum);
                        print_dealer_cards(dealer_hand, dealer_hand_size, dealer_sum);
                        std::cout<<"Dealer wins"<<std::endl;
                        dealer_win_flag = 1; //to exit main while loop
                        winner_flag = 1;  //to give chips to dealer
                        break;
                    }
                }
            }

        }
        else{
                print_player_cards(player_hand, player_hand_size, player_sum);
                print_dealer_cards(dealer_hand, dealer_hand_size, dealer_sum);                          
                std::cout<<"Player bust Dealer wins"<<std::endl;
                winner_flag = 1;  //to give chips to dealer
                break;
            }
       
    }
    if(!winner_flag){
        player_chip.set_change_chip_value(bet_amount);
        std::cout<<"Player chips = "<<player_chip.get_chip_value()<<std::endl;
        dealer_chip.set_change_chip_value(-bet_amount);
        std::cout<<"Dealer chips = "<<dealer_chip.get_chip_value()<<std::endl;
    }
    else{
        player_chip.set_change_chip_value(-bet_amount);
        std::cout<<"Player chips = "<<player_chip.get_chip_value()<<std::endl;
        dealer_chip.set_change_chip_value(bet_amount);
        std::cout<<"Dealer chips = "<<dealer_chip.get_chip_value()<<std::endl;
    }
    
    std::cout<<"end111"<<std::endl;
        
    return 0;
}



