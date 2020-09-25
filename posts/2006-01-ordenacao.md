---
title: Introdução à Ordenação de Vetores
type: post
date: 2006-01-10T00:52:10+00:00
excerpt: Nesse artigo, introduzo-lhes a ordenação de vetores. Um artigo light, apenas apresentando o conceito de vetor, de ordenação e pra que ela serve.
url: /2006/01/ordenacao/
ordem:
  - eeejj
categorias:
  - Ordenação
tags:
  - algoritmos
  - cartas
  - clrs
  - embaralhar
  - listas
  - ordenação
  - vetores

---
### O que é um vetor?

Vetor é uma estrutura de dados que serve para substituir várias variáveis. Para um problema pequeno onde desejo armazenar dois inteiros e tirar o _MMC_ deles eu posso usar duas variáveis: _n1_ e _n2_. Mas existem casos em que seria um número muito grande de variáveis (e em alguns deles nem sabemos ao certo, porque faremos uma alocação a partir de um número que o usuário pedir), por isso _vetores_ são extremamente úteis.

### No que consiste a ordenação?

Os algoritmos de ordenação tem como objetivo permutar uma seqüência $n\_{1}, n\_{2}, n\_{3}, \ldots{}$ de forma que $n\_{1} \leq{} n\_{2} \leq{} n\_{3} \leq{} \ldots{}$. A ordenação não precisa ser exatamente de um vetor, mas vetor é geralmente a estrutura que usamos para guardar uma lista de números para podermos ordená-los.

### Por que ordenar?

Citando o Cormen:

  * Às vezes, a necessidade de ordenar informações é inerente a uma aplicação. Por exemplo, para preparar os extratos de clientes, os bancos precisam ordenar os cheques pelo número do cheque.
  * Os algoritmos freqüentemente usam a ordenação como uma sub-rotina chave. Por exemplo, um programa que apresenta objetos gráficos dispostos em camadas uns sobre os outros talvez tenha de ordenar os objetos de acordo com uma relação “acima”, de forma a poder desenhar esses objetos de baixo para cima.
  * Existe uma ampla variedade de algoritmos de ordenação, e eles empregam um rico conjunto de técnicas. De fato, muitas técnicas importantes usadas ao longo do projeto de algoritmos são representadas no corpo de algoritmos de ordenação que foram desenvolvidos ao longo dos anos. Desse modo, a ordenação também é um problema de interesse histórico.

