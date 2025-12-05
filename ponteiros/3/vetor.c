#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void LeDadosParaVetor(int * vet, int tam){

    for(int i=0;i<tam;i++){

        scanf("%d",vet+i);
    }
}

void ImprimeDadosDoVetor(int * n, int tam){

    for(int i=0;i<tam;i++){

        printf("%d ",n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){

    int menor= vet[0];
    for(int i=0;i<tam;i++){
        if(vet[i]<menor){
            menor=vet[i];
        }
    }

    *paraTrocar=menor;

}
void OrdeneCrescente(int * vet, int tam){

    for (int i=0;i<tam;i++){

        for(int j=i+1;j<tam;j++){
            
            if(vet[i]>vet[j]){
                int t=vet[i];
                vet[i]=vet[j];
                vet[j]=t;
            }
        }
    }
}
