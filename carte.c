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
afficher_carte(Carte c)
{
    printf("%s de %s\n", nom_valeur(c.valeur), nom_couleur(c.couleur));
}

void
ajouter_carte(Node** premiere, Carte* c)
{
    Node* nouvelle = (Node*) malloc(sizeof(Node));
    nouvelle->carte = c;
    nouvelle->suivante = NULL;

    if (*premiere == NULL)
    {
        *premiere = nouvelle;
        return;
    }


    Node* temp = *premiere;
    while (temp->suivante != NULL)
    {
        temp = temp->suivante;
    }
    
    temp->suivante = nouvelle;
    return;
}

void
vider_liste(Node* premiere)
{
    Node* temp;

    while (premiere != NULL)
    {
        temp  = premiere;
        premiere = premiere->suivante;
        free(temp);
    }
}

Node*
trouver_carte(Node* premiere, size_t index)
{
    Node* resultat = premiere;
    while (index-- && resultat->suivante)
    {
        resultat = resultat->suivante;
    }
    return resultat;
}
