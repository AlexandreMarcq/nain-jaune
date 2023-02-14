#include <stdio.h>
#include <stdlib.h>
#include "carte.h"

char* 
nom_couleur(Couleur c)
{
    switch (c) 
    {
        case CARREAU: return "CARREAU";
        case COEUR: return "COEUR";
        case PIQUE: return "PIQUE";
        case TREFLE: return "TREFLE";
        default: return "";
    }
}

char*
nom_valeur(Valeur v)
{
    switch (v)
    {
        case AS: return "AS";
        case DEUX: return "DEUX";
        case TROIS: return "TROIS";
        case QUATRE: return "QUATRE";
        case CINQ: return "CINQ";
        case SIX: return "SIX";
        case SEPT: return "SEPT";
        case HUIT: return "HUIT";
        case NEUF: return "NEUF";
        case DIX: return "DIX";
        case VALET: return "VALET";
        case DAME: return "DAME";
        case ROI: return "ROI";
        default: return "";
    }
}

void
afficher_carte(Carte* c)
{
    printf("%s de %s\n", nom_valeur(c->valeur), nom_couleur(c->couleur));
}

size_t
nombre_cartes(ListeCarte* premiere)
{
    size_t n = 0;
    ListeCarte* temp = premiere;

    if (premiere == NULL)
    {
        return 0;
    } else 
    {
        n++;
    }

    while (temp->suivante != NULL)
    {
        n++;
        temp = temp->suivante;
    }

    return n;
}

void
ajouter_carte(ListeCarte** premiere, Carte* c)
{
    ListeCarte* nouvelle = (ListeCarte*) malloc(sizeof(ListeCarte));
    nouvelle->carte = c;
    nouvelle->suivante = NULL;

    if (*premiere == NULL)
    {
        *premiere = nouvelle;
        return;
    }


    ListeCarte* temp = *premiere;
    while (temp->suivante != NULL)
    {
        temp = temp->suivante;
    }
    
    temp->suivante = nouvelle;
}

ListeCarte*
trouver_carte(ListeCarte* premiere, size_t index)
{
    ListeCarte* resultat = premiere;
    while (index-- && resultat->suivante)
    {
        resultat = resultat->suivante;
    }
    return resultat;
}

void
trier_cartes(ListeCarte** premiere)
{
    size_t taille = nombre_cartes(*premiere);
    for (size_t n = taille; n > 1; n--)
    {
        ListeCarte* temp = *premiere;
        while (temp->suivante != NULL)
        {
            if (temp->carte->valeur > temp->suivante->carte->valeur) {
                Carte* c = temp->carte;
                temp->carte = temp->suivante->carte;
                temp->suivante->carte = c;
            }
            temp = temp->suivante;
        } 
    }
}

void
afficher_cartes(ListeCarte* premiere)
{
    ListeCarte* temp = premiere;

    while (temp->suivante != NULL)
    {
        afficher_carte(temp->carte);
        temp = temp->suivante;
    }
}

void
vider_liste_cartes(ListeCarte* premiere)
{
    ListeCarte* temp;

    while (premiere != NULL)
    {
        temp = premiere;
        premiere = premiere->suivante;
        free(temp);
    }
}
