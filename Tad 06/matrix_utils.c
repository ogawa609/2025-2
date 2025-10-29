#include <stdio.h>
#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols){
    tMatrix m;
    m.cols=cols;
    m.rows=rows;

    return m;
}
tMatrix MatrixRead(tMatrix matrix){

    int rows, cols;
    
    scanf("%d %d",&rows,&cols);
    matrix=MatrixCreate(rows,cols);

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

            scanf("%d",&matrix.data[i][j]);
        }
    }

    return matrix;


}

void MatrixPrint(tMatrix matrix){

    for(int i=0;i<matrix.rows;i++){

        printf("|");

        for(int j=0;j<matrix.cols;j++){

            if(j==matrix.cols-1){

                printf("%d|",matrix.data[i][j]);
            }

            else{

                printf("%d",matrix.data[i][j]);
            }
        }

        printf("\n");
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){

    if(matrix1.cols==matrix2.cols&&matrix1.rows==matrix2.rows){
        return 1;
    }

    return 0;
}


int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){

    if(matrix1.cols==matrix2.cols&&matrix1.rows==matrix2.rows){
        return 1;
    }

    return 0;

}


int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){

    if(matrix1.cols==matrix2.rows){
        return 1;
    }

    return 0;
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){

tMatrix m3;
m3.cols=matrix1.cols;
m3.rows=matrix1.rows;

for(int i=0;i<matrix1.rows;i++){
    for(int j=0;j<matrix2.cols;j++){

        m3.data[i][j]=matrix1.data[i][j]+matrix2.data[i][j];
    }
}

return m3;
}
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){

tMatrix m3;
m3.cols=matrix1.cols;
m3.rows=matrix1.rows;

for(int i=0;i<matrix1.rows;i++){
    for(int j=0;j<matrix2.cols;j++){

        m3.data[i][j]=matrix1.data[i][j]-matrix2.data[i][j];
    }
}

return m3;
}
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){

    tMatrix m3;
    m3.cols=matrix2.cols;
    m3.rows=matrix1.rows;

    for(int i=0;i<matrix1.rows;i++){
        for(int j=0;j<matrix2.cols;j++){

            m3.data[i][j]=0;

            for(int k=0;k<matrix1.cols;k++){

                m3.data[i][j]+=matrix1.data[i][k]*matrix2.data[k][j];
            }
        }
    }

    return m3;
}
tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix m3;
    m3.cols=matrix.rows;
    m3.rows=matrix.cols;

    for(int i=0;i<m3.rows;i++){
        for(int j=0;j<m3.cols;j++){

            m3.data[i][j]=matrix.data[j][i];
        }
    }

    return m3;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){

    for(int i=0;i<matrix.rows;i++){
        for(int j=0;j<matrix.cols;j++){

            matrix.data[i][j]=matrix.data[i][j]*scalar;
        }
    }

    return matrix;
}
