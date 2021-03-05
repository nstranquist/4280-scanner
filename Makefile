# Makefile

scanner: main.o scanner.o
	g++ main.o scanner.o -o scanner

main.o: main.cpp scanner.h token.h
	g++ -c -Wall main.cpp

scanner.o: scanner.cpp scanner.h token.h
	g++ -c -Wall scanner.cpp