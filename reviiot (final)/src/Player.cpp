#include "../include/Player.h"

Player:: Player(string name, int position, Deck &d, int strtg) : Hand(d), name(name),position(position),strategy(strtg),posIterator(0){
};

Player:: ~Player() {
};

Player::Player(const Player &other):name(other.name),position(other.position),strategy(other.strategy),posIterator(other.posIterator){
	string word="";
	vector<Card*> insideVec;
	for(unsigned int i=0; i<HandCards.size();i++){
		insideVec=HandCards[i];
		for(unsigned int j=0; j<insideVec.size();j++)
			word+=insideVec[j]->toString() + " ";
	}
	makeHandVec(word,other.N);
        

}

string PlayerToString(const Player &other){
	string word="";
		vector<Card*> insideVec;
		for(unsigned int i=0; i<other.HandCards.size();i++){
			insideVec=other.HandCards[i];
			for(unsigned int j=0; j<insideVec.size();j++)
				word+=insideVec[j]->toString() + " ";
		}
		return word;
}

Player& Player::operator =(Player &other){
	if(this==&other)
		return *this;

	string word="";
		vector<Card*> insideVec;
		for(unsigned int i=0; i<HandCards.size();i++){
			insideVec=HandCards[i];
			for(unsigned int j=0; j<insideVec.size();j++)
				word+=insideVec[j]->toString() + " ";
		}
		makeHandVec(word,other.N);
		return *this;
}

string Player:: getName(){return name;}

int Player:: getPosition(){return position;}

int Player:: getStrategy(){return strategy;}

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

PlayerType1::PlayerType1(string name, int position , Deck &d, int strtg) :Player( name, position , d,strtg){};

PlayerType1::PlayerType1(const Player &player): Player(player){
	string word = PlayerToString(player);
	makeHandVec(word,player.N);
};

vector<Card*> PlayerType1::selectCard(vector<vector<Card*> > myCards) {
	//getCommonCard
	unsigned int commonCardAmount=0,firstIndex=0;
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

PlayerType2::PlayerType2(string name, int position , Deck &d,int strtg) :Player( name, position , d,strtg){};


PlayerType2::PlayerType2(const Player &player): Player(player){
	string word = PlayerToString(player);
	makeHandVec(word,player.N);
};

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

PlayerType3::PlayerType3(string name, int position , Deck &d,int strtg) :Player( name, position , d,strtg){};

PlayerType3::PlayerType3(const Player &player): Player(player){
	string word = PlayerToString(player);
	makeHandVec(word,player.N);
};

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

PlayerType4::PlayerType4(string name, int position , Deck &d,int strtg) :Player( name, position , d,strtg){};

PlayerType4::PlayerType4(const Player &player): Player(player){
	string word = PlayerToString(player);
	makeHandVec(word,player.N);
};

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
