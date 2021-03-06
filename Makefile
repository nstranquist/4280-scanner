# Makefile

scanner: main.o testScanner.o scanner.o
	g++ main.o testScanner.o scanner.o -o scanner

main.o: main.cpp testScanner.h scanner.h token.h
	g++ -c -Wall main.cpp

testScanner.o: testScanner.cpp scanner.h token.h
	g++ -c -Wall testScanner.cpp

scanner.o: scanner.cpp scanner.h token.h
	g++ -c -Wall scanner.cpp