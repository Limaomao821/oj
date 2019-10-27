sourceCode=UVA_725.cpp
CC=g++
STD=-std=c++11

objective.o: $(sourceCode)
	$(CC) -g -o objective.o $(sourceCode) $(STD)

run:
	./objective.o <input >output