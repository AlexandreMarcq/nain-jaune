#include <stdlib.h>
#include "joueur.h"

void
initialiser_pions_joueur(Joueur* j)
{
    Pions* p = (Pions*) malloc(sizeof(Pions)); 
    p->nombre_un = 10;
    p->nombre_cinq = 5;
    p->nombre_dix = 3;
    j->pions = p;
}

void
supprimer_joueur(Joueur* j)
{
    free(j->pions);
    free(j);
}
