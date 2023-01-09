#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "paquet.h"
#include "carte.h"

void
generer_paquet(Paquet* p)
{
    size_t i = 0;
    p->cartes = NULL;
    for (int couleur = CARREAU; couleur <= TREFLE; couleur++)
    {
        for (int valeur = AS; valeur <= ROI; valeur++)
        {
            Carte* c = (Carte*) malloc(sizeof(Carte));
            c->couleur = couleur;
            c->valeur = valeur;
            ajouter_carte(&(p->cartes), c);
            i++;
        }
    }
    p->taille = i;
}

void
melanger_paquet(Paquet* p)
{
    ListeCarte* premiere = p->cartes;
    if (premiere && premiere->suivante)
    {
        srand(time(NULL));

        ListeCarte* temp = premiere;
        while (temp->suivante)
        {
            size_t rnd = (size_t) rand() / (RAND_MAX / p->taille + 1);

            ListeCarte* echange = trouver_carte(premiere, rnd);
            Carte* c = echange->carte;
            echange->carte = temp->carte;
            temp->carte = c;

            temp = temp->suivante;
        }
    }
}
