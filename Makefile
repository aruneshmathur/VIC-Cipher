CC = gcc
CFLAGS = -ansi -pedantic -Wall -g

a.out: checkerboard.o main.o
	$(CC) $(CFLAGS) -o a.out checkerboard.o main.o

checkerboard.o: checkerboard.c checkerboard.h
	$(CC) $(CFLAGS) -c checkerboard.c

main.o: main.c checkerboard.h
	$(CC) $(CFLAGS) -c main.c

