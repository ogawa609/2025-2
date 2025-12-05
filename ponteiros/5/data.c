#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data){

    data->dia=dia;
    data->mes=mes;
    data->ano=ano;
}
void LeData( tData *data ){
    int dia,mes,ano;

    scanf("%2d/%2d/%4d",&dia,&mes,&ano);

    InicializaDataParam(dia,mes,ano,data);
}

void ImprimeData( tData *data ){

    printf("%02d/%02d/%04d",data->dia,data->mes,data->ano);

}
int EhBissexto( tData *data ){

    int ano= data->ano;
    if(ano%400==0||ano%4==0){
        return 1;
    }

    return 0;
}

int InformaQtdDiasNoMes( tData *data ){

    int mes = data->mes;
    
    if(mes==4||mes==6||mes==9||mes==11){
        return 30;
    }
    else if(mes==2){
        if(EhBissexto(data)){
            return 29;
        }
        else {
            return 28;
        }
    }
    else {

        return 31;
    }
}
void AvancaParaDiaSeguinte( tData *data ){

    int dia=data->dia;
    int mes=data->mes;

    if(dia<InformaQtdDiasNoMes(data)){

        data->dia++;
    }
    else if(dia==InformaQtdDiasNoMes(data)){
        data->dia=1;
        data->mes++;
    }
}
int EhIgual( tData *data1, tData *data2 ){

    if(data1->ano==data2->ano){
        if(data1->mes==data2->mes){

            if(data1->dia==data2->dia){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
