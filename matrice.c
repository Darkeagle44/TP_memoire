#include "matrice.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
	if ((c<0)||(l<0)){matrice m= {0,0,NULL};return m;}
    matrice m ;
    m.c=c;
    m.l=l;
    m.donnees=malloc(l*sizeof(double*));
    for (int i=0;i<l;i++) m.donnees[i]=malloc(c*sizeof(double));
    return m;
}

void liberer_matrice(matrice m) {
	for (int i=0;i<m.l;i++) free(m.donnees[i]);
	m.l=0;m.c=0;
	free(m.donnees);
}

int est_matrice_invalide(matrice m) {
	if (m.donnees==NULL) return 1;
    return 0;
}

double *acces_matrice(matrice m, int i, int j) {
    return &(m.donnees[i][j]);
}

int nb_lignes_matrice(matrice m) {
    return m.l;
}

int nb_colonnes_matrice(matrice m) {
    return m.c;
}
