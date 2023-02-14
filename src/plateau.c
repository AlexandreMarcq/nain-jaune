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
distribuer_cartes(Plateau* p)
{
    size_t cartes_par_joueur = p->paquet->taille / nombre_joueurs(p->joueurs);

    ListeJoueur* joueur_curs = p->joueurs;
    ListeCarte* carte_curs = p->paquet->cartes;
    while (joueur_curs != NULL)
    {
        for (size_t n = 0; n < cartes_par_joueur; n++)
        {
            ajouter_carte(&(joueur_curs->joueur->main), carte_curs->carte);
            carte_curs = carte_curs->suivante;
        } 
        joueur_curs = joueur_curs->suivant;
    }
}

void
supprimer_plateau(Plateau* p)
{
    supprimer_paquet(p->paquet);
    vider_liste_joueurs(p->joueurs);
    free(p);
}
