#include "liste_joueur.h"

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

    while (temp->suivant != premier)
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

    if (*premier == NULL)
    {
        *premier = nouveau;
        nouveau->suivant = *premier;
        return;
    }

    ListeJoueur* temp = *premier;
    while (temp->suivant != *premier)
    {
        temp = temp->suivant;
    }

    temp->suivant = nouveau;
    nouveau->suivant = *premier;
    return;
}

void
afficher_liste_joueurs(ListeJoueur* premier)
{
    ListeJoueur* temp = premier;
    do
    {
        afficher_joueur(temp->joueur);
        temp = temp->suivant;
    } 
    while (temp != premier);
}

void
vider_liste_joueurs(ListeJoueur* premier)
{
    ListeJoueur* temp;
    do
    {
        temp = premier;
        premier = premier->suivant;
        supprimer_joueur(temp->joueur);
        free(temp);
    }
    while (premier != NULL);
}