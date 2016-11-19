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
  //Card();
  Card(char);
  virtual ~Card();
  virtual Shape getShape();
  virtual int getValue();
  virtual string toString();// was '= 0 //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
  
};

class FigureCard : public Card {
private:
	Figure figure;
	int value;
public:
	//FigureCard();
        FigureCard(char,char,int);
	int getValue() override;
        virtual string toString() override;
        Shape getShape() override;
};

class NumericCard : public Card {
private:
	int number;
public:
	//NumericCard();
	NumericCard(char,int);
	int getValue() override;
	virtual string toString() override;
        Shape getShape() override;
};

#endif
