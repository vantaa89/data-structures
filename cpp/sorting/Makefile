CC = g++
CPPFLAGS = -Wall -O2 -std=c++17
OBJ = main.out

main: main.cpp
	$(CC) $(CPPFLAGS) main.cpp -o $(OBJ)
	./main.out

clean:
	rm -f *.o
	rmdir -r *.dSYM
	rm -f *.out

valgrind:
	valgrind --leak-check=full ./main.out