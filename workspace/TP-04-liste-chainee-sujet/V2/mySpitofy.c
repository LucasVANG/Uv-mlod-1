// gcc -W -Wall LinkedList.c mySpitofy.c linkedListeOfMusic.c  -o mySpitofy
// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpitofy <music.csv> out.csv

#include "linkedListeOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
Liste l;

char *line=scanLine();
l=creer(readLineAsMusic());
for (long int i=0;i<2700;i++){
    l=ajoutFin_i(readLineAsMusic(),l);
}

printf("%s\n",line);
free(line);
afficheListe_i(l);
detruire_i(l);



    return 0;
}