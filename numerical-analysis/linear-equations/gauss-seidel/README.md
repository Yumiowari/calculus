## Gauss-Seidel

Suponha que na primeira iteração foram sorteados $x = 1$, $y = 1$ e $z = 1$. Em Gauss-Jacobi, os valores de $x$, $y$ e $z$ serão trocados somente ao fim da iteração. Já em Gauss-Siedel, a partir de $x = 1$ e $z = 1$, $y$ é encontrado. E a partir do novo valor de $y$ e $x = 1$, $z$ é obtido e assim por diante.

Assim sendo, soluções mais precisas foram encontradas no mesmo laço. O que diminui consideravelmente o número de iterações necessárias para convergir numa solução aceitável.

Além do mais, nos dois métodos a convergência das soluções é garantida ao dispor os maiores valores da linha na diagonal principal da matriz.

Compilação: `gcc -Wall gauss-seidel.c -o gauss-seidel`

Uso: `./gauss-seidel (nome do arquivo .txt em data/)`