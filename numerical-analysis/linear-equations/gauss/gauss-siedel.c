// Rafael Renó Corrêa
// 26/10/2023
// Cálculo Numérico para a Computação
// Algoritmo para resolver equações lineares. Método de Gauss-Siedel

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void imprimeMatriz(float **coef, float *res, int t);

// códigos de erro:
// 1: problema na leitura de arquivo
// 2: memória indisponível
// -1: solução impossível
int main(int argc, char *argv[]){
    if(argc < 2)return 1;

    FILE *f = NULL; // ponteiro para o arquivo
    int n; // nº de incógnitas
    int max; // máximo de iterações
    int c; // contador
    int m; // índice do maior valor
    float aux; // auxiliar
    float x; // maior incógnita
    float e; // maior erro
    float rel; // erro relativo
    float y; // precisão ε
    float **coef = NULL; // matriz dos coeficientes
    float *res = NULL; // vetor dos resultados
    float *sol = NULL; // vetor das soluções
    float ant; // solução anterior
    char *nome = NULL; // buffer para o nome do arquivo

    // LEITURA DO ARQUIVO

    nome = (char*) malloc(sizeof(char) * (strlen("nome/") + strlen(argv[1]))); // '\0 implícito'
    if(nome == NULL)return 2;

    strcpy(nome, "data/");
    strcat(nome, argv[1]);

    f = fopen(nome, "r");
    if(f != NULL){
        fscanf(f, "%d\n", &n);
        //if(n > 10){
        //    printf("A matriz é muito grande!\n");
        //    return 1;
        //}
        fscanf(f, "%f\n", &y);
        fscanf(f, "%d\n", &max);

        res = (float*) malloc(sizeof(float*) * n);
        if(res == NULL)return 2;

        coef = (float**) malloc(sizeof(float**) * n);
        if(coef == NULL)return 2;
            
        for(int i = 0; i < n; i++){
            coef[i] = (float*) malloc(sizeof(float*) * n);
            if(coef[i] == NULL)return 2;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n + 1; j++){
                if(j < n){
                    fscanf(f, "%f ", &coef[i][j]);
                }else fscanf(f, "%f\n", &res[i]); // se estiver na coluna dos resultados
            }
        }

        sol = (float*) malloc(sizeof(float*) * n);
        if(sol == NULL)return 2;
        for(int i = 0; i < n; i++)fscanf(f, "%f ", &sol[i]);

        printf("É a matriz de equações lineares:\n");
        imprimeMatriz(coef, res, n);
    }else{
        printf("Nome de arquivo inválido ou inexistente.\n");
        return 1;
    }
    //



    // AJUSTA AS LINHAS

    for(int i = 0; i < n; i++){
        m = 0;
        for(int j = 0; j < n; j++){
            if(fabs(coef[j][i]) > coef[m][i]){ // encontra o maior coeficiente na coluna
                m = j;
            }
        }

        if(m != i){ // troca as linhas
            for(int k = 0; k < n; k++){
                aux = coef[i][k];
                coef[i][k] = coef[m][k];
                coef[m][k] = aux;
            }

            // também troca os resultados
            aux = res[i];
            res[i] = res[m];
            res[m] = aux;
        }
    }

    printf("Após o ajuste de linhas:\n");
    imprimeMatriz(coef, res, n);

    //



    // GAUSS-SIEDEL

    c = 0;

    do{
        for(int i = 0; i < n; i++){
            aux = 0;
            for(int j = 0; j < n; j++){
                if(j != i){ // exceto o x da diagonal
                    aux += (coef[i][j] * sol[j]); // o coeficiente de x vezes a solução obtida
                }else{
                    if(coef[i][j] == 0){ 
                        printf("Sistema impossível!\nOcorreria divisão por zero...\n");
                        return -1;
                    }
                }
            }
            
            ant = sol[i];
            sol[i] = (res[i] - aux) / coef[i][i];

            // calcula...
            if(i > 0){
                if(fabs(sol[i] - ant) > e)e = fabs(sol[i] - ant); // o maior erro
                if(sol[i] > sol[i - 1])x = sol[i]; // o maior x
            }else e = fabs(sol[i] - ant);
        }

        c++;

        rel = fabs(e / x);
    }while(rel > y && c < max);

    if(c >= max && rel > y){
        printf("A solução não foi atingida com %d iterações e o erro relativo foi de %.6f.\n", c, rel);
        return -1;
    }else if(isnan(rel)){
        printf("As equações divergem da solução.\n");
        return -1;
    }

    printf("São as soluções com erro relativo %.6f:\n", rel);
    for(int i = 0; i < n; i++)printf("%.6f ", sol[i]);
    printf("\nEm %d iterações.\n", c);

    //



    // VERIFICAÇÃO

    printf("\nVerificação:");
    for(int i = 0; i < n; i++){
        aux = 0;
        for(int j = 0; j < n; j++){
            aux += (coef[i][j] * sol[j]);
        }
        printf("\n%.6f - %.6f", res[i], aux);
    }
    printf("\n");

    //

    for(int i = 0; i < n; i++)free(coef[i]);
    free(coef);

    free(res);
    free(sol);

    fclose(f);

    return 0;
}

void imprimeMatriz(float **coef, float *res, int t){
    for(int i = 0; i < t; i++){
        printf("%.3f ", coef[i][0]);
        for(int j = 1; j < t + 1; j++){
            if(j < t){
                printf("+ %.3f ", coef[i][j]);
            }else printf("= %.3f\n", res[i]);
        }
    }
    printf("\n");
}

// https://github.com/Yumiowari/calculus