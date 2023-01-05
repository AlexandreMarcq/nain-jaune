#include <stddef.h>
#include <stdlib.h>
#include "paquet.h"
#include "carte.h"

void
generer_paquet(Paquet* p)
{
    p->cartes = NULL;
    for (int couleur = CARREAU; couleur <= TREFLE; couleur++)
    {
        for (int valeur = AS; valeur <= ROI; valeur++)
        {
            Carte* c = (Carte*) malloc(sizeof(Carte));
            c->couleur = couleur;
            c->valeur = valeur;
            ajouter_carte(&(p->cartes), c);
        }
    }
}
