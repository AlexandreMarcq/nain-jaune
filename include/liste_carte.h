#ifndef LISTE_CARTE_H
#define LISTE_CARTE_H

#include <stdlib.h>
#include "carte.h"

typedef struct ListeCarte
{
    Carte* carte;
    struct ListeCarte* suivante;
} ListeCarte;

size_t nombre_cartes(ListeCarte* premiere);
void ajouter_carte(ListeCarte** premiere, Carte* c);
ListeCarte* trouver_carte(ListeCarte* premiere, size_t index);
void trier_cartes(ListeCarte** premiere);
void afficher_cartes(ListeCarte* premiere);
void vider_liste_cartes(ListeCarte* premiere);

#endif