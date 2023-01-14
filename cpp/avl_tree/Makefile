CC = g++-12
CPPFLAGS = --std=c++17
TARGET = main
OBJS = avl.o main.o

main: $(OBJS)
	$(CC) -o test.out $(CPPFLAGS) $(OBJS)
	./test.out

avl.o: avl.hpp avl.cpp
	$(CC) $(CPPFLAGS) -c avl.cpp 

main.o: main.cpp avl.o
	$(CC) $(CPPFLAGS) -c main.cpp

avl.cpp : avl.hpp

valgrind:
	valgrind --leak-check=full --track-origins=yes ./test.out

clean:
	rm -f *.o
	rm -f test