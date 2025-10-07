#include <stdio.h>

int main(){
int lin, col;
 int t=0;
 int fase=0;

    scanf("%d %d",&lin,&col);
    int matriz[lin][col];

    for(int i=0;i<lin;i++){

        for(int j=0;j<col;j++){

            scanf("%d",&matriz[i][j]);
        }

    }

    int x1,y1,x2,y2;
   

    scanf("%d %d %d %d\n",&x1,&y1,&x2,&y2);

    x1=x1-1;
    y1=y1-1;
    x2=x2-1;
    y2=y2-1;

    char comando[4];

    for(int i=0;i<4;i++){

        scanf("%c",&comando[i]);
    }

    matriz[x1][y1]=2;

   

    while(1){

      
       
        if(comando[t]=='B'){

            if(x1<lin-1){

                if(matriz[x1+1][y1]==0){

                    x1=x1+1;
                    fase++;
                    
                }

               
            }
           
        }
        else if(comando[t]=='E'){

            if(y1>0){
            
                 if(matriz[x1][y1-1]==0){
                
                    y1=y1-1;
                    fase++;
                    
                }

               
            }
        }

        else if(comando[t]=='D'){

            if(y1<col-1){
                if(matriz[x1][y1+1]==0){
                
                    y1=y1+1;
                    fase++;
                    
                }

               
            }
        }

        else if(comando[t]=='C'){

            if(x1>0){
            
                 if(matriz[x1-1][y1]==0){
                
                    x1=x1-1;
                    fase++;
                    
                }

               
            }
        }

        if(x1==x2&&y1==y2){
            
            matriz[x2][y2]=2;
             
            break;
        }

        else if(matriz[x1][y1]==0){

            matriz[x1][y1]=2;
            
        }

        else if(matriz[x1+1][y1]!=0&&
                matriz[x1-1][y1]!=0&&
                matriz[x1][y1+1]!=0&&
                matriz[x1][y1-1]!=0){

            break;
        }

        t++;

        if(fase==3){
            fase=0;
            t=0;
        }
        
            
        
        if(t>=4){
            t=0;
        }

    

    }

    for(int i=0;i<lin;i++){

        for (int j=0; j<col;j++){

            if(matriz[i][j]==2){

                printf("(%d,%d) ",i+1,j+1);
            }
        }
    }

    for(int i=0;i<lin;i++){

        for(int j=0;j<col;j++){

            printf("%d ",matriz[i][j]);
        }
        printf("\n");

    }

   
    return 0;
}