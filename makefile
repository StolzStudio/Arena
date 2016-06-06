
CC=g++
FILES= main.cpp unit.cpp map.cpp point.cpp gamemanager.cpp
all:
	$(CC) $(FILES) -lncurses -o game
