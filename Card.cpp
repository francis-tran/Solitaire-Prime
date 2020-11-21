#include <iostream>

#include <string>

using namespace std;

#include "Card.h"

void Card::setValue(){
    if(rank == 'A'){
        value = 1;
    }
    else if (rank == 'T' || rank == 'J' || rank == 'Q' || rank == 'K'){
        value = 10;
    }
    else{
        value = rank - 48;
    }
}

Card::Card(char r, char s){
    rank = r;
    suit = s;
    this->setValue();
}

void Card::setCard(char r, char s){
    rank = r;
    suit = s;
    this->setValue();
}
int Card::getValue(){
    return value;
}
string Card::getRank(){
    string tempRank(1, rank);
    if(tempRank == "T"){
        tempRank = "10";
    }
    return tempRank;
}
char Card::getSuit(){
    return suit;
}
void Card::showCard(){
    cout << this->getRank() << suit << ", ";
}

