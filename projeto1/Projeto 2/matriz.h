#ifndef _MATRIZ_H_
#define _MATRIZ_H_

void soma(int l1,int c1,int l2,int c2, int A[l1][c1],int B[l2][c2],int R[l1][c1]);
void subtrai(int l1,int c1,int l2,int c2, int A[l1][c1],int B[l2][c2],int R[l1][c1]);
void multiplicacao(int l1,int c1, int l2, int c2, int A[l1][c1],int B[l2][c2],int R[l1][c2]);
void multEscalar(int k,int linha, int coluna, int A[linha][coluna],int R[linha][coluna]);
void transposta(int l1, int c1,int l2,int c2, int A[l1][c1],int B[l2][c2], int T1[c1][l1],int T2[c2][l2]);
void ImprimirMenu();
void LeMatriz(int linha, int coluna, int matriz[linha][coluna]);
void Opcao(int op,int l1,int c1, int l2, int c2, int a[l1][c1],int b[l2][c2]);


#endif


