// Rafael Renó Corrêa - 2022000403
// 28/11/2023
// Cálculo Numérico para a Computação
// Resolução de Equações Diferenciais por Runge-Kutta de 2ª e 4ª ordem

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float fx(float x, float y){
    return (
        //1 + (y * y) // y(0) = 0
        //1 / (1 + (x * x)) // y(0) = 0
        //1 - (2 * x * y) // y(0) = 0
        (2 * y) - (2 * (x * x)) - 3 // y(0) = 2
    );
}

// códigos de erro:
// 1: argumentos insuficientes
// 2: b > a (impossível)
int main(int argc, char **argv){ // uso: ./runge-kutta (limite superior) (tamanho do passo) (ordem)
    if(argc < 4)return 1;

    float b = atof(argv[1]); // limitante superior de y

    float h = atof(argv[2]); // tamanho do passo
    int n = b / h; // quantas vezes h cabe em b
    float x, y;
    float k1, k2, k3, k4;

    int ordem = atoi(argv[3]); // qual a ordem?

    x = 0; y = 0; // valores iniciais
    if(ordem <= 2){
        for(float i = 0; i < n; i++){ // até alcançar o limite superior
            k1 = fx(x, y);
            k2 = fx(x + h, y + (h * k1));
            y = y + (h * (k1 + k2)) / 2;

            x += h;
        }
    }else{
        for(float i = 0; i < n; i++){ // até alcançar o limite superior
            k1 = fx(x, y);
            k2 = fx(x + (h / 2), y + ((h * k1) / 2));
            k3 = fx(x + (h / 2), y + ((h * k2) / 2));
            k4 = fx(x + h, y + (h * k3));
            y = y + (h * (k1 + (2 * k2) + (2 * k3) + k4)) / 6;

            x += h;
        }
    }
    
    printf("Para Runge-Kutta de %dª ordem com %d subintervalos, f(%f) = %f.\n", ordem, n, b, y);

    return 0;
}

// https://github.com/Yumiowari/calculus