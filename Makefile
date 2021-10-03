CFLAGS = -Wall -g
CC = g++

all: clean main clean

clean:
	rm -f core *.o main.o Student.o Instructor.o main

main: main.o Student.o Instructor.o
	$(CC) $(CFLAGS) -o main main.o Student.o Instructor.o

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
