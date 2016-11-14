#include <card.h>

Class Card {
		enum Shape {
	Club='C';
	Diamond='D';
	Heart='H';
	Spade='S';
};
	Card::Card () Shape(-1){} //check if -1 is legal for enum
	
	Card::Card (Shape s) Shape (s){}

	 virtual string toString (){
	 return this.Shape;
	 } 
}

Class FigureCard :: public Card{
	enum Figure {
	Jack,
	Queen,
	King,
	Ace
};
	
	FigureCard::FigureCard () Figure(-1) : Card() {}// empty constructor

	FigureCard::FigureCard (Figure figure, Shape shape) Figure (figure) :Figure Card(shape){} // constructor with parameters
	
	virtual string toString() {
		return this.figure+Card::toString();
		}
}

Class NumericCard :: public Card{
	
	NumericCard::NumericCardCard () int(0)::Card(){}

	NumericCard::NumericCard (int number , Shape shape) int (number) :: Card(shape){}
	
	virtual string toString() {
		return this.number+this.shape;
	}
}



