#ifndef LISTE_JOUEUR_H
#define LISTE_JOUEUR_H

#include "joueur.h"

typedef struct ListeJoueur {
    Joueur* joueur;
    struct ListeJoueur* suivant;
} ListeJoueur;

size_t nombre_joueurs(ListeJoueur* premier);
void ajouter_joueur(ListeJoueur** premier, Joueur* j);
void afficher_liste_joueurs(ListeJoueur* premier);
void vider_liste_joueurs(ListeJoueur* premier);

#endif