// Rafael Renó Corrêa - 2022000403
// 21/11/2023
// Cálculo Numérico para a Computação
// Resolução de Equações Diferenciais pelo Método de Euler Estendido

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float dfx(float x, float y){
    return x + y;
}
// y(0) = 1

// códigos de erro:
// 1: argumentos insuficientes
// 2: b > a (impossível)
int main(int argc, char **argv){ // uso: ./euler (limite superior) (qtd de subintervalos)
    if(argc < 3)return 1;

    float b = atoi(argv[1]); // limite superior: [2, b]
    if(b <= 2)return 2;

    int n = atoi(argv[2]); // qtd de subintervalos n
    float h = (b - 0) / n;
    float x, y;
    float s1, s2;

    x = 0; y = 1; // valores iniciais
    for(float i = 0; i < n; i++){
        s1 = dfx(x, y);
        s2 = dfx(x + h, y + h * s1);

        y += (h / 2) * (s1 + s2);
        x += h;
    }
    
    printf("Para o intervalo [2, %f] com %d subintervalos, f(%f) = %f.\n", b, n, b, y);

    return 0;
}

// https://github.com/Yumiowari/calculus