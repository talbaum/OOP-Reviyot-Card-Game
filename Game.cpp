#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector> // needed???
#include "Game.h"
#include "Player.h"
using namespace std;

//Game::Game(){}

Game::Game(char* config):players(),deck(){
    //deck = Deck();
    
    vector<Card> GameCards;
    
    ifstream filetext(config);
    if (!filetext){
     cout << "error reading conf file";
        return;
    }
    
    bool verbal;
    int N;
    bool verbalpass=false;
    bool highest=false;
    bool deck=false;
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
                N=(int)word.at(0)-'0';
                highest=true;
            }
            else if (!deck){
                char shape;
                char fig;
                int value;                
                unsigned int index=0;
                string s;
            while (word.length()>index){
                
                if (word.at(index)!=(char)32){ //not a space
                    
                    if (word.at(index)<='9'){ // numeric card
                        s=""; 
                        while (word.at(index)!=(char)32){ //this char isnt space 
                            if (word.at(index+1)==(char)32){ //next char is space
                                shape=word.at(index);
                                value=std::atoi(s.c_str());
                                GameCards.push_back(NumericCard(shape,value));
                                index++;
                            }
                            else{ //next one isnt space, keep going on nums
                                s=s+word.at(index);
                                index++;
                            }
                        }
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
                    //GameCards.push_back(FigureCard(shape,fig,value));
                    }
                
                cout << "next card:" << value << "," << fig << " of " << shape <<'\n';
                
                }
                index++; 
                
            }
            deck=true;
        }
            
        else if (!playersPass){
            int playerNum=1;
            while (!word.empty()){
            string name="";
            int index=0;
            int strtg;
            while (word.at(index)!=(char)32){
                name+=word.at(index);
                index++;
            }
            strtg=word.at(index+1)-'0';
             //Player* temp = new Player(name,playerNum,strtg);
            // players.push_back(&temp);
             cout << "player name: " << name << " playing " << strtg <<'\n';
             getline(filetext,word);
             playerNum++;
            } 
    }
    }
}
}

void Game::init(){
}

void Game::play(){
}

void Game::printWinner(){
}
	void Game::printState(){
        }        //Print the state of the game as described in the assignment.
        void Game::printNumberOfTurns(){
        } //Print the number of played turns at any given time.


//int main(){

    
    
 //   }
