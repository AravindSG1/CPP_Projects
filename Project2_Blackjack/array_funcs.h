#ifndef ARRAY_FUNCS_H
#define ARRAY_FUNCS_H

class Cards deck_card_pop(class Cards *input_array, int *position, int *input_array_size);

class Cards* add_to_hand(class Cards *input_array, class Cards input_card, int *input_array_size);

void hit(class Cards *hand, class Cards poped_from_deck, int *hand_size);

int sum_of_cards(class Cards *hand, int hand_size);

void print_player_cards(class Cards *player_hand, int player_hand_size, int player_sum);
void print_dealer_cards(class Cards *dealer_hand, int dealer_hand_size, int dealer_sum);
#endif