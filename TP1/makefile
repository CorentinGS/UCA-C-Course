PROG = main
CC = gcc

OUT = bin

CFLAGS = -Wall -ansi -pedantic -g

all: $(PROG) clean

$(PROG): $(PROG).o tp1_ex1.o tp1_ex2.o tp1_ex3.o tp1_ex5.o tp1_ex7.o tp1_ex9.o tp1_ex10.o
	$(CC) $(CFLAGS) -o $(PROG) $(PROG).o tp1_ex1.o tp1_ex2.o tp1_ex3.o tp1_ex5.o tp1_ex7.o tp1_ex9.o tp1_ex10.o

clean:
	rm -f *.o