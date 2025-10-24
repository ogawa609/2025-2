#include <stdio.h>
#include <string.h>
#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato c;
    strcpy(c.nome,nome);
    strcpy(c.partido,partido);
    c.cargo=cargo;
    c.id=id;
    c.votos=0;

    return c;
}

tCandidato LeCandidato(){

    tCandidato C;
    char nome[50];
    char partido[50];
    char cargo;
    int id;

    scanf("%[^,], %[^,], %c,%d\n",nome,partido,&cargo,&id);
    C=CriaCandidato(nome,partido,cargo,id);

    return C;
}

int VerificaIdCandidato(tCandidato candidato, int id){

    if(candidato.id==id){
        return 1;
    }

    return 0;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){

    if(candidato1.id==candidato2.id){
        return 1;
    }
    return 0;
}

char ObtemCargo(tCandidato candidato){

    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){

    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){

    float porcentagem=0;

    if (totalVotos > 0) {
        porcentagem = ((float)candidato.votos / totalVotos) * 100;
    }
    return porcentagem;
}
void ImprimeCandidato (tCandidato candidato, float percentualVotos){

    printf("%s (%s), %d voto(s), %.2d%\n",candidato.nome,candidato.partido,candidato.votos,percentualVotos);
}
