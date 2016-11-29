#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include "Card.h"
#include <vector>
#include <string>
#include "Deck.h"

using namespace std;

class Hand {
private:
	vector<vector<Card*> > HandCards;// Declare here the collection of "Card *" of the hand
	int whereToInsert(Card &card);
	vector<Card*> sortByShape (vector<Card*> sortMe);

public:
	int count;
	Deck deck;
	vector<vector<Card*> > initialHand;

	Hand();
	Hand(Deck deck);
	Hand(const Hand &other);
	Hand& operator=(Hand &other);
	virtual ~Hand();

	vector<vector<Card*> > getHand();
	void sortMyHand();
	int searchCard(Card &card);
	bool addCard(Card &card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line,
	//in a sorted order, ex: "2S 5D 10H"
};

#endif
