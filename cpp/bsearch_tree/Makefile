CC = g++
CPPFLAGS = -Wall -O2 --std=c++11
TARGET = main
OBJS = bst.o main.o

main: bst.o main.o
	$(CC) -o test.out $(CPPFLAGS) $(OBJS) 
	./test.out

bst.o: bst.h bst.cpp
	$(CC) $(CPPFLAGS) -c bst.cpp 

main.o: main.cpp bst.o
	$(CC) $(CPPFLAGS) -c main.cpp

bst.cpp : bst.h

valgrind:
	valgrind --leak-check=full ./test.out

clean:
	rm -f *.o
	rm -f test