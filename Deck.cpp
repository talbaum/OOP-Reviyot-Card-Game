#include "Card.h"
#include "Deck.h"
#include <vector>

	Deck::Deck(): DeckCards() {
       
       }; 
    
	Deck::Deck(vector<Card> GameCards):DeckCards(){
           vector<Card *> DeckCards; 
        Card *temp; 
        unsigned int i;
		for (i=0;i<GameCards.size();i++){
                temp = &GameCards[i];
			DeckCards.push_back(temp);
		}
		

	}
	
        Deck::~Deck(){
	//delete i;
      //  delete temp; //fix here!!
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
                unsigned int i;
		for (i=0;i<DeckCards.size();i++){
			ans+=DeckCards.at(i)->toString();
		}
		return ans;
	}
