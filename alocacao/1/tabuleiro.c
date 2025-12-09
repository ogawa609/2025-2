#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro(){

    tTabuleiro *tabuleiro = malloc(sizeof(tTabuleiro));

    if(tabuleiro==NULL){

        exit(1);
    }

   tabuleiro->posicoes=malloc(3*sizeof(char*));

   if(tabuleiro->posicoes==NULL){

    exit(1);
}

   for(int i=0;i<3;i++){

    tabuleiro->posicoes[i]=malloc(3*sizeof(char));

    if(tabuleiro->posicoes[i]==NULL){

        exit(1);
    }

    
   }

   for(int i=0;i<3;i++){

    for(int j=0;j<3;j++){
    tabuleiro->posicoes[i][j]='-';
    }
   }
    
    

    return tabuleiro;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro){

for(int i=0;i<3;i++){
    free(tabuleiro->posicoes[i]);
}
free(tabuleiro->posicoes);
free(tabuleiro);
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    char p;
    if(peca==1){
        p='x';
    }
    else if(peca==2){
        p='0';
    }

    tabuleiro->posicoes[x][y]=p;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            if(tabuleiro->posicoes[i][j]=='-'){

                return 1;

            }
        }
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){

    if(peca==1){

        if(tabuleiro->posicoes[x][y]=='X'){

            return 1;
        }
        else{
            return 0;
        }
    }

    else if(peca==2){

        if(tabuleiro->posicoes[x][y]=='0'){

            return 1;
        }
        else{
            return 0;
        }

    }
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){

    if(tabuleiro->posicoes[x][y]=='-'){

        return 1;
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y){

    if(x>=0&&x<3&&y>=0&&y<3){
        return 1;
    }

    return 0;
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro){

    for (int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            printf("%c",tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}