// Rafael Renó Corrêa - 2022000403
// 21/11/2023
// Cálculo Numérico para a Computação
// Resolução de Equações Diferenciais pelo Método de Euler

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define dfx ((x * x) / (1 - x)) // x² / (1 - x)
// y(2) = -1

// códigos de erro:
// 1: argumentos insuficientes
// 2: b > a (impossível)
int main(int argc, char **argv){ // uso: ./euler (limite superior) (qtd de subintervalos)
    if(argc < 3)return 1;

    float b = atoi(argv[1]); // limite superior: [2, b]
    if(b <= 2)return 2;

    int n = atoi(argv[2]); // qtd de subintervalos n
    float h = (b - 2) / n;
    float x, y;

    x = 2; y = -1; // valores iniciais
    for(float i = 0; i < n; i++){
        y = y + (h * dfx);
        x += h;
    }
    
    printf("Para o intervalo [2, %f] com %d subintervalos, f(%f) = %f.\n", b, n, b, y);

    return 0;
}

// https://github.com/Yumiowari/calculus