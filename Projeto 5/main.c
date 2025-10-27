#include <stdio.h>
#include <string.h>
#include "lesao.h"
#include "constantes.h"
#include "data.h"
#include "paciente.h"
#include "utils.h"

int main(int argc, char const *argv[]){

   char comando=0;
   tPaciente pacientes[MAX_TAM_PACIENTES];
   int quant_pacientes=0;

   while(1){

    scanf("%c\n",&comando);

    if(comando=='F'){
        break;
    }

    if(comando=='P'){
        if(quant_pacientes<MAX_TAM_PACIENTES){
            tPaciente p= lePaciente();
            char sus[MAX_TAM_SUS];
            obtemCartaoSusPaciente(p,sus);
            int verifica=1;

            for(int i=0;i<quant_pacientes;i++){
                char sus2[MAX_TAM_SUS];
                obtemCartaoSusPaciente(pacientes[i],sus2);

                if(!strcmp(sus,sus2)){
                    verifica=0;
                }
            }
            if(verifica){
            pacientes[quant_pacientes]= p;
            quant_pacientes++;
            }
        }
    }

    if(comando=='L'){

        tLesao les= leLesao();
        associaLesaoPaciente(pacientes,quant_pacientes,les);
        
    }
   }


   int media=0;
   int soma=0;
   int cirurgias=0;
   int lesoes;

   if(quant_pacientes>0){

for(int i=0;i<quant_pacientes;i++){

    soma+=obtemIdadePaciente(pacientes[i]);
     tLesao l[obtemQuatidadeLesoesPaciente(pacientes[i])];
     lesoes+=obtemQuatidadeLesoesPaciente(pacientes[i]);
    obtemLesoesPaciente(pacientes[i],l,obtemQuatidadeLesoesPaciente(pacientes[i]));

    for(int j=0;j<obtemQuatidadeLesoesPaciente(pacientes[i]);j++){

        if(chanceCirirgiaLesao(l[j])){
            cirurgias++;
        }
    }
}

media=soma/quant_pacientes;

printf("TOTAL PACIENTES: %d\n",quant_pacientes);
printf("MEDIA IDADE (ANOS): %d\n",media);
printf("TOTAL LESOES: %d\n",lesoes);
printf("TOTAL CIRURGIAS: %d\n",cirurgias);
printf("LISTA DE PACIENTES:\n");

for(int i=0;i<quant_pacientes;i++){

        printPaciente(pacientes[i]);
    
}
   }

return 0;

}