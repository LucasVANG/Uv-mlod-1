#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l;
	l=calloc(sizeof(Liste),1);
	l->val=v;
	l->suiv=NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
		Liste res;
		res=creer(v);
		res->suiv=l;
		return res;
}


void afficheElement(Element e) {
	printf("%i\n ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	while(!estVide(l)){
			afficheElement(l->val);
			l=l->suiv;

		}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	Liste tmp=l;
	if(estVide(l)){
	}
	else {
		afficheElement(tmp->val);
		afficheListe_r(l->suiv);
	}
}

void detruireElement(Element e) {
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste tmp;
	while(!estVide(l->suiv)){
		tmp=l;
		l=l->suiv;
		detruireElement(tmp->val);
		free(tmp);
	}
}

// version récursive
void detruire_r(Liste l) {
	if(estVide(l->suiv)){
		detruireElement(l->val);
		free(l);

	}
	else{
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste tmp=l;
	Liste res;
	res=creer(v);
	if(estVide(l)){
		return res;
	}
	else{ 
		while(!estVide(tmp->suiv)){
			tmp=tmp->suiv;
		}
		tmp->suiv=res;
	}
	return l;

}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l)){
		return creer(v);
	}
	else{
		l->suiv = ajoutFin_r(v,l->suiv);
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(!estVide(l) && !equalsElement(l->val,v)){
		
			l=l->suiv;
	}
	return l;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(estVide(l)){
		return l;
	}
	if(equalsElement(l->val,v)){
		return l;
	}
	else{
		return cherche_r(v,l->suiv);
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste tmp, lien;
	if(estVide(l)){
		return l;
	}

	if(equalsElement(l->val,v)){
		tmp=l->suiv;
		l->suiv=NULL;
		detruire_i(l);
		return tmp;
	}
	lien=l;
	tmp=l->suiv;
	while(!estVide(tmp) && !equalsElement(tmp->val,v)){
		lien=tmp;
		tmp=tmp->suiv;
	}

	if(!estVide(tmp)){
		lien->suiv=tmp->suiv;
		tmp->suiv=NULL;
		detruire_i(tmp);
	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	Liste tmp=l;


	if(cherche_r(v,tmp)!=NULL){
		if(equalsElement(tmp->val,v)){
			tmp=tmp->suiv;
			detruireElement(l->val);
			free(l);
			l=NULL;
			return tmp;

		}

		if( equalsElement(tmp->suiv->val,v)){
			
			Liste suivant=tmp->suiv->suiv;
			free(tmp->suiv);
			tmp->suiv=suivant;
		}
		else{
			retirePremier_r(v,tmp->suiv);
		}
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	Liste tmp=l;
	if(estVide(tmp->suiv)){
		afficheElement(tmp->val);

	}
	else{
		afficheEnvers_r(tmp->suiv);
		afficheElement(tmp->val);
	}
}



