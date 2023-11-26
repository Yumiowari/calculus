## Forma de Lagrange

Para $x$ e $f(x)$ observados. A cada iteração, o resultado será incrementado em

$$f(x_i)*L_i(x)$$

onde $x$ é sabido.

Uma vez que o polinômio de lagrange é dado por:

$$P_n(x)=f(x_0).L_0(x)+f(x_1).L_1(x)+...+f(x_{n}).L_n(x).$$

$$L_k = \frac{(x-x_1).(x-x_2)...(x-x_{n-1}).(x-x_n)}{(x_k-x_0).(x_k-x_1)...(x_k-x_{n-1}.(x_k-x_n)}.$$