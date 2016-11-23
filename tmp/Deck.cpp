#include "Card.h"
#include "Deck.h"
#include <vector>

	Deck::Deck(): DeckCards() {};

	Deck::Deck(vector<Card*> GameCards):DeckCards(){
        vector<Card *> DeckCards2;
        Card *temp;
		for (unsigned int i=0;i<GameCards.size();i++){
                temp = GameCards[i];
			DeckCards2.push_back(temp);
			this->DeckCards=DeckCards2;
		}
	}
	   Deck::~Deck(){}

	Deck& Deck::operator =(Deck &other){
		if(this==&other)
			return *this;

		//body of operator
	}


    	bool Deck::isEmpty(Deck d){
    		if(d.getNumberOfCards()==0)
    			return true;
    		return false;
    	}

        vector<Card *> Deck:: GetDeck(){
        	return DeckCards;
        }
        void Deck:: SetDeck(vector<Card *> newDeck){
        	this->DeckCards=newDeck;
        }

        Card* Deck::fetchCard(){
		Card *CardPtr = DeckCards.front(); // to check if the & create a pointer or go straight to card.
		DeckCards.erase(DeckCards.begin());
		return CardPtr;
	}

	int Deck::getNumberOfCards(){
		return DeckCards.size();
	}

	string Deck::toString(){
		string ans="";
                unsigned int i;
		for (i=0;i<DeckCards.size();i++){
			ans+=DeckCards.at(i)->toString();
		}
		return ans;
	}
//toString (using card to string), opertor =
