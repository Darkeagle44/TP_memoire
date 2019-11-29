#include "vecteur.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = {taille, malloc(taille*sizeof(double))};
    return v;
}

void liberer_vecteur(vecteur v) {
	v.taille=0;
	free(v.donnees);
}

int est_vecteur_invalide(vecteur v) {
    return 0;
}

double *acces_vecteur(vecteur v, int i) {
    return &(v.donnees[i]);
}

int taille_vecteur(vecteur v) {
    return v.taille;
}
