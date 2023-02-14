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
afficher_joueurs(ListeJoueur* premier)
{
    ListeJoueur* temp = premier;
    while (temp != NULL)
    {
        afficher_joueur(temp->joueur);
        temp = temp->suivant;
    }
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