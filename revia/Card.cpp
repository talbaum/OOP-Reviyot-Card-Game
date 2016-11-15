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
		 if (shape=Club){
			 return ans+'C';
		 }
		 else if (shape=Diamond){
		 			 return ans+'D';
		 		 }
		 else if (shape=Heart){
		 			 return ans+'H';
		 		 }
		 else if (shape=Spade){
		 			  ans=+'S';
		 		 }
		 return ans;
	 } 


	FigureCard::FigureCard():Card(),figure(){

	}// empty constructor

	FigureCard::FigureCard(Shape s,Figure f):Card(s),figure(f){

	}

	string FigureCard::toString() {
		 string ans="";
		 if (figure=Jack){
			 return ans+'J';
		 }
		 else if (figure=Queen){
		 			 return ans+'Q';
		 		 }
		 else if (figure=King){
		 			 return ans+'K';
		 		 }
		 else if (figure=Ace){
		 			  ans=+'A';
		 		 }
		 return ans;
		return ans+Card::toString();
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




