#include <stdio.h>
#include "aluno.h"
#include <string.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
    tAluno a;
    a.matricula=matricula;
    a.n1=n1;
    a.n2=n2;
    a.n3=n3;
    strcmp(a.nome,nome);

    return a;
}

tAluno LeAluno(){

    int matricula, n1,n2,n3;
    char nome[50];

    scanf("%[^\n]\n",nome);
    scanf("%d %d %d %d",&matricula,&n1,&n2,&n3);

    tAluno aluno= CriaAluno(nome,matricula,n1,n2,n3);
}
int ComparaMatricula(tAluno aluno1, tAluno aluno2){

    if(aluno1.matricula>aluno2.matricula){
        return 1;
    }

    return -1;
}


int CalculaMediaAluno(tAluno aluno){

    int media=aluno.n1+aluno.n2+aluno.n3;
    media=media/3;

return media;

}
int VerificaAprovacao(tAluno aluno){

    int media=CalculaMediaAluno(aluno);

    if(media>=7){
        return 1;
    }

    return 0;
}

void ImprimeAluno(tAluno aluno){
    printf("%s\n",aluno.nome);
}
