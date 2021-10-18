#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct matrix{
    int nbcol;
    int nblig;
    int **mat;
};
typedef struct matrix Matrix;
struct matrixArray{
    Matrix *tab;
};
typedef struct matrixArray MatrixArray;

Matrix readMatrix(int nblignes,int nbcolo){
    int tmp=0;
    Matrix matrice;
    matrice.mat=(int**)malloc(sizeof(int)*nbcolo*nblignes);
    matrice.mat[0]=(int*)malloc(sizeof(int)*nbcolo*nblignes);
    for(int l=0;l<nblignes;l++){
        for(int c=0;c<nbcolo;c++){
            scanf("%i",&tmp);
          // matrice.mat[l][c]=tmp;
        }
        scanf("\n");
    }
    matrice.nbcol=nbcolo;
    matrice.nblig=nblignes;
    return matrice;
}

void readMatrixArray(MatrixArray *matArr,int nb){
    int nbco,nbli;
    matArr->tab= calloc(sizeof(MatrixArray),nb);
    for (int i=0;i<nb;i++){
        scanf("%i %i\n",&nbli,&nbco);
        printf("%i %i\n",nbli,nbco);
        matArr->tab[i]=readMatrix(nbli,nbco);
    }

}
void printMatrixArray(MatrixArray matA,int nb){
    printf("%i\n",nb);
    for (int i=0;i<nb;i++){
        printf("%i %i\n",matA.tab[i].nblig,matA.tab[i].nbcol);
        for (int l=0;l<matA.tab[i].nblig;l++){
            for(int c=0;c<matA.tab[i].nbcol;c++){
                printf("%i",matA.tab[i].mat[l][c]);
            }
            printf("\n");
        }
    }
}
Matrix transposeMat(Matrix mat){
    Matrix transpose;
    transpose.mat=malloc(mat.nbcol*mat.nblig);
        for(int i = 0; i < mat.nblig; i++)
    {
        for(int j = 0; j < mat.nbcol; j++)
        {
            transpose.mat[j][i] = mat.mat[i][j];
        }
    }
    transpose.nbcol=mat.nblig;
    transpose.nblig=mat.nbcol;

    return transpose;
}
MatrixArray rotate90ccw(MatrixArray mA, int nbMat){
    MatrixArray Transpose;
    Transpose.tab=malloc(sizeof(MatrixArray)*nbMat);
    for(int i=0;i<nbMat;i++){
        Transpose.tab[i]=transposeMat(mA.tab[i]);
        
    }
    return Transpose;
}

int main(void){

    int nbMat;
    scanf("%i\n",&nbMat);
    MatrixArray mA;
    readMatrixArray(&mA,nbMat);
    printMatrixArray(mA,nbMat);
    free(mA.tab);



    return 0;
}