# For Linux or any machines with gcc compiler
CC = gcc 
CFLAGS = -std=c99 -Wall -pedantic
BIN = ../bin

all: RWExample BtildeExample

clean:
	/bin/rm *.o $(BIN)/*

OBJ = tiff.o allocate.o randlib.o qGGMRF.o solve.o

RWExample: RWExample.o $(OBJ) 
	$(CC) $(CFLAGS) -o RWExample RWExample.o $(OBJ) -lm
	mv RWExample $(BIN)

BtildeExample: BtildeExample.o $(OBJ) 
	$(CC) $(CFLAGS) -o BtildeExample BtildeExample.o $(OBJ) -lm
	mv BtildeExample $(BIN)
