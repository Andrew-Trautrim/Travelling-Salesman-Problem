CC = g++
CFLAGS = -Wall -ansi

christophide : christofide.o TSP.o
	$(CC) christofide.o TSP.o -o christofide

christofide.o : christofide.cpp TSP.h
	$(CC) -c christofide.cpp TSP.h

TSP.o : TSP.cpp TSP.h
	$(CC) -c TSP.cpp TSP.h

clean :
	rm christofide.o TSP.o christofide
