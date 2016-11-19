#include "Player.h"

Player::Player() : name(""),position(1),posIterator(0),startegy(0) {};

Player:: Player(string name, int position, int strtg) : name(name),position(position),posIterator(0), startegy (strtg){};

virtual Player:: ~Player() {delete(position,name);};

string Player:: getName(){
	return name;
}

int Player:: getPosition(){
	return position;
}

int Player::PlayerWithMostCards(vector<Player *> players){
	int max=0;
	int pos=0;
	for(int i=0;i<players.size();i++){
		if(players[i]->getNumberOfCards()>=max){
			max=players[i]->getNumberOfCards();
			pos=players[i]->getPosition();
		}
	}
	return pos;
}

	int Player:: cyclicOrder(vector<Player*> players){//switch Player parameter with "this"?
	 int myPos=this->getPosition();
	this->posIterator=(this->posIterator+1)%players.size();

		 if(this->posIterator%players.size()==myPos)
			 this->posIterator=(this->posIterator+1)%players.size();

		 if(this->posIterator==0)
			 return 1;
		 else
			 return this->posIterator;
}

int PlayerType1:: getCommonCard(vector<vector<Card*>> myCards) {
	int commonCardValue=0,commonCardAmount=0,index=0;

	for(int i=0;i<myCards.size();i++){
		if(myCards[i].size()>commonCardAmount){
			commonCardValue=myCards[i][0]->getValue();
			index=i;
		}
		else if(myCards[i].size()==commonCardAmount){
			int a=myCards[i][0]->getValue();
			int b=myCards[index][0]->getValue();
			commonCardValue=(a>b)?a:b;
		}
	}
return commonCardValue;
}

int PlayerType2:: getUncommonCard(vector<vector<Card*>> myCards) {
	int uncommonCardValue=0,uncommonCardAmount=4,index=0;

	for(int i=0;i<myCards.size();i++){
		if(myCards[i].size()<uncommonCardAmount){
			uncommonCardValue=myCards[i][0]->getValue();
			index=i;
		}
		else if(myCards[i].size()==uncommonCardAmount){
			int a=myCards[i][0]->getValue();
			int b=myCards[index][0]->getValue();
			uncommonCardValue=(a<b)?a:b;
		}
	}
return uncommonCardValue;
}
int PlayerType3:: getHighestVal(vector<vector<Card*>> myCards){
	int max=0;
	for(int i=0;i<myCards.size();i++){
		max= (myCards[i][0]->getValue()>max)?myCards[i][0]->getValue():max;
	}
	return max;
}

int PlayerType4:: getLowestVal(vector<vector<Card*>> myCards){
	int min=myCards[0][0]->getValue();
	for(int i=0;i<myCards.size();i++){
		min= (myCards[i][0]->getValue()<min)?myCards[i][0]->getValue():min;
	}
	return min;
}

