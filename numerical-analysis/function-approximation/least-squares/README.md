## Método dos Mínimos Quadrados

Com $\alpha_{ij} = \alpha_{ji} = \sum_{k=1}^{m}g_{i}(x_{k})*g_{k}(x_{k})$

e $\beta_{i} = \sum_{k=1}^{m}f(x_k)*g_{i}(x_{k})$.

Para a regressão linear, por exemplo, a resolução da matriz por Eliminação Gaussiana:

$\alpha_{11}*a_{1} + \alpha_{12}*a_{2} = \beta_{1}$ \
$\alpha_{21}*a_{1} + \alpha_{22}*a_{2} = \beta_{2}$

Resultará em $P(x) = a_{1}*g_{1}(x) + a_{2}*g_{2}(x)$

Onde $g_{1} = x$ e $g_{2} = x^0$ (ou constante).

Para aproximar uma parábola, por exemplo, seria $g_{1} = x^2$, $g_{2} = x$ e $g_{3} = x^0$. E assim por diante...

Tal que $P(x)$ é uma função que "mais se aproxima" aos dados medidos.

No entanto, diferentemente de outros métodos, o maior expoente somos nós que ditamos. Assim sendo, é possível inferir uma reta que melhor se aproxima aos pontos de uma parábola, por exemplo.

Compilação: `gcc -Wall least-squares.c -o least-squares`

Uso: `./least-squares (nome do arquivo .txt em data/)`

