#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	if(a->val==NULL){
		return true;
	}
	return false;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=calloc(sizeof(ArbreBinaire),1);
	(*a)->filsDroit=calloc(sizeof(ArbreBinaire),1);
	(*a)->filsGauche=calloc(sizeof(ArbreBinaire),1);
	(*a)->val=NULL;

}
// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a;
	initialiser(&a);
	a->val=e;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire tmp=a;
	if(estVide(a)){
		a->val=e;
		return a;
	}
	while(!estVide(tmp)){
		if(tmp->val==e){
			return a;
		}
		if(e>tmp->val){
			if(estVide(tmp->filsDroit)){
				tmp->filsDroit=creer(e);
				return a;
			}
			tmp=tmp->filsDroit;


		}
		if(e<tmp->val){
			if(estVide(tmp->filsGauche)){
				tmp->filsGauche=creer(e);
				return a;
			}

			tmp=tmp->filsGauche;
		}
	}

	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if(estVide(a)){
		a->val=e;
		return a;
	}
	if(a->val==e){
		return a;
	}
	if(e>a->val){
		if(estVide(a->filsDroit)){
			a->filsDroit=creer(e);
			return a;
		}
		a->filsDroit=insere_r(a->filsDroit,e);
		return a;
	}
	if(e<a->val){
		if(estVide(a->filsGauche)){
			a->filsGauche=creer(e);
		}
		a->filsGauche=insere_r(a->filsGauche,e);
		return a;
	}


	
	return NULL;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if(estVide(a)){
		return 0;
	}
	else{
		return(nombreDeNoeud(a->filsDroit)+nombreDeNoeud(a->filsGauche)+1);
	}
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){

		return 0;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheGRD_r(a->filsGauche);
		printf("%i",a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){
	if(estVide(a)){
		return NULL;
	}
	if(a->val==elem){
		return a;
	}
	else{
		if(elem<a->val){
			return recherche_r(a->filsGauche,elem);
		}
		else{
			return recherche_r(a->filsDroit,elem);
		}
	}

}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

