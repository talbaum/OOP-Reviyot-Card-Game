#include "Hand.h"
#include  <vector>
#include <iostream>
#include "Deck.h"

using namespace std;
Hand::Hand():HandCards(),count(0),deck() {}


Hand:: Hand(Deck deck2) :HandCards(), count(0),deck(deck2){//empty constructor
	for(unsigned int i=0;i<7;i++)
		addCard(*deck.fetchCard());

	sortMyHand();
	initialHand=HandCards;
	//deck=deck2;

}

Hand::Hand(const Hand &other): HandCards(other.HandCards) , count (other.count), deck(other.deck),initialHand(other.initialHand) {};
//copy constructor


Hand& Hand::operator =(Hand &other){
	if(this==&other)
		return *this;
	//body of operator
        
        HandCards = other.HandCards;
        count= other.count;
        deck= other.deck;
        initialHand = other.initialHand;
        return *this;
}


void Hand::sortMyHand(){
	vector <Card*> tmp;
	for(unsigned int i=0;i<HandCards.size();i++){
		for(unsigned int j=i;j<HandCards.size();j++){
			if(HandCards[i][0]->getValue()>HandCards[j][0]->getValue()){
				tmp=HandCards[i];
				HandCards[i]=HandCards[j];
				HandCards[j]=tmp;
			}
		}
	}
}
Hand::~Hand(){}

vector<vector<Card*> > Hand:: getHand(){
	return this->HandCards;
}

int Hand:: whereToInsert(Card &card){   // made for the addCard method.
	unsigned int mid=0, left = 0 ;
	unsigned int right = (HandCards.size()==0)?0:HandCards.size()-1;
	while (left < right) {
		mid = (left + right)/2;
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
		return mid; //for making sure its inserted before the closer bigger value. need to check it.
}

bool Hand:: addCard(Card &card){
	int myCardPos=searchCard(card);

	if(myCardPos==-1){
		std::vector<vector<Card*> >::iterator it;
		vector<Card*> insideVec;
		insideVec.push_back(&card);
		int pos=whereToInsert(card);
		it=HandCards.begin();
		HandCards.insert(it+pos,insideVec);
		sortMyHand();
	}
	else{
		HandCards.at(myCardPos).push_back(&card);


		if(HandCards.at(myCardPos).size()==4)   //if player got revia.
			for(int i=3;i>=0;i--)
				removeCard(*HandCards[myCardPos][i]);

		else if(HandCards.at(myCardPos).size()>=2)
			HandCards[myCardPos]=sortByShape(HandCards[myCardPos]);
	}
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
		//insideVec=HandCards[pos];
		//insideVec.erase(insideVec.begin());
		HandCards[pos].erase(HandCards[pos].begin());
		count--;
		addCard(*deck.fetchCard());
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

	  int left = 0;
	        int right = HandCards.size() - 1;
	        int middle;
	        while (left <= right) {
	            middle = left + (right - left)/2;
	            if (HandCards[middle][0]->getValue() > card.getValue())
	                right = middle - 1;
	            else
	                if (HandCards[middle][0]->getValue() < card.getValue())
	                    left = middle + 1;
	                else
	                    return middle;
	        }
	        return -1;
}
	/*unsigned int mid, left = 0 ;
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
}*/


int Hand:: getNumberOfCards(){
	return this->count;
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
