#include "matrice_dynamique.h"
#include "vecteur_dynamique.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    matrice m=malloc(sizeof(matrice));
    m->c=c;
    m->l=l;
    m->donnees=malloc(l*sizeof(double*));
    for (int i=0;i<l;i++) m->donnees[i]=malloc(c*sizeof(double));
    return m;
}

void liberer_matrice(matrice m) {
	for (int i=0;i<m->l;i++) free(m->donnees[i]);
	m->l=0;m->c=0;
	free(m->donnees);
	free(m);
}

int est_matrice_invalide(matrice m) {
	if (m->donnees==NULL) return 1;
    return 0;
}

double *acces_matrice(matrice m, int i, int j) {
	if ((i<0)||(j<0)) return NULL;
	while (i>=m->l){
		void* n=realloc(m->donnees,(i+1)*sizeof(double));
		if (n==NULL) return NULL;
		m->l=i+1;
	}while (j>=m->c){
		void* n;
		for (int k=0;k<m->l;k++) n=realloc(m->donnees[k],(j+1)*sizeof(double));
		if (n==NULL) return NULL;
		m->c=j+1;
	}
	if (m->donnees==NULL) return NULL;
    return &(m->donnees[i][j]);
}

int nb_lignes_matrice(matrice m) {
    return m->l;
}

int nb_colonnes_matrice(matrice m) {
    return m->c;
}
