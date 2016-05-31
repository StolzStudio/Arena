
CC=g++
FILES= main.cpp unit.cpp map.cpp
all:
	$(CC) $(FILES) -lncurses -o game
