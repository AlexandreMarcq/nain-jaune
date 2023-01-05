#include <stddef.h>
#include "paquet.h"

int main()
{
    Paquet p = { .cartes = NULL };
    generer_paquet(&p);

    for (Node* n = p.cartes; n != NULL; n = n->suivante)
    {
        afficher_carte(*(n->carte));
    }

    vider_liste(p.cartes);
    return 0;
}
