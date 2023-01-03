#ifndef CARTE_H
#define CARTE_H

typedef enum { CARREAU, COEUR, PIQUE, TREFLE } Couleur;
typedef enum { AS = 1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI } Valeur;

typedef struct 
{
    Couleur couleur;
    Valeur valeur;
} Carte;

char* nom_couleur(Couleur c);
char* nom_valeur(Valeur v);
void afficher_carte(Carte c);

#endif
