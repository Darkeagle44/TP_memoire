#include "vecteur_dynamique.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = malloc(sizeof(vecteur));
    v->taille=taille;
    v->donnees=malloc(taille*sizeof(double));
    return v;
}

void liberer_vecteur(vecteur v) {
	v->taille=0;
	free(v->donnees);
	free(v);
}

int est_vecteur_invalide(vecteur v) {
    if (v->taille<=0) return 1;
    return 0;
}

double *acces_vecteur(vecteur v, int i) {
	if (i<0) return NULL;
	while (i>=v->taille){
		void* n=realloc(v->donnees,(i+1)*sizeof(double));
		if (n==NULL) return NULL;
		v->taille++;
	}
	if (v->donnees==NULL) return NULL;
    return &(v->donnees[i]);
}

int taille_vecteur(vecteur v) {
    return v->taille;
}
