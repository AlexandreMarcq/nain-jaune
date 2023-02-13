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
supprimer_joueur(Joueur* j)
{
    free(j->pions);
    vider_liste_cartes(j->main);
    free(j);
}

size_t
nombre_joueurs(ListeJoueur* premier)
{
    size_t n = 0;
    ListeJoueur* temp = premier;

    if (premier == NULL)
    {
        return 0;
    } else 
    {
        n++;
    }

    while (temp->suivant != NULL)
    {
        n++;
        temp = temp->suivant;
    }

    return n;
}

void
ajouter_joueur(ListeJoueur** premier, Joueur* j)
{
    ListeJoueur* nouveau = (ListeJoueur*) malloc(sizeof(ListeJoueur));
    nouveau->joueur = j;
    nouveau->suivant = NULL;

    if (*premier == NULL)
    {
        *premier = nouveau;
        return;
    }

    ListeJoueur* temp = *premier;
    while (temp->suivant != NULL)
    {
        temp = temp->suivant;
    }

    temp->suivant = nouveau;
    return;
}

void
vider_liste_joueurs(ListeJoueur* premier)
{
    ListeJoueur* temp;

    while (premier != NULL)
    {
        temp = premier;
        premier = premier->suivant;
        supprimer_joueur(temp->joueur);
        free(temp);
    }
}
