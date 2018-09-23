COMPILER = g++
SRC = ../src/main.cpp ../src/Node.cpp ../src/AVL.cpp
SRC_TEST = ../src/main.cpp ../src/Node.cpp ../src/AVL.cpp
IDIR = -I../include/
BIN = ejecutable
BIN_TEST = ejecutableTest
COMMANDS = clear
FLAGS = -std=c++14 -g -o

all: build

unittest: build_unittest

clear:
	$(COMMANDS)
build:
	$(COMPILER) $(FLAGS) $(BIN) $(IDIR) $(SRC)
build_unittest:
	$(COMPILER) $(FLAGS) $(BIN_TEST) $(IDIR) $(SRC_TEST)
run:
	$(COMMANDS)
	./$(BIN)
run_unittest:
	$(COMMANDS)
	./$(BIN_TEST)
