#include <iostream>

#include <string>

using namespace std;

#include "Card.h"

#ifndef DECK_H
#define DECK_H

class Deck{
    private:
    static const int NUMBER_OF_CARDS = 52;
    static const int NUMBER_OF_SUITS = 4;
    static const int NUMBER_OF_RANKS = 13;
    int cardsRemaining;
    
    Card deck[NUMBER_OF_CARDS];
    char suits[NUMBER_OF_SUITS] = {'S', 'H', 'D', 'C'};
    char ranks[NUMBER_OF_RANKS] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    
    public:
    Deck(){
        for(int i = 0; i < NUMBER_OF_CARDS; i++){
            deck[i] = Card(ranks[i % NUMBER_OF_RANKS], suits[i / NUMBER_OF_RANKS]);
        }
        cardsRemaining = NUMBER_OF_CARDS;
    };
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
};


#endif