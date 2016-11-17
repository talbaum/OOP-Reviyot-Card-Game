#include "Card.h"
#include "Deck.h"
#include <vector>

	Deck::Deck(){
            vector<Card *> DeckCards;
        }; 
	
	Deck::Deck(vector<Card> GameCards){
            vector<Card *> DeckCards; 
        Card *temp; 
		for (int i=0;i<GameCards.size();i++){
        temp = &GameCards[i];
			DeckCards.push_back(temp);
		}
		

	}
	
        Deck::~Deck(){
	//delete temp?
	}
	
	
        Card* Deck::fetchCard(){
		Card *CardPtr = DeckCards.front(); // to check if the & create a pointer or go stright to card.
		DeckCards.erase(DeckCards.begin());
		return CardPtr;
	}
	

	
	int Deck::getNumberOfCards(){
		return DeckCards.size();
	}
	
	string Deck::toString(){
		string ans="";
		for (int i=0;i<DeckCards.size();i++){
			ans+=DeckCards.at(i)->toString();
		}
		return ans;
	}
	


