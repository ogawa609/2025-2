#include <stdio.h>
#include "departamento.h"

int main(){

    int N;
    tDepartamento d[N];
    char nome[STRING_MAX];
    char diretor[STRING_MAX];
    char c1[STRING_MAX];
    char c2[STRING_MAX];
    char c3[STRING_MAX];
    int m1=0,m2=0,m3=0;

    for(int i=0;i<N;i++){

        scanf(" %[^\n]\n",nome);
        scanf(" %[^\n]\n",diretor);
        scanf(" %[^\n]\n",c1);
        scanf(" %[^\n]\n",c2);
        scanf(" %[^\n]",c3);
        scanf("%d %d %d",&m1,&m2,&m3);

        if(validaMediaDepartamento(m1)&&validaMediaDepartamento(m2)&&validaMediaDepartamento(m3)){

             d[i]=criaDepartamento(c1,c2,c3,nome,m1,m2,m3,diretor);
             d[i].media_geral=calculaMediaGeralDepartamento(d[i]);
        }
       
    }

    ordenaPorMediaDepartamentos(d,N);

     for(int i=0;i<N;i++){

       imprimeAtributosDepartamento(d[i]);
       double dp=calculaDesvioPadraoDepartamento(d[i]);
       printf("%.2f\n",dp);
       printf("\n");
       
    }

   return 0;
}