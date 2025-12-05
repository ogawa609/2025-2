#include <stdio.h>
#include <stdlib.h>
#include "evento.h"
#include <string.h>

void cadastrarEvento(Evento* eventos, int* numEventos){
    char nome[50];
    int dia, mes,ano;

    scanf("%s",nome);
    scanf("%d/%d/%d",&dia,&mes,&ano);

    if(*numEventos<10){
        eventos[*numEventos].dia=dia;
         eventos[*numEventos].mes=mes;
          eventos[*numEventos].ano=ano;
          strcpy(eventos[*numEventos].nome,nome);
          (*numEventos)++;
          printf("Evento cadastrado com sucesso!\n");

    }
}
void exibirEventos(Evento* eventos, int* numEventos){

    if(*numEventos==0){

        printf("Nenhum evento cadastrado.\n");
    }
    else{
        printf("Eventos cadastrados:\n");
    for(int i=0;i<*numEventos;i++){

         printf("%d - %s - %02d/%02d/%4d\n",i,eventos[i].nome,eventos[i].dia,eventos[i].mes,eventos[i].ano);
    }
}
   
}


void trocarDataEvento(Evento* eventos, int* numEventos){
    int numero;
    scanf("%d",&numero);

    if(numero<=*numEventos&&numero>=0){

    int dia,mes,ano;
    scanf("%d/%d/%d",&dia,&mes,&ano);

    eventos[numero].dia=dia;
    eventos[numero].mes=mes;
    eventos[numero].ano=ano;
    printf("Eventos trocados com sucesso!\n");
    }
    else{
        printf("Indice invalido!\n");
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){

    if((*indiceA<=*numEventos)&&(*indiceB<=*numEventos)){
    Evento temp;
    temp= eventos[*indiceA];
    eventos[*indiceA]=eventos[*indiceB];
    eventos[*indiceB]=temp;
    printf("Eventos trocados com sucesso!\n");
    }
    else{
        printf("Indices invalidos!\n");
    }
}
