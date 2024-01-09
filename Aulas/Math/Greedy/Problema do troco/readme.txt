Algoritmo Guloso para o Problema do Troco
Como dito antes, para um sistema de moedas 𝐴 = {𝐶1, 𝐶2, ..., 𝐶𝑚}, com 𝐶1 = 1 e
𝐶1 < 𝐶2 < ... < 𝐶𝑚, e um troco 𝑊, o algoritmo guloso só tem garantia de correção caso
𝐴 seja canônico. De toda forma, o algoritmo é simples de entender, eficiente em tempo
de execução, tendo complexidade assintótica 𝑂(𝑚), e em memória, tendo complexidadea ssintótica 𝑂(1).

Algoritmo de Determinação de Canonicidade para o Problema do Troco
Como dito anteriormente, é possível determinar se um dado sistemas de moedas é canônico em 𝑂(𝑚^2) (onde 𝑚 é a quantidade de moedas do sistema) utilizando um algoritmo de canonicidade proposto por Cai (2009). Seu funcionamento pode ser visualizado no Algoritmo 6

Se o sistema de moedas nao for canonico, teremos que recorrer a tecnicas de programacao dinamica

1. Determinar a canonicidade do sistema de moedas 𝐴 em 𝑂(𝑚^2) com o Algoritmo de Canonicidade descrito na Seção 1.3.3.
1.1. Caso 𝐴 seja canônico, obter a resposta em 𝑂(𝑚) com o Algoritmo Guloso
descrito na Seção 1.3.3.
1.2. Caso 𝐴 não seja canônico, obter a resposta em 𝑂(𝑊𝑚) com o Algoritmo de Programação Dinâmica descrito na Seção 1.3.3.
