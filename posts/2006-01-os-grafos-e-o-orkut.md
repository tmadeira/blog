---
title: Os Grafos e o Orkut
type: post
date: 2006-01-22T17:43:22+00:00
excerpt: 'Grafo: uma forma de representar uma relação binária entre elementos de um conjunto. Ficou muito difícil? Então vamos trabalhar com o exemplo do Orkut! :)'
url: /2006/01/os-grafos-e-o-orkut/
ordem:
  - eeepp
categorias:
  - Grafos
tags:
  - algoritmos
  - algoritmos em grafos
  - amizade
  - aresta
  - definição
  - grafos
  - grafos orientados
  - orkut
  - problemas
  - vértice

---
Vou neste e nos próximos artigos falar-lhes sobre a **Teoria dos Grafos**. É uma coisa que **poderia** ser complicada, então pra facilitar o entendimento eu resolvi que trabalharemos sempre com exemplos da “vida real”. Neste artigo, vamos trabalhar com o Orkut como base, partindo do princípio que todo mundo sabe o que é o Orkut.

Neste primeiro artigo, só falarei sobre a definição do grafo e sua utilidade. Apresentarei as definições de: **vértice**, **aresta**, **grau**, **grafo orientado**, **grau de entrada** e **grau de saída**. Então, vamos lá!

A definição de **grafo** é muito simples. Segundo o [Professor Cid Carvalho de Souza][1]: _Uma forma de representar uma relação binária entre elementos de um conjunto._ Bom… É simplesmente uma representação de relações (que chamamos de **arestas**) entre objetos, que chamamos de **vértices**. Vamos logo ao exemplo: a **amizade** no [Orkut][2].

![Um grafo de amizades](/wp-content/uploads/2006/01/grafo-225x300.jpg)

Estão vendo esta árvore? Esta é a representação que chamamos de grafo. Vamos supor que este é o grafo das amizades do Orkut e as bolinhas nele são as seguintes pessoas:

  1. Eu
  2. João
  3. Maria
  4. José
  5. Pedro

Eu (número 1) tenho dois amigos: o **João** (número 2) e a **Maria** (número 3), porque estou **ligado** a eles. O **João** (número 2) tem três amigos: **eu** (número 1), a **Maria** (número 3) e o **José** (número 4). E assim podemos fazer com os outros contando as linhas que saem de cada pessoa.

Cada pessoa é um **vértice** e cada linha (relação entre duas pessoas) é uma **aresta**. Dizemos que é uma relação binária lá em cima, porque a relação é sempre entre **dois** vértices.

Os números de amigos que cada pessoa tem (o número de relações que cada vértice tem) é o que chamamos de “grau” de um vértice. Grau dos vértices do exemplo acima:

  1. 2
  2. 3
  3. 2
  4. 2
  5. 1

### Pra quê serve o grafo?

Ora, se você consegue contar as arestas que saem de cada vértice na programação (se você sabe fazer algo básico como calcular o grau de um vértice), você pode oferecer seus serviços ao Google e ganhar milhões, pois, como todos sabem, o Orkut não sabe fazer isso direito!

Brincadeiras a parte… Grafos são extremamente úteis porque são representações bastante simples (você teve dificuldade para entender minha árvore ali em cima?) e essa estrutura deles aparece em muitos problemas computacionais. Além disso, existem muitos algoritmos eficientes para problemas complexos que utilizam estas representações.

### Definições até agora

Traduzindo os conceitos do Orkut para os grafos:

  * **Vértice:** Pessoa.
  * **Aresta:** Amizade entre uma pessoa e outra.
  * **Grau de um vértice:** Número de amigos de uma pessoa.

### Grafos Orientados

Um grafo é _orientado_ quando eu sou seu amigo, mas você não é meu amigo. Você sabe que um grafo é _orientado_ através da representação quando ele tem “setinhas”, como o grafo abaixo.

![Grafo orientado](/wp-content/uploads/2006/01/orientado-300x225.jpg)

Vamos supor que isso aí é um mapa do Brasil. Ele despreza as cidades que não são importantes para o país, levando apenas em consideração portanto: **São Paulo**, **Florianópolis** e **Itajaí**.

  * **São Paulo** é a bolinha vermelha.
  * **Florianópolis** é a bolinha amarela.
  * **Itajaí** é a bolinha azul.

As arestas indicam que há uma estrada para você ir de uma cidade para a outra, mas só dá pra ir no sentido da estrada, que as setas representam. Portanto, você pode ir de **São Paulo** a **Florianópolis**, de **São Paulo** a **Itajaí** e **Florianópolis** a **Itajaí**, mas não de **Itajaí** para qualquer outro lugar.

#### Grau dos Vértices

Os graus dos vértices neste segundo grafo seriam os seguintes, certo?

  * **São Paulo:** 2
  * **Florianópolis:** 2
  * **Itajaí:** 2

Quase… Porém, nos grafos orientados nós temos dois tipos de grau diferentes. Dizemos que:

  * **grau de entrada** é o número de arestas que apontam para o vértice; _e_
  * **grau de saída** é o número de arestas que saem do vértice.

Portanto, os **graus de entrada** do nosso grafo são:

  * **São Paulo:** 0
  * **Florianópolis:** 1
  * **Itajaí:** 2

E os **graus de saída**:

  * **São Paulo:** 2
  * **Florianópolis:** 1
  * **Itajaí:** 0

### Onde mais posso utilizar grafos?

Existem vários casos onde você vai **querer** usar grafos:

  * Mapas
  * Sua árvore genealógica
  * Hierarquia de uma empresa
  * Sistema de amizades do seu sistema de comunidades virtuais
  * … e muito mais. Na [OBI][5] já apareceu até um jogo de dominó como problema de grafos!

Como veremos nos próximos artigos, tem algoritmo pra fazer “tudo” em grafos… Então representar alguma coisa em grafos é muito útil pra poder descobrir uma série de coisas.

A maioria das páginas que eu conheço sobre grafos são muito malignas porque apresentam uns 50 conceitos diferentes de grafos juntos (ex.: grafo conexo, grafo desconexo, caminho, ciclo, etc.). Nos meus artigos, devo tratar um assunto de cada vez para facilitar o entendimento. Então, vou parar por aqui hoje.

**No próximo artigo:** Como representar um grafo na programação? Você já pode ir pensando nisso…

 [1]: http://www.ic.unicamp.br/~cid/Welcome2.html
 [2]: http://www.orkut.com
 [5]: http://olimpiada.ic.unicamp.br

