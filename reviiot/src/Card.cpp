#include <string>
#include "../include/Card.h"
#include <sstream>
using namespace std;

Card::Card():shape(){ }

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

Card::Card(const Card &other): shape(other.shape){}

Card& Card::operator =(const Card &other){
	if(this==&other)
		return *this;
        this->shape = other.shape;
        return *this;
}

Card::~Card(){}

int Card::getValue(){return 0;}

char Card:: getShape(){
	char ans;
	switch (shape){
	case Club:
		ans='C';
		break;
	case Diamond:
		ans='D';
		break;
	case Heart:
		ans='H';
		break;
	case Spade:
		ans='S';
		break;
	}
	return ans;
}



FigureCard::FigureCard():Card(),figure(),value(0){}

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

FigureCard:: ~FigureCard() {}

int FigureCard::getValue(){
	return value;
}

string FigureCard::toString() {
	string ans="";
	switch (figure){
	case Jack:
		ans=+'J';
		break;
	case Queen:
		ans=+'Q';
		break;
	case King:
		ans=+'K';
		break;
	case Ace:
		ans=+'A';
	}
	switch (getShape()){
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

NumericCard::NumericCard():Card(), number(0){}

NumericCard::NumericCard(char s,int num):Card(s),number(num){}

NumericCard:: ~NumericCard(){}

int NumericCard:: getValue(){
	return number;
}

string NumericCard::toString() {
	std::stringstream ss;
	ss<<number;
	string ans = ss.str();
	switch (getShape()){
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