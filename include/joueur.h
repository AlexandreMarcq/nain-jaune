#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"
#include "pion.h"

typedef struct {
    ListeCarte* main;
    Pions* pions;
} Joueur;

typedef struct ListeJoueur {
    Joueur* joueur;
    struct ListeJoueur* suivant;
} ListeJoueur;

Joueur* nouveau_joueur();
void initialiser_pions_joueur(Joueur* j);
void supprimer_joueur(Joueur* j);
size_t nombre_joueurs(ListeJoueur* premier);
void ajouter_joueur(ListeJoueur** premier, Joueur* j);
void vider_liste_joueurs(ListeJoueur* premier);

#endif
