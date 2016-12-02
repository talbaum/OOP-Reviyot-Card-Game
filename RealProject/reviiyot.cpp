#include <iostream>

#include "Game.h"

using namespace std;

int main(int argc, char **argv) {

/*test for card:
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
	cout<<d->getValue()<<endl;
	cout<<b->getValue()<<endl;
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

/*
	//* test for hand:
	Hand * aa= new Hand();
	FigureCard * a=new FigureCard('C','A',14);
	NumericCard * b=new NumericCard('S',4);
	NumericCard * c=new NumericCard('D',8);
	FigureCard * d=new FigureCard('H','J',11);
	FigureCard * e=new FigureCard('H','Q',12);
	FigureCard * f=new FigureCard('S','K',13);
	NumericCard * g=new NumericCard('D',2);
	NumericCard * h=new NumericCard('S',9);
	NumericCard * i=new NumericCard('C',6);
	NumericCard * j=new NumericCard('H',6);
	FigureCard * k=new FigureCard('H','A',14);
	NumericCard * m=new NumericCard('S',6);
	NumericCard * l=new NumericCard('D',6);
	NumericCard* q=new NumericCard('C',7);
	NumericCard * n=new NumericCard('C',5);
	NumericCard * o=new NumericCard('C',10);
	FigureCard * p=new FigureCard('C','J',11);


	vector<Card*> cards;
	cards.push_back(d);
	cards.push_back(c);
	cards.push_back(o);
	cards.push_back(a);
	//cards.push_back(i);
	cards.push_back(g);
	cards.push_back(f);
	cards.push_back(h);
	cards.push_back(e);
	//cards.push_back(j);
	cards.push_back(q);
	cards.push_back(p);
	cards.push_back(n);
	cards.push_back(b);

	Deck  deck (cards);
	cout<<"Deck: "<<deck.toString()<<endl;


		vector<Card*> cards2;
		cards2.push_back(n);
		cards2.push_back(o);
		cards2.push_back(p);
		cards2.push_back(q);

		Deck deck2 (cards2);

	//fix whereToInsert and SearchCard


	Hand bb=Hand(deck);
	cout<<"Deck after hand : "<<bb.deck.toString()<<endl;
	cout<<"toString before adding somtheing: "<<bb.toString()<<endl;
	bb.addCard(*i);
	bb.addCard(*j);
	bb.addCard(*l);
	cout<<"tostring before reviia and after 3 addCards of 6: "<<bb.toString()<<endl;
	cout<<"Deck before reviia: "<<bb.deck.toString()<<endl;
	bb.addCard(*m);
	cout<<"tostring after reviia:"<<bb.toString()<<endl;
	cout<<"tostring Deck after reviia:"<<bb.deck.toString()<<endl;
*/

/*
/*
	//tests for player:
	//FigureCard * a=new FigureCard('C','A',14);
	NumericCard * b=new NumericCard('S',2);
	NumericCard * c=new NumericCard('D',2);
	FigureCard * d=new FigureCard('H','K',13);
	FigureCard * e=new FigureCard('C','K',13);
	FigureCard * f=new FigureCard('S','K',13);
	NumericCard * g=new NumericCard('D',3);
	NumericCard * h=new NumericCard('S',3);
	NumericCard * i=new NumericCard('C',3);
	NumericCard * j=new NumericCard('H',6);
	//FigureCard * k=new FigureCard('H','A',14);
	NumericCard * m=new NumericCard('S',6);
	NumericCard * l=new NumericCard('D',6);


	NumericCard* q=new NumericCard('C',7);
	NumericCard * n=new NumericCard('C',5);
	NumericCard * o=new NumericCard('C',10);
	FigureCard * p=new FigureCard('C','J',11);


	vector<Card*> cards;
	cards.push_back(b);
	cards.push_back(d);
	cards.push_back(c);
	cards.push_back(i);
	cards.push_back(j);
	cards.push_back(m);
	cards.push_back(l);
	cards.push_back(g);
	cards.push_back(f);
	cards.push_back(h);
	cards.push_back(e);
	//cards.push_back(g);
	//cards.push_back(p);
	//cards.push_back(n);



	Deck  deck (cards);
	cout<<"Deck: "<<deck.toString()<<endl;


	// player with most card on the table is 1
	  //player with least card on the table is 3


	Player * one= new PlayerType1("Tal",1,deck,1);
	Player * two= new PlayerType2("Elad",2,deck,2);
	Player * three= new PlayerType3("Ido",3,deck,3);
	Player * four= new PlayerType4("Nir",4,deck,4);

	three->removeCard(*b);
	three->removeCard(*d);
	three->removeCard(*c);
	four->addCard(*c);



	vector<Player*> players;
	players.push_back(one);
	players.push_back(two);
	players.push_back(three);
	players.push_back(four);


	cout<<"one position:" <<one->getPosition()<<endl;
	cout<<"two strategy:" <<two->getStrategy()<<endl;
	cout<<"three name:" <<three->getName()<<endl;
	cout<<"four numOfCards:" <<four->getNumberOfCards()<<endl;
	one->addCard(*h);
	one->addCard((*g));
	one->addCard((*e));
	cout<<"one cards:" <<one->toString()<<endl;

	vector <Card*>ans1=one->selectCard(one->getHand());
	vector <Card*>ans2=two->selectCard(one->getHand());
	vector <Card*>ans3=three->selectCard(one->getHand());
	vector <Card*>ans4=four->selectCard(one->getHand());

	cout<<ans1[0]->getValue()<<" is the value player 1 chose"<<endl;
	cout<<ans2[0]->getValue()<<" is the value player 2 chose"<<endl;
	cout<<ans3[0]->getValue()<<" is the value player 3 chose"<<endl; //problem. should print K and not 13
	cout<<ans4[0]->getValue()<<" is the value player 4 chose"<<endl;

	int asked1=one->PlayerWithMostCards(players);
	int asked2=two->PlayerWithMostCards(players);
	int asked3=three->cyclicOrder(players);
	int asked4=four->cyclicOrder(players);

	cout<<"player1 asked from (should be 4):"<< asked1<<endl;
	cout<<"player2 asked from (should be 1):"<< asked2<<endl;
	cout<<"player3 asked from (should be 1):"<< asked3<<endl;
	cout<<"player4 asked from (should be 1):"<< asked4<<endl;

	cout<<"player4 asked from (should be 2):"<<four->cyclicOrder(players)<<endl;
	cout<<"player4 asked from (should be 3):"<<four->cyclicOrder(players)<<endl;
	cout<<"player4 asked from (should be 1):"<<four->cyclicOrder(players)<<endl;


	cout<<"player4 asked from (should be 2):"<<four->cyclicOrder(players)<<endl;
	cout<<"player4 asked from (should be 3):"<<four->cyclicOrder(players)<<endl;
	cout<<"player3 asked from (should be 2):"<< three->cyclicOrder(players)<<endl;
	cout<<"player3 asked from (should be 4):"<< three->cyclicOrder(players)<<endl;
	cout<<"player3 asked from (should be 1):"<< three->cyclicOrder(players)<<endl;
	cout<<"player3 asked from (should be 2):"<< three->cyclicOrder(players)<<endl;
	cout<<"player3 asked from (should be 4):"<< three->cyclicOrder(players)<<endl;
	cout<<"player4 asked from (should be 1):"<<four->cyclicOrder(players)<<endl;


*/


 char* configurationFile = "config3.txt"; //was argv[1]
                 Game game = Game(configurationFile);
                 game.init();
                  Game initializedGame = game;
                  game.play();

          //       cout << std::endl;
          //        game.printWinner();
          //       game.printNumberOfTurns();
          //       cout << "----------" << endl;
           //      cout<<"Initial State:"<<endl;
           //        initializedGame.printState();
          //       cout<<"----------"<<endl;
         //        cout<<"Final State:"<<endl;
         //        game.printState();

	return 0;

}
