---
title: Ordenação por Inserção
type: post
date: 2006-01-11T21:32:04+00:00
excerpt: Também conhecida como Insertion Sort, a Ordenação por Inserção consiste em inserir um elemento N num vetor já ordenado de N-1 elementos. Neste artigo, apresento-lhes este simples algoritmo para ordenação de vetores.
url: /2006/01/ordenacao-por-insercao/
ordem:
  - eeekk
categories:
  - Ordenação
tags:
  - algoritmos
  - análise de algoritmos
  - insertion sort
  - ordenação
  - ordenação por inserção
  - pior caso
  - pseudocódigos
  - vetores

---
Também conhecida como _Insertion Sort_, a **Ordenação por Inserção** consiste em inserir um elemento \\(n\\) num vetor já ordenado de \\(n-1\\) elementos. Neste artigo, apresento-lhes este simples algoritmo para **ordenação de vetores**.

O pseudocódigo da **ordenação por inserção** é o seguinte:

<pre><code><strong>para</strong> <em>j</em> <span class="tex-render">\leftarrow{}</span> 2 <strong>até</strong> <em>comprimento do vetor</em>, <strong>faça</strong>
 <em>elemento</em> <span class="tex-render">\leftarrow{}</span> <em>vetor[j]</em>
 <em>i</em> <span class="tex-render">\leftarrow{}</span> <em>j</em> - 1
 <strong>enquanto</strong> <em>i</em> > 0 e <em>vetor[i]</em> > <em>elemento</em>, <strong>faça</strong>
     <em>vetor[i + 1]</em> <span class="tex-render">\leftarrow{}</span> <em>vetor[i]</em>
     <em>i</em> <span class="tex-render">\leftarrow{}</span> <em>i</em> - 1
 <strong>fim-enquanto</strong>
 <em>vetor[i + 1]</em> <span class="tex-render">\leftarrow{}</span> <em>elemento</em>
<strong>fim-para</strong></code></pre>

Para explicar eu vou fazer uma coisa que sempre faço para corrigir meus algoritmos, fingir que sou o programa, executando cada passo manualmente (claro que geralmente faço mais rápido, porque não preciso escrever tudo que faço). Vamos iniciar com o seguinte vetor **v**.

<style>
.preto { background: #000; color: #fff; }
.cinza { background: #999; }
</style>

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

    <td class="preto">
      3
    </td>

    <td class="preto">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

Aí o código me manda começar com \\(j=2\\) e iterar até o comprimento do vetor (6). A primeira ordem que ele me dá é para armazenar o elemento \\(a[j]\\) (<span class="tex-render">a[2]</span>) na variável **elemento**. Para facilitar toda a explicação eu vou sempre pintar de cinza o \\(v[j]\\) onde eu estou (no caso, o segundo elemento do vetor, 3) e de preto o vetor ainda não ordenado (elementos <span class="tex-render">\geq{}j</span>).

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

    <td class="cinza">
      3
    </td>

    <td class="preto">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

Então ele me diz que <span class="tex-render">i \leftarrow{} j-1</span>. Portanto, <span class="tex-render">i=1</span>. E agora ele me faz um **enquanto** (que poderia ser substituído por **para**) onde meu **i** deverá ir diminuindo. Vamos entrar no loop…

Bom, meu \\(i = 1\\) é maior que 0. \\(v[1]=5\\) é maior que o <span class="tex-render">elemento=3</span>? Sim, então vamos entrar no corpo do **enquanto**… Aqui ele me manda fazer um <span class="tex-render">vetor[i+1] = vetor[i]</span>, que nesse caso é fazer um <span class="tex-render">v[2]=v[1]=5</span>.

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

    <td class="cinza">
      5
    </td>

    <td class="preto">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

E agora subtrai de **i** um valor. Portanto, <span class="tex-render">i=0</span>. Ele retorna ao **enquanto**, mas agora não satisfazemos a condição \\(i>0\\), por isso saímos do **enquanto**. Então ele pede para \\(vetor[i+1]=elemento\\) (<span class="tex-render">v[1]=elemento</span>). Portanto, o vetor fica assim:

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
      3
    </td>

    <td>
      5
    </td>

    <td class="preto">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

E incrementamos o **j**, agora <span class="tex-render">j=3</span>.

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
      3
    </td>

    <td>
      5
    </td>

    <td class="cinza">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

<span class="tex-render">elemento = 7</span>
<span class="tex-render">i = 3-1 = 2</span>

\\(i > 0\\)… E \\(5 > 7\\)? Não! Portanto, não entramos no **enquanto**.

\\(v[3] = elemento\\) (nenhuma mudança)

E lá vamos para \\(j=4\\) e continuando até que vamos ter o vetor ordenado:

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
      2
    </td>

    <td>
      3
    </td>

    <td>
      5
    </td>

    <td>
      5
    </td>

    <td>
      7
    </td>

    <td>
      8
    </td>
  </tr>
</table>

### Qual a lógica?

Como eu já disse na introdução, mas lá sem grandes explicações, a _Ordenação por Inserção_ divide o vetor em dois. O primeiro (de elementos \\(< j\\)) contém todos seus valores ordenados e o segundo (de elementos \\(\geq{} j\\)) contém os valores que devem ser <strong>inseridos</strong> no <em>primeiro</em> vetor já ordenado (por isso ele se chama <strong>Algoritmo de Inserção</strong>). A chave do algoritmo é o <strong>enquanto</strong> que acontece para ir deslocando todos os elementos para seu índice \\(+1\\)) contém todos seus valores ordenados e o segundo (de elementos \\(\geq{}j\\)) contém os valores que devem ser <strong>inseridos</strong> no <em>primeiro</em> vetor já ordenado (por isso ele se chama <strong>Algoritmo de Inserção</strong>).

A variável **elemento** só serve para não perdermos o valor de \\(v[j]\\) (porque depois fazemos \\(v[i+1]=v[i]\\) quando <span class="tex-render">i=j-1</span>)

Acredito que não tenham restado dúvidas. Dê mais uma olhada no algoritmo e tente implementar. Se tiver dificulade, coloque mensagens de debug estratégicas para entender o algoritmo. (ex.: no início do **para** coloque para imprimir o valor de _j_ e no início de cada **enquanto** coloque para imprimir os valores **elemento**, **i** e **v[i]**)

### Custo

Você deve ter percebido que este algoritmo não tem um custo fixo. Se todo o vetor estiver ordenado, ele nunca precisará iterar o \\(i\\) e portanto será executado bem mais rápido do que se o vetor estiver inteiro em ordem decrescente (quando ele sempre precisará iterar \\(i\\) até o fim - 0). Então, neste artigo, gostaria-lhes de apresentar a análise de algoritmos baseada em casos. Para este programa, dizemos que:

  * **Melhor caso** é quando todos os elementos já estão ordenados. Custo: <span class="tex-render">\Theta{}(n)</span>
  * **Pior caso** é quando os elementos estão em ordem decrescente. Custo: <span class="tex-render">\Theta{}(n^{2})</span>

Em alguns programas o _caso médio_ é importante também, mas não é o caso da **ordenação por inserção**. Vemos que há uma diferença bem grande entre o custo dos dois casos. Por isso, precisamos conhecer onde que nosso algoritmo será implementado e quais as chances de ele ser o melhor ou pior caso. Em geral, o **pior caso** é o mais comum... Por isso, diremos que o custo deste algoritmo é <span class="tex-render">\Theta{}(n^{2})</span>.

