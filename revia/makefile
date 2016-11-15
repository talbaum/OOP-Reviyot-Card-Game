output: reviiyot.o Card.o Deck.o Hand.o Game.o
	g++ -std=c++11 reviiyot.o Card.o Deck.o Hand.o Game.o -o output
	
reviiyot.o: reviiyot.cpp
	g++  -std=c++11 -c reviiyot.cpp
	
Card.o: Card.cpp Card.h
	g++ -std=c++11 -c Card.cpp
	
Deck.o: Deck.cpp Deck.h
	g++ -std=c++11 -c Deck.cpp
		
Hand.o: Hand.cpp Hand.h
	g++ -std=c++11 -c Hand.cpp
	
Game.o: Game.cpp Game.h
	g++ -std=c++11 -c Game.cpp
clean:
	rm *.o