COMPILER = g++
SRC = ../src/main.cpp ../src/Node.cpp ../src/AVL.cpp
IDIR = -I../include/
BIN = ejecutable
COMMANDS = clear
FLAGS = -std=c++14 -g -o

all: build clear run clean

clean:
	rm $(BIN)
clear:
	$(COMMANDS)
build:
	$(COMPILER) $(FLAGS) $(BIN) $(IDIR) $(SRC)
run:
	./$(BIN)
