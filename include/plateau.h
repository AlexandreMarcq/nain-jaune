#ifndef PLATEAU_H
#define PLATEAU_H

#include <stdlib.h>
#include "liste_joueur.h"
#include "paquet.h"
#include "pion.h"

typedef struct {
    Pions* dix_carreau;
    Pions* valet_trefle;
    Pions* dame_pique;
    Pions* roi_coeur;
    Pions* sept_carreau;
    Paquet* paquet;
    ListeJoueur* joueurs;
} Plateau;

Plateau* nouveau_plateau(size_t nombre_joueurs);
void distribuer_cartes(Plateau* p);
void supprimer_plateau(Plateau* p);

#endif
