// Rafael Renó Corrêa
// 03/12/2023
// Cálculo Numérico para a Computação
// Calcula o valor de x no polinômio de Lagrange interpolado

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// códigos de erro:
// 1: problema na leitura de arquivo
// 2: memória insuficiente
int main(int argc, char *argv[]){
    if(argc < 2)return 1;

    FILE *f = NULL; // arquivo
    char *nome = NULL; // buffer para o nome do arquivo

    int t = 0; // tamanho dos vetores
    float *x = NULL; // valores de x observados
    float *y = NULL; // valores de f(x) observados
    float u; // valor para calcular o resultado do polinômio
    float L; // Lagrange
    float res = 0; // resultado para f(u)
    
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
            if(i != j){ // exceto quando ocorreria divisão por zero!
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

// https://github.com/Yumiowari/calculus