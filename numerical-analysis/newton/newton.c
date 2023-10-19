// Rafael Renó Corrêa
// 18/10/2023
// Cálculo Numérico para a Computação
// Aproximação de funções pelo Método de Newton

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimePolinomio(int **mat, int *res, int tam);

// códigos de erro:
// 1: problema na leitura de arquivo
// 2: memória insuficiente
int main(int argc, char **argv){
    if(argc < 2)return 1;

    FILE *f = NULL; // arquivo
    int tam; // tamanho
    int **mat = NULL; // matriz inicial
    int *res = NULL; // vetor de resultados em cada ordem
    int *aux = NULL; // vetor de resultados auxiliar

    // LEITURA DE ARQUIVO

    f = fopen(argv[1], "r");
    if(f == NULL)return 1;

    fscanf(f, "%d\n", &tam);

    mat = (int**) malloc(sizeof(int*) * tam); if(mat == NULL)return 2;
    for(int i = 0; i < tam; i++){
        mat[i] = (int*) malloc(sizeof(int) * 2); if(mat[i] == NULL)return 2;
    }

    res = (int*) malloc(sizeof(int) * tam); if(res == NULL)return 2;

    aux = (int*) malloc(sizeof(int) * tam); if(aux == NULL)return 2;
    

    for(int i = 0; i < tam; i++){
        fscanf(f, "%d ", &mat[i][0]);
        fscanf(f, "%d\n", &mat[i][1]);
    }

    //



    // MÉTODO DE NEWTON

    for(int i = 0; i < tam; i++){ // contador de ordens
        for(int j = i; j < tam; j++){ // contador de elementos do vetor de resultados
            if(i > 0){
                res[j] = (aux[j] - aux[j - 1]) / (mat[j][0] - mat[j - i][0]); // mat[j - i] uma vez que é x2 - x0 na terceira iteração, por exemplo.
                printf("%d = (%d - %d) / (%d - %d)\n", res[j], aux[j], aux[j - 1], mat[j][0], mat[j - i][0]);
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

    //

    for(int i = 0; i < tam; i++)free(mat[i]);
    free(mat);

    free(res);

    free(aux);

    return 0;
}

void imprimePolinomio(int **mat, int *res, int tam){
    for(int i = 0; i < tam; i++){
        printf("x%d = %d ", i, mat[i][0]);
        printf("fx%d = %d\n", i, mat[i][1]);
    }

    printf("\n");

    for(int i = 0; i < tam; i++)printf("D%d = %d ", i, res[i]);

    printf("\n");
}