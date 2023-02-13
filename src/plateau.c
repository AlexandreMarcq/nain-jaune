#include <stdlib.h>
#include "plateau.h"

Plateau*
nouveau_plateau(size_t nombre_joueurs)
{
    Plateau* plateau = (Plateau*) malloc(sizeof(Plateau));

    Paquet* paquet = (Paquet*) malloc(sizeof(Paquet));
    paquet->cartes = NULL;
    generer_paquet(paquet);
    melanger_paquet(paquet);

    plateau->joueurs = NULL;
    for (int i = 0; i < nombre_joueurs; i++)
    {
        Joueur* j = nouveau_joueur();
        ajouter_joueur(&(plateau->joueurs), j);
    }

    plateau->paquet = paquet;
    return plateau;
}

void
supprimer_plateau(Plateau* p)
{
    supprimer_paquet(p->paquet);
    vider_liste_joueurs(p->joueurs);
    free(p);
}
