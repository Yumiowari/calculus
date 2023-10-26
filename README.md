# Resolução de Equações Lineares

Seja as equações lineares:

$ax + by + cz = d$ \
$ex + fy + gz = h$ \
$ix + jy + kz = l$

Resolver a equação significa encontrar valores para $x$, $y$ e $z$ tais que as três equações sejam satisfeitas.

Na computação, a solução pode ser obtida por métodos iterativos.

## _Gauss-Jacobi_

A partir de soluções sorteadas na primeira iteração, as próximas soluções são calculadas. Em ∞ iterações, é certo que a solução real seja encontrada.

Para resolver em tempo humano, uma precisão é definida e, quando o erro relativo for inferior a ela, a solução é aceita.

Compilação: `gcc -lm -Wall gauss-jacobi.c -o gauss-jacobi`

Uso: `./gauss-jacobi (nome do arquivo .txt em data/)`

## _Gauss-Siedel_

Suponha que na primeira iteração foram sorteados $x = 1$, $y = 1$ e $z = 1$. Em Gauss-Jacobi, os valores de $x$, $y$ e $z$ serão trocados somente ao fim da iteração. Já em _Gauss-Siedel_, a partir de $x = 1$ e $z = 1$, $y$ é encontrado. E a partir do novo valor de $y$ e $x = 1$, $z$ é obtido e assim por diante.

Assim sendo, soluções mais precisas foram encontradas no mesmo laço. O que diminui consideravelmente o número de iterações necessárias para convergir numa solução aceitável.

Além do mais, nos dois métodos a convergência das soluções é garantida ao dispor os maiores valores da linha na diagonal principal da matriz.

Compilação: `gcc -lm -Wall gauss-siedel.c -o gauss-siedel`

Uso: `./gauss-siedel (nome do arquivo .txt em data/)`

# Aproximação de Funções Polinomiais

Sejam pontos arbitrários observados. 

Consiste na aproximação de coeficientes de um polinômio tal que o gráfico da função contenha os pontos observados.

## Interpolação Polinomial

Resolve as equações lineares de valores de $x$ para inferir os coeficientes do polinômio através da Eliminação Gaussiana.

Compilação: `gcc -lm -Wall polynomial.c -o polynomial -lm`

Uso: `./polynomial (nome do arquivo .txt em data/)`

## Interpolação pelo Método de Newton

Dados valores medidos, calcula o polinômio que passa pelos pontos no trecho. I. e., mesmo que os pontos tenham sido obtidos por outra função, o polinômio será, provavelmente, apenas válido para o intervalo da observação.

Para fazê-lo, na 1º ordem: $f[x_0, x_1] = \frac{f(x_1) - f(x_0)}{x_1 - x_0}$ e 

$f[x_1, x_2] = \frac{f(x_2) - f(x_1)}{x_2 - x_1}$. 

Na 2ª ordem: $f[x_0, x_1, x_2] = \frac{f[x_0, x_1] - f[x_1, x_2]}{x_2 - x_1}$.

E assim por diante. Ao fim das iterações, o polinômio será dado por

$P(x) = D_0 + D_1(x - x_0) + D_2(x - x_0)(x - x_1)...$

Onde $D_0$ é $f[x_0]$, $D_1$ é $f[x_0, x_1]$, $D_2$ é $f[x_0, x_1, x_2]$, etc.

Compilação: `gcc -lm -Wall newton.c -o newton`

Uso: `./newton (nome do arquivo .txt em data/)`