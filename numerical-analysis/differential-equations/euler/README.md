## Método de Euler

O método mais simples para resolver uma equação diferencial do tipo
$\frac{dy}{dx}=f(x,y)$ é devido ao matemático suiço Euler.

Suponha que desejamos encontrar a solução da equação no domínio da variável $x\in[a,b]$ e tenhamos a condição inicial $y(x_0)=y_0$.

Em poucas palavras,

$$y(x_0 + h) \approx y(x_0) + h.f(x_0, y_0)$$

Uma vez que $h$ é o passo do intervalo e $y'=f(x_0, y_0)$.

Ou seja, para $\frac{dy}{dx}=y$ com $y(0) = 1$ e 1 subintervalo no intervalo [0, 1] para $x$, faz:

1) $y_1 = y_0 + h*y_0$
   $y_1 = 1 + 1*1 = 2$.

Para 4 subintervalos:

1) $y_1 = y_0 + h*y_0$

   $y_1 = 1 + 0.25*1 = 1.25;$

2) $y_2 = y_1 + h*y_1$

   $y_2 = 1.25 + 0.25*1.25 = 1.5625;$

3) $y_3 = y_2 + h*y_2$

   $y_3 = 1.5625 + 0.25*1.5625 = 1.953125;$

4) $y_4 = y_3 + h*y_3$

   $y_4 = 1.953125 + 0.25*1.953125 = 2.44140625.$

Note que, uma vez que a solução de $\frac{dy}{dx}=y$ deve ser $e^x$, 2.44140625 é mais próximo de $e^x$ do que 2 é próximo de $e^x$. Assim sendo, nota-se uma característica do Método de Euler:

__Mais subintervalos garantem maior precisão.__