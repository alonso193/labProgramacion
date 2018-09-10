COMPILER = g++
SRC = main.cpp Node.cpp AVL.cpp
BIN = ejecutable
COMMANDS = clear
FLAGS = -g -o

all: build clear run clean

clean:
	rm $(BIN)
clear:
	$(COMMANDS)
build:
	$(COMPILER) $(FLAGS) $(BIN) $(SRC)
run:
	./$(BIN)
