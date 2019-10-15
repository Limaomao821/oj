sourceCode=UOJ_Assignment1_8.cpp
CC=g++

objective.o: $(sourceCode)
	$(CC) -g -o objective.o $(sourceCode)

data.o: backup.c
	gcc -o data.o backup.c
	
run:
	./objective.o <input >output

test:
	./objective.o

createData:
	./data.o > input