
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
	Deck initialDeck;
	bool twoWinners;
	int winner1;
	int winner2;
	int count;
        int verbal;

public:
	Game(char* configurationFile);
	//Game& operator=(Game &other);
	virtual ~Game();
	vector<Player *> getPlayers();
	void init(); // initiliaze players hands positions and startegy
	void play(); // loop with counter and printState and playTurn for each strategy
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
	void printNumberOfTurns(); //Print the number of played turns at any given time.
	void printInitialState();
};

#endif

//order of intialize the fields. warning.
