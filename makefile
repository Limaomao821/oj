sourceCode=UOJ_Assignment1_7.c
CC=gcc

objective.o: $(sourceCode)
	$(CC) -g -o objective.o $(sourceCode)
	
run:
	./objective.o <input >output