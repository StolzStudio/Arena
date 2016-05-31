
CC=g++
FILES= main.cpp unit.cpp
all:
	$(CC) $(FILES) -lncurses -o game
