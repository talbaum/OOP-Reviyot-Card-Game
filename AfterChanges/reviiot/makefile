INC_DIR=include
SRC_DIR=src
OBJ_DIR=bin
CC = g++
CFLAGS = -g -Wall -Weffc++ -std=c++11 -Iinclude
DEPS = $(INC_DIR)/Card.h $(INC_DIR)/Deck.h $(INC_DIR)/Game.h $(INC_DIR)/Hand.h $(INC_DIR)/Player.h
OBJ =  $(OBJ_DIR)/reviiot.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Hand.o $(OBJ_DIR)/Player.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
	
bin/reviiot: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	find . -type f | xargs -n 5 touch
	rm $(OBJ_DIR)/*.o
