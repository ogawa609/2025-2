#include "matriz.h"

void soma(int l1,int c1,int l2,int c2, int A[l1][c1],int B[l2][c2],int R[l1][c1]){

    if(l1==l2&&c1==c2){
    for(int i=0;i<l1; i++){
        for(int j=0;j<c1;j++){

            R[i][j]=A[i][j]+B[i][j];
        }
    }

     for(int i=0;i<l1; i++){
        printf("|");
        for(int j=0;j<c1;j++){
            
            if(j<c1-1){
            printf("%d ",R[i][j]);
            }
            else{
                 printf("%d",R[i][j]);
            }
        }
        printf("|\n");
    }
}
else{
    printf("Erro: as dimensoes da matriz nao correspondem\n");
}
}

void subtrai(int l1,int c1,int l2,int c2, int A[l1][c1],int B[l2][c2],int R[l1][c1]){

     if(l1==l2&&c1==c2){
     for(int i=0;i<l1; i++){
        for(int j=0;j<c1;j++){

            R[i][j]=A[i][j]-B[i][j];
        }
    }

    for(int i=0;i<l1; i++){
        printf("|");
        for(int j=0;j<c1;j++){
            
            if(j<c1-1){
            printf("%d ",R[i][j]);
            }
            else{
                 printf("%d",R[i][j]);
            }
        }
        printf("|\n");
    }
}
else{
    printf("Erro: as dimensoes da matriz nao correspondem\n");
}
}

void multiplicacao(int l1,int c1, int l2, int c2, int A[l1][c1],int B[l2][c2],int R[l1][c2]){

    if(l2==c1){
    for(int i=0;i<l1;i++){
        for(int j=0;j<c2;j++){

            R[i][j]=0;

            for(int k=0;k<c1;k++){

                R[i][j]+=A[i][k]*B[k][j];

            }
           
        }
    }

    for(int i=0;i<l1; i++){
        printf("|");
        for(int j=0;j<c2;j++){
            
            if(j<c2-1){
            printf("%d ",R[i][j]);
            }
            else{
                 printf("%d",R[i][j]);
            }
        }
        printf("|\n");
    }
}

else{
    printf("Erro: as dimensoes da matriz nao correspondem\n");
}
}

void multEscalar(int k,int linha, int coluna, int A[linha][coluna],int R[linha][coluna]){

    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){

            R[i][j]=k*A[i][j];
        }
    }

    for(int i=0;i<linha; i++){
        printf("|");
        for(int j=0;j<coluna;j++){
            
            if(j<coluna-1){
            printf("%d ",R[i][j]);
            }
            else{
                 printf("%d",R[i][j]);
            }
        }
        printf("|\n");
    }


}

void transposta(int l1, int c1,int l2,int c2, int A[l1][c1],int B[l2][c2], int T1[c1][l1],int T2[c2][l2]){

    for(int i=0;i<c1;i++){
        for(int j=0;j<l1;j++){

            T1[i][j]=A[j][i];
        }
    }

    for(int i=0;i<c2;i++){
        for(int j=0;j<l2;j++){

            T2[i][j]=B[j][i];
        }
    }

    for(int i=0;i<l1; i++){
        printf("|");
        for(int j=0;j<c1;j++){
            
            if(j<c1-1){
            printf("%d ",T1[i][j]);
            }
            else{
                 printf("%d",T1[i][j]);
            }
        }
        printf("|\n");
    }

    for(int i=0;i<l2; i++){
        printf("|");
        for(int j=0;j<c2;j++){
            
            if(j<c2-1){
            printf("%d ",T2[i][j]);
            }
            else{
                 printf("%d",T2[i][j]);
            }
        }
        printf("|\n");
    }
}


void ImprimirMenu(){

    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");
}

void LeMatriz(int linha, int coluna, int matriz[linha][coluna]){

    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){

            scanf("%d",&matriz[i][j]);
        }
    }
}

void Opcao(int op,int l1,int c1, int l2, int c2, int a[l1][c1],int b[l2][c2]){

    if(op==1){

        int I[l1][c1];
        soma(l1,c1,l2,c2,a,b,I);
    }

    else if(op==2){
        int H[l1][c1];
        subtrai(l1,c1,l2,c2,a,b,H);
    }

    else if(op==3){
        int G[l1][c2];
        multiplicacao(l1,c1,l2,c2,a,b,G);
    }

    else if(op==4){
        int mult, M;
        scanf("%d %d",&mult,&M);

        if(M==1){
            int R[l1][c1];
            multEscalar(mult,l1,c1,a,R);
        }
        else if(M==2){
            int F[l2][c2];
            multEscalar(mult,l2,c2,b,F);
        }
    }

    else if(op==5){
        int T1[c1][l1];
        int T2[c2][l2];
        transposta(l1,c1,l2,c2,a,b,T1,T2);
    }
}