#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

 Card::Card():shape(){
 }

	Card::Card(Shape s) : shape(s){
		//shape=s;
	}
virtual int getValue(){return 0;}

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


	FigureCard::FigureCard():Card(),figure(){

	}// empty constructor

	FigureCard::FigureCard(Shape s,Figure f):Card(s),figure(f){

	}

int FigureCard::GetValue(){
	int N=10; //TEST!!!!!
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
	virtual char NumericCard:: getValue(){
		return number;
	}

	string NumericCard::toString() {

		 string ans = std:: to_string(number);
		return ans+Card::toString();
	}




