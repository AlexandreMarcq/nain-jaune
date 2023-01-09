#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"
#include "pion.h"

typedef struct {
    ListeCarte* main;
    Pions* pions;
} Joueur;

void initialiser_pions_joueur(Joueur* j);
void supprimer_joueur(Joueur* j);

#endif
