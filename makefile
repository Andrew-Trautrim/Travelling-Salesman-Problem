CC = g++
CFLAGS = -Wall -ansi

christophide : christofides.o TSP.o
	$(CC) christofides.o TSP.o -o christofide

christofides.o : christofides.cpp TSP.h
	$(CC) -c christofides.cpp TSP.h

TSP.o : TSP.cpp TSP.h
	$(CC) -c TSP.cpp TSP.h

clean :
	rm christofides.o TSP.o christofide
