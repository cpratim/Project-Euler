PROG = main

main: 
	g++ src/main.cpp -o main.o -std=c++20

.PHONY: clean

clean:
	rm -f main.o

