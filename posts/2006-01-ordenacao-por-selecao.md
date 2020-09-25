---
title: Ordenação por Seleção
type: post
date: 2006-01-13T11:50:14+00:00
excerpt: Este é o segundo algoritmo de ordenação que estudamos e talvez seja o mais fácil deles. Tem um custo um pouco maior que a Ordenação por Inserção, mas uma lógica muito simples. Vamos ver qual é a dele...
url: /2006/01/ordenacao-por-selecao/
ordem:
  - eeell
categorias:
  - Ordenação
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

<pre><code><strong>para</strong> <em>i</em> <span class="tex-render">\leftarrow{}</span> 1 <strong>até</strong> <em>tamanho-1</em>, <strong>faça</strong>
 <em>minimo</em> <span class="tex-render">\leftarrow{}</span> i
 <strong>para</strong> <em>j</em> <span class="tex-render">\leftarrow{}</span> <em>i</em>+1 <strong>até</strong> <em>tamanho</em>, <strong>faça</strong>
     <strong>se</strong> <em>vetor[j]</em> < <em>vetor[minimo]</em>, <strong>então</strong>
         <em>minimo</em> <span class="tex-render">\leftarrow{}</span> j
     <strong>fim-se</strong>
 <strong>fim-para</strong>
 <em>temp</em> <span class="tex-render">\leftarrow{}</span> <em>vetor[i]</em>
 <em>vetor[i]</em> <span class="tex-render">\leftarrow{}</span> <em>vetor[minimo]</em>
<em>vetor[minimo]</em> <span class="tex-render">\leftarrow{}</span> <em>temp</em>
<strong>fim-para</strong></code></pre>

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

Aí ele começa com <span class="tex-render">i=1</span>. Vou sempre marcar \\(i\\) com a cor **preta** e \\(min\\) com a cor **cinza**.

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

Ele marca o próprio índice _i_ como a variável _minimo_, que é sempre o menor elemento do vetor. Então, ele faz um **para** de \\(j=2\\) até o comprimento do vetor, com o objetivo de descobrir qual o menor elemento.

\\(j=2\\) … \\(v[j] = 3 < v[minimo] = v[1] = 5\\), portanto \\(minimo = j = 2\\).

<table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td class="cinza">3</td> <td>7</td> <td>8</td> <td>2</td> <td>5</td> </tr> </table>

\\(j=3\\) ... \\(v[j] = 3 < v[minimo] = v[1] = 5\\), portanto \\(minimo = j = 2\\).

<table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td class="cinza">3</td> <td>7</td> <td>8</td> <td>2</td> <td>5</td> </tr> </table>

\\(j=3\\) ... \\(v[j] = 7 > v[minimo] = v[2] = 3\\), portanto não mexemos em nada.

\\(j=4\\) ... \\(v[j] = 8 > v[minimo] = v[2] = 3\\), portanto não mexemos em nada.

\\(j=5\\) ... \\(v[j] = 2 < v[minimo] = v[2] = 3\\), portanto \\(minimo = j = 5\\).

<table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td>3</td> <td>7</td> <td>8</td> <td class="cinza">2</td> <td>5</td> </tr> </table>

\\(j=6\\) ... \\(v[j] = 2 < v[minimo] = v[2] = 3\\), portanto \\(minimo = j = 5\\).

<table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td>3</td> <td>7</td> <td>8</td> <td class="cinza">2</td> <td>5</td> </tr> </table>

\\(j=6\\) ... \\(v[j] = 5 > v[minimo] = v[5] = 2\\), portanto não mexemos em nada.

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

  1. <span class="tex-render">n</span>
  2. <span class="tex-render">n</span>
  3. <span class="tex-render">\sum_{j=1}^{n} n</span>
  4. <span class="tex-render">\sum_{j=1}^{n} 1</span>
  5. <span class="tex-render">\sum_{j=1}^{n} 1</span>
  6. <span class="tex-render">0</span>
  7. <span class="tex-render">0</span>
  8. <span class="tex-render">n-1</span>
  9. <span class="tex-render">n-1</span>
 10. <span class="tex-render">n-1</span>
 11. <span class="tex-render">0</span>

Você pode estar se perguntando porque eu coloquei este custo para a linha 5. Afinal, a linha 5 diria que este programa tem um melhor/pior caso, porque ela não seria executada se o **se** retornar falso. Mas o caso é que ela é desprezível. Uma soma como estas para o custo geral do nosso algoritmo não vai influenciar em nada. Quer ver? Vamos somar os custos com esta linha valendo \\(0\\) (como se nenhum **se** entrasse) e depois com ela valendo \\(\sum\_{j=1}^{n}\\).

#### Primeiro cálculo

$$T(n) = n + (n-1) + (\sum\_{j=1}^n n) + (\sum\\_{j=1}^n 1) \times 2 + 0 \times 3 + (n-1) \times 3 + 0$$

$$T(n) = n^{2} + 6n - 3 = \Theta{}(n^2)$$

#### Segundo cálculo

$$T(n) = n + (n-1) + (\sum\_{j=1}^n n) + (\sum\\_{j=1}^n 1) \times 3 + 0 \times 2 + (n-1) \times 3 + 0$$

$$T(n) = 1,5 n^{2} + 6,5 n - 3 = \Theta{}(n^2)$$

#### Conclusão

Como vocês puderam ver, não faz diferença alguma o \\(\frac{n^{2} + n}{2}\\) que aquela somatória nos proporciona. Já que todo o cálculo de algoritmos é baseado apenas no maior expoente de **n** e desprezamos todas as constantes (inclusive as que multiplicam o **n** de maior expoente, muitos passos são desprezíveis.

