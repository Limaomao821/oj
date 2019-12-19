sourceCode=Euler_3.c
CC=gcc
STD=-std=c++11

objective.o: $(sourceCode)
	$(CC) -g -o objective.o $(sourceCode) -lm

run:
	./objective.o <input >output

simply_run:
	./objective.o