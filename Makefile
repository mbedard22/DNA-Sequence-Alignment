all: EDistance

EDistance: EDistance.o main.o
	g++ EDistance.o main.o -o EDistance -lsfml-system

EDistance.o: EDistance.cpp EDistance.h
	g++ -c EDistance.cpp -Wall -Werror -pedantic

main.o: main.cpp
	g++ -c main.cpp -Wall -Werror -pedantic

clean:
	rm *.o EDistance
