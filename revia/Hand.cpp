#include "Hand.h"
#include  <vector>
#include <iostream>
using namespace std;

Hand:: Hand(); vector<vector<Card*>> HandCards() {   //empty constructor
    int count=0;
};

Hand:: Hand(vector<Card*> temp); vector<vector<Card*>> HandCards() {
    int count=temp.size();  //constructor that receives a vector<Cards*> from the Deck and make it a vector of vectors.
    for (int i=0;i<temp.size();i++){
            int pos = searchCard(temp[i]);
                    HandCards[pos].push_back(temp[i]);
            // if we already have a card from this value it will add to the back , if not it will be the first element.
        }
    for (int i=0;i<HandCards.size();i++){
        if(HandCards[i].size()>0)
            HandCards[i].sort();
        // sort the inside vector by abc order (C-->D-->H-->S) which is the requested order for "strength" of shapes.
    }

};

~Hand(){
    delete (pos);//delete count?
};

int whereToInsert(Card &card){   // made for the addCard method.
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
~whereToInsert{
        delete (right,mid,left)
};

    bool addCard(Card &card){
        int pos=whereToInsert(card);
        HandCards[pos].push_back(card);
        HandCards[pos].sort();
        count++;
        return true;
    }

~addCard{
delete(pos)
};

    bool removeCard(Card &card) {
        int pos = searchCard(card);
        if (pos < 0)
            return false; //no such card at the hand.
        else {
            for (int i = 0; i < HandCards[pos].size(); ++i) {
                if ((HandCards[pos])[i].getShape().equals(card.getShape())) {
                    HandCards[pos].erase(i);
                    count--;
                    HandCards[pos].sort();
                    return true;
                }
            }
            return false;//the shape of this card is not in the inner vector.
        }
    }
~removeCard{
        delete(pos)
};

int searchCard(Card &card){  //made for remove card method. (had to make 2 diffrenet ones).
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

~searchCard{
        delete (right,mid,left)
};

	int getNumberOfCards(){
	    return count;
}
~getNumberOfCards{}; //delete count?

    string toString(){
	for(int i=0; i<HandCards.size();i++){
		cout << HandCards[i].toString()+ " " ;
	}
}
~toString{};


