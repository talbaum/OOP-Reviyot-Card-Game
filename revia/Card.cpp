#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

 Card::Card():shape(){
 }

	Card::Card(Shape s) : shape(s){
		//shape=s;
	}
virtual char getValue(){return '0';}

Shape Card:: getShape(){
	return shape;
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
	virtual char  FigureCard::getValue(){
				 if (figure=Jack){
					 return 'J';
				 }
				 else if (figure=Queen){
				 			 return 'Q';
				 		 }
				 else if (figure=King){
				 			 return 'K';
				 		 }
				 else if (figure=Ace){
				 			  return'A';
				 		 }
				 return '0';

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
		 //return ans;
		return ans+Card::toString();
		}


NumericCard::NumericCard():Card(), number(0){

}

	NumericCard::NumericCard ( Shape s,int num):Card(s),number(num){
		number=num;
	}
	virtual char NumericCard:: getValue(){
		return number;
	}

	string NumericCard::toString() {

		 string ans = std:: to_string(number);
		return ans+Card::toString();
	}




