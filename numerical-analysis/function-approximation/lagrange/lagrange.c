// Rafael Renó Corrêa
// 26/11/2023
// Cálculo Numérico para a Computação
// Aproximação de funções pela Forma de Lagrange

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void imprimeMatriz(float **var, float *res, int t);

void pivoteamento(float **var, int t);

// códigos de erro:
// 1: problema na leitura de arquivo
// 2: memória insuficiente
int main(int argc, char *argv[]){
    if(argc < 2)return 1;

    FILE *f = NULL; // arquivo
    int t; // tamanho dos vetores
    float *x = NULL; // valores de x medidos
    float *y = NULL; // valores de f(x) medidos
    float u; // valor para calcular o resultado do polinômio
    float L;
    float res = 0; // resultado para x = u
    char *nome = NULL; // buffer para o nome do arquivo
    
    // LEITURA DO ARQUIVO

    nome = (char*) malloc(sizeof(char) * (strlen("nome/") + strlen(argv[1])));
    if(nome == NULL)return 2;

    strcpy(nome, "data/");
    strcat(nome, argv[1]);

    f = fopen(nome, "r");
    if(f == NULL)return 1;

    fscanf(f, "%d\n", &t);
    
    x = (float*) malloc(sizeof(float) * t);
    if(x == NULL)return 2;

    y = (float*) malloc(sizeof(float) * t);
    if(y == NULL)return 2;

    for(int i = 0; i < t; i++){
        fscanf(f, "%f ", &x[i]);
        fscanf(f, "%f\n", &y[i]);
    }

    fscanf(f, "%f\n", &u);

    //



    // FORMA DE LAGRANGE

    for(int i = 0; i < t; i++){
        L = y[i];

        for(int j = 0; j < t; j++){
            if(i != j){
                L *= (u - x[j]) / (x[i] - x[j]);
            }
        }

        res += L;
    }

    printf("P(%.6f) = %.6f", u, res);

    //

    free(x);
    free(y);

    fclose(f);

    return 0;
}