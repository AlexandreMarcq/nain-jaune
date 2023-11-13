#ifndef PION_H
#define PION_H

typedef struct {
    int nombre_un;
    int nombre_cinq;
    int nombre_dix;
} Pions;

void afficher_pions(Pions p);
void transferer_pions(Pions* source, Pions* destination, Pions* montant);

#endif
