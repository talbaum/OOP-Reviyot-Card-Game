#include "Player.h"
Player::Player() : name(""),position(1),posIterator(0),strategy(0) {};
Player:: Player(string name, int position, Deck d, int strtg) : Hand(d), name(name),position(position),posIterator(0),strategy(strtg){};

Player:: ~Player() {};

Player& Player::operator =(Player &other){
	if(this==&other)
		return *this;

	//body of operator
}

//vector<Card*> Player::selectCard(vector<vector<Card*> > myCards){};

string Player:: getName(){
	return name;}
int Player:: getPosition(){
	return position;}
int Player:: getStrategy(){
	return strategy;}


int Player::PlayerWithMostCards(vector<Player *> players){
	int max=0;
	int pos=0;
	for(unsigned int i=0;i<players.size();i++){
		if(players[i]->getNumberOfCards()>=max){
			if(players[i]->getPosition() != this->position){ //to make sure i wont ask for cards from me
				max=players[i]->getNumberOfCards();
				pos=players[i]->getPosition();
			}
		}
	}
	return pos;
}
int Player:: cyclicOrder(vector<Player*> players){
	unsigned int myPos=this->getPosition() -1;//getPosition-1 array start from 0 and position starts from 1

	if(posIterator % players.size()==myPos)
		posIterator++;

	posIterator++;
	return (posIterator-1)%players.size() +1;
}

PlayerType1::PlayerType1(string name, int position , Deck d, int strtg) :Player( name, position , d,strtg){};

vector<Card*> PlayerType1::selectCard(vector<vector<Card*> > myCards) {
	//getCommonCard
	int commonCardAmount=0,firstIndex=0;
	vector<Card*> commonCard;
	for(unsigned int i=0;i<myCards.size();i++){
		if(myCards[i].size()>commonCardAmount){
			commonCardAmount=myCards[i].size();
			commonCard=myCards[i];
			firstIndex=i;
		}
		else if(myCards[i].size()==commonCardAmount){
			int firstVal=myCards[firstIndex][0]->getValue();
			int secondVal=myCards[i][0]->getValue();

			commonCard=(firstVal>secondVal)?myCards[firstIndex]:myCards[i];
		}
	}
	return commonCard;
}
PlayerType2::PlayerType2(string name, int position , Deck d,int strtg) :Player( name, position , d,strtg){};

vector<Card*> PlayerType2:: selectCard(vector<vector<Card*> > myCards) {
	//getUnCommonCard
	unsigned int uncommonCardAmount=4,firstIndex=0;
	vector<Card*> unCommonCard;

	for(unsigned int i=0;i<myCards.size();i++){
		if(myCards[i].size()<uncommonCardAmount){
			uncommonCardAmount=myCards[i].size();
			unCommonCard=myCards[i];
			firstIndex=i;
		}
		else if(myCards[i].size()==uncommonCardAmount){
			int firstVal=myCards[firstIndex][0]->getValue();
			int secondVal=myCards[i][0]->getValue();

			unCommonCard=(secondVal<firstVal)? myCards[i]:myCards[firstIndex];
		}
	}
	return unCommonCard;
}
PlayerType3::PlayerType3(string name, int position , Deck d,int strtg) :Player( name, position , d,strtg){};

vector<Card*> PlayerType3:: selectCard(vector<vector<Card*> > myCards){
	//getHighestValue
	int max=0;
	vector<Card*> maxCard;
	for(unsigned int i=0;i<myCards.size();i++){
		if(myCards[i][0]->getValue()>max){
			max=myCards[i][0]->getValue();
			maxCard=myCards[i];
		}
	}
	return maxCard;
}
PlayerType4::PlayerType4(string name, int position , Deck d,int strtg) :Player( name, position , d,strtg){};

vector<Card*> PlayerType4:: selectCard(vector<vector<Card*> > myCards){
	//getLowestValue
	int min=myCards[0][0]->getValue();
	vector<Card*> minCard=myCards[0];
	for(unsigned int i=0;i<myCards.size();i++){
		if(myCards[i][0]->getValue()<min){
			min=myCards[i][0]->getValue();
			minCard=myCards[i];
		}
	}
	return minCard;
}

//opertor= , abstract function selectCard to make sure it works
