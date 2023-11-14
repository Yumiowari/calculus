## Interpolação pelo Método de Newton

Dados valores medidos, calcula o polinômio que passa pelos pontos no trecho. I. e., mesmo que os pontos tenham sido obtidos por outra função, o polinômio será, provavelmente, apenas válido para o intervalo da observação.

Para fazê-lo, na 1º ordem: $f[x_0, x_1] = \frac{f(x_1) - f(x_0)}{x_1 - x_0}$ e 

$f[x_1, x_2] = \frac{f(x_2) - f(x_1)}{x_2 - x_1}.$

Na 2ª ordem: $f[x_0, x_1, x_2] = \frac{f[x_0, x_1] - f[x_1, x_2]}{x_2 - x_1}.$

E assim por diante. Ao fim das iterações, o polinômio será dado por

$P(x) = D_0 + D_1(x - x_0) + D_2(x - x_0)(x - x_1)...$

Onde $D_0$ é $f[x_0]$, $D_1$ é $f[x_0, x_1]$, $D_2$ é $f[x_0, x_1, x_2]$, etc.

Compilação: `gcc -Wall newton.c -o newton`

Uso: `./newton (nome do arquivo .txt em data/)`