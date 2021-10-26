// gcc -W -Wall LinkedList.c mySpitofy.c linkedListeOfMusic.c  -o mySpitofy
// pour vérifier la lecture et création de la liste de Music faire ./mySpitofy music.csv> out.csv
// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpitofy music.csv> out.csv
// pour vérifier le tri de la liste de musique créé faire ./mySpitofy tri music.csv> out.csv
// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpitofy tri music.csv> out.csv

#include "linkedListeOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
if(argc==2)
    {
    Liste l=NULL;
    char * fileName =argv[1];
    FILE* f=fopen(fileName,"r");
    char *line=calloc(sizeof(char),255);


    fgets(line,255,f);
    l=creationListeMusic(f,l);

    printf("%s",line);
    free(line);
    afficheListe_i(l);
    fclose(f);
    detruire_i(l);
    }
else if(argc==3 && (strcmp(argv[1],"tri")==0))
    {
    Liste l=NULL;
    char * fileName =argv[2];
    FILE* f=fopen(fileName,"r");
    char *line=calloc(sizeof(char),255);


    fgets(line,255,f);
    l=creationListeMusic(f,l);

    printf("%s",line);
    free(line);

    bubbleSortListeMusic(l);
    afficheListe_i(l);
    fclose(f);
    detruire_i(l);

    }
    else
    {
        printf("Too few arguments");
    }


    return 0;
}