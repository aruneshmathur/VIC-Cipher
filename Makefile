CC = gcc
CFLAGS = -pedantic -Wall -g

vic-cipher: checkerboard.o main.o operations.o
	$(CC) $(CFLAGS) -o vic-cipher checkerboard.o main.o operations.o

checkerboard.o: checkerboard.c checkerboard.h
	$(CC) $(CFLAGS) -c checkerboard.c

operations.o: operations.c checkerboard.h
	$(CC) $(CFLAGS) -c operations.c

main.o: main.c operations.h args.h
	$(CC) $(CFLAGS) -c main.c

