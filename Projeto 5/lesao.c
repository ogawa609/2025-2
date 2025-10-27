#include <stdio.h>
#include <string.h>
#include "lesao.h"

tLesao leLesao(){
tLesao les;
    scanf("%[^\n]\n",les.cartaoSus);
        scanf("%[^\n]\n",les.idLesao);
            scanf("%[^\n]\n",les.diagnostico);
                scanf("%[^\n]\n",les.regiaoCorpo);
                    scanf("%d",&les.malignidade);

                    return les;
}

void printLesao(tLesao *les, int qtdLesoes){
    for(int i=0;i<qtdLesoes;i++){
        printf("%s ",les[i].idLesao);
    }

}

void obtemCartaoSusLesao(tLesao les, char cartaoSus[]){
    strcpy(cartaoSus,les.cartaoSus);
}

int chanceCirirgiaLesao(tLesao les){
    if(les.malignidade>50){
        return 1;

    }

    return 0;
}


