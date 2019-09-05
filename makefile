sourceCode=UVA_11991.cpp
objective.o: UVA_11991.cpp
	g++ -g -o objective.o $(sourceCode) -std=c++11
	
run:
	./objective.o <input >output