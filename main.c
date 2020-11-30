#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "methods.h"

int main() {
    FILE *input;

    // Alocando dinamicamente as variáveis
    double *S0 = alocar_din(2);
    double *I0 = alocar_din(1);
    double *R0 = alocar_din(1);
    double *h = alocar_din(2);
    double *N_b = alocar_din(2);
    double *T_b = alocar_din(2);
    double *S_b0 = alocar_din(2);
    double *I_b0 = alocar_din(2);
    double *m_k = alocar_din(1);
    double *n_k = alocar_din(2);
    double *T_k = alocar_din(2);

    // Abertura do arquivo de especificação
    input = fopen("input.txt", "r"); 

    // Verifica se o arquivo foi aberto
    if (input == NULL) {
        printf("ERRO! O arquivo não foi aberto!\n");

        exit(1);
    }

    fscanf(input,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", S0, I0, R0, h, N_b, T_b, S_b0, I_b0, m_k, n_k, T_k);

    printf("Dados de entrada lidos com sucesso!\n");

    //Calculando as constantes
    double b = (*N_b)/((*T_b) * (*S_b0) * (*I_b0));
    double k = (*m_k)/((*n_k) * (*T_k));

    //Calculando SIR
    calcularSRI(S0, I0, R0, h, b, k);

    fclose(input);

    return 0;
}