CC=gcc
CFLAGS=-Iinclude -Wall
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
EXEC=bin/visualizer

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)
