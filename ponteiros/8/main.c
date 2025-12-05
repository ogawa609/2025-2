#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tDepartamento.h"

int main(){

    int n;
    scanf("%d",&n);
    tDepartamento d[n];
     char nome[STRING_MAX];
        char curso1[STRING_MAX];
        char curso2[STRING_MAX];
        char curso3[STRING_MAX];
        int m1,m2,m3;
        char diretor[STRING_MAX];

    for(int i=0;i<n;i++){

       scanf("%s",nome);
       scanf("%s",diretor);
       scanf("%s",curso1);
       scanf("%s",curso2);
       scanf("%s",curso3);
       scanf("%d %d %d",&m1,&m2,&m3);

       if(m1<0||m2<0||m3<0){
        printf("Digite um departamento com médias válidas\n");
        i--;
        continue;
       }
       else{
       d[i] =CriaDepartamento(curso1,curso2,curso3,nome,m1,m2,m3,diretor);
       }
    }

    OrdenaDepartamentosPorMedia(d,n);
    for(int i=0;i<n;i++){
        ImprimeAtributosDepartamento(d[i]);
    }

    return 0;
}