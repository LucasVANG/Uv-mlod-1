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
	while(l!=NULL){
			afficheElement(l->val);
			l=l->suiv;

		}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	Liste tmp=l;
	if(l==NULL){
	}
	else {
		afficheElement(tmp->val);
		afficheListe_r(l->suiv);
	}
}

void detruireElement(Element e) {
	e=NULL;
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste tmp;
	while(l->suiv!=NULL){
		tmp=l->suiv;
		detruireElement(l->val);
		free(l);
		l=NULL;
		l=tmp;
	}
}

// version récursive
void detruire_r(Liste l) {
	TODO;
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste tmp=l;
	Liste res;
	if(l==NULL){
		tmp=ajoutTete(v,l);
	}
	else{ 
		res=creer(v);
		while(l->suiv!=NULL){
			l=l->suiv;
		}
		l->suiv=res;
	}
	return tmp;

}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l==NULL){
		l=creer(v);
	}
	else{
		if(l->suiv!=NULL){
			ajoutFin_r(v,l->suiv);
		}
		else{
			Liste res;
			res=creer(v);
			l->suiv=res;
		}
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
	while(l!=NULL){
		if(equalsElement(l->val,v)){
			return l;
		}
		else{
			l=l->suiv;
		}
	}
	return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	Liste res;
	if(l==NULL){
		return NULL;
	}
	if(equalsElement(l->val,v)){
		return l;
	}
	else{
		res=cherche_r(v,l->suiv);
	}
	return res;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste tmp=l;

	if(cherche_i(v,l)!=NULL){
		while(l->suiv->val!=v){
			l=l->suiv;	
		}
		l->suiv=l->suiv->suiv;
	}
	return tmp;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {


	if(cherche_r(v,l)!=NULL){

		if(l->suiv->val==v){
			l->suiv=l->suiv->suiv;
		}
		else{
			retirePremier_r(v,l->suiv);
		}
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	TODO;
}



