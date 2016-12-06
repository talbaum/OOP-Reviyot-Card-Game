#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

enum Shape {
	Club='C',
	Diamond='D',
	Heart='H',
	Spade='S'
};

enum Figure {
	Jack='J',
	Queen='Q',
	King='K',
	Ace='A'
};

class Card {
private:
	Shape shape;
public:
	Card();
	Card(char);
	Card (const Card &other);
	Card& operator =(const Card &other);
	virtual ~Card();
        char getShape();
        
	virtual int getValue()=0;
	virtual string toString()=0;//Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"

};

class FigureCard : public Card {
private:
	Figure figure;
	int value;
public:
	FigureCard();
	FigureCard(char,char,int);
        FigureCard (const FigureCard &other);
	virtual ~FigureCard();
	virtual int getValue();
	virtual string toString() ;

};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard();
	NumericCard(char,int);
        NumericCard (const NumericCard &other);
	virtual ~NumericCard();
	virtual int getValue() ;
	virtual string toString();

};

#endif
