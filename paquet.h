#ifndef PAQUET_H
#define PAQUET_H

#include "carte.h"

#define TAILLE_PAQUET 52

typedef struct {
    Node* cartes;
} Paquet;

void generer_paquet(Paquet* p);

#endif
