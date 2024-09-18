#include <iostream>
#include "board.h"
#include "input_to_board.h"
#include "winner_logic.h"

char k[10]; //holds the required character from keys 1-9
//char k[10];
char player_side; //to store player1 choice x or o
char player_1;
char player_2;
int input_1;         //user input value given to the board throug keys 1-9
char current_player_token; //stores current player's token x or o
char option;         //stores y or n for game continuation option

int main()
{
    std::cout<<"Welcome to Tic-Tac-Toe"<<std::endl;
    
    while(1){
        //this loop is for clearing the board also initialising with value ' '
        for(int i = 0;i<=10;i++){
            k[i] = ' ';
        }
        std::cout<<"Player 1 please select your side, x or o"<<std::endl;
        std::cin>>player_side; //receiving the side
        player_1 = player_side;  //assigning sides
        if(player_side == 'x'|| player_side == 'o'){        //if(player_side == ('x'||'o')) not working why
            if(player_1 == 'x'){
                player_2 = 'o';
            }
            else{
                player_2 = 'x';
            }
        std::cout<<"Player 1 is "<<player_1<<" and Player 2 is "<<player_2<<std::endl;
                
        }
        else{
        std::cout<<"Choose correct character"<<std::endl;
        continue; //go back and enter correct character
        }

        int player_flag = 0; /*To switch between player1 and player2, value 0 for player1 and value 1 for
        player2. After each time a player is played flag value will be switched*/
        while(1){
            int winner_flag = 0;   /*Stores the value returned by winner_check function, value 0 for no 
            results and value 1 for win*/
            if(!player_flag){
                current_player_token = player_1;
                std::cout<<"Player 1 enter input "<<current_player_token<<std::endl;
                input_to_board(input_1, current_player_token, k);
                board(k);
                winner_flag = winner_check(k, current_player_token, "Player1");
                
                if(winner_flag){
                    /*This piece of code decides to continue game or not after winning*/
                    std::cout<<"Would you like to continue, press y to continue and n to end"<<std::endl;                
                    std::cin>>option;
                    if(option == 'y'){
                        break;
                    }
                    else{
                        return 0;
                    }
                }
                player_flag = 1;
            }
            else{
                current_player_token = player_2;
                std::cout<<"Player 2 enter input "<<current_player_token<<std::endl;
                input_to_board(input_1, current_player_token, k);
                board(k);
                winner_flag = winner_check(k, current_player_token, "Player2");
                if(winner_flag){
                    /*This piece of code decides to continue game or not*/
                    std::cout<<"Would you like to continue, press y to continue and n to end"<<std::endl;                
                    std::cin>>option;
                    if(option == 'y'){
                        break;
                    }
                    else{
                        return 0;
                    }
                }
                player_flag = 0;

            }

            /*Below statements check if the board is full, if all the positions are not ' '
            then it will be draw condition*/
            if(k[1]!= ' '&& k[1]!= ' '&& k[2]!= ' '&& k[3]!= ' '&& k[4]!= ' '&& k[5]!= ' '&&
               k[6]!= ' '&& k[7]!= ' '&& k[8]!= ' '&& k[9]!= ' '){ 
                std::cout<<"Well, its a draw"<<std::endl;

                /*This piece of code decides to continue game or not*/
                std::cout<<"Would you like to continue, press y to continue and n to end"<<std::endl;                
                std::cin>>option;
                if(option == 'y'){
                    break;
                }
                else{
                    return 0;
                }
                
            }
          
        }      

        
    }  
    
    return 0;
}

//Below statements check if the board is full
            //if(k[1]!= '\0'&& k[1]!= '\0'&& k[2]!= '\0'&& k[3]!= '\0'&& k[4]!= '\0'&& k[5]!= '\0'&&
               //k[6]!= '\0'&& k[7]!= '\0'&& k[8]!= '\0'&& k[9]!= '\0')