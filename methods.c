  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "methods.h"

int* alocar_din_int(int tamanho){
    int *ponteiro;
    ponteiro = (int*)malloc(tamanho*sizeof(int));

    return ponteiro;
}

double* alocar_din_double(int tamanho){
    double *ponteiro;
    ponteiro = (double*)malloc(tamanho*sizeof(double));

    return ponteiro;
}