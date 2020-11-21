#include <stdio.h>

#include <iostream>

#include <string>

#include <cctype>

using namespace std;

#include "Deck.h"

bool isPrime(int x){
    // Case 0:
    if(x == 1){
        return false;
    }
    
    // Case 1:
    if(x == 2){
        return true;
    }
    
    // Case 2: All prime numbers are odd except 2
    if(x % 2 == 0){
        return false;
    }
    
    // Case 3: odd Non-Prime numbers are divisible by odd prime numbers 
    // Max sum of all card values/worst case is 340
    // 17 * 17 is 289 and 19 * 19 is 361. So I do not need to check for squared prime numbers past 17
    int primeNumbers[6] = {3, 5, 7, 11, 13, 17};
    bool prime = true;
    for(int i = 0; i < 6; i++){
        if(x != primeNumbers[i] && x % primeNumbers[i] == 0){
            prime = false;
        }
    }
    return prime;
}

int main()
{
    cout << "Welcome to Solitaire Prime!\n1) New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Solitaire Prime\n5) Exit" << endl;
    int menuOption = 0;
    Deck newDeck;
    while(menuOption != 5){
        cin >> menuOption;
        if(menuOption == 1){
            newDeck.refreshDeck();
            cout << "A new deck has been created." << endl;
        }
        else if (menuOption == 2){
            cout<< "Deck is being displayed." << endl;
            newDeck.showDeck();
        }
        else if (menuOption == 3){
            newDeck.shuffle();
            cout << "Deck has been shuffled." << endl;
        }
        else if (menuOption == 4){
            cout << "Playing Solitaire Prime!!!" << endl;
            break;
        }
    }
    if (menuOption == 4){
        int sum = 0;
        int piles = 0;
        bool prime;
        while(newDeck.cardsLeft() != 0){
            prime = false;
            Card topCard = newDeck.deal();
            sum += topCard.getValue();
            topCard.showCard();
            if(isPrime(sum)){
                prime = true;
                piles++;
                cout << "Prime:" << sum << endl;
                sum = 0;
            }
        }
        if(prime && newDeck.cardsLeft() == 0){
            cout << "Winner in " << piles << " piles!" << endl;
        }
        else{
            cout << "Loser" << endl;
        }
    }
    
    return 0;
}
