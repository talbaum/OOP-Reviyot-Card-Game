#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

 Card::Card():shape(){
     
 }

	Card::Card(char s) : shape(){
                switch (s){
                     case 'C':
                     shape=Club;
                     break;
                     case 'D':
                     shape=Diamond;
                     break;
                     case 'H':
                     shape=Heart;
                     break;
                     case 'S':
                     shape=Spade;
                     break;
                 }     
	}
	
	Card::~Card(){
            
        }
        
int Card::getValue(){return 0;}


Shape Card:: getShape(){
	return shape;
}


	 string Card::toString(){
		 string ans="";
                 switch (shape){
                     case Club:
                     ans+='C';
				 break;
                     case Diamond:
                     ans+='D';
				 break;
                     case Heart:
                     ans+='H';
				 break;
                     case Spade:
                     ans+='S';
				 break;
                 }
		 return ans;
	 } 


	FigureCard::FigureCard():Card(),figure(),value(0){

	}// empty constructor

	FigureCard::FigureCard(char s,char f, int v):Card(s),figure(),value(v){

            switch (f){
                     case 'J':
                     figure = Jack;
                     break;
                     case 'Q':
                     figure = Queen;
                     break;
                     case 'K':
                     figure = King;
                     break;
                     case 'A':
                     figure = Ace;
                     break;
                 }
	}

int FigureCard::getValue(){
return value;
        }

string FigureCard::toString() {
		 string ans="";
                 switch (figure){
                     case Jack:
                     ans=+'J';
                     case Queen:
                     ans=+'Q';
                     case King:
                     ans=+'K';
                     case Ace:
                     ans=+'A';
                 }
		return ans+Card::toString();
		}


NumericCard::NumericCard():Card(), number(0){

}

	NumericCard::NumericCard ( char s,int num):Card(s),number(num){
		//number=num; // needed?
	}
	int NumericCard:: getValue(){
		return number;
	}

	string NumericCard::toString() {

		 string ans = std:: to_string(number);
		return ans+Card::toString();
	}


//why is main needed??
 main(){
    
}
