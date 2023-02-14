#include "pile_carte.h"

int
est_vide(PileCarte* sommet)
{
    return sommet == NULL ? 1 : 0;
}

void
empiler_carte(PileCarte** sommet, Carte* c)
{
    PileCarte* nouvelle = (PileCarte*) malloc(sizeof(PileCarte));
    nouvelle->carte = c;
    if (est_vide(*sommet))
    {
        nouvelle->suivante = NULL;
    } else
    {
        nouvelle->suivante = *sommet;
    }
    *sommet = nouvelle;
}

Carte*
depiler_carte(PileCarte** sommet)
{
    if (est_vide(*sommet))
    {
        return NULL;
    } else {
        PileCarte* temp = *sommet;
        Carte* retour = temp->carte;
        *sommet = (*sommet)->suivante;
        free(temp);
        return retour;
    }
}

void
afficher_pile_cartes(PileCarte* sommet)
{
    PileCarte* temp = sommet;
    while (temp != NULL)
    {
        afficher_carte(temp->carte);
        temp = temp->suivante;
    }
}