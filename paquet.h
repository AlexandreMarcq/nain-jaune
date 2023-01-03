#ifndef PAQUET_H
#define PAQUET_H

#include "carte.h"

#define TAILLE_PAQUET 52

typedef struct {
    Carte cartes[TAILLE_PAQUET];
} Paquet;

void generer_paquet(Paquet* p);

#endif
