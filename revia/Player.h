#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

#include "Hand.h"

using namespace std;

class Player : public Hand {
private:
	const string name;
public:
	string getName();   //Returns the name of the player
};

class PlayerType1 : public Player {  //For strategy 1
//...
};

class PlayerType2 : public Player {  //For strategy 2
//...
};

class PlayerType3 : public Player {  //For strategy 3
//...
};

class PlayerType4 : public Player {  //For strategy 4
//...
};

#endif
