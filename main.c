/**
 *  Programa que calcula um cenário SRI
 *  
 *  @author Frank Laércio - franklaercio@ufrn.edu.br
 *  @author Ohanna Dezidério - ohannadeziderio@ufrn.edu.br	
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "methods.h"

int main() {
    FILE *input;

    // Declarando as variáveis
    double S0, I0, R0, h, N_b, T_b, S_b0, I_b0, m_k, n_k, T_k;

    // Abertura do arquivo de especificação
    input = fopen("input.txt", "r"); 

    // Verifica se o arquivo foi aberto
    if (input == NULL) {
        printf("ERRO! O arquivo não foi aberto!\n");

        exit(1);
    }

    // Lendo do arquivo os dados padrões das variáveis
    fscanf(input,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", &S0, &I0, &R0, &h, &N_b, &T_b, &S_b0, &I_b0, &m_k, &n_k, &T_k);

    printf("Dados de entrada lidos com sucesso!\n");

    // Calculando as constantes
    double b = (N_b)/((T_b) * (S_b0) * (I_b0));
    double k = (m_k)/((n_k) * (T_k));

    // Calculando SIR - Cenário Zero
    cenarioZeroSRI(&S0, &I0, &R0, &h, b, k, 5042);

    // Calculando SIR - Cenário Um
    double b_AposControle = (N_b)/((T_b + 10) * (S_b0) * (I_b0));
    cenarioUmSRI(&S0, &I0, &R0, &h, b, k, 5042, 40, b_AposControle);

    // Calculando SIR - Cenário Dois
    double k_AposControle = (m_k)/((n_k) * (T_k - 10));
    cenarioDoisSRI(&S0, &I0, &R0, &h, b, k, 5042, 40, k_AposControle);

    fclose(input);

    return 0;
}