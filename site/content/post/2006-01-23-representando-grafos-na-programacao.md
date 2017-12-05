---
title: Representando Grafos na Programação
type: post
date: 2006-01-23T12:50:15+00:00
excerpt: Como representar relações binárias na programação? Qual a estrutura de dados perfeita para representar aquela árvore que vimos no último artigo? Isto é o que descobriremos aqui...
url: /2006/01/representando-grafos-na-programacao/
ordem:
  - eeeqq
categories:
  - Grafos
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

{{< figure src="/wp-content/uploads/2006/01/grafo-225x300.jpg" title="Grafo desenhado" >}}

Como todos sabemos, seria bem difícil trabalhar uma árvore assim na programação! Por isso, existem várias maneiras de representar um grafo. Nesta série só vou usar as duas mais populares:

  * Matriz de Adjacência
  * Lista de Adjacência

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

<table>
  <tr>
    <td>
       
    </td>

    <td>
      <strong>1</strong>
    </td>

    <td>
      <strong>2</strong>
    </td>

    <td>
      <strong>3</strong>
    </td>

    <td>
      <strong>4</strong>
    </td>

    <td>
      <strong>5</strong>
    </td>
  </tr>

  <tr>
    <td>
      <strong>1</strong>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>
  </tr>

  <tr>
    <td>
      <strong>2</strong>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>
  </tr>

  <tr>
    <td>
      <strong>3</strong>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>
  </tr>

  <tr>
    <td>
      <strong>4</strong>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>
  </tr>

  <tr>
    <td>
      <strong>5</strong>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>
  </tr>
</table>

#### Relações do nosso grafo

Já que o grafo não é orientado, a relação **1–2** significa **2–1** também.

  * 1–2 (2–1)
  * 1–3 (3–1)
  * 2–3 (3–2)
  * 2–4 (4–2)
  * 4–5 (5–4)

Essas são as **cinco arestas** do nosso grafo. Vamos representá-la na **matriz de adjacência**:

<table>
  <tr>
    <td>
    </td>
    <td>
      <strong>1</strong>
    </td>
    <td>
      <strong>2</strong>
    </td>
    <td>
      <strong>3</strong>
    </td>
    <td>
      <strong>4</strong>
    </td>
    <td>
      <strong>5</strong>
    </td>
  </tr>
  <tr>
    <td>
      <strong>1</strong>
    </td>
    <td>
    </td>
    <td class="preto">
      1
    </td>
    <td class="preto">
      1
    </td>
    <td>
    </td>
    <td>
    </td>
  </tr>
  <tr>
    <td>
      <strong>2</strong>
    </td>
    <td class="preto">
      1
    </td>
    <td>
    </td>
    <td class="preto">
      1
    </td>
    <td class="preto">
      1
    </td>
    <td>
    </td>
  </tr>
  <tr>
    <td>
      <strong>3</strong>
    </td>

    <td class="preto">
      1
    </td>

    <td class="preto">
      1
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>
  </tr>
  <tr>
    <td>
      <strong>4</strong>
    </td>

    <td>
    </td>

    <td class="preto">
      1
    </td>

    <td>
    </td>

    <td>
    </td>

    <td class="preto">
      1
    </td>
  </tr>
  <tr>
    <td>
      <strong>5</strong>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td>
    </td>

    <td class="preto">
      1
    </td>

    <td>
    </td>
  </tr>
</table>

#### Simetria

Uma das características da matriz de adjacência quando o grafo não é orientado é a simetria encontrada na “diagonal”. É interessante que se lermos uma coluna de índice **v** ou uma linha de índice **v** vamos encontrar a mesma coisa.

#### Problemas da OBI {#probma}

Alguns desses programas são complicados, mas isto não entra em questão. Apenas dê uma olhada no recebimento da entrada deles. Todos estão em **C**. O que eles têm em comum é a utilização de uma **matriz de adjacência** para guardar o grafo (geralmente nomeada **g**):

  * [Ambulância][3]
  * [Batuíra][4] +
  * [Carga Pesada][5] * +
  * [Dengue][6]
  * [Dominó][7]
  * [Manutenção][8]
  * [Número de Erdos][9] X
  * [Orkut][10] *
  * [Pedágio][11]
  * [Rede Ótica][12]

\* – **Grafo orientado**  
\+ – **Grafo ponderado** (veremos no próximo artigo)  
X – Não queira ver esse problema. Nunca vi solução mais feia. Já estou providenciando uma implementação mais decente… ;)

#### Descobrir o grau de cada vértice

Eu não disse pra vocês que era fácil conseguir emprego no [Orkut][13]? Hehehe… Vamos pensar como podemos descobrir o grau (relembrando… o número de arestas que cada vértice tem OU o número de amigos que cada pessoa tem) na matriz de adjacências. Não basta contar quantos **1**s tem na sua linha correspondente? Então façamos isto.

<pre><code><strong>para</strong> <em>i</em> <span class="tex-render">\leftarrow{}</span> 1 <strong>até</strong> <em>N</em>, <strong>faça</strong>
	<em>grau</em> <span class="tex-render">\leftarrow{}</span> 0
	<strong>para</strong> <em>j</em> <span class="tex-render">\leftarrow{}</span> 1 <strong>até</strong> <em>N</em>, <strong>faça</strong>
		<strong>se</strong> <em>matriz[i][j] = 1</em>, <strong>então</strong>
			<em>grau</em> <span class="tex-render">\leftarrow{}</span> <em>grau</em> + 1
		<strong>fim-se</strong>
	<strong>fim-para</strong>
	<strong>imprima</strong> "O vértice " <em>i</em> " tem grau " <em>grau</em> "."
<strong>fim-para</strong></code></pre>

O custo é \\(\Theta{}(n^{2})\\) até no melhor caso… Será que não há uma maneira mais simples de fazer isso? Imagina um negócio do tamanho do Orkut. Milhões de pessoas… Não seria bem mais fácil se ao invés de termos que passar por todos os vértices, só passarmos pelos amigos? Não poderíamos colocar somente seus amigos num vetor? É por isto que utilizamos a **lista de adjacência**.

### Lista de Adjacência

A **lista de adjacência** consiste em criar um vetor para cada vértice. Este vetor contém cada vértice que o vértice “conhece” (tem uma aresta para). Geralmente é representada com uma matriz, porque cada vértice vai precisar de um vetor diferente, não é? Já que eu não vou ser duas vezes “amigo” de ninguém, então podemos fazer uma matriz de **NxN**.

<table>
  <tr>
    <td>
       
    </td>

    <td>
      <strong>1</strong>
    </td>

    <td>
      <strong>2</strong>
    </td>

    <td>
      <strong>3</strong>
    </td>

    <td>
      <strong>4</strong>
    </td>

    <td>
      <strong>5</strong>
    </td>
  </tr>

  <tr>
    <td>
      <strong>1</strong>
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>

  <tr>
    <td>
      <strong>2</strong>
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>

  <tr>
    <td>
      <strong>3</strong>
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>

  <tr>
    <td>
      <strong>4</strong>
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>

  <tr>
    <td>
      <strong>5</strong>
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>
</table>

A lista consiste em escrever para cada número de linha (= vértice) seus amigos, da seguinte maneira:

  1. 2, 3
  2. 1, 3, 4
  3. 1, 2
  4. 2, 5
  5. 4

Portanto, na programação seria representado da seguinte maneira:

<table>
  <tr>
    <td>
       
    </td>

    <td>
      <strong>1</strong>
    </td>

    <td>
      <strong>2</strong>
    </td>

    <td>
      <strong>3</strong>
    </td>

    <td>
      <strong>4</strong>
    </td>

    <td>
      <strong>5</strong>
    </td>
  </tr>

  <tr>
    <td>
      <strong>1</strong>
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      3
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>

  <tr>
    <td>
      <strong>2</strong>
    </td>

    <td class="preto">
      1
    </td>

    <td class="preto">
      3
    </td>

    <td class="preto">
      4
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>

  <tr>
    <td>
      <strong>3</strong>
    </td>

    <td class="preto">
      1
    </td>

    <td class="preto">
      2
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>

  <tr>
    <td>
      <strong>4</strong>
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>

  <tr>
    <td>
      <strong>5</strong>
    </td>

    <td class="preto">
      4
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>

    <td>
       
    </td>
  </tr>
</table>

<p id="vantagensl">
  O método da <strong>lista de adjacências</strong> tem várias vantagens: dependendo de como você implementa você não precisa inicializar a lista (zerar), as buscas são bem mais rápidas (você só passa pelos vértices que são “amigos” do atual) e geralmente você já tem o grau do vértice na ponta da língua (eu, pelo menos, sempre uso um vetor <strong>cont</strong> que contém o número de amigos de cada vértice para ficar mais fácil inserir o próximo elemento na lista – <strong>lista[cont[v]++]=w</strong>).
</p>

### Como implementar

Vamos trabalhar com uma entrada de vários **x, y**, indicando relação entre x-y (y-x) até que **x=0 e y=0**. O grafo **não** é orientado.

#### Matriz de Adjacências

<pre><code><strong>para</strong> <em>i</em> <span class="tex-render">\leftarrow{}</span> 1 <strong>até</strong> <em>N</em>, <strong>faça</strong>
	<strong>para</strong> <em>j</em> <span class="tex-render">\leftarrow{}</span> 1 <strong>até</strong> <em>N</em>, <strong>faça</strong>
		<em>matriz[i][j]</em> <span class="tex-render">\leftarrow{}</span> 0
	<strong>fim-para</strong>
<strong>fim-para</strong>

<strong>enquanto</strong> (<strong>recebe</strong> <em>x</em>, <em>y</em> <strong>e</strong> <em>x <span class="tex-render">\neq{}</span> 0</em>), <strong>faça</strong>
	<em>matriz[x][y]</em> <span class="tex-render">\leftarrow{}</span> <em>1</em>
	<em>matriz[y][x]</em> <span class="tex-render">\leftarrow{}</span> <em>1</em>
<strong>fim-enquanto</strong></code></pre>

Tem vários exemplos implementados em C [aqui][14].

#### Lista de Adjacências

<pre><code><strong>para</strong> <em>i</em> <span class="tex-render">\leftarrow{}</span> 1 <strong>até</strong> <em>N</em>, <strong>faça</strong>
	<em>grau[i]</em> <span class="tex-render">\leftarrow{}</span> 0
<strong>fim-para</strong>

<strong>enquanto</strong> (<strong>recebe</strong> <em>x</em>, <em>y</em> <strong>e</strong> <em>x <span class="tex-render">\neq{}</span> 0</em>), <strong>faça</strong>
	<em>lista[x][grau[x]++]</em> <span class="tex-render">\leftarrow{}</span> <em>y</em>
	<em>lista[y][grau[y]++]</em> <span class="tex-render">\leftarrow{}</span> <em>x</em>
<strong>fim-enquanto</strong></code></pre>

Para quem não programa em **C**, o _variavel++_ significa “incrementar _variavel_ depois da instrução atual”.

#### As duas juntas

<pre><code><strong>para</strong> <em>i</em> <span class="tex-render">\leftarrow{}</span> 1 <strong>até</strong> <em>N</em>, <strong>faça</strong>
	<strong>para</strong> <em>j</em> <span class="tex-render">\leftarrow{}</span> 1 <strong>até</strong> <em>N</em>, <strong>faça</strong>
		<em>matriz[i][j]</em> <span class="tex-render">\leftarrow{}</span> 0
	<strong>fim-para</strong>
	<em>grau[i]</em> <span class="tex-render">\leftarrow{}</span> 0
<strong>fim-para</strong>

<strong>enquanto</strong> (<strong>recebe</strong> <em>x</em>, <em>y</em> <strong>e</strong> <em>x <span class="tex-render">\neq{}</span> 0</em>), <strong>faça</strong>
	<em>matriz[x][y]</em> <span class="tex-render">\leftarrow{}</span> <em>1</em>
	<em>matriz[y][x]</em> <span class="tex-render">\leftarrow{}</span> <em>1</em>
	<em>lista[x][grau[x]++]</em> <span class="tex-render">\leftarrow{}</span> <em>y</em>
	<em>lista[y][grau[y]++]</em> <span class="tex-render">\leftarrow{}</span> <em>x</em>
<strong>fim-enquanto</strong></code></pre>

### Qual a representação que devo utilizar?

Isso depende totalmente do problema. Em alguns casos, o mais barato é usar as **duas representações juntas**. As _vantagens da lista de adjacências_ eu já escrevi [aqui][15]. A única vantagem da **matriz de adjacências** é você em tempo **constante** (não é nem linear) saber se um vértice é amigo de outro. Afinal, basta testar **matriz\[v\]\[w\]**.

Até maio do ano passado, eu não tinha aprendido isso direito e sempre usava a matriz de adjacências. Por isso muitos dos meus problemas estão resolvidos de forma pouco eficiente… e isso pode ser crucial numa prova. Por isso, saiba usar as duas formas!

 [2]: #ex1
 [3]: http://tiagomadeira.net/script/ambulancia.c
 [4]: http://tiagomadeira.net/script/batuira.c
 [5]: http://tiagomadeira.net/script/carga.c
 [6]: http://tiagomadeira.net/script/dengue.c
 [7]: http://tiagomadeira.net/script/domino.c
 [8]: http://tiagomadeira.net/script/manutencao.c
 [9]: http://tiagomadeira.net/script/numeroerdos.c
 [10]: http://tiagomadeira.net/script/orkut.c
 [11]: http://tiagomadeira.net/script/pedagio.c
 [12]: http://tiagomadeira.net/script/redeotica.c
 [13]: http://www.orkut.com
 [14]: #probma
 [15]: #vantagensl

