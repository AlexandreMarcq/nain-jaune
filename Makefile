IDIR = ./include
SDIR = ./src
ODIR = ./src/obj

CC=gcc
CFLAGS=-I$(IDIR)

_DEPS = carte.h paquet.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = carte.o paquet.o main.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nain-jaune: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
