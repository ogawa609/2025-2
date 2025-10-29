#include <stdio.h>
#include "matrix_utils.h"

//1 - Somar matrizes
//2 - Subtrair matrizes
//3 - Multiplicar matrizes
//4 - Multiplicacao de uma matriz por escalar
//5 - Transposta de uma matriz
//6 - Encerrar o programa
//Opcao escolhida: 

int main(){

    tMatrix m1,m2;

    m1=MatrixRead(m1);
    m2=MatrixRead(m2);
    int com;

    while(1){

        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        scanf("%d",&com);


        if(com==1){
            if(PossibleMatrixSum(m1,m2)){

                tMatrix m3=MatrixAdd(m1,m2);
                MatrixPrint(m3);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        }
        else if(com==2){

            if(PossibleMatrixSub(m1,m2)){

                tMatrix m3=MatrixSub(m1,m2);
                MatrixPrint(m3);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        }
        else if(com==3){
            if(PossibleMatrixMultiply(m1,m2)){

                tMatrix m3=MatrixMultiply(m1,m2);
                MatrixPrint(m3);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        }
        else if(com==4){
            int esc=0,m=0;
            scanf("%d %d",&esc,&m);

            if(m==1){
                m1=MatrixMultiplyByScalar(m1,esc);
                MatrixPrint(m1);
            }
            else if(m==2){
                m2=MatrixMultiplyByScalar(m2,esc);
                MatrixPrint(m2);
            }
            
        }
        else if(com==5){

           tMatrix m11=TransposeMatrix(m1);
           tMatrix m22=TransposeMatrix(m2);

           MatrixPrint(m1);
           MatrixPrint(m2);
        }
        else if(com==6){
            break;
        }
        
    }
return 0;

}