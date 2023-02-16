#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

Joueur*
nouveau_joueur(char* nom)
{
    Joueur* j = (Joueur*) malloc(sizeof(Joueur));
    j->nom = nom;
    j->main = NULL;
    initialiser_pions_joueur(j);
    return j;
}

void
initialiser_pions_joueur(Joueur* j)
{
    Pions* p = (Pions*) malloc(sizeof(Pions)); 
    p->nombre_un = 10;
    p->nombre_cinq = 5;
    p->nombre_dix = 3;
    j->pions = p;
}

void
afficher_joueur(Joueur* j)
{
    printf("Nom : %s\n", j->nom);
    afficher_pions(*(j->pions));
}

void
supprimer_joueur(Joueur* j)
{
    free(j->pions);
    vider_liste_cartes(j->main);
    free(j);
}