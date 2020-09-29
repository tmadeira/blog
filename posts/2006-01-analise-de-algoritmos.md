---
title: Análise de Algoritmos
type: post
date: 2006-01-08T03:53:26+00:00
excerpt: Analisar um algoritmo é prever o que o algoritmo irá precisar. Com este artigo, pretendo explicar como analisamos um algoritmo para compará-lo com outros algoritmos na realização de uma mesma tarefa.
url: /2006/01/analise-de-algoritmos/
ordem:
  - eeehh
categorias:
  - Básico
tags:
  - algoritmos
  - análise
  - análise de algoritmos
  - inequações
  - Matemática
  - notação assintótica
  - omega
  - ordem de crescimento
  - theta

---
**Analisar** um algoritmo é prever o que o algoritmo irá precisar. Às vezes o hardware é importante, mas acho que o que acontece com mais freqüência, ao menos em olimpíadas, maratonas e problemas em casa, é precisarmos medir o tempo que ele irá demorar.

Eu expliquei em algum dos artigos anteriores que o **tempo de um algoritmo** depende geralmente do tamanho de sua entrada. Com este artigo, pretendo explicar como analisamos um algoritmo baseado nesse tamanho de sua entrada para compará-lo com outros algoritmos e ter uma noção de quanto tempo ele vai demorar.

Para o entendimento ficar mais fácil, vamos partir do seguinte algoritmo (que vamos chamar de **Algoritmo 1**):

<pre><code><strong>para</strong> <em>i</em> <span class="tex-render">\leftarrow{}</span> 1 até <em>n</em>, <strong>faça</strong>
 <strong>para</strong> <em>j</em> <span class="tex-render">\leftarrow{}</span> 1 até <em>i</em>, <strong>faça</strong>
     <strong>imprima</strong> <em>i</em> <span class="tex-render">\times{}</span> <em>j</em> <span class="tex-render">\times{}</span> <em>n</em>
 <strong>fim-para</strong>
<strong>fim-para</strong></code></pre>

O que este algoritmo faz é, depois de receber a entrada $n$ do usuário, imprimir o produto de $n$ com todos dois números $i$ e $j$, tal que $j \leq{} i \leq{} n$.

Para medir o custo do algoritmo, nossa análise consistirá em ver quantas vezes cada passo é executado. Mediremos o custo de cada linha (cada passo a ser executado), sempre em função de **n**, que para este algoritmo é a variável mais importante (aliás, a única variável). Por isso o pseudocódigo do **Algoritmo 1** está com suas linhas numeradas. Vamos analisar…

  * **Linha 1:** Será executada $n + 1$ vezes.
  * **Linha 2:** Será executada $n \times{} \sum\_{i=1}^{n} + n$ vezes.
  * **Linha 3:** Será executada $n \times{} \sum\_{i=1}^{n}$ vezes.
  * **Linhas 4 e 5:** Não tem custo. :)

### Por que estes números de execução?

Se você já entendeu por que cada passo é executado este número de vezes, pode pular essa parte (continuar a ler a partir da linha horizontal).

#### Linha 1

O loop **para** voltará para si mesmo $n$ vezes, isso é, testará novamente sua condicional e incrementará um. Por sempre testar um condicional, no final ele terá que testar novamente para dizer que já passou de $n$. Por isso, ele será executado $n+1$ vezes, ao invés de simplesmente $n$.

#### Linha 2

Este loop **para** será executado um número de vezes variável ($i$), que irá de $1$ a $n$. Portanto, ele será executado duas vezes (1 mais “o último condicional”) no primeiro loop de $i$, três (2 mais “o último condicional”) no segundo, e por aí vai. Com isso, ele será executado o número de vezes que equivale a soma de $1$ a $n$, mais $n$ que são “os últimos condicionais”.

#### Linha 3

Exatamente o mesmo número que a **Linha 2**, mas sem “os últimos condicionais” ($-n$).

* * *

Imprimir algo na tela pode demorar mais do que fazer uma operação, mas a análise de algoritmos é uma coisa bem _rústica_. Desprezamos todas as constantes, com isso só levando a sério a informação importante: neste caso, apenas $n$. Então agora, vamos escrever o tempo de execução do algoritmo, que é a soma dos tempos de execução para cada instrução executada.

$$
T(n) = (n + 1) + (\sum\_{i=1}^{n} + n) + (\sum\_{i=1}^{n})
$$

_Os parênteses não são necessários, mas coloquei para ajudar na visualização separando o custo de cada instrução._

Simplificando esta operação, teremos:

$T(n) = n^{2} + 3n$, uma **função quadrática**.

### Ordem de Crescimento

Como eu já disse antes, descobrir o custo de um algoritmo é uma coisa feita sem precisão, porque para entradas realmente grandes (que são casos onde precisamos do computador!) as constantes não importam. Agora vamos determinar a **ordem de crescimento** de um algoritmo resgatando do nosso algoritmo apenas o valor mais importante, o maior expoente de $n$ nele, neste caso, $n^{2}$. Se tivéssemos $2 n^{2}$, por exemplo, também usaríamos apenas $n^{2}$ porque o $2$ que multiplica também é desprezível!

Vamos agora aprender como representar o custo desse algoritmo usando **notações assintóticas** com a ordem de crescimento do algoritmo.

_Se você não entendeu alguma coisa aí em cima, sugiro reler antes de continuar…_

### Notações Assintóticas

#### Sugestão

Principalmente para pessoas pouco habituadas com matemática, essa parte é difícil e cansativa. Quando eu comecei a aprender isto, talvez por causa da matemática tão básica que é ensinada na escola, eu não entendia nada… Mas só quero dar uma dica: se você não entender direito ou achar muito complicado, pule para a próxima linha horizontal ao invés de desistir e dizer que _“algoritmos são muito difíceis”_. Tentei fazer o artigo para você poder pular essa parte e mesmo assim não parar no estudo dos algoritmos… Depois, com o tempo, você vai aprendendo isso.

As notações que usamos para descrever o tempo de execução de um algoritmo são **cinco**:

  * <span class="tex-render">\Theta{}</span>
  * <span class="tex-render">O</span>
  * <span class="tex-render">\Omega{}</span>
  * <span class="tex-render">o</span>
  * <span class="tex-render">\omega{}</span>

Embora essas notações sejam conjuntos, usamos o **sinal de igualdade** (=) para expressar que $f(n)$ pertence a algum deles, ao invés de usar o **sinal de pertinência** ($\in{}$).

Vou explicá-las, omitindo alguns fatos para tentar facilitar o entendimento, porque eu acho que analisar algoritmos é meio complicado e nessa parte é extremamente difícil ser didático. Mas se você realmente se interessar, você pode me enviar um comentário pedindo mais um artigo sobre isso (e eu terei o prazer de até pesquisar para informar-lhes mais) ou então leia o _Capítulo 3_ do livro **Algoritmos: Teoria e Prática**, que acredito que seja bem completo. Gostaria de enfatizar aqui que _meu objetivo com essa série é tornar uma introdução a algoritmos simples_ e não _ser uma referência_, como é o objetivo, por exemplo, do livro do **Cormen [et al]**.

#### A notação $\Theta{}$

Lê-se _“theta de gê de ene”_.

$\Theta{}(g(n)) = f(n)$, **se** existem constantes positivas $c\_{1}$, $c\_{2}$ e $n\_{0}$ tais que $0 \leq{} c\_{1} g(n) \leq{} f(n) \leq{} c\_{2} g(n)$ para todo $n \geq{} n\_{0}$.

#### A notação $O$

Lê-se _“ó maiúsculo de gê de ene”_. Para quando há apenas um **limite assintótico superior**.

$O(g(n)) = f(n)$, **se** existem constantes positivas $c$ e $n\_{0}$ tais que $0 \leq{} f(n) \leq{} cg(n)$ para todo $n \geq{} n\_{0}$.

#### A notação $\Omega{}$

Lê-se _“omega maiúsculo de gê de ene”_. Para quando há apenas um **limite assintótico inferior**.

$\Omega{}(g(n)) = f(n)$, **se** existem constantes positivas $c$ e $n\_{0}$ tais que $0 \leq{} cg(n) \leq{} f(n)$ para todo $n \geq{} n\_{0}$.

#### A notação $o$

Lê-se _“ó minúsculo de gê de ene”_. Para quando há apenas um **limite assintótico superior**, sem permitir que $f(n) = cg(n)$. Utiliza-se a notação $o$ para denotar um limite superior que não é assintoticamente restrito.

$o(g(n)) = f(n)$, **se** _para qualquer constante_ $c > 0$, existe uma constante $n\_{0} > 0$ tal que $0 \leq{} f(n) \leq{} cg(n)$ para todo $n \geq{} n\_{0}$.

#### A notação $\omega{}$

Lê-se _“omega minúsculo de gê de ene”_. Para quando há apenas um **limite assintótico inferior**, sem permitir que $cg(n) = f(n)$. Utiliza-se a notação $\omega{}$ para denotar um limite inferior que não é assintoticamente restrito.

$\omega{}(g(n)) = f(n)$, **se** _para qualquer constante_ $c > 0$, existe uma constante $n\_{0} > 0$ tal que $0 \leq{} cg(n) \leq{} f(n)$ para todo $n \geq{} n\_{0}$.

Para analisar problemas mais complexos como, por exemplo, recorrências, existem métodos bastante interessantes, como o Teorema Mestre que o Cormen apresenta no Capítulo 4. É uma boa leitura pra quem se interessou.

* * *

Podemos criar várias comparações entre estas funções, mas isto não vem ao caso. O importante é saber em que notação a nossa função se encontra. Com o tempo vamos compreendendo melhor essas fórmulas.

Vamos relembrar o custo de nosso algoritmo… $T(n) = n^{2} + 3n$.

Vamos ver em que notação ele pode se encaixar, sabendo que $g(n)$ seria a **ordem de crescimento** (parte importante) do nosso custo; no caso, $n^{2}$.

Testamos primeiro se ele encaixa na função $\Theta{}(n^{2})$. Vamos substituir $f(n)$ e  $g(n)$ (naquela função ali em cima, onde diz **A notação $\Theta{}$**) pelos valores que conhecemos.

$$
c\_{1}n^{2} \leq{} n^{2} + 3 n \leq{} c\_{2} n^{2}
$$

Se dividirmos tudo por $n^{2}$, obteremos:

$$
c\_{1} \leq{} 1 + \frac{3}{n} \leq{} c\_{2}
$$

Agora separaremos as inequações.

**Inequação 1:** $c\_{1} \leq{} 1 + \frac{3}{n}$

**Inequação 2:** $1 + \frac{3}{n} \leq{} c\_{2}$

Para satisfazer a **Inequação 1**, podemos quase automaticamente perceber que para qualquer $n \geq{} 1$, é válido $c\_{1} = 1$ (ora, por mais que $\frac{3}{n}$ chegue perto de 0, sempre ainda vamos ter a constante 1 adicionada a ele). Para satisfazer a **Inequação 2**, podemos perceber facilmente que para qualquer $n \geq{} 1$, é válido $c\_{2} = 4$ (a função só tende a diminuir a partir que $n$ vai aumentando e com $n=1$, $c\_{2}=4$). Com isso, agora chegamos as três constantes que precisávamos.

$n\_{0}$ (o menor valor de $n$) $= 1$; $c\_{1} = 1$; $c\_{2} = 4$.

Logo, concluímos que $f(n) = n^{2} + 3n = \Theta{}(n^{2})$. Uma função que pertence a $\Theta{}$, tem um **limite assintótico superior** e **inferior** e, portanto, pertenceria também a $O(n^{2})$ e $\Omega{}(n^{2})$, mas nem é necessário testar os outros valores porque já identificamos nossa função como _“theta de ene ao quadrado”_, que é a função mais “retinha” que podemos esperar.

Bom… Nos próximos artigos, veremos que um mesmo problema pode ter várias soluções diferentes com custos ainda mais diferentes! Por isso, é crucial sabermos analisar, mesmo que por cima, qual o algoritmo que é mais eficiente. Vou ficando por aqui…

