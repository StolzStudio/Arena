
CC=g++
FILES= main.cpp unit.cpp map.cpp point.cpp
all:
	$(CC) $(FILES) -lncurses -o game
