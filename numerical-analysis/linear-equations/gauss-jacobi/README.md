## Gauss-Jacobi

A partir de valores sorteados na primeira iteração, soluções iniciais são calculados. Para que, nas próximas iterações, soluções sejam calculadas a partir dos resultados anteriores.

Em $\infty$ iterações, é certo que a solução real seja encontrada.

Para resolver em tempo humano, uma precisão é definida e, quando o erro relativo for inferior a ela, a solução é aceita.

Compilação: `gcc -Wall gauss-jacobi.c -o gauss-jacobi`

Uso: `./gauss-jacobi (nome do arquivo .txt em data/)`