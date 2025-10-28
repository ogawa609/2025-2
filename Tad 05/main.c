#include <stdio.h>
#include <string.h>
#include "conta.h"
#include "usuario.h"

int main(){

    int maximo;
    scanf("%d",&maximo);
    int posicao=0;

    tConta contas[maximo];

    int operacao=-1;

    while(1){
        scanf("%d",&operacao);

        if(operacao==0){
            break;
        }
        else if(operacao==1){

            int conta;
            scanf("%d",&conta);
            float valor;
            scanf("%f",&valor);

            for(int i=0;i<maximo;i++){
                if(VerificaConta(contas[i],conta)){

                   contas[i]= SaqueConta(contas[i],valor);
                }
            }
        }

        else if(operacao==2){

            int conta;
            scanf("%d",&conta);
            float valor;
            scanf("%f",&valor);

            for(int i=0;i<maximo;i++){
                if(VerificaConta(contas[i],conta)){

                   contas[i]= DepositoConta(contas[i],valor);
                }
            }
        }

        else if(operacao==3){

            char nome[50];
            char cpf[15];
            int conta;
            int verifica=1;

            for(int i=0;i<maximo;i++){
                if(VerificaConta(contas[i],conta)){

                   verifica=0;
                }
            }

            if(verifica){
            scanf("%s ",nome);
            scanf("%s",cpf);
            scanf("%d\n",&conta);

            tUsuario user;
           user= CriaUsuario(nome,cpf);

           contas[posicao]=CriaConta(conta,user);
           posicao++;
            }

        }

        else if(operacao==4){

            printf("===| Imprimindo Relatorio |===\n");

             for(int i=0;i<maximo;i++){
               
                ImprimeConta(contas[i]);
               
            }
        }
    }
}