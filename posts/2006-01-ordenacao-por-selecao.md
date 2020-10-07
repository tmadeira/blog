---
title: Ordenação por Seleção
date: 2006-01-13T11:50:14+00:00
excerpt: Este é o segundo algoritmo de ordenação que estudamos e talvez seja o mais fácil deles. Tem um custo um pouco maior que a Ordenação por Inserção, mas uma lógica muito simples. Vamos ver qual é a dele...
url: /2006/01/ordenacao-por-selecao/
tags:
  - algoritmos
  - análise de algoritmos
  - ordenação
  - ordenação por seleção
  - pseudocódigos
  - selection sort
  - vetores
---

Hoje vou apresentar mais um algoritmo de ordenação de vetores. É a **Ordenação por Seleção** (ou _Selection Sort_). Sem mais papo e antes mesmo da explicação, vamos ao seu pseudocódigo:

**para** _i_ $\leftarrow{}$ 1 **até** _tamanho-1_, **faça**  
 &emsp;_minimo_ $\leftarrow{}$ i  
 &emsp;**para** _j_ $\leftarrow{}$ _i_+1 **até** _tamanho_, **faça**  
 &emsp;&emsp;**se** _vetor[j]_ < _vetor[minimo]_, **então**  
 &emsp;&emsp;&emsp;_minimo_ $\leftarrow{}$ j  
 &emsp;&emsp;**fim-se**  
 &emsp;**fim-para**  
 &emsp;_temp_ $\leftarrow{}$ _vetor[i]_  
 &emsp;_vetor[i]_ $\leftarrow{}$ _vetor[minimo]_  
 &emsp;_vetor[minimo]_ $\leftarrow{}$ _temp_  
**fim-para**

_tamanho_ = comprimento do vetor

### Funcionamento

A idéia é sempre procurar o menor elemento do vetor e inseri-lo no início do vetor. Procuramos o menor valor do vetor e colocamos ele em _vetor[1]_. Procuramos o menor valor do vetor excluindo o já colocado e colocamos ele em _vetor[2]_. E assim vamos indo até termos todo o vetor ordenado.

Partindo sempre a partir do último elemento reordenado (a partir do _i_), o programa procura o menor elemento no vetor e o substitue pelo elemento _i_ atual.

### Exemplo de Funcionamento

<style>
.preto {
  background: #000;
  color: #fff;
}

.cinza {
  background: #999;
}
</style>

O programa recebe o seguinte vetor.

<table>
  <tr>
    <td>
      v[1]
    </td>
    <td>
      v[2]
    </td>
    <td>
      v[3]
    </td>
    <td>
      v[4]
    </td>
    <td>
      v[5]
    </td>
    <td>
      v[6]
    </td>
  </tr>
  <tr>
    <td>
      5
    </td>
    <td>
      3
    </td>
    <td>
      7
    </td>
    <td>
      8
    </td>
    <td>
      2
    </td>
    <td>
      5
    </td>
  </tr>
</table>

Aí ele começa com $i=1$. Vou sempre marcar $i$ com a cor **preta** e $min$ com a cor **cinza**.

<table>
  <tr>
    <td>
      v[1]
    </td>
    <td>
      v[2]
    </td>
    <td>
      v[3]
    </td>
    <td>
      v[4]
    </td>
    <td>
      v[5]
    </td>
    <td>
      v[6]
    </td>
  </tr>
  <tr>
    <td class="preto">
      5
    </td>
    <td>
      3
    </td>
    <td>
      7
    </td>
    <td>
      8
    </td>
    <td>
      2
    </td>
    <td>
      5
    </td>
  </tr>
</table>

Ele marca o próprio índice _i_ como a variável _minimo_, que é sempre o menor elemento do vetor. Então, ele faz um **para** de $j=2$ até o comprimento do vetor, com o objetivo de descobrir qual o menor elemento.

$j=2$ … $v[j] = 3 < v[minimo] = v[1] = 5$, portanto $minimo = j = 2$.

<table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td class="cinza">3</td> <td>7</td> <td>8</td> <td>2</td> <td>5</td> </tr> </table>

$j=3$ ... $v[j] = 3 < v[minimo] = v[1] = 5$, portanto $minimo = j = 2$.

<table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td class="cinza">3</td> <td>7</td> <td>8</td> <td>2</td> <td>5</td> </tr> </table>

$j=3$ ... $v[j] = 7 > v[minimo] = v[2] = 3$, portanto não mexemos em nada.

$j=4$ ... $v[j] = 8 > v[minimo] = v[2] = 3$, portanto não mexemos em nada.

$j=5$ ... $v[j] = 2 < v[minimo] = v[2] = 3$, portanto $minimo = j = 5$.

<table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td>3</td> <td>7</td> <td>8</td> <td class="cinza">2</td> <td>5</td> </tr> </table>

$j=6$ ... $v[j] = 2 < v[minimo] = v[2] = 3$, portanto $minimo = j = 5$.

<table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td>3</td> <td>7</td> <td>8</td> <td class="cinza">2</td> <td>5</td> </tr> </table>

$j=6$ ... $v[j] = 5 > v[minimo] = v[5] = 2$, portanto não mexemos em nada.

Agora substituímos o _v[minimo]_ pelo _v[i]_, formando com isto o novo vetor:

<table>
  <tr>
    <td>
      v[1]
    </td>
    <td>
      v[2]
    </td>
    <td>
      v[3]
    </td>
    <td>
      v[4]
    </td>
    <td>
      v[5]
    </td>
    <td>
      v[6]
    </td>
  </tr>
  <tr>
    <td class="cinza">
      2
    </td>
    <td>
      3
    </td>
    <td>
      7
    </td>
    <td>
      8
    </td>
    <td class="preto">
      5
    </td>
    <td>
      5
    </td>
  </tr>
</table>

E assim vamos fazendo com os outros elementos até que todo o vetor esteja ordenado.

### Custo

Este algoritmo não tem um melhor/pior caso, porque todos os elementos são varridos, sempre. Medir seu custo é simples. Custo de linha por linha...

_n_ = tamanho do vetor

1. $n$
2. $n$
3. $\sum\_{j=1}^{n} n$
4. $\sum\_{j=1}^{n} 1$
5. $\sum\_{j=1}^{n} 1$
6. $0$
7. $0$
8. $n-1$
9. $n-1$
10. $n-1$
11. $0$

Você pode estar se perguntando porque eu coloquei este custo para a linha 5. Afinal, a linha 5 diria que este programa tem um melhor/pior caso, porque ela não seria executada se o **se** retornar falso. Mas o caso é que ela é desprezível. Uma soma como estas para o custo geral do nosso algoritmo não vai influenciar em nada. Quer ver? Vamos somar os custos com esta linha valendo $0$ (como se nenhum **se** entrasse) e depois com ela valendo $\sum\_{j=1}^{n}$.

#### Primeiro cálculo

$$
T(n) = n + (n-1) + (\sum\_{j=1}^n n) + \\
(\sum\\_{j=1}^n 1) \times 2 + 0 \times 3 + (n-1) \times 3 + 0
$$

$$
T(n) = n^{2} + 6n - 3 = \Theta{}(n^2)
$$

#### Segundo cálculo

$$
T(n) = n + (n-1) + (\sum\_{j=1}^n n) + \\
(\sum\\_{j=1}^n 1) \times 3 + 0 \times 2 + (n-1) \times 3 + 0
$$

$$
T(n) = 1,5 n^{2} + 6,5 n - 3 = \Theta{}(n^2)
$$

#### Conclusão

Como vocês puderam ver, não faz diferença alguma o $\frac{n^{2} + n}{2}$ que aquela somatória nos proporciona. Já que todo o cálculo de algoritmos é baseado apenas no maior expoente de **n** e desprezamos todas as constantes (inclusive as que multiplicam o **n** de maior expoente, muitos passos são desprezíveis.
