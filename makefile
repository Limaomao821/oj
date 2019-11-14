sourceCode=UVA_10405.c
CC=gcc
STD=-std=c++11

objective.o: $(sourceCode)
	$(CC) -g -o objective.o $(sourceCode)

run:
	./objective.o <input >output