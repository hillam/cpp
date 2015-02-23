#ifndef CARD_UTILITIES_H
#define CARD_UTILITIES_H

#include <iostream>
using namespace std;

const int HAND_SIZE = 5;
enum Suit{hearts,clubs,diamonds,spades}; 
struct Card{
	int rank;
	Suit suit;
};

int randRank();
Suit randSuit();
bool isInHand(const Card& c, Card hand[]);
ostream& operator<<(ostream& os,const Card& c);

#endif