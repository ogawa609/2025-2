#include "utils.h"
#include <string.h>

void associaLesaoPaciente(tPaciente *pacs, int qtdPacientes, tLesao les){

    char susP[MAX_TAM_SUS],susL[MAX_TAM_SUS];
    obtemCartaoSusLesao(les,susL);

    for(int i=0;i<qtdPacientes;i++){
        obtemCartaoSusPaciente(pacs[i],susP);

        if(!strcmp(susP,susL)){

           pacs[i]= insereLesaoPaciente(pacs[i],les);
           return;
        }
    }
}