#include <stdio.h>
#include "carte.h"

int attribuer_valeur(char* valeur, int valeurlen, char* buf, int buflen)
{
    if (buflen < valeurlen)
    {
        return -1;
    }
    else
    {
        buf = valeur;
        return 0;
    }
}

int nom_couleur(Couleur c, char* buf, int buflen)
{
    switch (c) 
    {
        case CARREAU: return attribuer_valeur("CARREAU", 7, buf, buflen);
        case COEUR: return attribuer_valeur("COEUR", 5, buf, buflen);
        case PIQUE: return attribuer_valeur("PIQUE", 5, buf, buflen);
        case TREFLE: return attribuer_valeur("TREFLE", 6, buf, buflen);
        default: return -1;
    }
}

int nom_valeur(Valeur v, char* buf, int buflen)
{
    switch (v)
    {
        case AS: return attribuer_valeur("AS", 2, buf, buflen);
        case DEUX: return attribuer_valeur("DEUX", 4, buf, buflen);
        case TROIS: return attribuer_valeur("TROIS", 5, buf, buflen);
        case QUATRE: return attribuer_valeur("QUATRE", 5, buf, buflen);
        case CINQ: return attribuer_valeur("CINQ", 4, buf, buflen);
        case SIX: return attribuer_valeur("SIX", 3, buf, buflen);
        case SEPT: return attribuer_valeur("SEPT", 4, buf, buflen);
        case HUIT: return attribuer_valeur("HUIT", 4, buf, buflen);
        case NEUF: return attribuer_valeur("NEUF", 4, buf, buflen);
        case DIX: return attribuer_valeur("DIX", 3, buf, buflen);
        case VALET: return attribuer_valeur("VALET", 5, buf, buflen);
        case DAME: return attribuer_valeur("DAME", 4, buf, buflen);
        case ROI: return attribuer_valeur("ROI", 3, buf, buflen);
        default: return -1;
    }
}

void afficher_carte(Carte c)
{
    char couleur[7], valeur[6];
    if (nom_couleur(c.couleur, &couleur, sizeof couleur) == -1)
    {
        couleur = "COULEUR INVALIDE";
    }
    if (nom_valeur(c.valeur, &valeur, sizeof valeur) == -1)
    {
        valeur = "VALEUR INVALIDE";
    }
    printf("%s de %s\n", couleur, valeur);
}
