sourceCode=UOJ_Test0_Count_Inversion.cpp
objective.o: $(sourceCode)
	g++ -g -o objective.o $(sourceCode)
	
run:
	./objective.o <input >output