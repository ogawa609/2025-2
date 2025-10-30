#include <stdio.h>
#include "funcionario.h"
#include "empresa.h"

int main(){

    int quantE;
    scanf("%d",&quantE);
    tEmpresa empresas[quantE];

    for(int i=0;i<quantE;i++){

        empresas[i]=leEmpresa();
        int funcionarios;
        scanf("%d",&funcionarios);
        for(int j=0;j<funcionarios;j++){

            tFuncionario f=leFuncionario();
            empresas[i]=contrataFuncionarioEmpresa(empresas[i],f);

        }
    }

    for (int i=0;i<quantE;i++){
        imprimeEmpresa(empresas[i]);
    }
    
return 0;

}