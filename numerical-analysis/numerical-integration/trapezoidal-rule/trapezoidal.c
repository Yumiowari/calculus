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
    if(argc < 4)return 1;

    float a, b; // intervalo da integração
    int n; // qtd de intervalos
    float x;
    float res; // resultado da integração
    float max; // f''x máximo
    float E; // erro
    
    // TRATAMENTO DOS PARÂMETROS

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    n = atoi(argv[3]);

    //



    // REGRA DOS TRAPÉZIOS

    res = 0;
    x = a; res += fx; // f(x0)
    for(int i = 1; i < n; i++){
        x = a + ((b - a) / n) * i; // (b - a) / n <-> passo
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