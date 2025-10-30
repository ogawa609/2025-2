#include <stdio.h>
#include "data.h"

tData CriaData(int dia, int mes, int ano){
    tData d;
    d.ano=ano;
    d.dia=dia;
    d.mes=mes;

    return d;
}

int VerificaDataValida(tData data){

    if(data.mes>0&&data.mes<13){

        if(data.mes==4||data.mes==6||data.mes==9||data.mes==11){
            if(data.dia>0&&data.dia<31){
                return 1;
            }
            else{
                return 0;
            }
        }

        else if(data.mes==2){

            if(VerificaBissexto(data)){

                if(data.dia>0&&data.dia<30){

                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                if(data.dia>0&&data.dia<29){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }

        else{
            if(data.dia>0&&data.dia<32){
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    return 0;
}

void ImprimeMesExtenso(tData data){

    int mes=data.mes;

    if(mes==1){
        printf("Janeiro ");
    }
    else if(mes==2){
        printf("Fevereiro ");
    }
    else if(mes==3){
        printf("Marco ");
    }
    else if(mes==4){
        printf("Abril ");
    }
    else if(mes==5){
        printf("Maio ");
    }
    else if(mes==6){
        printf("Junho ");
    }
    else if(mes==7){
        printf("Julho ");
    }
    else if(mes==8){
        printf("Agosto ");
    }
    else if(mes==9){
        printf("Setembro ");
    }
    else if(mes==10){
        printf("Outubro ");
    }
    else if(mes==11){
        printf("Novembro ");
    }
    else if(mes==12){
        printf("Dezembro ");
    }
    
}
void ImprimeDataExtenso(tData data){

    printf("%2d de ",data.dia);
    ImprimeMesExtenso(data);
    printf("de %4d\n",data.ano);
}

int VerificaBissexto(tData data){

    if((data.ano % 400 == 0) || ((data.ano % 4 == 0) && (data.ano % 100 != 0))){

        return 1;
    }

    return 0;
}

int NumeroDiasMes(tData data){
    if(data.mes==4||data.mes==6||data.mes==9||data.mes==11){
            return 30;
        }

        else if(data.mes==2){

            if(VerificaBissexto(data)){

               return 29;
            }
            else{
               return 28;
            }
        }

        else{
           return 31;
        }
}

int ComparaData(tData data1, tData data2){

    if(data1.ano>data2.ano){
        return 1;
    }
    else if(data1.ano<data2.ano){
        return -1;
    }

    else{
        if(data1.mes>data2.mes){
            return 1;
        }
        else if(data1.mes<data2.mes){
            return -1;
        }
        else{
            if(data1.dia>data2.dia){
                return 1;
            }
            else if(data1.dia<data2.dia){
                return -1;
            }
            else{
                return 0;
            }
        }
    }
}

int CalculaDiasAteMes(tData data){
    int soma=0;
    tData d;
    d.ano=data.ano;
    d.dia=data.dia;
    d.mes=data.mes;

    for(int i=1;i<data.mes;i++){
        d.mes=i;
        int dias=NumeroDiasMes(d);
        soma+=dias;
    }
    soma=soma+data.dia;
    return soma;
}
int CalculaDiferencaDias(tData data1, tData data2){
tData d;
int total=0;
int d1=0;
int d2=0;

    d=data1;
 for(int i=1;i<data1.ano-1;i++){
        
        d.ano=i;

        if(VerificaBissexto(d)){
            d1+=366;
        }
        else{
            d1+=365;
        }

       }
       d1=d1+CalculaDiasAteMes(data1);
       
       d=data2;
       
       for(int i=1;i<data2.ano-1;i++){
        
        d.ano=i;

        if(VerificaBissexto(d)){
            d2+=366;
        }
        else{
            d2+=365;
        }

       }
        d2=d2+CalculaDiasAteMes(data2);

    if(ComparaData(data1,data2)==1){
        
      
        total=d1-d2;
        return total;
    }

    else if(ComparaData(data1,data2)==-1){
         
      total=d2-d1;
        return total;
        
    }
    else{
        return 0;
    }
}
