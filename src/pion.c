#include <stdio.h>
#include "pion.h"

void
afficher_pions(Pions p)
{
    printf("1: %d, 5: %d, 10: %d\n", p.nombre_un, p.nombre_cinq, p.nombre_dix);
}

void
transferer_pions(Pions* source, Pions* destination, Pions* montant)
{

}