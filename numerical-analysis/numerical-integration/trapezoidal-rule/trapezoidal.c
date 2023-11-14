// Rafael Renó Corrêa
// 14/11/2023
// Cálculo Numérico para a Computação
// Integração Numérica pela Regra dos Trapézios Generalizad

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fx (1 / (x + 1))
#define ddfx (2 / pow((x + 1), 3))

int main(int argc, char **argv){
    if(argc < 2)return 1;

    float a, b; // intervalo da integração
    float x;
    float res; // resultado da integração
    float max; // f''x máximo
    float E; // erro
    int n; // qtd de intervalos
    FILE *f = NULL; // arquivo
    char *nome = NULL; // buffer para o nome do arquivo
    
    // LEITURA DO ARQUIVO

    nome = (char*) malloc(sizeof(char) * (strlen("nome/") + strlen(argv[1])));
    if(nome == NULL)return 2;

    strcpy(nome, "data/");
    strcat(nome, argv[1]);

    f = fopen(nome, "r");
    if(f == NULL)return 1;

    fscanf(f, "%f ", &a); fscanf(f, "%f\n", &b);
    fscanf(f, "%d\n", &n);

    fclose(f);

    //



    // REGRA DOS TRAPÉZIOS

    res = 0;
    x = a; res += fx; // f(x0)
    for(int i = 1; i < n; i++){
        x = a + ((b - a) / n) * i; // (b - a) / n <-> passo
        printf("%f\n", x);
        res += 2 * fx;
    }
    x = b; res += fx; // f(xn)
    res *= ((b - a) / n) / 2; // h / 2

    x = a; max = ddfx;
    for(int i = 1; i < n; i++){
        x = a + ((b - a) / n) * i; // (b - a) / n <-> passo
        if(ddfx > max)max = ddfx;
    }

    E = (((b - a)/12) * (b - a)) * fabs(max);

    printf("Resultado: %.6f\n", res);
    printf("Erro: %.6f\n", E);

    //

    return 0;
}