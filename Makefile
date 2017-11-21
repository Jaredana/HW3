.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall -fgcse

all: hw4

hw4: hw4.o mult.o
	gcc -g -o hw4 $(CFLAGS) hw4.o mult.o

hw4.o: hw4.c
	gcc -c -g -o hw4.o $(CFLAGS) hw4.c

mult.o: mult.c
	gcc -c -g -o mult.o $(CFLAGS) mult.c

clean:
	rm -f *.o hw4
