#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//fonction exo 1
void echangeContenu(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

// fonction pour exo 2
bool estConvexe(bool *tab, int length){
short nb_chaine=0;
    for(int64_t i=0;i<length-1;i++){
        if(tab[i]!=tab[i+1]){
            nb_chaine+=1;

        }
        if(nb_chaine>2){
            return false;
            
        }
        if((nb_chaine==2)&&(tab[0]!=tab[length-1])){
            return false;
        }
    }
    return true;
    
}

//fonctions exo 3 
void mult_matrice(int64_t resultat[5][5], int64_t matriceA[5][5], int64_t matriceB[5][5]){
    int resultatCase;
    for(int ligne=0; ligne<5; ligne++){
        for(int colonne=0; colonne<5; colonne++){
            resultatCase=0;
            for(int i=0; i<5; i++){
                resultatCase+= matriceA[ligne][i] * matriceB[i][colonne];
            };
        resultat[ligne][colonne]=resultatCase;
        };
    };
}
void affiche_matrice(int64_t matrice[5][5]){
    for(int lig=0; lig<5; lig++){
        for(int col=0; col<5; col++){
            printf("%li ", matrice[lig][col]);
        }
        printf("\n");
    }
}

//exo 4
enum mois{
    janvier =1,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
};
typedef enum mois Mois;

struct date{
    int jour;
    Mois mois;
    int annee;

};
typedef struct date Date;

void initialiseDate(Date *d){
    printf("Entrez le jour :");
    int j;
    scanf("%i",&j);
    printf("Entrez le mois :");
    int m;
    scanf("%i",&m);
    printf("Entrez le annee :");
    int a;
    scanf("%i",&a);

    d->annee=a;
    d->mois=m;
    d->jour=j;

}
void afficheDate(Date *d){
    char *mois;
    switch(d->mois){
        
        case 1:
        mois="janvier";
        break;
        
        case 2:
        mois="fevrier";
        break;
        
        case 3:
        mois="mars";
        break;
        
        case 4:
        mois="avril";
        break;
        
        case 5:
        mois="mai";
        break;
        
        case 6:
        mois="juin";
        break;
        
        case 7:
        mois="juillet";
        break;
        
        case 8:
        mois="aout";
        break;
        
        case 9:
        mois="septembre";
        break;
        
        case 10:
        mois="octobre";
        break;
        
        case 11:
        mois="novembre";
        break;

        case 12:
        mois="decembre";
        break;

    }
    printf("Nous somme le %i %s %i \n",d->jour,mois,d->annee);
}

Date creerDateParCopie(){
    Date d;
    printf("Entrez le jour :");
    scanf("%i",&d.jour);
    printf("Entrez le mois :");
    scanf("%i",(int*)&d.mois);
    printf("Entrez le annee :");
    scanf("%i",&d.annee);
    return d;

}

Date * newDate(){
    Date *d;
    d=malloc(sizeof(*d));
    printf("Entrez le jour :");
    int j;
    scanf("%i",&j);
    printf("Entrez le mois :");
    int m;
    scanf("%i",&m);
    printf("Entrez le annee :");
    int a;
    scanf("%i",&a);

    d->annee=a;
    d->mois=m;
    d->jour=j;
    return d;
}

//exo bonus
struct fraction{
    int num;
    int den;
};
typedef struct fraction Fraction;
int PGCD(int a ,int b){
    int pgcd=1;
        for(int i=1; i <= a && i <= b; ++i)
    {
        if(a%i==0 && b%i==0)
            pgcd = i;
    }
    return pgcd;
}

void simplifie(Fraction *f){
    int pgcd=PGCD(f->num,f->den);
    if(pgcd==1){
        return 0;
    }
    else{
        f->num/=pgcd;
        f->den/=pgcd;
        simplifie(f);
    }
    
        
}
Fraction addFra(Fraction a,Fraction b){
    Fraction res;
    res.den=a.den*b.den;
    res.num=a.num*b.den + b.num*a.den;
    simplifie(&res);
    return res;

}
Fraction sommeInvN(int n){
    Fraction tmp;
    tmp.num=0;
    tmp.den=1;
    Fraction add;
    add.num=1;
    for(int i=1;i<=n;i++){
        add.den=i;

        tmp=addFra(tmp,add);
    }
    return tmp;

}

//main
int main(void){
    // test exo 1
    /*int a=5;
    int b=2;
    echangeContenu(&a,&b);
    printf("a=%i,b=%i \n",a,b);
    a=3;
    b=8;
    echangeContenu(&a,&b);
    printf("a=%i,b=%i \n",a,b);

    // test exo 2
    bool test1[5] ={true,false,false,true,false};
    bool test2[7] ={true,true,false,false,false,true,true};
    bool test3[7] ={false,false,false,true,true,true,false};
    bool test4[9] ={true,true,false,false,true,false,false,true,true};
    printf("Le tableau de bool test1 est convexe %s \n",estConvexe(test1,sizeof(test1))? "true":"false");
    printf("Le tableau de bool test2 est convexe %s \n",estConvexe(test2,sizeof(test2))? "true":"false");
    printf("Le tableau de bool test3 est convexe %s \n",estConvexe(test3,sizeof(test3))? "true":"false");
    printf("Le tableau de bool test4 est convexe %s \n",estConvexe(test4,sizeof(test4))? "true":"false");

    // test exo 3

    //matrices en ligne * colonne
    int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[5][5];
    mult_matrice(matriceResultat,matrice1,matrice2);
    affiche_matrice(matriceResultat);
    */

    //test exo 4

    Date d;
    initialiseDate(&d);//On ajoute un & pour pouvoir modifier d dans la fonction
    afficheDate(&d);
    Date d2=creerDateParCopie();
    afficheDate(&d2);
    Date *d3;
    d3= newDate();
    afficheDate(d3);


    free(d3);

    

    //test exo bonus

    Fraction testfra;
    testfra.num=45;
    testfra.den=27;
    printf("%i/%i donne ", testfra.num,testfra.den);
    simplifie(&testfra);
    printf("%i / %i \n",testfra.num,testfra.den);
    Fraction testfra2;
    Fraction testfra3;
    Fraction testfrares;
    testfra2.num=2;
    testfra2.den=3;
    testfra3.num=1;
    testfra3.den=4;
    testfrares=addFra(testfra2,testfra3);
    printf("l'addition donne %i / %i \n",testfrares.num,testfrares.den);

    int n;
    n=3;
    Fraction res;
    res=sommeInvN(n);
    printf("La somme des inverses de 1 à %i donne %i / %i \n",n,res.num,res.den);

    return 0;
    
}

