#include <iostream>
#include <string>
#include <fstream>
#include "Game.h"
//using namespace std;

//Game::Game(){}

Game::Game(char* config):players(), deck(){
    const char* config1 = "config.txt";
    
    ifstream filetext(config1);
    
    if (!filetext) return;
    bool verbal;
    int N;
    
    bool verbalpass=false;
    bool highest=false;
    bool deck=false;
    bool players= false;
    
    string word;
    while (getline(filetext,word)){
       
        if (!verbal){
            if (word.at(0)=='#'){
                getline(filetext,word);
                if (word.at(0)=='1')
                    verbal=true;
                else
                    verbal=false;
            verbalpass=true;
            }
            cout << "verbal:" << verbal << '\n';
        }
        getline(filetext,word);
        getline(filetext,word);
        if (!highest){
              if (word.at(0)=='#'){
                getline(filetext,word);
                cout << word <<'\n';
                N=(int)word.at(0)-'0';
            highest=true;
            }
        }
        
        getline(filetext,word);
        getline(filetext,word);
        
        
        if (!deck){
            if (word.at(0)=='#'){
                getline(filetext,word);
                char value,shape;                
            unsigned int index=0;
            while (word.length()>index){
                value=word.at(index);
                index++;
                shape=word.at(index);
                index+=2;
                cout << "next card:" << value << "of" << shape <<'\n';
            }
            deck=true;
            }
        }
        if (!players){
            if (word.at(0)=='#'){
                getline(filetext,word);
                

    }
}
    }
}