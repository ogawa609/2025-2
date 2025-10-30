#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

tEmpresa criaEmpresa(int id){
    tEmpresa e;
    e.id=id;
    e.qtdFuncionarios=0;
    return e;
}

tEmpresa leEmpresa(){
    tEmpresa e;
    int id;
    scanf("%d",&id);
    e=criaEmpresa(id);

    return e;


}


tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){

    int igual=1;
    for(int i=0;i<empresa.qtdFuncionarios;i++){
        int id1=getIdFuncionario(funcionario);
        int id2=getIdFuncionario(empresa.funcionarios[i]);

        if(id1==id2){
            printf("A empresa %d ja possui um funcionario com o id %d\n",empresa.id,id1);
            igual=0;
        }
    }

    if(igual){
        if(empresa.qtdFuncionarios<20){
        empresa.funcionarios[empresa.qtdFuncionarios]=funcionario;
        empresa.qtdFuncionarios++;
        }
    }

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){

    printf("Empresa %d:\n",empresa.id);
    for(int i=0;i<empresa.qtdFuncionarios;i++){

        imprimeFuncionario(empresa.funcionarios[i]);
    }

}
