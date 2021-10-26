#include <stdio.h>
#include <stdlib.h>
#include "linkedListeOfMusic.h"




Music * readLineAsMusic(char *line){
    Music * m;
    m=(Music*) malloc(sizeof(Music));
    char *p;
    char *str=strdup(line);
    char *tmp=str;


    p=strsep(&str,",");
    m->name=calloc(sizeof(char),strlen(p)+1);
    strcpy(m->name,p);

    p=strsep(&str,",");
    m->artist=calloc(sizeof(char),strlen(p)+1);
    strcpy(m->artist,p);

    p=strsep(&str,",");
    m->album=calloc(sizeof(char),strlen(p)+1);
    strcpy(m->album,p);

    p=strsep(&str,",");
    m->genre=calloc(sizeof(char),strlen(p)+1);
    strcpy(m->genre,p);

    p=strsep(&str,",");
    m->discNumber=atoi(p);

    p=strsep(&str,",");
    m->trackNumber=atoi(p);

    p=strsep(&str,",");
    m->year=atoi(p);
    free(tmp);

    return m;
}

Liste creationListeMusic(FILE* f,Liste l){
    char *line=calloc(255,sizeof(char));
    fgets(line,255,f);
    l=creer(readLineAsMusic(line));
    free(line);
    line=NULL;
for (long int i=0;;i++){
    line=calloc(255,sizeof(char));
    fgets(line,255,f);
    if(strlen(line)==0){
        free(line);
        line=NULL;
        break;
    }
    l=ajoutFin_i(readLineAsMusic(line),l);
    free(line);
    line=NULL;
}
return l;

}




void swapMusic(Liste l,Liste k){
    Music * temp=(Music *)l->val;
    l->val=k->val;
    k->val=temp;

}

// On adapte l'algorithme de trie à Bulle à la liste de Musique selon l'année

void bubbleSortListeMusic(Liste l){
    int estTrie;
    Liste lTemp;
    
    if(estVide(l)){
        return;
    }
    do
    {
        estTrie=0;
        lTemp=l;
        while(lTemp->suiv!=NULL){
            if(((Music*)lTemp->val)->year> ((Music *)lTemp->suiv->val)->year){
                swapMusic(lTemp,lTemp->suiv);
                estTrie=1;
            }
            lTemp=lTemp->suiv;
        }
    } while (estTrie);
    
}



void afficheElement(Element e){
    Music * m=(Music *)e;
    printf("%s,",m->name);
    printf("%s,",m->artist);
    printf("%s,",m->album);
    printf("%s,",m->genre);

    if((m->discNumber)==0){
        printf(",");
    }
    else {
        printf("%i,",m->discNumber);
    }

    if((m->trackNumber)==0){
        printf(",");
    }
    else {
        printf("%i,",m->trackNumber);
    }

    if((m->year)==0){
        printf("\n");
    }
    else {
        printf("%i\n",m->year);
    }
    
}
void detruireElement(Element e){
   Music *m=(Music*)e;
   free(m->name);
   free(m->genre);
   free(m->album);
   free(m->artist);
   m->artist=NULL;
   m->album=NULL;
   m->genre=NULL;
   m->name=NULL;
   free(m);
   e=NULL;


}
bool equalsElement(Element e, Element f){
    Music * m=(Music *)e;
    Music * n=(Music *)f;
    if(strcmp(m->name,n->name)!=0){
        return 0;
    }
     if(strcmp(m->artist,n->artist)!=0){
        return 0;
    }
     if(strcmp(m->album,n->album)!=0){
        return 0;
    }
    if(strcmp(m->genre,n->genre)!=0){
        return 0;
    }
    return 1;
}
