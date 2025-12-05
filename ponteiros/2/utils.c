#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void LeIntervalo(int * m, int * n){

    scanf("%d %d",m,n);
}
int EhPrimo(int n){

    if(n==1||n==0){
        return 0;
    }
    else if(n==2||n==3){
        return 1;
    }
    else{

        for(int i=2;i<=n/2;i++){

            if(n%i==0){
                return 0;
            }
        }
    }

    return 1;
}
void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
*maior=m;
*menor=m;
    for(int i=m;i<=n;i++){

        if(EhPrimo(i)){
        if(*maior<i){
            *maior=i;
        }
        if(*menor>i){
            *menor=i;
        }
    }
    }
}