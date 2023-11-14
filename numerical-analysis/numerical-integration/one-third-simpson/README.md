## Regra $\frac{1}{3}$ de Simpson Generalizada

Para o intervalo [$a, b$] e com $n$ subintervalos, faz:

$\int\limits_{a}^{b} f(x) dx = \frac{h}{3} (f(x_0) + f(x_n) + 2 \sum\limits_{i = 1}^{\frac{n}{2} - 1} + 4 \sum\limits_{i = 1}^{\frac{n}{2}}), h = \frac{(b - a)}{n}.$

Isto é, $\sum\limits_{i = 1}^{\frac{n}{2} - 1} \leftrightarrow \{f(x_1) + f(x_3) + f(x_5) + ...\}$ e,

$\sum\limits_{i = 1}^{\frac{n}{2}} \leftrightarrow \{f(x_2) + f(x_4) + f(x_6) + ...\}.$

Com erro:

$| E | \leq \frac{h^4}{180} (x_n - x_0) max |f^{IV}(x_k) |$, $0 \leq k \leq n.$

Compilação: `gcc -Wall simpson.c -o simpson -lm`

Uso: `./simpson (a) (b) (n)`