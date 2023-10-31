// Rafael Renó Corrêa
// 26/10/2023
// Cálculo Numérico para a Computação
// Aproximação de funções por interpolação polinomial

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void imprimeMatriz(float **var, float *res, int t);

void trocaLinha(float **var, int n, int m);

void pivoteamento(float **var, int t);

// códigos de erro:
// 1: problema na leitura de arquivo
// 2: memória insuficiente
int main(int argc, char *argv[]){
    if(argc < 2)return 1;

    FILE *f = NULL; // arquivo
    int t; // tamanho da matriz
    float **var = NULL; // matriz de variáveis
    float *res = NULL; // vetor de resultados
    float *x = NULL; // vetor para leitura
    float *coef = NULL; // vetor de coeficientes
    float aux; // auxiliar
    char *nome = NULL; // buffer para o nome do arquivo
    
    // LEITURA DO ARQUIVO

    nome = (char*) malloc(sizeof(char) * (strlen("nome/") + strlen(argv[1])));
    if(nome == NULL)return 2;

    strcpy(nome, "data/");
    strcat(nome, argv[1]);

    f = fopen(nome, "r");
    if(f == NULL)return 1;

    fscanf(f, "%d\n", &t);
    //if(t > 10){
    //    printf("A matriz é muito grande!\n");
    //    return 1;
    //} 

    var = (float**) malloc(sizeof(float*) * t);
    if(var == NULL)return 2;
    for(int i = 0; i < t; i++){
        var[i] = (float*) malloc(sizeof(float) * t);
        if(var[i] == NULL)return 2;
    }

    res = (float*) malloc(sizeof(float) * t);
    if(res == NULL)return 2;

    x = (float*) malloc(sizeof(float) * t);
    if(x == NULL)return 2;

    coef = (float*) malloc(sizeof(float) * t);
    if(coef == NULL)return 2;

    for(int i = 0; i < t; i++)coef[i] = 1;

    for(int i = 0; i < t; i++){
        fscanf(f, "%f ", &x[i]); // x
        fscanf(f, "%f\n", &res[i]); // f(x)
    }

    for(int i = 0; i < t; i++){
        var[i][0] = 1;
        for(int j = 1; j < t; j++){
            var[i][j] = pow(x[i], j);
        }
    }

    //



    // ELIMINAÇÃO DE GAUSS

    pivoteamento(var, t);

    printf("É a matriz:\n");
    imprimeMatriz(var, res, t);

    for(int i = t - 1; i >= 0; i--){
        aux = 0;
        for(int j = 0; j < t; j++){
            if(i != j)aux += var[i][j] * coef[j];
        }
        coef[i] = (res[i] - aux) / var[i][i];
    }

    //



    // VERIFICAÇÃO

    printf("Verificação:\n");
    for(int i = 0; i < t; i++){
        aux = 0;
        for(int j = 0; j < t; j++){
            aux += var[i][j] * coef[j];
        }
        printf("%.3f - %.3f\n", aux, res[i]);
    }

    printf("\nSão os coeficientes:\n");
    for(int i = 0; i < t - 1; i++)printf("a%d = %.6f, ", i, coef[i]);
    printf("a%d = %.6f\n", t - 1,coef[t - 1]);

    //

    for(int i = 0; i < t; i++)free(var[i]);
    free(var);

    free(res);
    free(x);
    free(coef);
    free(nome);

    fclose(f);

    return 0;
}

void imprimeMatriz(float **var, float *res, int t){
    for(int i = 0; i < t; i++){
        printf("%.3f ", var[i][0]);
        for(int j = 1; j < t + 1; j++){
            if(j < t){
                printf("+ %.3f ", var[i][j]);
            }else printf(" = %.3f\n", res[i]);
        }
    }
    printf("\n");
}

void pivoteamento(float **var, int t){
    int m; // índice da maior variável
    float fator;
    float *aux;

    for(int i = 0; i < t; i++){ // linhas
        m = i;
        for(int j = 0; j < t; j++){ // colunas
            if(fabs(var[j][i]) < fabs(var[m][i])){
                m = j;
            }
        }

        // troca as linhas
        aux = var[i];
        var[i] = var[m];
        var[m] = aux;
    }

    for(int i = 0; i < t - 1; i++){
        if(var[i][i] == 0){
            for(int j = 1; j < t; j++){
                if(var[j][i] != 0){ // se houver zero na diagonal principal
                    // troca as linhas
                    aux = var[i];
                    var[i] = var[j];
                    var[j] = aux;

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

