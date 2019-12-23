sourceCode=UOJ_Assignment4_1.cpp
CC=g++
STD=-std=c++11

objective.o: $(sourceCode)
	$(CC) -g -o objective.o $(sourceCode) -lm

run:
	./objective.o <input >output

simply_run:
	./objective.o

test:
	gcc -o test.o test.c

run_test:
	./test.o