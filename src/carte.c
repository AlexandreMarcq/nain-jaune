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

Carte*
nouvelle_carte(Valeur v, Couleur c)
{
    Carte* carte = (Carte*) malloc(sizeof(Carte));
    carte->valeur = v;
    carte->couleur = c;
    return carte;
}

void
afficher_carte(Carte* c)
{
    printf("%s de %s\n", nom_valeur(c->valeur), nom_couleur(c->couleur));
}