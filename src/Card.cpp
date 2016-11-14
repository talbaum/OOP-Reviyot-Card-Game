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
	
	FigureCard::FigureCard () Figure(-1){}// add super constructor

	FigureCard::FigureCard (Figure f) Figure (f){}
	
	virtual string toString() {
		return this.Figure+this.Shape;
	}
}

Class NumericCard :: public Card{
	
	NumericCardCard::NumericCardCard () int(0){}


	NumericCard::NumericCard (int num) int (num){}
	
	virtual string toString() {
		return this.num+this.Shape;
	}
}



