#ifndef PILE_CARTE_H
#define PILE_CARTE_H

#include <stdlib.h>
#include "carte.h"

typedef struct PileCarte
{
    Carte* carte;
    struct PileCarte* suivante;
} PileCarte;

int est_vide(PileCarte* sommet);
void empiler_carte(PileCarte** sommet, Carte* c);
Carte* depiler_carte(PileCarte** sommet);
void afficher_pile_cartes(PileCarte* sommet);

#endif