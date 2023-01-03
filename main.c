#include "paquet.h"

int main()
{
    Paquet p;
    generer_paquet(&p);

    for (int i = 0; i < TAILLE_PAQUET; i++) 
    {
        afficher_carte(p.cartes[i]);
    }

    return 0;
}
