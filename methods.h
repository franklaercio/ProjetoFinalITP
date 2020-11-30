#ifndef METHODS_H
#define METHODS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double* alocar_din(int tamanho);

void calcularSRI(double *S0, double *I0, double *R0, double *h, double b, double k);

void preencherCSV(double *S, double *I, double *R, double *t);

#endif