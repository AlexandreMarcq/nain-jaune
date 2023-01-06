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

typedef struct Node
{
    Carte carte;
    struct Node* suivante;
} Node;

char* nom_couleur(Couleur c);
char* nom_valeur(Valeur v);
void afficher_carte(Carte c);
void ajouter_carte(Node** premiere, Carte c);
Node* trouver_carte(Node* premiere, size_t index);
void vider_liste(Node* premiere);

#endif
