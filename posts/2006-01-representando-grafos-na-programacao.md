---
title: Representando Grafos na Programação
date: 2006-01-23T12:50:15+00:00
excerpt: Como representar relações binárias na programação? Qual a estrutura de dados perfeita para representar aquela árvore que vimos no último artigo? Isto é o que descobriremos aqui...
url: /2006/01/representando-grafos-na-programacao/
tags:
  - adjacência
  - algoritmos
  - computação
  - grafos
  - implementação
  - lista de adjacência
  - matriz de adjacência
  - problemas
  - programação
  - pseudocódigos
  - representação
---

No último artigo, conhecemos a representação chamada “grafo” da seguinte maneira:

![Grafo desenhado](/wp-content/uploads/2006/01/grafo-225x300.jpg)

Como todos sabemos, seria bem difícil trabalhar uma árvore assim na programação! Por isso, existem várias maneiras de representar um grafo. Nesta série só vou usar as duas mais populares:

- Matriz de Adjacência
- Lista de Adjacência

Poderíamos falar também sobre a **Matriz de Incidência**, mas eu nunca precisei utilizá-la, então prefiro só entrar nessas duas mesmo.

### Cada vértice é um número

Para representar um grafo, cada vértice **sempre** vai ser um número. No caso de você querer representar amizade entre duas pessoas, como no exemplo do Orkut no último artigo, você cria um vetor chamado **nome[]** que contém o nome de cada número…

1. Eu
2. João
3. Maria
4. José
5. Pedro

### Matriz de Adjacência

A matriz de adjacência é uma matriz de **N x N** (onde **N** é o número de vértices do grafo). Ela inicialmente é preenchida toda com **0** e quando há uma relação entre o vértice do _x_ (**número da coluna**) com o do _y_ (**número da linha**), _matriz\[x\]\[y\]_ é marcado um **1**.

Vamos escrever este [grafo aqui][2] usando uma matriz de adjacência:

#### Matriz Inicial

|       | 1   | 2   | 3   | 4   | 5   |
| ----- | --- | --- | --- | --- | --- |
| **1** |     |     |     |     |     |
| **2** |     |     |     |     |     |
| **3** |     |     |     |     |     |
| **4** |     |     |     |     |     |
| **5** |     |     |     |     |     |

#### Relações do nosso grafo

Já que o grafo não é orientado, a relação **1–2** significa **2–1** também.

- 1–2 (2–1)
- 1–3 (3–1)
- 2–3 (3–2)
- 2–4 (4–2)
- 4–5 (5–4)

Essas são as **cinco arestas** do nosso grafo. Vamos representá-la na **matriz de adjacência**:

|       | 1   | 2   | 3   | 4   | 5   |
| ----- | --- | --- | --- | --- | --- |
| **1** |     | 1   | 1   |     |     |
| **2** | 1   |     | 1   | 1   |     |
| **3** | 1   | 1   |     |     |     |
| **4** |     | 1   |     |     | 1   |
| **5** |     |     |     | 1   |     |

#### Simetria

Uma das características da matriz de adjacência quando o grafo não é orientado é a simetria encontrada na “diagonal”. É interessante que se lermos uma coluna de índice **v** ou uma linha de índice **v** vamos encontrar a mesma coisa.

#### Problemas da OBI

Alguns desses programas são complicados, mas isto não entra em questão. Apenas dê uma olhada no recebimento da entrada deles. Todos estão em **C**. O que eles têm em comum é a utilização de uma **matriz de adjacência** para guardar o grafo (geralmente nomeada **g**):

- [Ambulância][3]
- [Batuíra][4] +
- [Carga Pesada][5] \* +
- [Dengue][6]
- [Dominó][7]
- [Manutenção][8]
- [Número de Erdos][9] X
- [Orkut][10] \*
- [Pedágio][11]
- [Rede Ótica][12]

\* – **Grafo orientado**  
\+ – **Grafo ponderado** (veremos no próximo artigo)  
X – Não queira ver esse problema. Nunca vi solução mais feia. Já estou providenciando uma implementação mais decente… ;)

#### Descobrir o grau de cada vértice

Eu não disse pra vocês que era fácil conseguir emprego no [Orkut][13]? Hehehe… Vamos pensar como podemos descobrir o grau (relembrando… o número de arestas que cada vértice tem OU o número de amigos que cada pessoa tem) na matriz de adjacências. Não basta contar quantos **1**s tem na sua linha correspondente? Então façamos isto.

**para** _i_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;_grau_ $\leftarrow{}$ 0  
 &emsp;**para** _j_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;&emsp;**se** _matriz[i][j] = 1_, **então**  
 &emsp;&emsp;&emsp;_grau_ $\leftarrow{}$ _grau_ + 1  
 &emsp;&emsp;**fim-se**  
 &emsp;**fim-para**  
 &emsp;**imprima** "O vértice " _i_ " tem grau " _grau_ "."  
**fim-para**

O custo é $\Theta{}(n^{2})$ até no melhor caso… Será que não há uma maneira mais simples de fazer isso? Imagina um negócio do tamanho do Orkut. Milhões de pessoas… Não seria bem mais fácil se ao invés de termos que passar por todos os vértices, só passarmos pelos amigos? Não poderíamos colocar somente seus amigos num vetor? É por isto que utilizamos a **lista de adjacência**.

### Lista de Adjacência

A **lista de adjacência** consiste em criar um vetor para cada vértice. Este vetor contém cada vértice que o vértice “conhece” (tem uma aresta para). Geralmente é representada com uma matriz, porque cada vértice vai precisar de um vetor diferente, não é? Já que eu não vou ser duas vezes “amigo” de ninguém, então podemos fazer uma matriz de **NxN**.

|       | 1   | 2   | 3   | 4   | 5   |
| ----- | --- | --- | --- | --- | --- |
| **1** |     |     |     |     |     |
| **2** |     |     |     |     |     |
| **3** |     |     |     |     |     |
| **4** |     |     |     |     |     |
| **5** |     |     |     |     |     |

A lista consiste em escrever para cada número de linha (= vértice) seus amigos, da seguinte maneira:

1. 2, 3
2. 1, 3, 4
3. 1, 2
4. 2, 5
5. 4

Portanto, na programação seria representado da seguinte maneira:

|       | 1   | 2   | 3   | 4   | 5   |
| ----- | --- | --- | --- | --- | --- |
| **1** | 2   | 3   |     |     |     |
| **2** | 1   | 3   | 4   |     |     |
| **3** | 1   | 2   |     |     |     |
| **4** | 2   | 5   |     |     |     |
| **5** | 4   |     |     |     |     |

O método da **lista de adjacências** tem várias vantagens: dependendo de como você implementa você não precisa inicializar a lista (zerar), as buscas são bem mais rápidas (você só passa pelos vértices que são “amigos” do atual) e geralmente você já tem o grau do vértice na ponta da língua (eu, pelo menos, sempre uso um vetor **cont** que contém o número de amigos de cada vértice para ficar mais fácil inserir o próximo elemento na lista – **lista[cont[v]++]=w**).

### Como implementar

Vamos trabalhar com uma entrada de vários **x, y**, indicando relação entre x-y (y-x) até que **x=0 e y=0**. O grafo **não** é orientado.

#### Matriz de Adjacências

**para** _i_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;**para** _j_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;&emsp;_matriz[i][j]_ $\leftarrow{}$ 0  
 &emsp;**fim-para**  
**fim-para**

**enquanto** (**recebe** _x_, _y_ **e** _x $\neq{}$ 0_), **faça**  
 &emsp;_matriz[x][y]_ $\leftarrow{}$ _1_  
 &emsp;_matriz[y][x]_ $\leftarrow{}$ _1_  
**fim-enquanto**

Tem vários exemplos implementados em C [aqui][14].

#### Lista de Adjacências

**para** _i_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;_grau[i]_ $\leftarrow{}$ 0  
**fim-para**

**enquanto** (**recebe** _x_, _y_ **e** _x $\neq{}$ 0_), **faça**  
 &emsp;_lista[x]grau[x]++]_ $\leftarrow{}$ _y_  
 &emsp;_lista[y]grau[y]++]_ $\leftarrow{}$ _x_  
**fim-enquanto**

Para quem não programa em **C**, o _variavel++_ significa “incrementar _variavel_ depois da instrução atual”.

#### As duas juntas

**para** _i_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;**para** _j_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;&emsp;_matriz[i][j]_ $\leftarrow{}$ 0  
 &emsp;**fim-para**  
 &emsp;_grau[i]_ $\leftarrow{}$ 0  
**fim-para**

**enquanto** (**recebe** _x_, _y_ **e** _x $\neq{}$ 0_), **faça**  
 &emsp;_matriz[x][y]_ $\leftarrow{}$ _1_  
 &emsp;_matriz[y][x]_ $\leftarrow{}$ _1_  
 &emsp;_lista[x]grau[x]++]_ $\leftarrow{}$ _y_  
 &emsp;_lista[y]grau[y]++]_ $\leftarrow{}$ _x_  
**fim-enquanto**

### Qual a representação que devo utilizar?

Isso depende totalmente do problema. Em alguns casos, o mais barato é usar as **duas representações juntas**. As _vantagens da lista de adjacências_ eu já escrevi [aqui][15]. A única vantagem da **matriz de adjacências** é você em tempo **constante** (não é nem linear) saber se um vértice é amigo de outro. Afinal, basta testar **matriz\[v\]\[w\]**.

Até maio do ano passado, eu não tinha aprendido isso direito e sempre usava a matriz de adjacências. Por isso muitos dos meus problemas estão resolvidos de forma pouco eficiente… e isso pode ser crucial numa prova. Por isso, saiba usar as duas formas!

[2]: #ex1
[3]: /wp-content/uploads/c/ambulancia.c
[4]: /wp-content/uploads/c/batuira.c
[5]: /wp-content/uploads/c/carga.c
[6]: /wp-content/uploads/c/dengue.c
[7]: /wp-content/uploads/c/domino.c
[8]: /wp-content/uploads/c/manutencao.c
[9]: /wp-content/uploads/c/numeroerdos.c
[10]: /wp-content/uploads/c/orkut.c
[11]: /wp-content/uploads/c/pedagio.c
[12]: /wp-content/uploads/c/redeotica.c
[13]: http://www.orkut.com
