  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "methods.h"

double* alocar_din(int tamanho){
    double *ponteiro;
    ponteiro = (double*)malloc(tamanho*sizeof(double));

    return ponteiro;
}

void calcularSRI(double *S0, double *I0, double *R0, double *h, double b, double k) {
    double *S, *I, *R, *tempo, tmp = 0;

    S   = (double*) malloc(5042 * sizeof(double));
    I   = (double*) malloc(5042 * sizeof(double));   
    R   = (double*) malloc(5042 * sizeof(double));
    tempo = (double*) malloc(5042 * sizeof(double));

    S[0] = *S0; 
    R[0] = *R0;    
    I[0] = *I0;

    for (int t = 1; t < 5042; t++) {
        S[t] = S[t-1] - ((*h) * b * (S[t-1]) * (I[t-1]));
        I[t] = I[t-1] + ((*h) * ((b * S[t-1] * I[t-1]) - (k * I[t-1])));
        R[t] = R[t-1] + ((*h) * k * I[t-1]); 

        tempo[t] = tmp;      
        tmp += (*h); 
    }
}