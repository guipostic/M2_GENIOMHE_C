CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -O3 -march=native
SRC1    = ./01_basics.c
SRC2    = ./02_array_pointers.c
EXE1    = basics
EXE2    = array_pointers

all: $(EXE1) $(EXE2)
	
$(EXE1): $(SRC1)
	$(CC) $(SRC1) $(CFLAGS) -o $(EXE1)

$(EXE2): $(SRC2)
	$(CC) $(SRC2) $(CFLAGS) -o $(EXE2)
