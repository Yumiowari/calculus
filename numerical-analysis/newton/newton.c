// Rafael Renó Corrêa
// 24/10/2023
// Cálculo Numérico para a Computação
// Aproximação de funções pelo Método de Newton

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimePolinomio(float **mat, float *res, int tam);

float resolveFuncao(float **mat, float *res, float x, int tam);

// códigos de erro:
// 1: problema na leitura de arquivo
// 2: memória insuficiente
int main(int argc, char **argv){
    if(argc < 2)return 1;

    FILE *f = NULL; // arquivo
    int tam; // tamanho
    float **mat = NULL; // matriz inicial
    float *res = NULL; // vetor de resultados em cada ordem
    float *aux = NULL; // vetor de resultados auxiliar
    float x; // x da função
    float fx; // f(x) da função

    // LEITURA DE ARQUIVO

    f = fopen(argv[1], "r");
    if(f == NULL)return 1;

    fscanf(f, "%d\n", &tam);

    mat = (float**) malloc(sizeof(float*) * tam); if(mat == NULL)return 2;
    for(int i = 0; i < tam; i++){
        mat[i] = (float*) malloc(sizeof(float) * 2); if(mat[i] == NULL)return 2;
    }

    res = (float*) malloc(sizeof(float) * tam); if(res == NULL)return 2;

    aux = (float*) malloc(sizeof(float) * tam); if(aux == NULL)return 2;
    

    for(int i = 0; i < tam; i++){
        fscanf(f, "%f ", &mat[i][0]);
        fscanf(f, "%f\n", &mat[i][1]);
    }

    fscanf(f, "%f\n", &x);

    //



    // MÉTODO DE NEWTON

    for(int i = 0; i < tam; i++){ // contador de ordens
        for(int j = i; j < tam; j++){ // contador de elementos do vetor de resultados
            if(i > 0){
                res[j] = (aux[j] - aux[j - 1]) / (mat[j][0] - mat[j - i][0]); // mat[j - i] uma vez que é x2 - x0 na terceira iteração, por exemplo.
                printf("%.3f = (%.3f - %.3f) / (%.3f - %.3f)\n", res[j], aux[j], aux[j - 1], mat[j][0], mat[j - i][0]);
            }else{ // para a primeira ordem
                res[j] = mat[j][1];
                aux[j] = res[j];
            }
        }

        if(i > 0){
            for(int j = i; j < tam; j++){ // contador de elementos do vetor auxiliar
                aux[j] = res[j]; // atualiza o vetor auxiliar
            }

            printf("\n");
        }
    }

    imprimePolinomio(mat, res, tam);

    fx = resolveFuncao(mat, res, x, tam);

    printf("Verificação: f(%.3f) = %.3f\n", x, fx);

    //

    for(int i = 0; i < tam; i++)free(mat[i]);
    free(mat);

    free(res);

    free(aux);

    fclose(f);

    return 0;
}

void imprimePolinomio(float **mat, float *res, int tam){
    printf("Dos valores:\n");

    for(int i = 0; i < tam; i++){
        printf("x%d = %.3f ", i, mat[i][0]);
        printf("fx%d = %.3f\n", i, mat[i][1]);
    }

    printf("\nÉ o polinômio: ");

    for(int i = 0; i < tam; i++)printf("D%d = %.3f ", i, res[i]);

    printf("\n\n");
}

float resolveFuncao(float **mat, float *res, float x, int tam){
    float fx = 0;
    float aux;

    fx += res[0];
    
    for(int i = 1; i < tam; i++){ // para todos as ordens
        aux = res[i];

        for(int j = 0; j < i; j++){ // para todos os x
            aux *= (x - mat[j][0]);
        }

        fx += aux;
    }

    return fx;
}

// https://github.com/Yumiowari/calculus