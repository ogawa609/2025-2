#include <stdio.h>
#include <string.h>
#include "aluno.h"

int main(){

    int total=0;
    scanf("%d",&total);
    tAluno alunos[total];

    for(int i=0;i<total;i++){

        alunos[i]=LeAluno();
    }

    for(int i=0;i<total;i++){

        for(int j=i+1;j<total;j++){
            if(ComparaMatricula(alunos[i],alunos[j])){

                tAluno t=alunos[j];
                alunos[j]=alunos[i];
                alunos[i]=t;
            }
        }
    }

    for(int i=0;i<total;i++){

        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
    }

    return 0;
}