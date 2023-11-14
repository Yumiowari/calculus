// Rafael Renó Corrêa
// 14/11/2023
// Cálculo Numérico para a Computação
// Aproximação de integrais pela Regra 1/3 DE Simpson Generalizada

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fx (sin(x)) // f(x)
#define dqfx (sin(x)) // derivada de quarta ordem de f(x)

int main(int argc, char **argv){
    if(argc < 4)return 1;

    float a, b; // intervalo da integração
    int n; // qtd de intervalos
    float x;
    float res; // resultado da integração
    float max; // f''''x máximo
    float E; // erro
    
    // TRATAMENTO DOS PARÂMETROS

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    n = atoi(argv[3]);

    //



    // REGRA 1/3 DE SIMPSON

    res = 0;
    x = a; res += fx; // f(x0)
    for(int i = 1; i < n; i += 2){ // ímpares
        x = a + ((b - a) / n) * i; // (b - a) / n <-> passo
        res += 2 * fx;
    }
    for(int i = 2; i < n; i += 2){ // pares
        x = a + ((b - a) / n) * i;
        res += 4 * fx;
    }
    x = b; res += fx; // f(xn)
    res *= ((b - a) / n) / 3; // h / 3

    x = a; max = dqfx;
    for(int i = 1; i < n; i++){
        x = a + ((b - a) / n) * i; // (b - a) / n <-> passo
        if(dqfx > max)max = dqfx;
    }

    E = ((pow((b - a) / n, 2) / 180) * (b - a)) * fabs(max);

    printf("Resultado: %.6f\n", res);
    printf("Erro: %.6f\n", E);

    //

    return 0;
}

// https://github.com/Yumiowari/calculus