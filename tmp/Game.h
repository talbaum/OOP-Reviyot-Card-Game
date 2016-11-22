
#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck; ///The deck of the game
public:
	Game(char* configurationFile);
	//Game& operator=(const Game &other);
	virtual ~Game();
	void init(); // initilizae players hands positions
	void play(); // loop with counter and printstate and playTurn for each strategy
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
        void printNumberOfTurns(); //Print the number of played turns at any given time.
};

#endif
