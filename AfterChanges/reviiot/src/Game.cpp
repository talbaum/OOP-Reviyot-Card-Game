#include <fstream>
#include <cstdlib>
#include "../include/Game.h"
using namespace std;

Game::Game(const Game &other):players(),deck(other.deck),twoWinners(other.twoWinners),winner1(other.winner1),winner2(other.winner2),count(other.count),verbal(other.verbal){

	for( unsigned int i=0;i<other.players.size(); i++) {
		switch (other.players[i]->getStrategy()) {
		case 1:{
			PlayerType1 *c = new PlayerType1(*other.players[i]);
			//PlayerType1 c = other.players[i];
			//c(*other.players[i]);
			players.push_back(c);
			break;
		}
		case 2:{
			PlayerType2 *c = new PlayerType2(*other.players[i]);;
			players.push_back(c);
			//players.push_back(new PlayerType2(*other.players[i]));
			break;
		}
		case 3:{
			PlayerType3 *c = new PlayerType3(*other.players[i]);
			//c = other.players[i];
			players.push_back(c);
			//players.push_back(new PlayerType2(*other.players[i]));
			break;
		}
		case 4:{
			PlayerType4 *c = new PlayerType4(*other.players[i]);
			//c = other.players[i];
			players.push_back(c);
			//players.push_back(new PlayerType2(*other.players[i]));
			break;
		}
		}
	}
}


/*Game:: Game(const Game &&other) :players(),deck(&other.deck),initialDeck(&other.initialDeck),twoWinners(&other.twoWinners),winner1(&other.winner1),winner2(&other.winner2),count(&other.count),verbal(other.verbal){
    for(int i=other.players.size()-1;i>=0; i--) {
        switch (other.players[i]->getStrategy()) {
            case 1:
                players.push_back(new PlayerType1(*other.players[i]));
                break;
            case 2:
                players.push_back(new PlayerType2(*other.players[i]));
                break;
            case 3:
                players.push_back(new PlayerType3(*other.players[i]));
                break;
            case 4:
                players.push_back(new PlayerType4(*other.players[i]));
                break;
        }
    }
}*/

Game::Game(char* config):players(),deck(),twoWinners(false),winner1(0),winner2(0),count(0),verbal(0){
	vector<Card*> GameCards;
	ifstream filetext(config);
	if (!filetext.is_open()){
		cout << "error reading conf file"<<endl;
		return;
	}
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
			}
			else if (!highest){
				string highestVal="";
				for(unsigned int i=0;i<word.length();i++){
					highestVal+=word.at(i);
				}
				N=atoi(highestVal.c_str());
				highest=true;
				deck.setN(N);
			}
			else if (!deckCheck){
				deckCheck=true;
				deck.makeDeckVec(word,N);
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

}

void Game::play(){
	unsigned int numOfPlayer,askedPlayer;
	bool isAskedWon=false, actionHappend=false;
	Player* myPlayer;
	vector<Card*> askedCardVec;
	string cVal;
	int vectorIndex,numofcardsadded,i;
	Card* requestedCard;
	Card* cardToDelete;
	vector<Card*> foundCardVec;
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
}

void Game::printWinner(){
	if(!twoWinners){
		cout<<"***** The Winner is: "<< players[winner1]->getName()<<" *****"<<endl;
	}
	else{
		if(winner1<winner2)
			cout<<"***** The Winners are: "<< players[winner1]->getName()<<" and "<<players[winner2]->getName()<<" *****"<<endl;
		else
			cout<<"***** The Winners are: "<< players[winner2]->getName()<<" and "<<players[winner1]->getName()<<" *****"<<endl;
	}
}

void Game::printState(){ //Print the state of the game as described in the assignment.

	cout <<"Deck: "<< deck.toString()<<endl;
	for(unsigned int i=0;i<players.size();++i)
		cout << players[i]->getName() << ": " << players[i]->toString()<<endl;

}

void Game::printNumberOfTurns(){//Print the number of played turns at any given time.
	cout << "Number of turns: " << count<< endl;
}
