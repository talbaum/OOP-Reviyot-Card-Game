#ifndef HAND_H_
#define HAND_H_

#include <string>
#include "Deck.h"

using namespace std;

class Hand {
private:

	int whereToInsert(Card &card);
	vector<Card*> sortByShape (vector<Card*> sortMe);

public:
	vector<vector<Card*> > HandCards;// Declare here the collection of "Card *" of the hand
	int count;
	int N;

	Hand();
	Hand(Deck &deck);
	Hand(Hand &other);
	Hand& operator=(Hand &other);
	virtual ~Hand();

	void makeHandVec(string word,int N);
	vector<vector<Card*> > getHand();
	void sortMyHand();
	int searchCard(Card &card);
	bool addCard(Card &card);
	bool removeCard(Card &card);
	bool removeCardReviia(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line,
	//in a sorted order, ex: "2S 5D 10H"
};

#endif
