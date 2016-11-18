#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

#include "Hand.h"

using namespace std;

class Player : public Hand {
private:
	const string name;
	const int position;

public:
	int posIterator;
	Player();
	Player(string name, int position);
	~Player();
	string getName();   //Returns the name of the player
	int getPosition();
	int PlayerWithMostCards(vector<Player*> player);
	int cyclicOrder(vector<Player*> players,Player player); //need to check if Player is required
};

class PlayerType1 : public Player {  //For strategy 1
public:
	int getCommonCard(vector<vector<Card*> > myCards);
};

class PlayerType2 : public Player {  //For strategy 2
public:
	int getUncommonCard(vector<vector<Card*> > myCards);
};

class PlayerType3 : public Player {  //For strategy 3
	int getHighestVal(vector<vector<Card*> > myCards);
};

class PlayerType4 : public Player {  //For strategy 4
	int getLowestVal(vector<vector<Card*> > myCards);
};

#endif
