#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "methods.h"

int main() {
    FILE *dados;

    // Alocando dinamicamente as variáveis
    int *S0 = alocar_din_int(2);
    int *I0 = alocar_din_int(1);
    int *R0 = alocar_din_int(1);
    double *h = alocar_din_double(2);
    int *N_b = alocar_din_int(2);
    int *T_b = alocar_din_int(2);
    int *S_b0 = alocar_din_int(2);
    int *l_b0 = alocar_din_int(2);
    int *m_k = alocar_din_int(1);
    int *n_k = alocar_din_int(2);
    int *T_k = alocar_din_int(2);

    // Abertura do arquivo de especificação
    dados = fopen("dados.txt", "r"); 

    // Verifica se o arquivo foi aberto
    if (dados == NULL) {
        printf("ERRO! O arquivo não foi aberto!\n");

        return 0;
    }

    fscanf(dados,"%i,%i,%i,%lf,%i,%i,%i,%i,%i,%i,%i\n", S0, I0, R0, h, N_b, T_b, S_b0, l_b0, m_k, n_k, T_k);

    printf("S0: %i \n", *S0);
    printf("I0: %i \n", *I0);
    printf("R0: %i \n", *R0);
    printf("h: %.2lf \n", *h);
    printf("N_b: %i \n", *N_b);
    printf("T_b: %i \n", *T_b);
    printf("Sb0: %i \n", *S_b0);
    printf("l_b0: %i \n", *l_b0);
    printf("m_k: %i \n", *m_k);
    printf("n_k: %i \n", *n_k);
    printf("T_k: %i \n", *T_k);

    fclose(dados);

    return 0;
}