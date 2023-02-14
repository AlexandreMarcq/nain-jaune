#ifndef JOUEUR_H
#define JOUEUR_H

#include "liste_carte.h"
#include "pion.h"

typedef struct {
    ListeCarte* main;
    Pions* pions;
} Joueur;

Joueur* nouveau_joueur();
void initialiser_pions_joueur(Joueur* j);
void afficher_joueur(Joueur* j);
void supprimer_joueur(Joueur* j);

#endif
