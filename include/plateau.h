#ifndef PLATEAU_H
#define PLATEAU_H

#include <pions.h>

typedef struct {
    Pions* dix_carreau;
    Pions* valet_trefle;
    Pions* dame_pique;
    Pions* roi_coeur;
    Pions* sept_carreau;
} Plateau;

#endif
