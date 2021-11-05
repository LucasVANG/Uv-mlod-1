#include "arbre-bin-recherche.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// fonction pour les elements pour changer plus facilement le code en cas de changement de int en quelque chose d'autre
void afficheElement(Element e) {
	printf("%i",e);
}
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}
void detruireElement(Element e) {
}
// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	if(a==NULL){
		return true;
	}
	return false;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL;
}
// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a;
	// On alloue une "case" mémoire de la taille d'un noeud à l'arbre
	a=calloc(sizeof(Noeud),1);
	// Et on initialise les deux fils
	initialiser(&a->filsDroit);
	initialiser(&a->filsGauche);
	a->val=e;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire tmp=a;
	//Si l'arbre est vide on le créer
	if(estVide(a)){
		a=creer(e);
		return a;
	}
	while(!estVide(tmp)){
		// Si l'element est déjà présent on ne fait rien et arrete
		if(equalsElement(tmp->val,e)){
			return a;
		}
		//Si l'element est supp à la valeur du noeud on va dans le fils de droit, si il existe pas on le crée
		if(e>tmp->val){
			if(estVide(tmp->filsDroit)){
				tmp->filsDroit=creer(e);
				return a;
			}
			tmp=tmp->filsDroit;


		}
		//Si l'element est inf à la valeur du noeud on va dans le fils de gauche, si il existe pas on le crée
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
	//Si l'arbre est vide on le créer
	if(estVide(a)){
		a=creer(e);
		return a;
	}
	//si l'elem est déjà présent on ne fait rien et on arrete la fonction
	if(a->val==e){
		return a;
	}
	//On va dans le fils droit si il existe si l'elément est plus grand que la valeur du noeud,sinon on le crée avec l'élement voulu
	if(e>a->val){
		if(estVide(a->filsDroit)){
			a->filsDroit=creer(e);
			return a;
		}
		a->filsDroit=insere_r(a->filsDroit,e);
		return a;
	}
	//On va dans le fils gauche si il existe si l'elément est plus petit que la valeur du noeud,sinon on le crée avec l'élement voulu
	if(e<a->val){
		if(estVide(a->filsGauche)){
			a->filsGauche=creer(e);
		}
		a->filsGauche=insere_r(a->filsGauche,e);
		return a;
	}

	return a;


}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	//On retourne 0 si l'arbre est vide
	if(estVide(a)){
		return 0;
	}
	// On additione le noeud actuel au nombre de noeud des deux fils
	else{
		return(nombreDeNoeud(a->filsDroit)+nombreDeNoeud(a->filsGauche)+1);
	}
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	//Si l'arbre est nul on retourne -1
		if(estVide(a)){
		return -1;
	}
	// Si on trouve l'element on retourne 0
	if(equalsElement(a->val,e)){
		return 0;
	}
	//On retourne le max entre les profondeurs dans chaque fils, un sera forcément -1 et l'autre la profondeur du noeud ou -1
	// On incrémente de +1 à chaque fois qu'on remonte d'un niveau vers la racine
	if(profondeur(a->filsDroit,e)<profondeur(a->filsGauche,e)){
		return profondeur(a->filsGauche,e)+1;
	}
	if (profondeur(a->filsDroit,e)>profondeur(a->filsGauche,e)){
		return profondeur(a->filsDroit,e)+1;

	}
	return -1;

}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(estVide(a)){
		return 0;
	}
	//On calcule la hauteur des deux fils +1 et on retourne le max
	else{
		int hg=hauteur(a->filsGauche);
		int hd=hauteur(a->filsDroit);
		if(hd>hg){
			return hd+1;
		}
		else{
			return hg+1;
		}
	}

}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	//Si c'est l'arbre nul il n'a pas de pere
	if(estVide(a)){
		return NULL;
	}
	// la racine n'a pas de pere
	if(equalsElement(a->val,elem)){
		return NULL;
	}
	// On cherche si le fils gauche est l'elem recherché si oui le noeud actuel est le pere
	if(!estVide(a->filsGauche)){
		if(equalsElement(a->filsGauche->val,elem)){
			return a;
		}
	}
	// On cherche si le fils droit est l'elem recherché si oui le noeud actuel est le pere
	if(!estVide(a->filsDroit)){
		if(equalsElement(a->filsDroit->val,elem)){
			return a;
		}
	}
	// Sinon on va dans un des fils selon la valeur de l'elem en fonction de la valeur du noeud actuel
	if(elem<a->val){
		return pere(a->filsGauche,elem);
	}
	if(elem>a->val){
		return pere(a->filsDroit,elem);
	}
	return a;
}


void afficheRGD_r(ArbreBinaire a){
		if(!estVide(a)){
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
		afficheElement(a->val);
	}
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheGRD_r(a->filsGauche);
		afficheElement(a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
		if(!estVide(a)){
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		afficheElement(a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	// On retourne NULL si c'est l'arbre nul
	if(estVide(a)){
		return NULL;
	}
	// Si le fils gauche n'existe pas, on a trouvé le min
	if(estVide(a->filsGauche)){
		return a;
	}
	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	// On retourne NULL si c'est l'arbre nul
	if(estVide(a)){
		return NULL;
	}
	//Si le  fils droit n'existe pas, on a trouvé le max
	if(estVide(a->filsDroit)){
		return a;
	}
	return max(a->filsDroit);
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){
	// On retourne NULL si c'est l'arbre nul
	if(estVide(a)){
		return NULL;
	}
	// On trouve l'element on renvoie le noeud
	if(equalsElement(a->val,elem)){
		return a;
	}
	// On cherche dans ses fils en fonction si il est supérieur ou inférieur à la valeur du noeud actuel
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
	// On verifie si c'est l'arbre nul
	if(estVide(a)){
		return a;
	}
	// Si l'element est inférieur à la valeur du noeud actuel on va dans le sous arbre de gauche
	if(x<a->val){
		a->filsGauche=supprimer_r(a->filsGauche,x);
	}
	// Si l'element est supérieur à la valeur du noeud actuel on va dans le sous arbre de droit
	else if(x>a->val){
		a->filsDroit=supprimer_r(a->filsDroit,x);
	}
	// Sinon on est au bon noeud
	else {
		// Si il a pas de fils on le supprime
		if(estVide(a->filsDroit)&&estVide(a->filsGauche)){
			detruireElement(a->val);
			free(a);
			return NULL;
		}
		// Si il a un seul fils on le remplace par son fils
		else if(a->filsGauche==NULL){
			ArbreBinaire tmp=a->filsDroit;
			detruireElement(a->val);
			free(a);
			return tmp;
		}
		else if(a->filsDroit==NULL){
			ArbreBinaire tmp=a->filsGauche;
			detruireElement(a->val);
			free(a);
			return tmp;
		}
		// Sinon on le remplace par le maximum de son fils de gauche
		ArbreBinaire tmp=max(a->filsGauche);
		a->val=tmp->val;
		a->filsGauche=supprimer_r(a->filsGauche,tmp->val);
	}
return a;
}

void detruire_r(ArbreBinaire a){
	// Si son fils gauche existe on le supprime
	if(!estVide(a->filsGauche)){
		detruire_r(a->filsGauche);
	}
	// Si son fils de droit existe on le supprime
	if(!estVide(a->filsDroit)){
		detruire_r(a->filsDroit);
	}
	// On supprime ensuite la racine en dernier
	detruireElement(a->val);
	free(a);
	a=NULL;

}

