#include "../include/Card.h"
#include "../include/Deck.h"
#include <vector>

	Deck::Deck(): DeckCards() {};

	Deck::Deck(vector<Card*> GameCards):DeckCards(){
		for (unsigned int i=0;i<GameCards.size();i++)
			DeckCards.push_back(GameCards[i]);
	}
	   Deck::~Deck(){/*
		   for(int i=DeckCards.size()-1;i>=0;--i){
			   delete(DeckCards[i]);
	   }
		   DeckCards.clear();*/
	   }

	 /*
	   Deck::Deck (const Deck &other){
               
               this->DeckCards=other.DeckCards;
           }
       */
           
           
	Deck& Deck::operator =(const Deck &other){
		if(this==&other)
			return *this;

	DeckCards=other.DeckCards;
	return *this;
	}


    	bool Deck::isEmpty(){
    		if(getNumberOfCards()==0)
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
			ans+=DeckCards.at(i)->toString()+  " ";
		}
		return ans;
	}
//toString (using card to string), opertor =
