#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

 Card::Card():shape(){
     
 }

	Card::Card(Shape s) : shape(s){
		//shape=s;
	}
int getValue(){return 0;}

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

	FigureCard::FigureCard(Shape s,char f, int v):Card(s),figure(),value(v){
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
	int N=10; //TES5T!!!!!
            switch (figure){
                     case Jack:
                     return N+1;
                     break; //??
                     case Queen:
                     return N+2;
                     break; //??
                     case King:
                     return N+3;
                     break; //??
                     case Ace:
                     return N+4;
                     break; //??
                 }
                 cout <<"no Value Error";
                 return 0;
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

	NumericCard::NumericCard ( Shape s,int num):Card(s),number(num){
		number=num; // needed?
	}
	int NumericCard:: getValue(){
		return number;
	}

	string NumericCard::toString() {

		 string ans = std:: to_string(number);
		return ans+Card::toString();
	}




