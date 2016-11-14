#ifndef HAND_H_
#define HAND_H_

#include <iostream>

#include "Card.h"

using namespace std;

class Hand {
private:
	// Declare here the collection of "Card *" of the hand
public:
	bool addCard(Card &card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line,
 in a sorted order, ex: "2S 5D 10H"
};

#endif
