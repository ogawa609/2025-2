#include <stdio.h>
#include "data.h"

int main(){
int dia=0,mes=0,ano=0;
scanf("%d/%d/%d",&dia,&mes,&ano);
tData d1=CriaData(dia,mes,ano);
dia=0;
mes=0;
ano=0;
scanf("%d/%d/%d",&dia,&mes,&ano);
tData d2=CriaData(dia,mes,ano);

if(!(VerificaDataValida(d1)&&VerificaDataValida(d2))){
    printf("A primeira e/ou segunda data(s) invalida(s)\n");
    return 0;
}

printf("Primeira data: ");
ImprimeDataExtenso(d1);

printf("Segunda data: ");
ImprimeDataExtenso(d2);

if(ComparaData(d1,d2)==-1){

    printf("A primeira data eh mais antiga\n");
}
else if(ComparaData(d1,d2)==1){

    printf("A segunda data eh mais antiga\n");
}
else{
    printf("As datas sao iguais\n");
}

int quantidade=CalculaDiferencaDias(d1,d2);
printf("A diferenca em dias entre as datas eh: %02d dias",quantidade);

    return 0;
}