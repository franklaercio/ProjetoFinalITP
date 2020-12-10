#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "methods.h"

/**
 *  Função responsável por alocar dinamicamente um double
 *  
 *  @param tamanho	
 *  @return double
*/
double* alocar_din(int tamanho){
    double *ponteiro;
    ponteiro = (double*)malloc(tamanho*sizeof(double));

    return ponteiro;
}

/**
 *  Função responsável por calcular o cenário zero proposto pelo desafio
 *  
 *  @param S0, I0, R0, h, b, k, tamanho	
 *  @return
*/
void cenarioZeroSRI(double *S0, double *I0, double *R0, double *h, double b, double k, int tamanho) {
    double *S, *I, *R, *tempo, tmp = 0;

    S   = (double*) malloc(tamanho * sizeof(double));
    I   = (double*) malloc(tamanho * sizeof(double));   
    R   = (double*) malloc(tamanho * sizeof(double));
    tempo = (double*) malloc(tamanho * sizeof(double));

    S[0] = *S0; 
    R[0] = *R0;    
    I[0] = *I0;

    for (int t = 1; t < tamanho - 1; t++) {
        SRI modelo = calcularSRI(S, I, R, h, t, b, k);
        
        S[t] = modelo.S;
        I[t] = modelo.I;
        R[t] = modelo.R; 

        tmp += (*h); 
        tempo[t] = tmp;      
    }

    char nomeArquivo[256] = "cenarioZero.csv";

    preencherCSV(S, I, R, tempo, nomeArquivo);

    free (S);
    free (R);
    free (I);
    free (tempo); 
}

/**
 *  Função responsável por calcular os seguintes valores:
 *  - Número de indivíduos sucetíveis
 *  - Número de indivíduos infectados
 *  - Número de indivíduos removidos
 *  
 *  @param S, I, R, h, t, b, k	
 *  @return
*/
SRI calcularSRI(double *S, double *I, double *R, double *h, int t, double b, double k) {
    SRI modelo;

    modelo.S = S[t-1] - ((*h) * b * (S[t-1]) * (I[t-1]));
    modelo.I = I[t-1] + ((*h) * ((b * S[t-1] * I[t-1]) - (k * I[t-1])));
    modelo.R = R[t-1] + ((*h) * k * I[t-1]);

    return modelo;
}

/**
 *  Função responsável por preencher um CSV
 *  
 *  @param S, I, R, t	
 *  @return
*/
void preencherCSV(double *S, double *I, double *R, double *t, char *nomeArquivo) {   
    FILE *saida = fopen(nomeArquivo, "w+");
    
    if(saida == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");

        exit(1);
    }

    for(int i = 0; i < 5041; i++){
        fprintf(saida, "%f,%f,%f,%.1f\n", S[i], I[i], R[i], t[i]);
    }

    printf("Arquivo %s com os dados do SRI criado com sucesso!\n", nomeArquivo);

    fclose(saida);
}