sourceCode=UOJ_Assignment3_5.cpp
CC=g++
STD=-std=c++11

objective.o: $(sourceCode)
	$(CC) -g -o objective.o $(sourceCode)

run:
	./objective.o <input >output