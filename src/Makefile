# For Linux or any machines with gcc compiler
CC = gcc
CFLAGS = -ansi -Wall -pedantic
BIN = ../bin

all: Example

clean:
	/bin/rm *.o $(BIN)/Example

OBJ = tiff.o allocate.o randlib.o

Example: Example.o $(OBJ) 
	$(CC) $(CFLAGS) -o Example Example.o $(OBJ) -lm
	mv Example $(BIN)
