#include "Card.h"
#include "Deck.h"
#include <vector>

	Deck::Deck(): DeckCards(){}; 
	
	Deck::Deck(vector<Card> GameCards): DeckCards() {
    Card* temp; 
		for (int i=0;i<GameCards.size();i++){
      temp = &GameCards[i];
			DeckCards.push_back(temp);
		}	
	}
	
	Card* fetchCard(){
		*Card CardPtr = &DeckCards[i]; // to check if the & create a pointer or go stright to card.
		DeckCards.erase(DeckCards.begin());
		return CardPtr;
	}
	
	~fetchCard{
		// delete Cardptr?
	}
	
	int GetNumberOfCards(){
		return DeckCards.size();
	}
	
	string toString(){
		string ans="";
		for (int i=0;i<DeckCards.size();i++){
			ans+=DeckCards.at(i)&.toString();
		}
		return ans;
	}
	
	~toString(){
		
	}

