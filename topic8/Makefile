CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

main04: main04.o Bond.o NonlinearSolver02.o Function02.o
	$(CC) $(CFLAGS) -o main04 main04.o Bond.o NonlinearSolver02.o Function02.o

main04.o: main04.cpp Function02.h NonlinearSolver02.h Bond.h 
	$(CC) $(CFLAGS) -c main04.cpp
	
Bond.o: Bond.h NonlinearSolver02.h Function02.h Bond.cpp
	$(CC) $(CFLAGS) -c Bond.cpp	

NonlinearSolver02.o: NonlinearSolver02.h Function02.h NonlinearSolver02.cpp
	$(CC) $(CFLAGS) -c NonlinearSolver02.cpp
	
Function02.o: Function02.h Function02.cpp
	$(CC) $(CFLAGS) -c Function02.cpp
	
clean:
	rm -rf main04 *.o



