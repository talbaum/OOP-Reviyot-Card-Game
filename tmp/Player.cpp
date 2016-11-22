#include "Player.h"
Player::Player() : name(""),position(1),posIterator(0),strategy(0) {};
Player:: Player(string name, int position, Deck d, int strtg) : Hand(d), name(name),position(position),posIterator(0),strategy(strtg){};
//Player Player::operator =(const Player &other): position(other.position),posIterator(other.posIterator){};
Player:: ~Player() {};

string Player:: getName(){
	return name;}
int Player:: getPosition(){
	return position;}
int Player:: getStrategy(){
	return strategy;}

 int Player:: selectCard(vector<vector<Card*> > myCards){};

int Player::PlayerWithMostCards(vector<Player *> players){
	int max=0;
	int pos=0;
	for(unsigned int i=0;i<players.size();i++){
		if(players[i]->getNumberOfCards()>=max){
			max=players[i]->getNumberOfCards();
			pos=players[i]->getPosition();
		}
	}
	return pos;
}
int Player:: cyclicOrder(vector<Player*> players){
	unsigned int myPos=this->getPosition();
	posIterator=(posIterator +1)%players.size();
	if(posIterator % players.size()==myPos)
		posIterator=(posIterator+1)%players.size();
	if(posIterator==0)
		return 1;
	else
		return posIterator;
}

PlayerType1::PlayerType1(string name, int position , Deck d, int strtg) :Player( name, position , d,strtg){};

int PlayerType1::selectCard(vector<vector<Card*> > myCards) {
	//getCommonCard
	int commonCardValue=0,commonCardAmount=0,index=0;
	for(unsigned int i=0;i<myCards.size();i++){
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
PlayerType2::PlayerType2(string name, int position , Deck d,int strtg) :Player( name, position , d,strtg){};

int PlayerType2:: selectCard(vector<vector<Card*> > myCards) {
	//getUnCommonCard
	unsigned int uncommonCardValue=0,uncommonCardAmount=4,index=0;
	for(unsigned int i=0;i<myCards.size();i++){
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
PlayerType3::PlayerType3(string name, int position , Deck d,int strtg) :Player( name, position , d,strtg){};

int PlayerType3:: selectCard(vector<vector<Card*> > myCards){
	//getHighestValue
	int max=0;
	for(unsigned int i=0;i<myCards.size();i++){
		max= (myCards[i][0]->getValue()>max)?myCards[i][0]->getValue():max;
	}
	return max;
}
PlayerType4::PlayerType4(string name, int position , Deck d,int strtg) :Player( name, position , d,strtg){};

int PlayerType4:: selectCard(vector<vector<Card*> > myCards){
	//getLowestValue
	int min=myCards[0][0]->getValue();
	for(unsigned int i=0;i<myCards.size();i++){
		min= (myCards[i][0]->getValue()<min)?myCards[i][0]->getValue():min;
	}
	return min;
}

//opertor= , abstract function selectCard to make sure it works
