#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector> // needed???
#include "Game.h"
#include "Player.h"
using namespace std;

//Game::Game():players(),deck(), highNumVal(0){} // needed?

Game::Game(char* config): initialDeck(),twoWinners(false),winner1(0),winner2(0),count(0){

	vector<Card*> GameCards;
	ifstream filetext(config);
	if (!filetext.is_open()){
		cout << "error reading conf file"<<endl;
		return;
	}
	cout << "passed first if- conf file"<<endl;
	bool verbal;
	int N;
	bool verbalpass=false;
	bool highest=false;
	bool deckCheck=false;
	bool playersPass= false;

	string word;
	while (getline(filetext,word)){

		if ((!word.empty())&&(word.at(0)!='#')){

			if (!verbalpass){
				if (word.at(0)=='1')
					verbal=true;
				else
					verbal=false;
				verbalpass=true;
				cout << "verbal:" << verbal << '\n';
			}
			else if (!highest){
				cout << "N:" << word <<'\n';
				string highestVal="";
				for(unsigned int i=0;i<word.length();i++)
					highestVal+=word.at(i);

				N=atoi(highestVal.c_str());
				//N=(int)word.at(0)-'0'; // if N is more then 1 digit then problem
				highest=true;
			}
			else if (deckCheck==false){
				char shape;
				char fig;
				int value;
				unsigned int index=0;
				string s;

				while (index<word.length()){

					if (word.at(index)!=(char)32){ //not a space
						if (word.at(index)<='9'){ // numeric card
							s="";
							while (word.at(index)!=(char)32){ //this char isnt space

								if (word.at(index+1)==(char)32){ //next char is space-need to add if next char is end line!!
									shape=word.at(index);
									value=std::atoi(s.c_str());
									NumericCard * c=new NumericCard(shape,value); // new!
									GameCards.push_back(c);
									index++;
								}
								else{ //next one isnt space, keep going on nums
									s=s+word.at(index);
									index++;
								}
							}
							cout << "next card value:" << value << " of " << shape <<'\n';
						}
						else{ //figure card
							fig=word.at(index);
							switch (fig){
							case 'J':
								value=N+1;
								break;
							case 'Q':
								value=N+2;
								break;
							case 'K':
								value=N+3;
								break;
							case 'A':
								value=N+4;
								break;
							}
							index++;
							shape=word.at(index);
							FigureCard * f=new FigureCard(shape,fig,value); // new!
							GameCards.push_back(f);
							cout << "next card value:" << value << ", figure: " << fig << " of " << shape <<'\n';
						}
					}
					index++;
				}
				deckCheck=true;
				//deck.SetDeck(GameCards); //need to check if its really updated it
				deck=GameCards;
				//initialize the deck from the gameCards.
			}

			else if (!playersPass){
				int playerNum=1;
				while (!word.empty()&&(word.at(0)!='#')){
					string name="";
					int index=0;
					int strtg;
					while (word.at(index)!=(char)32){
						name+=word.at(index);
						index++;
					}
					strtg=word.at(index+1)-'0';
					Player * temp;
					switch (strtg){
					case 1:
						temp = new PlayerType1(name,playerNum,deck,strtg); // new!
						break;
					case 2:
						temp = new PlayerType2(name,playerNum,deck,strtg);// new!
						break;
					case 3:
						temp = new PlayerType3(name,playerNum,deck,strtg);// new!
						break;
					case 4:
						temp = new PlayerType4(name,playerNum,deck,strtg);// new!
						break;
					}
					//initialize player & his hand and strategy.
					this->deck=temp->deck;
					players.push_back(temp);
					cout << "player name: " << name << " playing " << strtg <<'\n';
					getline(filetext,word);
					playerNum++;
				}
			}
		}
	}
}

Game ::~Game(){
	//delete temp?
}

vector<Player *> Game::getPlayers(){ return players;};
void Game::init(){
	initialDeck.SetDeck(deck.GetDeck());
}

void Game::play(){
	unsigned int numOfPlayer,askedPlayer;
	bool isAskedWon=false;
	Player* myPlayer;
	vector<Card*> askedCardVec;

	while(winner1==0){
		count++;
		cout << "Turn " << count <<'\n';
		printState();
		numOfPlayer=(count-1)%players.size();
		myPlayer=players[numOfPlayer];
		askedCardVec=myPlayer->selectCard(myPlayer->getHand());

		if(myPlayer->getStrategy()<=2)
			askedPlayer=myPlayer->PlayerWithMostCards(getPlayers())-1;
		else
			askedPlayer= myPlayer->cyclicOrder(getPlayers())-1;

		string cVal=askedCardVec[0]->toString();
		cVal.resize(cVal.length()-1);
		cout << myPlayer->getName() << " Asked " << players[askedPlayer]->getName()<< " for the value "<< cVal<<'\n';
		cout<<""<<endl;

                bool actionHappend=false;


		Card* requestedCard = askedCardVec[0];
                Card* cardToDelete;
               // int requestedValue = askedCardVec[0]->getValue();

                int vectorIndex = players[askedPlayer]->searchCard(*requestedCard);
                int numofcardsadded=players[askedPlayer]->getHand()[vectorIndex].size();

                if (vectorIndex>-1){
                    actionHappend=true;
                    vector<Card*> foundCardVec;
                    for (int i=0;i<numofcardsadded;i++){
                        foundCardVec.push_back(players[askedPlayer]->getHand()[vectorIndex][i]);
                    }
                    for (int i=0;i<numofcardsadded;i++){
                        cardToDelete = players[askedPlayer]->getHand()[vectorIndex][0];
                        players[askedPlayer]->removeCard(*cardToDelete);
                        myPlayer->addCard(*foundCardVec.back());
                        foundCardVec.pop_back();
                        if (!deck.isEmpty())
                        players[askedPlayer]->addCard(*deck.fetchCard());
                    }
                    myPlayer->sortMyHand();

                }

		if(actionHappend){
			//checking if the game has ended.
			if(players[askedPlayer]->getNumberOfCards()==0){
				winner1=askedPlayer;
				isAskedWon=true;
			}
			if (myPlayer->getNumberOfCards()==0){
				winner1=numOfPlayer;
				if(isAskedWon){
					twoWinners=true;
					winner2=askedPlayer;
				}
			}
		}
		else if(myPlayer->getNumberOfCards()!=0 && deck.getNumberOfCards()!=0)
			myPlayer->deck.fetchCard();

		//the asked card is not at the asked player hand. so my player takes a card from deck.
		//player can fetch card only if his hand and the deck are not empty



	}//end of while.game over.

	printWinner();
}

void Game::printWinner(){
	if(!twoWinners){
		cout<<"***** The Winner is: "<< players[winner1]->getName()<<" *****"<<endl;
		printNumberOfTurns();
		printInitialState();
		cout<<"Final state: "<<endl;
		printState();
	}
	else{
		if(winner1<winner2)
		cout<<"***** The Winners are: "<< players[winner1]->getName()<<"and: "<<players[winner2]->getName()<<" *****"<<endl;
		else
		cout<<"***** The Winners are: "<< players[winner2]->getName()<<"and: "<<players[winner1]->getName()<<" *****"<<endl;

		printNumberOfTurns();
		printInitialState();
		cout<<"Final state: "<<endl;
		printState();
	}
}

void Game::printInitialState(){
	string ans="";
	vector<vector<Card*> > printMe;
	cout<<"----------"<<endl;
	cout<<"Initial state: "<<endl;
	cout<<"Deck: "<<initialDeck.toString()<<endl;

	for(unsigned int i=0;i<players.size();++i){
		printMe=players[i]->initialHand;
		for(unsigned j=0;j<printMe.size();j++){
			for(unsigned k=0;k<printMe[j].size();k++)
				ans+=printMe[j][k]->toString() + " ";
		}
		cout << players[i]->getName() << ": " << ans <<endl;;
		ans="";
	}
	cout<<"----------"<<endl;
}
void Game::printState(){ //Print the state of the game as described in the assignment.

	cout <<"Deck: "<< deck.toString()<<endl;
	for(unsigned int i=0;i<players.size();++i)
		cout << players[i]->getName() << ": " << players[i]->toString()<<endl;


}
void Game::printNumberOfTurns(){//Print the number of played turns at any given time.
	cout << "Number of turns: " << count<< endl;
}


//empty constructor is needed?, check gameplay
