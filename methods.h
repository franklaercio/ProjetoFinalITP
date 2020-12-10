#ifndef METHODS_H
#define METHODS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { 
    double S,R,I;
} SRI;

double* alocar_din(int tamanho);

void cenarioZeroSRI(double *S0, double *I0, double *R0, double *h, double b, double k, int tamanho);

void preencherCSV(double *S, double *I, double *R, double *t, char *nomeArquivo);

SRI calcularSRI(double *S, double *I, double *R, double *h, int t, double b, double k);

#endif