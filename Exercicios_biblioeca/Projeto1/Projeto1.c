#include <stdio.h>
#include "circulo.h"

int main(){

    float raio;

    scanf("%f",&raio);

    printf("Area = %.2f\n",Area(raio));
    printf("Volume = %.2f\n",Volume(raio));

    return 0;
}