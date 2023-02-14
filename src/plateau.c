#include <stdlib.h>
#include "plateau.h"

Plateau*
nouveau_plateau(size_t nombre_joueurs)
{
    Plateau* plateau = (Plateau*) malloc(sizeof(Plateau));

    generer_paquet(plateau);
    melanger_cartes(&(plateau->paquet));

    plateau->joueurs = NULL;
    for (int i = 0; i < nombre_joueurs; i++)
    {
        Joueur* j = nouveau_joueur();
        ajouter_joueur(&(plateau->joueurs), j);
    }

    return plateau;
}

void
generer_paquet(Plateau* p)
{
    p->paquet = NULL;
    for (int couleur = CARREAU; couleur <= TREFLE; couleur++)
    {
        for (int valeur = AS; valeur <= ROI; valeur++)
        {
            Carte* c = (Carte*) malloc(sizeof(Carte));
            c->couleur = couleur;
            c->valeur = valeur;
            ajouter_carte(&(p->paquet), c);
        }
    }
}

void
distribuer_cartes(Plateau* p)
{
    size_t cartes_par_joueur = nombre_liste_cartes(p->paquet) / nombre_joueurs(p->joueurs);

    ListeJoueur* joueur_curs = p->joueurs;
    ListeCarte* carte_curs = p->paquet;
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
    vider_liste_cartes(p->paquet);
    vider_liste_joueurs(p->joueurs);
    free(p);
}
