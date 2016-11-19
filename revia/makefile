output: Card.o Deck.o Game.o Hand.o player.o
	g++ -g -Wall -Weffc++ -std=c++11 Card.o Deck.o Game.o Hand.o player.o  -o output
	
Card.o: Card.cpp Card.h
	g++ -g -Wall -Weffc++ -std=c++11  Card.cpp Deck.cpp Game.cpp Hand.cpp
	

clean:
	rm *.o
