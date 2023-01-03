#include "paquet.h"
#include "carte.h"

void
generer_paquet(Paquet* p)
{
    int i = 0;
    for (int couleur = CARREAU; couleur <= TREFLE; couleur++)
    {
        for (int valeur = AS; valeur <= ROI; valeur++)
        {
            Carte c;
            c.couleur = couleur;
            c.valeur = valeur;
            p->cartes[i] = c;
            i++;
        }
    }
}
