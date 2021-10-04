CFLAGS = -g -Wall
CC = g++

all: main

main: main.o ItemType.o SortedLinkedList.o
	$(CC) $(CFLAGS) main.o ItemType.o SortedLinkedList.o -o main

main.o : main.cpp
	$(CC) -c main.cpp

SortedLinkedList.o : SortedLinkedList.cpp SortedLinkedList.h
	$(CC) -c SortedLinkedList.cpp

ItemType.o : ItemType.h ItemType.cpp
	$(CC) -c ItemType.cpp


clean:
	-rm -f core *.o
	-rm -f *.class
	-rm -f main
