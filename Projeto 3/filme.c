#include <stdio.h>
#include "filme.h"
#include <string.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme filme;

    strcpy(filme.nome,nome);
    filme.codigo=codigo;
    filme.valor=valor;
    filme.qtdEstoque=quantidade;

    return filme;

}
tFilme leFilme(int codigo){
    tFilme f;
    char nome[MAX_CARACTERES];
    int valor;
    int estoque;
    scanf(",%[^,],%d,%d\n",nome,&valor,&estoque);
    f=criarFilme(nome,codigo,valor,estoque);
    return f;
}
int obterCodigoFilme (tFilme filme){

    return filme.codigo;
}
void imprimirNomeFilme (tFilme filme);

int obterValorFilme (tFilme filme){
    return filme.valor;
}
int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada;
}


int ehMesmoCodigoFilme (tFilme filme, int codigo){

    if(filme.codigo==codigo){
        return 1;
    }
    return 0;
}
tFilme alugarFilme (tFilme filme){

    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}
tFilme devolverFilme (tFilme filme){
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}
int compararNomesFilmes (tFilme filme1, tFilme filme2){
    if(strcmp(filme1.nome,filme2.nome)){
        return 0;

    }

    else if(strlen(filme1.nome)<strlen(filme2.nome)){
        return -1;
    }

    else if(strlen(filme1.nome)>strlen(filme2.nome)){
        return 1;
    }
}
