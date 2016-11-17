#include <iostream>
#include <string>

#include "Card.h"
using namespace std;

    Card::Card():shape(){
    }

	
    Card::Card(Shape s) : shape(s){
		//shape=s;
    }

	 string Card::toString(){
		 string ans="";
                 switch (shape){
                     case Club:
                     ans+='C';
                     case Diamond:
                     ans+='D';
                     case Heart:
                     ans+='H';
                     case Spade:
                     ans+='S';
                 }
		 return ans;
	 } 


	FigureCard::FigureCard():Card(),figure(){

	}// empty constructor

	FigureCard::FigureCard(Shape s,Figure f):Card(s),figure(f){

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
		
        int FigureCard::GetValue(int N){
            switch (figure){
                     case Jack:
                     return N+1;
                     
                     case Queen:
                     return N+2;
                     
                     case King:
                     return N+3;
                     
                     case Ace:
                     return N+4;
                 }
                 cout <<"no Value Error";
        }

NumericCard::NumericCard():Card(), number(0){

}

	NumericCard::NumericCard ( Shape s,int num):Card(s),number(num){
		number=num;
	}
	
	string NumericCard::toString() {

		 string ans = std:: to_string(number);
		return ans+Card::toString();
	}
	

	int NumericCard::GetValue(int N){
            return number;
        }



