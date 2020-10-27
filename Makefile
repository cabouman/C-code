# For Linux or any machines with gcc compiler
CC = gcc
CFLAGS = -ansi -Wall -pedantic
SRC = src
BIN = bin 

all: Example

clean:
	/bin/rm *.o Example

OBJ = SRC/tiff.o SRC/allocate.o SRC/randlib.o

Example: SRC/Example.o $(OBJ) 
	$(CC) $(CFLAGS) -o Example SRC/Example.o $(OBJ) -lm
	mv Example BIN
