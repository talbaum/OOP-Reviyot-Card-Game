output: reviiyot.o Card.o Deck.o Game.o Hand.o player.o
	g++ -g -Wall -Weffc++ -std=c++11 reviiyot.o Card.o Deck.o Game.o Hand.o player.o -o output
	
reviiyot.o: reviiyot.cpp
	g++  -g -Wall -Weffc++ -std=c++11 -c reviiyot.cpp
	
Card.o: Card.cpp Card.h
	g++ -g -Wall -Weffc++ -std=c++11 -c Card.cpp
	
Deck.o: Deck.cpp Deck.h
	g++ -g -Wall -Weffc++ -std=c++11 -c Deck.cpp
		
Game.o: Game.cpp Game.h
	g++ -g -Wall -Weffc++ -std=c++11 -c Game.cpp
		
Hand.o: Hand.cpp Hand.h
	g++ -g -Wall -Weffc++ -std=c++11 -c Hand.cpp

clean:
	rm *.o