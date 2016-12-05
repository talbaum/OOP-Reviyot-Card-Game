#ifndef DECK_H_
#define DECK_H_
#include <vector>
#include "Card.h"

using namespace std;

class Deck {
private:
	vector<Card *> DeckCards;// Declare here the collection of "Card *" of the deck
	int N;
public:
	Deck ();
	Deck (vector<Card*>);
	Deck (Deck &other);
	void setN(int n);
	void makeDeckVec(string word,int N);
	virtual ~Deck();
	Deck& operator =(const Deck &other);
	bool isEmpty();
	vector<Card *> GetDeck();
	void SetDeck(vector<Card *> other);
	Card* fetchCard();   //Returns the top card of the deck and remove it rom the deck
	int getNumberOfCards(); // Get the number of cards in the deck
	string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"

};

#endif
