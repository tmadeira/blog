---
title: Recursão
type: post
date: 2006-01-08T21:38:18+00:00
excerpt: A "recursão" é uma das técnicas mais simples e úteis que existem para usarmos em nossos algoritmos. Consiste em uma função (denominada recursiva) chamar a si mesmo, até que o retorno seja trivial. Resolvi abordá-la aqui porque alguns algoritmos que estudaremos mais pra frente usarão essas funções recursivas.
url: /2006/01/algoritmos-recursivos/
ordem:
  - eeeii
categories:
  - Básico
tags:
  - algoritmos
  - algoritmos recursivos
  - análise de algoritmos
  - fibonacci
  - função recursiva
  - loops
  - números fatoriais
  - recursão
  - repetições

---
A **recursão** é uma das técnicas mais simples e úteis que existem para usarmos em nossos algoritmos. Consiste em uma função (denominada _recursiva_) chamar a si mesmo, até que o retorno seja trivial. Resolvi abordá-la aqui porque alguns algoritmos que estudaremos mais para frente usam **funções recursivas**.

Gostaria de, antes de falar sobre o assunto, contar um pouco da minha história com recursão, porque foi meu início no mundo dos algoritmos.

Junho de 2004, tinha eu 13 anos e fui premiado com medalha de ouro na modalidade iniciação da Olimpíada de Informática. Fui convidado para o curso de introdução a programação na UNICAMP e, extremamente geek como eu era (e ainda sou), falei para os professores que já programava em C e então eles sugeriram que eu fosse para o curso de programação avançada.

No entanto, eu ainda achava muito complicado os algoritmos da modalidade de programação da OBI, por isso pedi pra ficar num “meio-termo”. Eles toparam numa boa e com isso passei a ter aulas com um monitor excelente (aluno da UNICAMP) chamado Ribamar. Esse cara foi extremamente importante para minha iniciação na programação _de verdade_.

Na primeira tarde que tive aula com ele, ele perguntou se eu sabia o que era recursão. Respondi que não e, a partir daquele dia e depois de ele me ensinar também de grafos e programação dinâmica, além de me apresentar o Slackware, me tornei um amante de algoritmos. A recursão, portanto, mesmo sendo algo simples, é um assunto especial pra mim porque representa a mudança de “nível”.

Então, mãos à obra!

* * *

Em matemática, o número fatorial de \\(n\\) é igual a: <span class="tex-render">n \times{} n-1 \times{} n-2 \times{} \ldots{} 2 \times{} 1</span>.

Logo, por exemplo, \\(5!\\) (cinco fatorial) seria igual a: <span class="tex-render">5 \times{} 4 \times{} 3 \times{} 2 \times{} 1 = 120</span>.

* * *

Um exemplo bom e simples de recursão é um algoritmo para determinar números fatoriais:

<pre><code><strong>função</strong> <em>fatorial</em> (<em>n</em>)
 <strong>se</strong> <span class="tex-render">n = 1</span>, <strong>então</strong>
     <strong>retorna</strong> <span class="tex-render">1</span>
 <strong>senão</strong>
     <strong>retorna</strong> <span class="tex-render">n \times{} fatorial(n-1)</span>
 <strong>fim-se</strong>
<strong>fim-função</strong></code></pre>

**Domínio de nossa função:** <span class="tex-render">n \in{} \mathbf{N} / n \geq{} 1</span>.

### Qual o custo desse algoritmo?

Vamos abrir um grande parênteses aqui até a próxima linha horizontal para descobrir qual o custo do nosso algoritmo antes de continuar com a conversa sobre **recursão** e relembrar/reforçar o post sobre [Análise de Algoritmos][1]. Vou colocar o número de vezes que cada instrução é executada, usando o esquema que será o padrão para as próximas vezes que veremos custos:

**Número da linha: Número de vezes que é executada.**.

  1. <span class="tex-render">n</span>
  2. <span class="tex-render">n-1</span>
  3. <span class="tex-render">1</span>
  4. <span class="tex-render">n-1</span>
  5. <span class="tex-render">n-1</span>

\\(T(n) = (n) + (n-1) + (1) + (n-1) + (n-1) = 4n - 2\\)

Uma **função linear**, o tipo de algoritmo mais simples que podemos encontrar, com excessão dos que são uma **função constante**. Mas o parênteses na verdade não serviu só pra isso. Eu queria aproveitar pra _escovar uns bits_ de nosso código. Você percebeu que o primeiro condicional é executado \\(n-1\\) vezes, mas só entramos nele **uma** vez? Então vamos inverter nosso condicional.

<pre><code><strong>função</strong> <em>fatorial</em> (<em>n</em>)
 <strong>se</strong> <span class="tex-render">n \geq{} 2</span>, <strong>então</strong>
     <strong>retorna</strong> <span class="tex-render">n \times{} fatorial(n-1)</span>
 <strong>senão</strong>
     <strong>retorna</strong> <span class="tex-render">1</span>
 <strong>fim-se</strong>
<strong>fim-função</strong></code></pre>

#### Novo custo

  1. <span class="tex-render">n</span>
  2. <span class="tex-render">n-1</span>
  3. <span class="tex-render">n-1</span>
  4. <span class="tex-render">1</span>
  5. <span class="tex-render">1</span>

\\(T(n) = (n) + (n-1) + (n-1) + (1) + (1) = 3n\\)

Claro que continua uma **função linear**, não houve nenhuma grande mudança. Os dois continuam com a mesma ordem de crescimento e tal… \\(4n+2\\) comparado com \\(3n\\) é uma diferença pequena, mas essa solução ficou bem mais elegante. ;) Poxa, diminuímos o custo do algoritmo em <span class="tex-render">\frac{1}{4}</span>! Hehehe…

Agora, antes de continuar, só vamos definir a **notação assintótica** desse nosso novo custo!

A fórmula do \\(\Theta{}\\) é: \\(0 \leq{} c\_{1} g(n) \leq{} f(n) \leq{} c\_{2} g(n)\\)

Substituindo pela nossa função, temos: \\(c\_{1}n \leq{} 3n \leq{} c\_{2}n\\). É trivial, que podemos escolher para as duas constantes \\(c\_{1}=c\_{2}=3\\) e para \\(n\_{0}=0\\). Com isso pretendi mostrar-lhes uma conclusão óbvia que no outro artigo não tinha mostrado para não complicar muito: uma função reta (linear) pertence sempre a notação \\(\Theta{}(n)\\) e uma função quadrática pertence sempre a notação \\(\Theta{}(n^{2})\\) (ora, façam um gráfico das funções e vejam se isso não é óbvio!). Mas vamos aprendendo mais sobre **análise de algoritmos** com o tempo…

* * *

Bom… Continuando com a recursão… Nossa função cria um loop consigo mesma, ao invés de usar um **para** (for) ou **enquanto** (while). Ela se repete diminuindo um de \\(n\\) a cada iteração, até que chegue ao valor mínimo \\(1\\) aonde a resposta é trivial: <span class="tex-render">1</span>.

O que é necessário para criarmos uma **recursão**? Apenas um ponto de parada! Temos que tomar cuidado para não criarmos _loops infinitos_ cuidando sempre com cada entrada que o usuário pode colocar. Nesse caso, eu determinei que o domínio da função é <span class="tex-render">n \in{} \mathbf{N} / n \geq{} 1</span>. Se o cara colocasse <span class="tex-render">n=0</span>, minha função iria diminuindo infinitamente… e nunca iria retornar nada!

Para fazer a recursão portanto, precisamos analisar o domínio de nossa função e mais: precisamos conhecer um valor (que vai ser o limite; no caso do **fatorial**, o valor que sabíamos é que <span class="tex-render">1! = 1</span>).

Acredito que vocês tenham achado tudo simples e que não tenham problema com isso. Funções recursivas vão ser extremamente úteis para nós nos próximos artigos. Vou finalizar mostrando-lhes alguns casos básicos de algoritmos em que podemos usar a recursão:

### Números de Fibonacci

<pre><code><strong>função</strong> <em>fibonacci</em> (<em>n</em>)
 <strong>se</strong> <span class="tex-render">n \geq{} 3</span>, <strong>então</strong>
     <strong>retorna</strong> <span class="tex-render">fibonacci(n-1) + fibonacci(n-2)</span>
 <strong>senão</strong>
     <strong>retorna</strong> <span class="tex-render">1</span>
 <strong>fim-se</strong>
<strong>fim-função</strong></code></pre>

**Domínio de fibonacci(n)**: <span class="tex-render">n \in{} N / n \geq{} 1</span>

_Depois descobriremos como calcular os **números de Fibonacci** mais rápido, mas por enquanto nosso objetivo é a recursão!_

### Substituir um loop

Vamos supor que você quer imprimir os números de **n** a **1** e esqueceu a sintaxe do **para**… :D

<pre><code><strong>função</strong> <em>imprime_ate</em> (<em>n</em>)
 <strong>imprima</strong> <span class="tex-render">n</span>
 <strong>se</strong> \(n>1\), <strong>então</strong>
     <strong>imprime_ate</strong>(<em>n-1</em>)
 <strong>fim-se</strong>
<strong>fim-função</strong></code></pre>

**Domínio de imprime_ate(n)**: <span class="tex-render">n \in{} N / n \geq{} 1</span>

Todo loop pode ser uma recursão e tem alguns que ficam bem mais fáceis se forem! Nesse caso, é claro que seria mais simples usarmos um **para**!

### Outros exemplos, para concluir

  * Ordenação por Intercalação (Merge Sort)
  * Busca em Profundidade (Depth-First Search) em Grafos
  * Union/Find
  * … entre vários outros casos!

 [1]: /2006/01/analise-de-algoritmos/

