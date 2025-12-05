#include<stdio.h>
#include <stdlib.h>
#include "tDepartamento.h"
#include <string.h>

// 1o curso: CC
	//Media do 1o curso: 10
	//2o curso: EC
	//Media do 2o curso: 7
	//3o curso: SI
	//Media do 3o curso: 5
	//Media dos cursos: 7.33

tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor ){
tDepartamento d;
strcpy(d.curso1,curso1);
strcpy(d.curso2,curso2);
strcpy(d.curso3,curso3);
strcpy(d.nome,nome);
strcpy(d.diretor,diretor);
d.m1=m1;
d.m2=m2;
d.m3=m3;
return d;
                                }


void ImprimeAtributosDepartamento(tDepartamento depto){

    printf("Departamento: %s\n",depto.nome);
    printf("Diretor: %s\n",depto.diretor);
    printf("1o curso: %s\n",depto.curso1);
     printf("Media do 1o curso: %d\n",depto.m1);
      printf("2o curso: %s\n",depto.curso2);
      printf("Media do 2o curso:: %d\n",depto.m2);
            printf("3o curso: %s\n",depto.curso3);
                  printf("Media do 3o curso:: %d\n",depto.m3);

                  float soma= depto.m1+depto.m2+depto.m3;
                  float media= soma/3.0;
                  printf("Media dos cursos: %f\n",media);
}
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){

    tDepartamento temp;
    for(int i=0;i<num_deptos;i++){

       float soma= vetor_deptos[i].m1+vetor_deptos[i].m2+vetor_deptos[i].m3;
       float media=soma/3.0;

       for(int j=i+1;j<num_deptos;j++){

        float soma2= vetor_deptos[j].m1+vetor_deptos[j].m2+vetor_deptos[j].m3;
        float media2=soma2/3.0;

        if(media<media2){

            temp=vetor_deptos[i];
            vetor_deptos[i]=vetor_deptos[j];
            vetor_deptos[j]=temp;
        }
       }
        
    }
}
