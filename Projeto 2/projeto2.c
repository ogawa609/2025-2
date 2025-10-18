#include <stdio.h>
#include "matriz.h"

int main(){

    int l1,c1,l2,c2;

    scanf("%d %d",&l1,&c1);
    scanf("%d %d",&l2,&c2);
    int M1[l1][c1];
    int M2[l2][c2];

    LeMatriz(l1,c1,M1);
    LeMatriz(l2,c2,M2);

    int opcao;
    while(1){

        ImprimirMenu();
        scanf("%d",&opcao);

        if(opcao<6){

            Opcao(opcao,l1,c1,l2,c2,M1,M2);
        }

        else{
            return 0;
        }
    }
}