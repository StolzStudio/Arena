
CC=g++
FILES= main.cpp
all:
	$(CC) $(FILES) -lncurses -o game
