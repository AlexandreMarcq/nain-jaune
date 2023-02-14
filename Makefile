IDIR = ./include
SDIR = ./src
ODIR = ./src/obj

CC=gcc
CFLAGS=-I$(IDIR) -Wall

_DEPS = carte.h joueur.h liste_carte.h liste_joueur.h pile_carte.h pion.h plateau.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = carte.o joueur.o liste_carte.o liste_joueur.o pile_carte.o pion.o plateau.o main.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: nain-jaune

debug: CFLAGS += -g
debug: clean
debug: nain-jaune

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nain-jaune: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean debug

clean:
	rm -f $(ODIR)/*.o
