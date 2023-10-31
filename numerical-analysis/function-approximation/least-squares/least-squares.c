// Rafael Renó Corrêa
// 30/10/2023
// Cálculo Numérico para a Computação
// Aproximação de funções pelo Método dos Mínimos Quadrados

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define gx (x)
#define C 3

void imprimeMatriz(float **mat, int t);

void trocaLinha(float **var, int n, int m);

void pivoteamento(float **var, int t);

// códigos de erro:
// 1: problema na leitura de arquivo
// 2: memória insuficiente
int main(int argc, char **argv){
    if(argc < 2)return 1;

    FILE *f = NULL; // arquivo
    int tam; // tamanho
    float **mat = NULL; // matriz inicial
    float **res = NULL;
    char *nome = NULL; // buffer para o nome do arquivo
    float x, fx, c1, c2;
    
    // LEITURA DO ARQUIVO

    nome = (char*) malloc(sizeof(char) * (strlen("nome/") + strlen(argv[1])));
    if(nome == NULL)return 2;

    strcpy(nome, "data/");
    strcat(nome, argv[1]);

    f = fopen(nome, "r");
    if(f == NULL)return 1;

    fscanf(f, "%d\n", &tam);

    mat = (float**) malloc(sizeof(float*) * tam); if(mat == NULL)return 2;
    for(int i = 0; i < tam; i++){
        mat[i] = (float*) malloc(sizeof(float) * 2); if(mat[i] == NULL)return 2;
    }

    for(int i = 0; i < tam; i++){
        fscanf(f, "%f ", &mat[0][i]); // x
        fscanf(f, "%f\n", &mat[1][i]); // f(x)
    }

    //



    // MÉTODO DOS MÍNIMOS QUADRADOS (compatível para p(x) = a + bx)

    res = (float**) malloc(sizeof(float*) * 2); if(res == NULL)return 2;
    for(int i = 0; i < tam; i++){
        res[i] = (float*) malloc(sizeof(float) * 3); if(res[i] == NULL)return 2;
    }

    res[0][0] = 0; res[0][1] = 0; res[0][2] = 0;
    res[1][0] = 0; res[1][1] = 0; res[1][2] = 0;
    for(int i = 0; i < tam; i++){
        x = mat[0][i];
        res[0][0] += gx * gx;
        res[0][1] += gx * C;
        res[1][1] += C * C;
        fx = mat[1][i];
        res[0][2] += fx * gx;
        res[1][2] += fx * C;
    }
    res[1][0] = res[0][1];

    pivoteamento(res, 2);

    printf("É a matriz:\n");
    imprimeMatriz(res, 2);

    c2 = res[1][2] / res[1][1];
    c1 = (res[0][2] - (res[0][1] * c2)) / res[0][0];

    printf("a = %f\n", c1);
    printf("b = %f\n", c2 * C);

    //

    return 0;
}

void imprimeMatriz(float **mat, int t){
    for(int i = 0; i < t; i++){
        printf("%.3f ", mat[i][0]);
        for(int j = 1; j < t + 1; j++){
            if(j < t){
                printf("+ %.3f ", mat[i][j]);
            }else printf(" = %.3f\n", mat[i][j]);
        }
    }
    printf("\n");
}

void trocaLinha(float **var, int n, int m){
    float *aux = var[n];
    var[n] = var[m];
    var[m] = aux;
}

void pivoteamento(float **var, int t){
    int m; // índice da maior variável
    float fator;

    for(int i = 0; i < t; i++){ // linhas
        m = i;
        for(int j = 0; j < t; j++){ // colunas
            if(fabs(var[j][i]) < fabs(var[m][i])){
                m = j;
            }
        }

        trocaLinha(var, i, m);
    }

    for(int i = 0; i < t - 1; i++){
        if(var[i][i] == 0){
            for(int j = 1; j < t; j++){
                if(var[j][i] != 0){ // troca as linhas se houver zero na diagonal principal
                    trocaLinha(var, i, j);
                    break;
                }
            }
        }
        
        for(int j = i + 1; j < t; j++){
            fator = var[j][i] / var[i][i];
            for(int k = i; k < t + 1; k++){
                var[j][k] -= fator * var[i][k];
            }
        }
    }
}

// https://github.com/Yumiowari/calculus
