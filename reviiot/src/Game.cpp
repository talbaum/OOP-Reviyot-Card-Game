#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector> // needed???
#include "../include/Game.h"
#include "../include/Player.h"
using namespace std;

//Game::Game():players(),deck(), highNumVal(0){} // needed?

Game::Game(char* config):players(),deck(), initialDeck(),twoWinners(false),winner1(0),winner2(0),count(0),verbal(0){

	vector<Card*> GameCards;
	ifstream filetext(config);
	if (!filetext.is_open()){
		cout << "error reading conf file"<<endl;
		return;
	}
	//cout << "passed first if- conf file"<<endl;
	int N;
	bool verbalpass=false;
	bool highest=false;
	bool deckCheck=false;
	bool playersPass= false;
	string word;

	while ((!filetext.eof())&&(getline(filetext,word))){

		if ((!word.empty())&&(word.at(0)!='#')){

			if (!verbalpass){
                                verbal=word.at(0) - '0';
				verbalpass=true;
				//cout << "verbal:" << verbal << '\n';
			}
			else if (!highest){
				//cout << "N:" << word <<'\n';
				string highestVal="";
				for(unsigned int i=0;i<word.length();i++){
					highestVal+=word.at(i);
                                }
				N=atoi(highestVal.c_str());
				highest=true;
			}
			else if (!deckCheck){
				char shape;
				char fig;
				int value;
				unsigned int index=0;
				string s;

				while (index<word.length()){
                                        s="";
                                        while ((index<word.length())&&(word.at(index)!=(char)32)){
                                            s=s+word.at(index);
                                            index++;
                                        }

                                        if (s.at(0)<='9'){ //numericCard
                                            shape=s.at(s.length()-1);
                                            s.resize(s.length()-1);
                                            value=std::atoi(s.c_str());
                                            NumericCard * c=new NumericCard(shape,value); // new!
                                            GameCards.push_back(c);
                                          //  cout << "card: " << value << " of " << shape <<'\n';
                                        }
                                        else{
                                            fig=s.at(0);
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
							shape=s.at(1);
							FigureCard * f=new FigureCard(shape,fig,value); // new!
							GameCards.push_back(f);
                                                     //   cout << "card: " << value << " of " << shape <<'\n';
                                        }
                                        index++;
                                }
				deckCheck=true;
				//deck.SetDeck(GameCards); //need to check if its really updated it
				deck=GameCards;
				//initialize the deck from the gameCards.

                        //    cout << "deck pass" << '\n';

                        }


			else if (!playersPass){
				int playerNum=1;
				while ((!playersPass)&&(!word.empty())&&(word.at(0)!='#')){
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
					//cout << "player name: " << name << " playing " << strtg <<'\n';

                                        if (!getline(filetext,word))
                                            playersPass=true;
					playerNum++;
				}

			}

		}
        }
}

Game ::~Game(){
	for(int i=players.size()-1;i>=0;i--)
	{
		if(players[i]!=0){
			players[i]=0;
			delete(players[i]);
		}
	}
	players.clear();
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

        bool actionHappend=false;
        string cVal;
        int vectorIndex;
        int numofcardsadded;
        Card* requestedCard;
        Card* cardToDelete;
        vector<Card*> foundCardVec;
        int i;
	while(winner1==0){
		count++;
                if (verbal==1){
		cout << "Turn " << count <<'\n';
		printState();
                }
		numOfPlayer=(count-1)%players.size();
		myPlayer=players[numOfPlayer];
		askedCardVec=myPlayer->selectCard(myPlayer->getHand());

		if(myPlayer->getStrategy()<=2)
			askedPlayer=myPlayer->PlayerWithMostCards(getPlayers())-1;
		else
			askedPlayer= myPlayer->cyclicOrder(getPlayers())-1;

		cVal=askedCardVec[0]->toString();
		cVal.resize(cVal.length()-1);
                if (verbal==1){
		cout << myPlayer->getName() << " Asked " << players[askedPlayer]->getName()<< " for the value "<< cVal<<'\n';
		cout<<""<<endl;
                }

                actionHappend=false;
		requestedCard = askedCardVec[0];

               // int requestedValue = askedCardVec[0]->getValue();

                vectorIndex = players[askedPlayer]->searchCard(*requestedCard);
                numofcardsadded=players[askedPlayer]->getHand()[vectorIndex].size();

                if (vectorIndex>-1){
                    actionHappend=true;

                    for (i=0;i<numofcardsadded;i++){
                        foundCardVec.push_back(players[askedPlayer]->getHand()[vectorIndex][i]);
                    }
                    for (i=0;i<numofcardsadded;i++){
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
			myPlayer->addCard(*deck.fetchCard());

		//the asked card is not at the asked player hand. so my player takes a card from deck.
		//player can fetch card only if his hand and the deck are not empty



	}//end of while.game over.

	//printWinner();
}

void Game::printWinner(){
	if(!twoWinners){
		cout<<"***** The Winner is: "<< players[winner1]->getName()<<" *****"<<endl;
		//printNumberOfTurns();
		//printInitialState();
		//cout<<"Final state: "<<endl;
		//printState();
	}
	else{
		if(winner1<winner2)
		cout<<"***** The Winners are: "<< players[winner1]->getName()<<" and "<<players[winner2]->getName()<<" *****"<<endl;
		else
		cout<<"***** The Winners are: "<< players[winner2]->getName()<<" and "<<players[winner1]->getName()<<" *****"<<endl;

		//printNumberOfTurns();
		//printInitialState();
		//cout<<"Final state: "<<endl;
		//printState();
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
