// gcc -W -Wall LinkedList.c mySpitofy.c linkedListeOfMusic.c  -o mySpitofy
// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpitofy <music.csv> out.csv

#include "linkedListeOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

Liste l;
int a=argc;
char * fileName =argv[1];
FILE* f=fopen(fileName,"r");


char *line=calloc(sizeof(char),255);
fgets(line,250,f);
l=creationListeMusic(f,l);

printf("%s",line);
free(line);
afficheListe_i(l);
fclose(f);
detruire_i(l);



    return 0;
}