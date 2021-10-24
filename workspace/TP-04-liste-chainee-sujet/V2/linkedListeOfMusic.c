#include <stdio.h>
#include <stdlib.h>
#include "linkedListeOfMusic.h"


char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}
Music * readLineAsMusic(){
    Music * m;
    m=(Music*) malloc(sizeof(Music));
    char *p;
    char *line=scanLine();
    char *str=strdup(line);
    char *tmp=str;
    free(line);

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
