#include <card.h>
#include <deck.h>
#include <vector>

Class Deck{
	
	Deck::Deck() Vector<Card*> DeckCards {}; 
	
	Deck::Deck(Vector<Cards> GameCards)Vector<Card*> DeckCards= new Vector<Card*> {

		for (int i=0;i<GameCards.size();i++){
			DeckCards.insert(GameCards[i]*);
		}	
	}
	
	Card* fetchCard(){
		Card* CardPtr = DeckCards[i]&; // to check if the & create a pointer or go stright to card.
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


	
	
	
}