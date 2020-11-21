
#include <iostream>

#include <string>

using namespace std;

#ifndef CARD_H
#define CARD_H

class Card{
    private:
    char rank;
    char suit;
    int value;
    
    public:
    Card(){
        rank = '0';
        suit = '0';
        value = 0;
    };
    void setValue();
    Card(char r, char s);
    void setCard(char r, char s);
    int getValue();
    string getRank();
    char getSuit();
    void showCard();
};


#endif