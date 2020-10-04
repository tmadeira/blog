---
title: Ordenação por Inserção
type: post
date: 2006-01-11T21:32:04+00:00
excerpt: Também conhecida como Insertion Sort, a Ordenação por Inserção consiste em inserir um elemento N num vetor já ordenado de N-1 elementos. Neste artigo, apresento-lhes este simples algoritmo para ordenação de vetores.
url: /2006/01/ordenacao-por-insercao/
ordem:
  - eeekk
categorias:
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

Também conhecida como _Insertion Sort_, a **Ordenação por Inserção** consiste em inserir um elemento $n$ num vetor já ordenado de $n-1$ elementos. Neste artigo, apresento-lhes este simples algoritmo para **ordenação de vetores**.

O pseudocódigo da **ordenação por inserção** é o seguinte:

**para** _j_ $\leftarrow{}$ 2 **até** _comprimento do vetor_, **faça**  
 &emsp;_elemento_ $\leftarrow{}$ _vetor[j]_  
 &emsp;_i_ $\leftarrow{}$ _j_ - 1  
 &emsp;**enquanto** _i_ > 0 e _vetor[i]_ > _elemento_, **faça**  
 &emsp;&emsp;_vetor[i + 1]_ $\leftarrow{}$ _vetor[i]_  
 &emsp;&emsp;_i_ $\leftarrow{}$ _i_ - 1  
 &emsp;**fim-enquanto**  
 &emsp;_vetor[i + 1]_ $\leftarrow{}$ _elemento_  
**fim-para**

<style>.preto{background:#000;color:#fff;}</style>

Para explicar eu vou fazer uma coisa que sempre faço para corrigir meus algoritmos, fingir que sou o programa, executando cada passo manualmente (claro que geralmente faço mais rápido, porque não preciso escrever tudo que faço). Vamos iniciar com o seguinte vetor **v**.

<table>
  <thead>
    <tr>
      <th>
        v[1]
      </th>
      <th>
        v[2]
      </th>
      <th>
        v[3]
      </th>
      <th>
        v[4]
      </th>
      <th>
        v[5]
      </th>
      <th>
        v[6]
      </th>
    </tr>
  </thead>
  <tbody>
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
  </tbody>
</table>

Aí o código me manda começar com $j=2$ e iterar até o comprimento do vetor (6). A primeira ordem que ele me dá é para armazenar o elemento $a[j]$ ($a[2]$) na variável **elemento**. Para facilitar toda a explicação eu vou sempre pintar de cinza o $v[j]$ onde eu estou (no caso, o segundo elemento do vetor, 3) e de preto o vetor ainda não ordenado (elementos $\geq{}j$).

<table>
  <thead>
    <tr>
      <th>
        v[1]
      </th>
      <th>
        v[2]
      </th>
      <th>
        v[3]
      </th>
      <th>
        v[4]
      </th>
      <th>
        v[5]
      </th>
      <th>
        v[6]
      </th>
    </tr>
  </thead>
  <tbody>
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
  </tbody>
</table>

Então ele me diz que $i \leftarrow{} j-1$. Portanto, $i=1$. E agora ele me faz um **enquanto** (que poderia ser substituído por **para**) onde meu **i** deverá ir diminuindo. Vamos entrar no loop…

Bom, meu $i = 1$ é maior que 0. $v[1]=5$ é maior que o $elemento=3$? Sim, então vamos entrar no corpo do **enquanto**… Aqui ele me manda fazer um $vetor[i+1] = vetor[i]$, que nesse caso é fazer um $v[2]=v[1]=5$.

<table>
  <thead>
    <tr>
      <th>
        v[1]
      </th>
      <th>
        v[2]
      </th>
      <th>
        v[3]
      </th>
      <th>
        v[4]
      </th>
      <th>
        v[5]
      </th>
      <th>
        v[6]
      </th>
    </tr>
  </thead>
  <tbody>
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
  </tbody>
</table>

E agora subtrai de **i** um valor. Portanto, $i=0$. Ele retorna ao **enquanto**, mas agora não satisfazemos a condição $i>0$, por isso saímos do **enquanto**. Então ele pede para $vetor[i+1]=elemento$ ($v[1]=elemento$). Portanto, o vetor fica assim:

<table>
  <thead>
    <tr>
      <th>
        v[1]
      </th>
      <th>
        v[2]
      </th>
      <th>
        v[3]
      </th>
      <th>
        v[4]
      </th>
      <th>
        v[5]
      </th>
      <th>
        v[6]
      </th>
    </tr>
  </thead>
  <tbody>
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
  </tbody>
</table>

E incrementamos o **j**, agora $j=3$.

<table>
  <thead>
    <tr>
      <th>
        v[1]
      </th>
      <th>
        v[2]
      </th>
      <th>
        v[3]
      </th>
      <th>
        v[4]
      </th>
      <th>
        v[5]
      </th>
      <th>
        v[6]
      </th>
    </tr>
  </thead>
  <tbody>
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
  </tbody>
</table>

$elemento = 7$

$i = 3-1 = 2$

$i > 0$… E $5 > 7$? Não! Portanto, não entramos no **enquanto**.

$v[3] = elemento$ (nenhuma mudança)

E lá vamos para $j=4$ e continuando até que vamos ter o vetor ordenado:

<table>
  <thead>
    <tr>
      <th>
        v[1]
      </th>
      <th>
        v[2]
      </th>
      <th>
        v[3]
      </th>
      <th>
        v[4]
      </th>
      <th>
        v[5]
      </th>
      <th>
        v[6]
      </th>
    </tr>
  </thead>
  <tbody>
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
  </tbody>
</table>

### Qual a lógica?

Como eu já disse na introdução, mas lá sem grandes explicações, a _Ordenação por Inserção_ divide o vetor em dois. O primeiro (de elementos $< j$) contém todos seus valores ordenados e o segundo (de elementos $\geq{} j$) contém os valores que devem ser <strong>inseridos</strong> no <em>primeiro</em> vetor já ordenado (por isso ele se chama <strong>Algoritmo de Inserção</strong>). A chave do algoritmo é o <strong>enquanto</strong> que acontece para ir deslocando todos os elementos para seu índice $+1$) contém todos seus valores ordenados e o segundo (de elementos $\geq{}j$) contém os valores que devem ser <strong>inseridos</strong> no <em>primeiro</em> vetor já ordenado (por isso ele se chama <strong>Algoritmo de Inserção</strong>).

A variável **elemento** só serve para não perdermos o valor de $v[j]$ (porque depois fazemos $v[i+1]=v[i]$ quando $i=j-1$)

Acredito que não tenham restado dúvidas. Dê mais uma olhada no algoritmo e tente implementar. Se tiver dificulade, coloque mensagens de debug estratégicas para entender o algoritmo. (ex.: no início do **para** coloque para imprimir o valor de _j_ e no início de cada **enquanto** coloque para imprimir os valores **elemento**, **i** e **v[i]**)

### Custo

Você deve ter percebido que este algoritmo não tem um custo fixo. Se todo o vetor estiver ordenado, ele nunca precisará iterar o $i$ e portanto será executado bem mais rápido do que se o vetor estiver inteiro em ordem decrescente (quando ele sempre precisará iterar $i$ até o fim - 0). Então, neste artigo, gostaria-lhes de apresentar a análise de algoritmos baseada em casos. Para este programa, dizemos que:

- **Melhor caso** é quando todos os elementos já estão ordenados. Custo: $\Theta{}(n)$
- **Pior caso** é quando os elementos estão em ordem decrescente. Custo: $\Theta{}(n^{2})$

Em alguns programas o _caso médio_ é importante também, mas não é o caso da **ordenação por inserção**. Vemos que há uma diferença bem grande entre o custo dos dois casos. Por isso, precisamos conhecer onde que nosso algoritmo será implementado e quais as chances de ele ser o melhor ou pior caso. Em geral, o **pior caso** é o mais comum... Por isso, diremos que o custo deste algoritmo é $\Theta{}(n^{2})$.
