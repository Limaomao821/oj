sourceCode=backup.c
CC=gcc

objective.o: $(sourceCode)
	$(CC) -g -o objective.o $(sourceCode)
	
run:
	./objective.o <input >output

test:
	./objective.o