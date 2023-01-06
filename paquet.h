#ifndef PAQUET_H
#define PAQUET_H

#include <stdlib.h>
#include "carte.h"

typedef struct {
    size_t taille;
    Node* cartes;
} Paquet;

void generer_paquet(Paquet* p);
void melanger_paquet(Paquet* p);

#endif
