#include <stdio.h>
float prix_plein_tarif=10;

float prix_billet(float prix, int age){
    if(age<2){
        return 0.1*prix;
    }
    else if (age<12){
        return 0.5*prix;
    }
    return prix;
}

int affichagedes(int n){
    if(n>18||n<3){
        printf("Valeur non valide");
        return 0;
    }
    for (int a=1; a<=6;a++){
        for(int b=1;b<=6;b++){
            for(int c=1;c<=6;c++){
                if(a+b+c==n){
                    printf("%i%i%i \n",a,b,c);
                }
            }
        }
    }
    return 0;
}
int isperfect(int n){
     int somme=0;
        for(int t=1;t<n;t++){
            if(n%t==0){
                somme+=t;
            }
        }
        if (somme==n){
            return 1;
        }
        return 0;

}

void nombreparfait(int n){
    for (int i=0;i<n;i++){
        int res=isperfect(i);
        if(res==1){
            printf("Le nombre %i est parfait \n",i);
        }

    }

}
typedef long TypeEntier;

TypeEntier factorielle(TypeEntier n){
    int res=1;
    if(n==0||n==1){
        return res;
    }
    for (int i=2;i<=n;i++){
        res*=i;
    }
    return res;

}

int main (void){
    nombreparfait(1000);
    int a=15;
    for(TypeEntier i=0;i<=a;i++){
        printf("%li!= %li \n",i,factorielle(i));
    }
    return 0;

}