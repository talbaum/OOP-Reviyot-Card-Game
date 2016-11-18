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
  Card(Shape s);
  Shape getShape();
  virtual char getValue();
  virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
  virtual ~Card();
};

class FigureCard : public Card {
private:
	Figure figure;
public:
	virtual string toString() override;
	FigureCard();
	FigureCard(Shape,Figure);
	virtual char getValue();
};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard();
	NumericCard(Shape,int);
	virtual char getValue();
	virtual string toString() override;
};

#endif
