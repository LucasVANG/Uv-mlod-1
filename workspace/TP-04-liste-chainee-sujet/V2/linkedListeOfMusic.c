#include <stdio.h>
#include <stdlib.h>
#include "LinkedListeOfMusic.h"

void afficheElement(Element e){
    Music * m=(Music *)e;
    printf("%s",m->name);
    printf("%s",m->artist);
    printf("%s",m->album);
    printf("%s",m->genre);
    printf("%i",m->discNumber);
    printf("%i",m->trackNumber);
    printf("%i",m->year);
}
void detruireElement(Element e){
    free(e);
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
