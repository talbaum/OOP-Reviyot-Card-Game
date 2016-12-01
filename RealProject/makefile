
CC = g++
CFLAGS = -g -Wall -Weffc++ -std=c++11
DEPS = Card.h Deck.h Game.h Hand.h Player.h
OBJ =  reviiyot.o Card.o Deck.o Game.o Hand.o Player.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
	
reviiyot: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	find . -type f | xargs -n 5 touch
	rm *.o