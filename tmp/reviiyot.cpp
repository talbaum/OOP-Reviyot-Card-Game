#include <iostream>

#include "Game.h"

using namespace std;

int main(int argc, char **argv) {

	/*
	 * test for card:
	NumericCard * a=new NumericCard();
	NumericCard * b=new NumericCard('S',2);
	cout<<a->toString()<<endl;
	cout<<b->toString()<<endl;
	FigureCard * c=new FigureCard();
	FigureCard * d=new FigureCard('H','J',11);
	cout<<" c: "<<c->toString()<<endl;
	cout<<d->toString()<<endl;
	cout<<d->getShape()<<endl;
	cout<<a->getValue()<<endl;
	cout<<c->getValue()<<endl;
	 */

	/*
	 //test for deck:
	FigureCard * a=new FigureCard('C','A',14);
	NumericCard * b=new NumericCard('S',2);
	NumericCard * c=new NumericCard('D',8);
	FigureCard * d=new FigureCard('H','J',11);


	vector<Card*> cards;
	cards.push_back(d);
	cards.push_back(c);
	cards.push_back(b);
	cards.push_back(a);

	Deck * d1 = new Deck();
	Deck  deck (cards);
	Deck * deck2 = new Deck();


	cout<<"deck to string should print all the card   "<<deck.toString()<<endl;
	cout<<"numOfCards before fetch "<<deck.getNumberOfCards()<<endl;
	Card* ptr=deck.fetchCard();
	cout<<"fetch card "<<ptr->toString()<<endl;
	deck.fetchCard();
	cout<<"deck to string should print 2 cards after 2 fetch   "<<deck.toString()<<endl;
	cout<<"d to string should be empty "<<d1->toString()<<endl;
	cout<<"numOfCards after fetch "<<deck.getNumberOfCards()<<endl;
	cout<<"deck is empty? should be 0 which is false "<<deck.isEmpty()<<endl;
	cout<<"d is empty? should be 1 which is true "<<d1->isEmpty()<<endl;
	deck2->SetDeck(deck.GetDeck());
	cout<<"deck2 to string after GetDeck and SetDeck "<<deck2->toString()<<endl;
*/


 //* test for hand:
cout<<"check1"<<endl;
	Hand * aa= new Hand();
	FigureCard * a=new FigureCard('C','A',14);
	NumericCard * b=new NumericCard('S',2);
	NumericCard * c=new NumericCard('D',8);
	FigureCard * d=new FigureCard('H','J',11);
	FigureCard * e=new FigureCard('H','Q',12);
	FigureCard * f=new FigureCard('S','K',13);
	NumericCard * g=new NumericCard('D',2);
	NumericCard * h=new NumericCard('S',9);
	NumericCard * i=new NumericCard('C',6);
	NumericCard * j=new NumericCard('H',6);

	cout<<"check2"<<endl;
	vector<Card*> cards;
	cards.push_back(d);
	cards.push_back(c);
	cards.push_back(b);
	cards.push_back(a);
	cards.push_back(e);
	cards.push_back(g);
	cards.push_back(f);
	cards.push_back(h);
	cards.push_back(i);
	cards.push_back(j);
	cout<<"check3"<<endl;
	Deck  deck (cards);
	cout<<deck.toString()<<endl;
	cout<<"check4"<<endl;
	cout<<"empty hand number of cards:" <<aa->getNumberOfCards()<<endl;
	aa->addCard(*a);
	cout<<aa->getNumberOfCards()<<endl;

	cout<<"check5"<<endl;

//	cout<<"regular hand number of cards:" <<bb.getNumberOfCards()<<endl;



	/*
                 char* configurationFile = argv[1];

                 Game game = Game(configurationFile);
                 game.init();
                  Game initializedGame = game;
                  game.play();

                 cout << std::endl;
                  game.printWinner();
                 game.printNumberOfTurns();
                 cout << "----------" << endl;
                 cout<<"Initial State:"<<endl;
                   initializedGame.printState();
                 cout<<"----------"<<endl;
                 cout<<"Final State:"<<endl;
                 game.printState();
	 */
	return 0;

}
