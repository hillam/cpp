#include "CardUtilities.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int randRank(){
	return (rand() % 13) + 1;
}

Suit randSuit(){
	Suit s;
	s = rand() % 4;
	return s;
}

bool isInHand(const Card& c, Card hand[]){
	bool yes = false;

	for(int i(0))
		if(c.rank == crd.rank && c.suit == crd.suit)
			yes = true;

	return yes;
}

ostream& operator<<(ostream& os,const Card& c){
	if(c.rank == 1)
		cout << "Ace";
	else if(c.rank == 11)
		cout << "Jack";
	else if(c.rank == 12)
		cout << "Queen";
	else if(c.rank == 13)
		cout << "King";
	else 
		cout << c.rank;
}