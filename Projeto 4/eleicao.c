#include <stdio.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"

tEleicao InicializaEleicao(){
    tEleicao eleicao;
    eleicao.votosNulosPresidente=0;
    eleicao.votosNulosGovernador=0;
    eleicao.votosBrancosPresidente=0;
    eleicao.votosBrancosGovernador=0;
    eleicao.totalEleitores=0;
    eleicao.totalGovernadores=0;
    eleicao.votosBrancosGovernador=0;
    
    int totalcandidatos;
    tCandidato temp;

    scanf("%d",&totalcandidatos);

    for(int i=0;i<totalcandidatos;i++){

        temp=LeCandidato();

        if(temp.cargo=='P'){

            eleicao.presidentes[eleicao.totalPresidentes]=temp;
            eleicao.totalPresidentes++;
        }
        else if(temp.cargo=='G'){

            eleicao.governadores[eleicao.totalGovernadores]=temp;
            eleicao.totalGovernadores++;
        }

    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){

    int totaleleitores;
    scanf("%d",&totaleleitores);

    if(totaleleitores<=10){

        tEleitor temp;
        for(int i=0;i<totaleleitores;i++){

            temp=LeEleitor();
            int confirma=1;
            int nuloP=1;
            int nuloG=1;

            for(int j=0;j<eleicao.totalEleitores;j++){

                

                if(EhMesmoEleitor(temp,eleicao.eleitores[i])){

                    
                    confirma=0;
                    eleicao.votosNulosPresidente=-1;
            
                }
            }

            if(confirma){

                eleicao.eleitores[eleicao.totalEleitores]=temp;
                eleicao.totalEleitores++;

                if(temp.votoP==0){
                    eleicao.votosBrancosPresidente++;
                }

                else{

                    for(int p=0;p<eleicao.totalPresidentes;p++){

                        if(VerificaIdCandidato(eleicao.presidentes[p],temp.id)){

                            eleicao.presidentes[p]=IncrementaVotoCandidato(eleicao.presidentes[p]);
                            nuloP=0;
                        }
                    }

                    if(nuloP){
                        eleicao.votosNulosPresidente++;
                    }
                }

                if(temp.votoG==0){

                    eleicao.votosBrancosGovernador++;
                }
                else{

                    for(int g=0;g<eleicao.totalGovernadores;g++){

                        if(VerificaIdCandidato(eleicao.governadores[g],temp.id)){

                            eleicao.presidentes[g]=IncrementaVotoCandidato(eleicao.governadores[g]);
                            nuloG=0;
                        }
                    }

                    if(nuloG){
                        eleicao.votosNulosGovernador++;
                    }
                }


            }
        }
    }

    else{

        eleicao.votosNulosPresidente=-1;
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){

    int maior=0;
    int p=0;
    int empateP=0;
    int empateG=0;
    
    for (int i=0;i<eleicao.totalPresidentes;i++){

        if(maior<eleicao.presidentes[i].votos){

            maior=eleicao.presidentes[i].votos;
            p=i;

        }
    }
maior=0;
int g=0;

    for(int j=0;j<eleicao.totalGovernadores;j++){

        if(maior<eleicao.governadores[j].votos){

            maior=eleicao.governadores[j].votos;
            g=j;

        }
    }

    int cont=0;
    for(int i=0;i<eleicao.totalPresidentes;i++){

        if(eleicao.presidentes[i].votos==eleicao.presidentes[p].votos){
            cont++;
        }
    }
    if(cont>1){
        empateP=1;
    }

    cont=0;
    for(int i=0;i<eleicao.totalGovernadores;i++){

        if(eleicao.governadores[i].votos==eleicao.governadores[g].votos){
            cont++;
        }
    }
    if(cont>1){
        empateG=1;
    }


    if(eleicao.votosNulosPresidente=-1||eleicao.votosNulosGovernador==-1){
        printf("ELEICAO ANULADA\n");
        return 0;
    }

    else if(eleicao.presidentes[p].votos<eleicao.votosBrancosPresidente+eleicao.votosNulosPresidente){

        printf("PRESIDENTE ELEITO: SEM DECISAO\n");

    }

    else{

        
    }

}
