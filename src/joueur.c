#include <stdlib.h>
#include "joueur.h"

Joueur*
nouveau_joueur()
{
    Joueur* j = (Joueur*) malloc(sizeof(Joueur));
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
    afficher_pions(*(j->pions));
}

void
supprimer_joueur(Joueur* j)
{
    free(j->pions);
    vider_liste_cartes(j->main);
    free(j);
}