#include "Hand.h"
#include  <vector>
#include <iostream>
#include "Deck.h"

using namespace std;
Hand::Hand():HandCards(),count(0),deck() {}


Hand:: Hand(Deck deck2) :HandCards(), count(7),deck(deck2){//empty constructor
	HandCards.resize(1);

	for(unsigned int i=0;i<7;i++)
		Hand::addCard(*deck2.fetchCard());

	initialHand=HandCards;
	deck=deck2;

}

Hand::Hand(const Hand &other): HandCards(other.HandCards) , count (other.count), deck(other.deck),initialHand(other.initialHand) {};
//copy constructor


Hand& Hand::operator =(Hand &other){
	if(this==&other)
		return *this;
	//body of operator

}

Hand::~Hand(){}//delete *deck;?

vector<vector<Card*> > Hand:: getHand(){
	return this->HandCards;
}

int Hand:: whereToInsert(Card &card){   // made for the addCard method.
	unsigned int mid=0, left = 0 ;
	unsigned int right = HandCards.size();
	while (left < right) {
		mid = left + (right - left)/2;
		if (card.getValue() > HandCards[mid][0]->getValue()){
			left = mid+1;
		}
		else if (card.getValue() < HandCards[mid][0]->getValue()){
			right = mid;
		}
		else {
			return mid;
		}
	}
	if(mid!=0)
		return mid-1; //for making sure its inserted before the closer bigger value. need to check it.
	else
		return 0; //if the vec is empty , it will insert at first position.
}

bool Hand:: addCard(Card &card){
	int pos=whereToInsert(card);
	vector<Card*> insideVec= HandCards.at(pos);
	insideVec.push_back(&card);
	HandCards.at(pos)=insideVec;

	if(HandCards[pos].size()==4)   //if player got revia.
			Hand::removeCard(*HandCards[pos][0]);

	else if(HandCards[pos].size()>1)
		HandCards[pos]=sortByShape(HandCards[pos]);

	count++;
	return true;
}

vector<Card*> Hand:: sortByShape(vector<Card*> sortMe) {
	//insertion sort.
	Card* tmp;
	for (unsigned int i = 1; i < sortMe.size(); i++)  {
		for (unsigned int j = i; j >= 1; j--) {
			if (sortMe[j]->getShape() < sortMe[j-1]->getShape()) {
				tmp = sortMe[j];
				sortMe[j] = sortMe[j-1];
				sortMe[j-1] = tmp;
			}
		}
	}
	return sortMe;
}

bool  Hand:: removeCard(Card &card) {
	vector<Card*> insideVec;
	int pos = searchCard(card);
	if (pos < 0)
		return false; //no such card at the hand.
	else {
		insideVec=HandCards[pos];
		insideVec.erase(insideVec.end());
		count--;
		this->addCard(*deck.fetchCard());
		return true;

/*
 * Old version: delete all the vec at once.
		insideVec=HandCards[pos];
		int K=insideVec.size();
		insideVec.erase(insideVec.begin(),insideVec.end());
		count-=K;
		int j=0;
		Deck deck2=deck;	//find more efficent code for this
		while(j<K){
			Hand::addCard(*deck2.fetchCard());
			count++;
			j++;
		}
		deck=deck2;
		return true;
		*/
	}
}


int Hand:: searchCard(Card &card){  //made for remove card method. (had to make 2 diffrenet ones).
	unsigned int mid, left = 0 ;
	unsigned int right = HandCards.size();
	while (left < right) {
		mid = left + (right - left)/2;
		if (card.getValue() > HandCards[mid][0]->getValue()){
			left = mid+1;
		}
		else if (card.getValue() < HandCards[mid][0]->getValue()){
			right = mid;
		}
		else {
			return mid;
		}
	}
	return -1; // if the exact value is not found at the vec.
}

int Hand:: getNumberOfCards(){
	return count;
}

string Hand:: toString(){
	string ans="";
	vector<Card*> insideVec;
	for(unsigned int i=0; i<HandCards.size();i++){
		insideVec=HandCards[i];
		for(unsigned int j=0; j<insideVec.size();j++)
			ans+=insideVec[j]->toString() + " ";
	}
	return ans;
}

//opertor =
