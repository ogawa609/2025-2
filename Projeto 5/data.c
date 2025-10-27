#include "data.h"
#include <stdio.h>

tData leData(){

    tData d;
    scanf("%d/%d/%d\n",&d.dia,&d.mes,&d.ano);
}

void printData(tData d){

    printf("%02d/%02d/%04d\n",d.dia,d.mes,d.ano);
}
//retorna idade
int retornaAno(tData inicio){
    tData hoje;
    hoje.ano=2024;
    hoje.mes=04;
    hoje.dia=03;
    int idade;
    if(inicio.mes<hoje.mes){
        idade=(hoje.ano-inicio.ano)-1;
    }
    else if(inicio.mes==hoje.mes){
        if(inicio.dia>=hoje.dia){
            idade=hoje.ano-inicio.ano;
        }
        else{
             idade=(hoje.ano-inicio.ano)-1;
        }
    }

    else{
        idade=hoje.ano-inicio.ano;
    }

    return idade;

}

