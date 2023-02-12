#ifndef CARTE_H
#define CARTE_H

#include <stdlib.h>

typedef enum { CARREAU, COEUR, PIQUE, TREFLE } Couleur;
typedef enum { AS = 1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI } Valeur;

typedef struct Carte
{
    Couleur couleur;
    Valeur valeur;
} Carte;

typedef struct ListeCarte
{
    Carte* carte;
    struct ListeCarte* suivante;
} ListeCarte;

char* nom_couleur(Couleur c);
char* nom_valeur(Valeur v);
void afficher_carte(Carte c);
void ajouter_carte(ListeCarte** premiere, Carte* c);
ListeCarte* trouver_carte(ListeCarte* premiere, size_t index);
void vider_liste(ListeCarte* premiere);

#endif