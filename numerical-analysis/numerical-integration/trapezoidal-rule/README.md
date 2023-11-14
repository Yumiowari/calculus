## Regra dos Trapézios Generalizada

Para o intervalo [$a, b$] e com $n$ subintervalos, faz:

$\int\limits_{a}^{b} f(x) dx = \frac{h}{2} (f(x_0) + f(x_n) + 2 \sum\limits_{i = 1}^{n - 1} f(x_i)), h = \frac{(b - a)}{n}.$

Com erro:

$| E | \leq \frac{h^2}{12} (x_n - x_0) max |f''(x_k) |$, $0 \leq k \leq n.$

Compilação: `gcc -Wall trapezoidal.c -o trapezoidal -lm`

Uso: `./trapezoidal (a) (b) (n)`