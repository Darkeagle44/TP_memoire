#include "matrice_lineaire.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    if ((l<0)||(c<0)) {matrice m = { 0, 0, NULL };return m;}
	matrice m= {l,c,malloc(l*c*sizeof(double))};
    return m;
}

void liberer_matrice(matrice m) {
	m.l=0;m.c=0;
	free(m.donnees);
}

int est_matrice_invalide(matrice m) {
    if (m.donnees==NULL) return 1;
    else return 0;
}

double *acces_matrice(matrice m, int i, int j) {
    return &(m.donnees[i*m.c+j]);
}

int nb_lignes_matrice(matrice m) {
    return m.l;
}

int nb_colonnes_matrice(matrice m) {
    return m.c;
}
