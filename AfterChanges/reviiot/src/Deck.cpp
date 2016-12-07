#include "../include/Card.h"
#include "../include/Deck.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>

Deck::Deck() :  DeckCards(),N(), deckAsString() {};

Deck::Deck(vector<Card *> GameCards) : DeckCards(),N(),deckAsString() {
	for (unsigned int i = 0; i < GameCards.size(); i++)
		DeckCards.push_back(GameCards[i]);

	deckAsString=this->toString();
}

void Deck::setN(int p){
	this->N=p;
}

void Deck::makeDeckVec(string word,int N){
	//vector<Card*> GameCards;

	DeckCards.clear();

	char shape;
	char fig;
	int value;
	unsigned int index=0;
	string s;
	while (index<word.length()){
		s="";
		while ((index<word.length())&&(word.at(index)!=(char)32)){
			s=s+word.at(index);
			index++;
		}
		if (s.at(0)<='9'){ //numericCard
			shape=s.at(s.length()-1);
			s.resize(s.length()-1);
			//value = atoi(s);
			value=atoi(s.c_str());
			NumericCard * c=new NumericCard(shape,value); // new! LEAK!!
			DeckCards.push_back(c);
		}
		else{ //figureCard
			fig=s.at(0);
			switch (fig){
			case 'J':
				value=N+1;
				break;
			case 'Q':
				value=N+2;
				break;
			case 'K':
				value=N+3;
				break;
			case 'A':
				value=N+4;
				break;
			}
			shape=s.at(1);
			FigureCard * f=new FigureCard(shape,fig,value); //LEAK!!
			DeckCards.push_back(f);
		}
		index++;
	}
}

Deck::~Deck() {
   // cout<<"deck destructor"<<endl;
	for (int i=DeckCards.size()-1;i>=0;i--) {
		if(DeckCards[i]!=NULL){
		delete (DeckCards[i]);
		DeckCards[i]=NULL;
		}
	}
	/*for(int i=0;i<DeckCards.size();i++)
		cout<<DeckCards[i]->toString()<<" "<< endl;*/
	DeckCards.clear();
}

Deck::Deck(const Deck &other): DeckCards(),N(other.N),deckAsString(other.toString()){
	//deckAsString=other.toString();
	makeDeckVec(deckAsString,N);
}


Deck &Deck::operator=(const Deck &other) {
	if (this == &other)
		return *this;

	DeckCards = other.DeckCards;
        N=other.N;
	return *this;
}


bool Deck::isEmpty() {
	if (getNumberOfCards() == 0)
		return true;
	return false;
}

vector<Card *> Deck::GetDeck() {
	return DeckCards;
}

void Deck::SetDeck(vector<Card *> newDeck) {
	this->DeckCards = newDeck;
}

Card *Deck::fetchCard() {
	Card* CardPtr=DeckCards[0]; // to check if the & create a pointer or go straight to card.
	//delete(DeckCards[0]);
	//DeckCards[0]=0;
	DeckCards.erase(DeckCards.begin());
	return CardPtr;
}

int Deck::getNumberOfCards() {
	return DeckCards.size();
}

const string Deck::toString() const {
	string ans = "";
	unsigned int i;
	for (i = 0; i < DeckCards.size(); i++) {
		ans += DeckCards[i]->toString() + " ";
	}
	//deckAsString.c_str(ans);
	return ans;
}

