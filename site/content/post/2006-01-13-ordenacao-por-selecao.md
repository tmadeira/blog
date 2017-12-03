---
title: Ordenação por Seleção
type: post
date: 2006-01-13T11:50:14+00:00
excerpt: Este é o segundo algoritmo de ordenação que estudamos e talvez seja o mais fácil deles. Tem um custo um pouco maior que a Ordenação por Inserção, mas uma lógica muito simples. Vamos ver qual é a dele...
url: /2006/01/ordenacao-por-selecao/
ordem:
  - eeell
categories:
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

```
1. <strong>para</strong> <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> 1 <strong>até</strong> <em>tamanho-1</em>, <strong>faça</strong>
2.  <em>minimo</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> i
3.  <strong>para</strong> <em>j</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>i</em>+1 <strong>até</strong> <em>tamanho</em>, <strong>faça</strong>
4.      <strong>se</strong> <em>vetor[j]</em> < <em>vetor[minimo]</em>, <strong>então</strong>
5.          <em>minimo</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> j
6.      <strong>fim-se</strong>
7.  <strong>fim-para</strong>
8.  <em>temp</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>vetor[i]</em>
9.  <em>vetor[i]</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>vetor[minimo]</em>
10. <em>vetor[minimo]</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>temp</em>
11. <strong>fim-para</strong>
```

_tamanho_ = comprimento do vetor

### Funcionamento

A idéia é sempre procurar o menor elemento do vetor e inseri-lo no início do vetor. Procuramos o menor valor do vetor e colocamos ele em _vetor[1]_. Procuramos o menor valor do vetor excluindo o já colocado e colocamos ele em _vetor[2]_. E assim vamos indo até termos todo o vetor ordenado.

Partindo sempre a partir do último elemento reordenado (a partir do _i_), o programa procura o menor elemento no vetor e o substitue pelo elemento _i_ atual.

### Exemplo de Funcionamento

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

Aí ele começa com <img src='https://s0.wp.com/latex.php?latex=i%3D1&bg=T&fg=000000&s=0' alt='i=1' title='i=1' class='latex' />. Vou sempre marcar  <img src='https://s0.wp.com/latex.php?latex=i&bg=T&fg=000000&s=0' alt='i' title='i' class='latex' />com a cor **preta** e  <img src='https://s0.wp.com/latex.php?latex=min&bg=T&fg=000000&s=0' alt='min' title='min' class='latex' />com a cor **cinza**.

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

Ele marca o próprio índice _i_ como a variável _minimo_, que é sempre o menor elemento do vetor. Então, ele faz um **para** de  <img src='https://s0.wp.com/latex.php?latex=j%3D2&bg=T&fg=000000&s=0' alt='j=2' title='j=2' class='latex' />até o comprimento do vetor, com o objetivo de descobrir qual o menor elemento.

 <img src='https://s0.wp.com/latex.php?latex=j%3D2&bg=T&fg=000000&s=0' alt='j=2' title='j=2' class='latex' />…  <img src='https://s0.wp.com/latex.php?latex=v%5Bj%5D+%3D+3+%3C+v%26%2391%3Bminimo%26%2393%3B+%3D+v%26%2391%3B1%26%2393%3B+%3D+5%26%2391%3B%2Flatex%26%2393%3B%2C+portanto+%26%2391%3Blatex%26%2393%3Bminimo+%3D+j+%3D+2%26%2391%3B%2Flatex%26%2393%3B.++%3Ctable%3E+%3Cthead%3E+%3Ctr%3E+%3Ctd%3Ev%5B1%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B2%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B3%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B4%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B5%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B6%5D%3C%2Ftd%3E+%3C%2Ftr%3E+%3C%2Fthead%3E+%3Ctr%3E+%3Ctd+class%3D%22preto%22%3E5%3C%2Ftd%3E+%3Ctd+class%3D%22cinza%22%3E3%3C%2Ftd%3E+%3Ctd%3E7%3C%2Ftd%3E+%3Ctd%3E8%3C%2Ftd%3E+%3Ctd%3E2%3C%2Ftd%3E+%3Ctd%3E5%3C%2Ftd%3E+%3C%2Ftr%3E+%3C%2Ftable%3E++%5Blatex%5Dj%3D3&bg=T&fg=000000&s=0' alt='v[j] = 3 < v[minimo] = v[1] = 5[/latex], portanto [latex]minimo = j = 2[/latex].  <table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td class="cinza">3</td> <td>7</td> <td>8</td> <td>2</td> <td>5</td> </tr> </table>  [latex]j=3' title='v[j] = 3 < v[minimo] = v[1] = 5[/latex], portanto [latex]minimo = j = 2[/latex].  <table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td class="cinza">3</td> <td>7</td> <td>8</td> <td>2</td> <td>5</td> </tr> </table>  [latex]j=3' class='latex' />... <img src='https://s0.wp.com/latex.php?latex=v%5Bj%5D+%3D+7+%3E+v%5Bminimo%5D+%3D+v%5B2%5D+%3D+3&bg=T&fg=000000&s=0' alt='v[j] = 7 > v[minimo] = v[2] = 3' title='v[j] = 7 > v[minimo] = v[2] = 3' class='latex' />, portanto não mexemos em nada.

 <img src='https://s0.wp.com/latex.php?latex=j%3D4&bg=T&fg=000000&s=0' alt='j=4' title='j=4' class='latex' />... <img src='https://s0.wp.com/latex.php?latex=v%5Bj%5D+%3D+8+%3E+v%5Bminimo%5D+%3D+v%5B2%5D+%3D+3&bg=T&fg=000000&s=0' alt='v[j] = 8 > v[minimo] = v[2] = 3' title='v[j] = 8 > v[minimo] = v[2] = 3' class='latex' />, portanto não mexemos em nada.

 <img src='https://s0.wp.com/latex.php?latex=j%3D5&bg=T&fg=000000&s=0' alt='j=5' title='j=5' class='latex' />...  <img src='https://s0.wp.com/latex.php?latex=v%5Bj%5D+%3D+2+%3C+v%26%2391%3Bminimo%26%2393%3B+%3D+v%26%2391%3B2%26%2393%3B+%3D+3%26%2391%3B%2Flatex%26%2393%3B%2C+portanto+%26%2391%3Blatex%26%2393%3Bminimo+%3D+j+%3D+5%26%2391%3B%2Flatex%26%2393%3B.++%3Ctable%3E+%3Cthead%3E+%3Ctr%3E+%3Ctd%3Ev%5B1%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B2%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B3%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B4%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B5%5D%3C%2Ftd%3E+%3Ctd%3Ev%5B6%5D%3C%2Ftd%3E+%3C%2Ftr%3E+%3C%2Fthead%3E+%3Ctr%3E+%3Ctd+class%3D%22preto%22%3E5%3C%2Ftd%3E+%3Ctd%3E3%3C%2Ftd%3E+%3Ctd%3E7%3C%2Ftd%3E+%3Ctd%3E8%3C%2Ftd%3E+%3Ctd+class%3D%22cinza%22%3E2%3C%2Ftd%3E+%3Ctd%3E5%3C%2Ftd%3E+%3C%2Ftr%3E+%3C%2Ftable%3E++%5Blatex%5Dj%3D6&bg=T&fg=000000&s=0' alt='v[j] = 2 < v[minimo] = v[2] = 3[/latex], portanto [latex]minimo = j = 5[/latex].  <table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td>3</td> <td>7</td> <td>8</td> <td class="cinza">2</td> <td>5</td> </tr> </table>  [latex]j=6' title='v[j] = 2 < v[minimo] = v[2] = 3[/latex], portanto [latex]minimo = j = 5[/latex].  <table> <thead> <tr> <td>v[1]</td> <td>v[2]</td> <td>v[3]</td> <td>v[4]</td> <td>v[5]</td> <td>v[6]</td> </tr> </thead> <tr> <td class="preto">5</td> <td>3</td> <td>7</td> <td>8</td> <td class="cinza">2</td> <td>5</td> </tr> </table>  [latex]j=6' class='latex' />... <img src='https://s0.wp.com/latex.php?latex=v%5Bj%5D+%3D+5+%3E+v%5Bminimo%5D+%3D+v%5B5%5D+%3D+2&bg=T&fg=000000&s=0' alt='v[j] = 5 > v[minimo] = v[5] = 2' title='v[j] = 5 > v[minimo] = v[5] = 2' class='latex' />, portanto não mexemos em nada.

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

  1. <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />
  2. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />
  3. <img src='https://s0.wp.com/latex.php?latex=%5Csum_%7Bj%3D1%7D%5E%7Bn%7D+%2B+n&bg=T&fg=000000&s=0' alt='\sum_{j=1}^{n} + n' title='\sum_{j=1}^{n} + n' class='latex' />
  4. <img src='https://s0.wp.com/latex.php?latex=%5Csum_%7Bj%3D1%7D%5E%7Bn%7D&bg=T&fg=000000&s=0' alt='\sum_{j=1}^{n}' title='\sum_{j=1}^{n}' class='latex' />
  5.  <img src='https://s0.wp.com/latex.php?latex=%5Csum_%7Bj%3D1%7D%5E%7Bn%7D&bg=T&fg=000000&s=0' alt='\sum_{j=1}^{n}' title='\sum_{j=1}^{n}' class='latex' />???
  6. <img src='https://s0.wp.com/latex.php?latex=0&bg=T&fg=000000&s=0' alt='0' title='0' class='latex' />
  7. <img src='https://s0.wp.com/latex.php?latex=0&bg=T&fg=000000&s=0' alt='0' title='0' class='latex' />
  8. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />
  9. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />
 10. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />
 11. <img src='https://s0.wp.com/latex.php?latex=0&bg=T&fg=000000&s=0' alt='0' title='0' class='latex' />

Você pode estar se perguntando porque eu coloquei este custo para a linha 5. Afinal, a linha 5 diria que este programa tem um melhor/pior caso, porque ela não seria executada se o **se** retornar falso. Mas o caso é que ela é desprezível. Uma soma como estas para o custo geral do nosso algoritmo não vai influenciar em nada. Quer ver? Vamos somar os custos com esta linha valendo  <img src='https://s0.wp.com/latex.php?latex=0&bg=T&fg=000000&s=0' alt='0' title='0' class='latex' />(como se nenhum **se** entrasse) e depois com ela valendo <img src='https://s0.wp.com/latex.php?latex=%5Csum_%7Bj%3D1%7D%5E%7Bn%7D&bg=T&fg=000000&s=0' alt='\sum_{j=1}^{n}' title='\sum_{j=1}^{n}' class='latex' />.

#### Primeiro cálculo

 <img src='https://s0.wp.com/latex.php?latex=T%28n%29&bg=T&fg=000000&s=0' alt='T(n)' title='T(n)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%3D&bg=T&fg=000000&s=0' alt='=' title='=' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n%29&bg=T&fg=000000&s=0' alt='(n)' title='(n)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n-1%29&bg=T&fg=000000&s=0' alt='(n-1)' title='(n-1)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28%5Csum_%7Bj%3D1%7D%5E%7Bn%7D+%2B+n%29&bg=T&fg=000000&s=0' alt='(\sum_{j=1}^{n} + n)' title='(\sum_{j=1}^{n} + n)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28%5Csum_%7Bj%3D1%7D%5E%7Bn%7D%29&bg=T&fg=000000&s=0' alt='(\sum_{j=1}^{n})' title='(\sum_{j=1}^{n})' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%280%29&bg=T&fg=000000&s=0' alt='(0)' title='(0)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%280%29&bg=T&fg=000000&s=0' alt='(0)' title='(0)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%280%29&bg=T&fg=000000&s=0' alt='(0)' title='(0)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n-1%29&bg=T&fg=000000&s=0' alt='(n-1)' title='(n-1)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n-1%29&bg=T&fg=000000&s=0' alt='(n-1)' title='(n-1)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n-1%29&bg=T&fg=000000&s=0' alt='(n-1)' title='(n-1)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /><img src='https://s0.wp.com/latex.php?latex=%280%29&bg=T&fg=000000&s=0' alt='(0)' title='(0)' class='latex' />


<img src='https://s0.wp.com/latex.php?latex=T%28n%29+%3D+n%5E%7B2%7D+%2B+6n+-3&bg=T&fg=000000&s=0' alt='T(n) = n^{2} + 6n -3' title='T(n) = n^{2} + 6n -3' class='latex' />
<img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28n%5E%7B2%7D%29+%3D+f%28n%29&bg=T&fg=000000&s=0' alt='\Theta{}(n^{2}) = f(n)' title='\Theta{}(n^{2}) = f(n)' class='latex' />

#### Segundo cálculo

 <img src='https://s0.wp.com/latex.php?latex=T%28n%29&bg=T&fg=000000&s=0' alt='T(n)' title='T(n)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%3D&bg=T&fg=000000&s=0' alt='=' title='=' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n%29&bg=T&fg=000000&s=0' alt='(n)' title='(n)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n-1%29&bg=T&fg=000000&s=0' alt='(n-1)' title='(n-1)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28%5Csum_%7Bj%3D1%7D%5E%7Bn%7D+%2B+n%29&bg=T&fg=000000&s=0' alt='(\sum_{j=1}^{n} + n)' title='(\sum_{j=1}^{n} + n)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28%5Csum_%7Bj%3D1%7D%5E%7Bn%7D%29&bg=T&fg=000000&s=0' alt='(\sum_{j=1}^{n})' title='(\sum_{j=1}^{n})' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28%5Csum_%7Bj%3D1%7D%5E%7Bn%7D%29&bg=T&fg=000000&s=0' alt='(\sum_{j=1}^{n})' title='(\sum_{j=1}^{n})' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%280%29&bg=T&fg=000000&s=0' alt='(0)' title='(0)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%280%29&bg=T&fg=000000&s=0' alt='(0)' title='(0)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n-1%29&bg=T&fg=000000&s=0' alt='(n-1)' title='(n-1)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n-1%29&bg=T&fg=000000&s=0' alt='(n-1)' title='(n-1)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%28n-1%29&bg=T&fg=000000&s=0' alt='(n-1)' title='(n-1)' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%2B&bg=T&fg=000000&s=0' alt='+' title='+' class='latex' /><img src='https://s0.wp.com/latex.php?latex=%280%29&bg=T&fg=000000&s=0' alt='(0)' title='(0)' class='latex' />


<img src='https://s0.wp.com/latex.php?latex=T%28n%29+%3D+1%2C5+n%5E%7B2%7D+%2B+6%2C5+n+-+3&bg=T&fg=000000&s=0' alt='T(n) = 1,5 n^{2} + 6,5 n - 3' title='T(n) = 1,5 n^{2} + 6,5 n - 3' class='latex' />
<img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28n%5E%7B2%7D%29+%3D+f%28n%29&bg=T&fg=000000&s=0' alt='\Theta{}(n^{2}) = f(n)' title='\Theta{}(n^{2}) = f(n)' class='latex' />

#### Conclusão

Como vocês puderam ver, não faz diferença alguma o  <img src='https://s0.wp.com/latex.php?latex=%5Cfrac%7Bn%5E%7B2%7D+%2B+n%7D%7B2%7D&bg=T&fg=000000&s=0' alt='\frac{n^{2} + n}{2}' title='\frac{n^{2} + n}{2}' class='latex' />que aquela somatória nos proporciona. Já que todo o cálculo de algoritmos é baseado apenas no maior expoente de **n** e desprezamos todas as constantes (inclusive as que multiplicam o **n** de maior expoente, muitos passos são desprezíveis.

