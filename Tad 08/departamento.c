#include <stdio.h>
#include <string.h>
#include "departamento.h"
#include <math.h>

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){

    tDepartamento d;
    strcpy(d.c1,c1);
    strcpy(d.c2,c2);
    strcpy(d.c3,c3);
    strcpy(d.nome,nome);
    d.m1=m1;
    d.m2=m2;
    d.m3=m3;
    strcpy(d.diretor,diretor);
    d.media_geral=0;
    

    return d;

}
void imprimeAtributosDepartamento (tDepartamento depto){
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n",depto.nome);
    printf("diretor => %s\n",depto.diretor);
    printf("curso1 => %s, media1 => %d\n",depto.c1,depto.m1);
    printf("curso2 => %s, media2 => %d\n",depto.c2,depto.m2);
    printf("curso1 => %s, media1 => %d\n",depto.c1,depto.m3);
    printf("media geral => %.2f\n",depto.media_geral);
    printf ("desvio padrao => ");

}   

int validaMediaDepartamento (int media){
    if(media>0&&media<=10){
        return 1;
    }

    return 0;
}


double calculaDesvioPadraoDepartamento(tDepartamento depto){

    double soma=0;
    double media=(depto.m1+depto.m2+depto.m3)/3.0;
    int n[3];
    n[0]=depto.m1;
    n[1]=depto.m2;
    n[2]=depto.m3;

    for(int i=0;i<3;i++){
        soma+=((n[i]-media)*(n[i]-media));
    }
    soma=soma/3.0;
    soma=sqrt(soma);

    return soma;
}
double calculaMediaGeralDepartamento(tDepartamento depto){

    double media=0;
    double soma=depto.m1+depto.m2+depto.m3;
    media = soma/3.0;

    return media;

}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){

    for (int i=0;i<tamanho;i++){

        for(int j=i+1;j<tamanho;j++){
            if(d[i].media_geral<d[j].media_geral){

                tDepartamento de=d[i];
                d[i]=d[j];
                d[j]=de;
            }

        }
        
    }
}
