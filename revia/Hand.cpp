#include "Hand.h"
#include  <vector>
#include <iostream>

using namespace std;

Hand:: Hand(): vector<vector<Card*>> HandCards() , count(0); {}  //empty constructor

Hand::Hand(vector<Card*> other): HandCards() : count (other.size()) {
  //constructor that receives a vector<Cards*> from the Deck and make it a vector of vectors.
    for (int i=0;i<other.size();i++){
            int pos = searchCard(other[i]&);
            (HandCards[pos].push_back(other[i]);
             if(HandCards[pos].size()>1)
                 HandCards[i].sort();
        }    // sort the inside vector by abc order (C-->D-->H-->S) which is the requested order.
    return HandCards;
}

Hand::Hand(vector<vector<Card*>> other): HandCards(other) : count (other.size()) {};
//copy constructor


Hand::~Hand(){
//delete count && pos?
}

int Hand:: whereToInsert(Card &card){   // made for the addCard method.
    int mid, left = 0 ;
    int right = HandCards.size();
    while (left < right) {
        mid = left + (right - left)/2;
        if (card.getValue() > HandCards[mid]){
            left = mid+1;
        }
        else if (card.getValue() < HandCards[mid]){
            right = mid;
        }
        else {
            return mid;
        }
    }

       return mid-1; //for making sure its inserted before the closer bigger value. need to check it.

}

    bool Hand:: addCard(Card &card){
        int pos=whereToInsert(card);
        HandCards[pos].push_back(&card);
        HandCards[pos]=sort(HandCards[pos]);
        count++;
        return true;
    }

    vector<Card*> Hand:: sort(vector<Card*> sortMe) {
    	//insertion sort.
    	Card* tmp;
        for (int i = 1; i < sortMe.size(); i++)  {
            for (int j = i; j >= 1; j--) {
                if (sortMe[j]->getValue() < sortMe[j-1]->getValue()) {
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
            for (int i = 0; i < insideVec.size(); ++i) {
                if((*insideVec[i]).getShape()==card.getShape()) {
                	insideVec.erase(insideVec.begin()+i);
                    count--;
                    insideVec=sort(insideVec);
                    return true;
                }
            }
            return false;//the shape of this card is not in the inner vector.
        }
    }

int Hand:: searchCard(Card &card){  //made for remove card method. (had to make 2 diffrenet ones).
    int mid, left = 0 ;
    int right = HandCards.size();
    while (left < right) {
        mid = left + (right - left)/2;
        if (card.getValue() > HandCards[mid]){
            left = mid+1;
        }
        else if (card.getValue() < HandCards[mid]){
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
	for(int i=0; i<HandCards.size();i++){
		insideVec=HandCards[i];
		for(int j=0; j<insideVec.size();j++)
			ans+=insideVec[j]->toString() + " ";
	}
	return ans;
}

