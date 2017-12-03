---
title: Análise de Algoritmos
type: post
date: 2006-01-08T03:53:26+00:00
excerpt: Analisar um algoritmo é prever o que o algoritmo irá precisar. Com este artigo, pretendo explicar como analisamos um algoritmo para compará-lo com outros algoritmos na realização de uma mesma tarefa.
url: /2006/01/analise-de-algoritmos/
ordem:
  - eeehh
categories:
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

```
1. <strong>para</strong> <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> 1 até <em>n</em>, <strong>faça</strong>
2.  <strong>para</strong> <em>j</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> 1 até <em>i</em>, <strong>faça</strong>
3.      <strong>imprima</strong> <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Ctimes%7B%7D&bg=T&fg=000000&s=0' alt='\times{}' title='\times{}' class='latex' /> <em>j</em> <img src='https://s0.wp.com/latex.php?latex=%5Ctimes%7B%7D&bg=T&fg=000000&s=0' alt='\times{}' title='\times{}' class='latex' /> <em>n</em>
4.  <strong>fim-para</strong>
5. <strong>fim-para</strong>
```

O que este algoritmo faz é, depois de receber a entrada  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />do usuário, imprimir o produto de  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />com todos dois números  <img src='https://s0.wp.com/latex.php?latex=i&bg=T&fg=000000&s=0' alt='i' title='i' class='latex' />e <img src='https://s0.wp.com/latex.php?latex=j&bg=T&fg=000000&s=0' alt='j' title='j' class='latex' />, tal que <img src='https://s0.wp.com/latex.php?latex=j+%5Cleq%7B%7D+i+%5Cleq%7B%7D+n&bg=T&fg=000000&s=0' alt='j \leq{} i \leq{} n' title='j \leq{} i \leq{} n' class='latex' />.

Para medir o custo do algoritmo, nossa análise consistirá em ver quantas vezes cada passo é executado. Mediremos o custo de cada linha (cada passo a ser executado), sempre em função de **n**, que para este algoritmo é a variável mais importante (aliás, a única variável). Por isso o pseudocódigo do **Algoritmo 1** está com suas linhas numeradas. Vamos analisar…

  * **Linha 1:** Será executada  <img src='https://s0.wp.com/latex.php?latex=n+%2B+1&bg=T&fg=000000&s=0' alt='n + 1' title='n + 1' class='latex' />vezes.
  * **Linha 2:** Será executada  <img src='https://s0.wp.com/latex.php?latex=n+%5Ctimes%7B%7D+%5Csum_%7Bi%3D1%7D%5E%7Bn%7D+%2B+n&bg=T&fg=000000&s=0' alt='n \times{} \sum_{i=1}^{n} + n' title='n \times{} \sum_{i=1}^{n} + n' class='latex' />vezes.
  * **Linha 3:** Será executada  <img src='https://s0.wp.com/latex.php?latex=n+%5Ctimes%7B%7D+%5Csum_%7Bi%3D1%7D%5E%7Bn%7D&bg=T&fg=000000&s=0' alt='n \times{} \sum_{i=1}^{n}' title='n \times{} \sum_{i=1}^{n}' class='latex' />vezes.
  * **Linhas 4 e 5:** Não tem custo. :)

### Por que estes números de execução?

Se você já entendeu por que cada passo é executado este número de vezes, pode pular essa parte (continuar a ler a partir da linha horizontal).

#### Linha 1

O loop **para** voltará para si mesmo  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />vezes, isso é, testará novamente sua condicional e incrementará um. Por sempre testar um condicional, no final ele terá que testar novamente para dizer que já passou de <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />. Por isso, ele será executado  <img src='https://s0.wp.com/latex.php?latex=n%2B1&bg=T&fg=000000&s=0' alt='n+1' title='n+1' class='latex' />vezes, ao invés de simplesmente <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />.

#### Linha 2

Este loop **para** será executado um número de vezes variável (<img src='https://s0.wp.com/latex.php?latex=i&bg=T&fg=000000&s=0' alt='i' title='i' class='latex' />), que irá de  <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />a <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />. Portanto, ele será executado duas vezes (1 mais “o último condicional”) no primeiro loop de <img src='https://s0.wp.com/latex.php?latex=i&bg=T&fg=000000&s=0' alt='i' title='i' class='latex' />, três (2 mais “o último condicional”) no segundo, e por aí vai. Com isso, ele será executado o número de vezes que equivale a soma de  <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />a <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />, mais  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />que são “os últimos condicionais”.

#### Linha 3

Exatamente o mesmo número que a **Linha 2**, mas sem “os últimos condicionais” (<img src='https://s0.wp.com/latex.php?latex=-n&bg=T&fg=000000&s=0' alt='-n' title='-n' class='latex' />).

* * *

Imprimir algo na tela pode demorar mais do que fazer uma operação, mas a análise de algoritmos é uma coisa bem _rústica_. Desprezamos todas as constantes, com isso só levando a sério a informação importante: neste caso, apenas <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />. Então agora, vamos escrever o tempo de execução do algoritmo, que é a soma dos tempos de execução para cada instrução executada.


<img src='https://s0.wp.com/latex.php?latex=T%28n%29+%3D+%28n+%2B+1%29+%2B+%28%5Csum_%7Bi%3D1%7D%5E%7Bn%7D+%2B+n%29+%2B+%28%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%29&bg=T&fg=000000&s=0' alt='T(n) = (n + 1) + (\sum_{i=1}^{n} + n) + (\sum_{i=1}^{n})' title='T(n) = (n + 1) + (\sum_{i=1}^{n} + n) + (\sum_{i=1}^{n})' class='latex' />

_Os parênteses não são necessários, mas coloquei para ajudar na visualização separando o custo de cada instrução._

Simplificando esta operação, teremos:

<img src='https://s0.wp.com/latex.php?latex=T%28n%29+%3D+n%5E%7B2%7D+%2B+3n&bg=T&fg=000000&s=0' alt='T(n) = n^{2} + 3n' title='T(n) = n^{2} + 3n' class='latex' />, uma **função quadrática**.

### Ordem de Crescimento

Como eu já disse antes, descobrir o custo de um algoritmo é uma coisa feita sem precisão, porque para entradas realmente grandes (que são casos onde precisamos do computador!) as constantes não importam. Agora vamos determinar a **ordem de crescimento** de um algoritmo resgatando do nosso algoritmo apenas o valor mais importante, o maior expoente de  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />nele, neste caso, <img src='https://s0.wp.com/latex.php?latex=n%5E%7B2%7D&bg=T&fg=000000&s=0' alt='n^{2}' title='n^{2}' class='latex' />. Se tivéssemos <img src='https://s0.wp.com/latex.php?latex=2+n%5E%7B2%7D&bg=T&fg=000000&s=0' alt='2 n^{2}' title='2 n^{2}' class='latex' />, por exemplo, também usaríamos apenas  <img src='https://s0.wp.com/latex.php?latex=n%5E%7B2%7D&bg=T&fg=000000&s=0' alt='n^{2}' title='n^{2}' class='latex' />porque o  <img src='https://s0.wp.com/latex.php?latex=2&bg=T&fg=000000&s=0' alt='2' title='2' class='latex' />que multiplica também é desprezível!

Vamos agora aprender como representar o custo desse algoritmo usando **notações assintóticas** com a ordem de crescimento do algoritmo.

_Se você não entendeu alguma coisa aí em cima, sugiro reler antes de continuar…_

### Notações Assintóticas

#### Sugestão

Principalmente para pessoas pouco habituadas com matemática, essa parte é difícil e cansativa. Quando eu comecei a aprender isto, talvez por causa da matemática tão básica que é ensinada na escola, eu não entendia nada… Mas só quero dar uma dica: se você não entender direito ou achar muito complicado, pule para a próxima linha horizontal ao invés de desistir e dizer que _“algoritmos são muito difíceis”_. Tentei fazer o artigo para você poder pular essa parte e mesmo assim não parar no estudo dos algoritmos… Depois, com o tempo, você vai aprendendo isso.

As notações que usamos para descrever o tempo de execução de um algoritmo são **cinco**:

  * <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D&bg=T&fg=000000&s=0' alt='\Theta{}' title='\Theta{}' class='latex' />
  * <img src='https://s0.wp.com/latex.php?latex=O&bg=T&fg=000000&s=0' alt='O' title='O' class='latex' />
  * <img src='https://s0.wp.com/latex.php?latex=%5COmega%7B%7D&bg=T&fg=000000&s=0' alt='\Omega{}' title='\Omega{}' class='latex' />
  * <img src='https://s0.wp.com/latex.php?latex=o&bg=T&fg=000000&s=0' alt='o' title='o' class='latex' />
  * <img src='https://s0.wp.com/latex.php?latex=%5Comega%7B%7D&bg=T&fg=000000&s=0' alt='\omega{}' title='\omega{}' class='latex' />

Embora essas notações sejam conjuntos, usamos o **sinal de igualdade** (<img src='https://s0.wp.com/latex.php?latex=%3D&bg=T&fg=000000&s=0' alt='=' title='=' class='latex' />) para expressar que  <img src='https://s0.wp.com/latex.php?latex=f%28n%29&bg=T&fg=000000&s=0' alt='f(n)' title='f(n)' class='latex' />pertence a algum deles, ao invés de usar o **sinal de pertinência** (<img src='https://s0.wp.com/latex.php?latex=%5Cin%7B%7D&bg=T&fg=000000&s=0' alt='\in{}' title='\in{}' class='latex' />).

Vou explicá-las, omitindo alguns fatos para tentar facilitar o entendimento, porque eu acho que analisar algoritmos é meio complicado e nessa parte é extremamente difícil ser didático. Mas se você realmente se interessar, você pode me enviar um comentário pedindo mais um artigo sobre isso (e eu terei o prazer de até pesquisar para informar-lhes mais) ou então leia o _Capítulo 3_ do livro **Algoritmos: Teoria e Prática**, que acredito que seja bem completo. Gostaria de enfatizar aqui que _meu objetivo com essa série é tornar uma introdução a algoritmos simples_ e não _ser uma referência_, como é o objetivo, por exemplo, do livro do **Cormen [et al]**.

#### A notação <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D&bg=T&fg=000000&s=0' alt='\Theta{}' title='\Theta{}' class='latex' />

Lê-se _“theta de gê de ene”_.

<img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28g%28n%29%29+%3D+f%28n%29&bg=T&fg=000000&s=0' alt='\Theta{}(g(n)) = f(n)' title='\Theta{}(g(n)) = f(n)' class='latex' />, **se** existem constantes positivas <img src='https://s0.wp.com/latex.php?latex=c_%7B1%7D&bg=T&fg=000000&s=0' alt='c_{1}' title='c_{1}' class='latex' />,  <img src='https://s0.wp.com/latex.php?latex=c_%7B2%7D&bg=T&fg=000000&s=0' alt='c_{2}' title='c_{2}' class='latex' />e  <img src='https://s0.wp.com/latex.php?latex=n_%7B0%7D&bg=T&fg=000000&s=0' alt='n_{0}' title='n_{0}' class='latex' />tais que  <img src='https://s0.wp.com/latex.php?latex=0+%5Cleq%7B%7D+c_%7B1%7D+g%28n%29+%5Cleq%7B%7D+f%28n%29+%5Cleq%7B%7D+c_%7B2%7D+g%28n%29&bg=T&fg=000000&s=0' alt='0 \leq{} c_{1} g(n) \leq{} f(n) \leq{} c_{2} g(n)' title='0 \leq{} c_{1} g(n) \leq{} f(n) \leq{} c_{2} g(n)' class='latex' />para todo <img src='https://s0.wp.com/latex.php?latex=n+%5Cgeq%7B%7D+n_%7B0%7D&bg=T&fg=000000&s=0' alt='n \geq{} n_{0}' title='n \geq{} n_{0}' class='latex' />.

#### A notação <img src='https://s0.wp.com/latex.php?latex=O&bg=T&fg=000000&s=0' alt='O' title='O' class='latex' />

Lê-se _“ó maiúsculo de gê de ene”_. Para quando há apenas um **limite assintótico superior**.

<img src='https://s0.wp.com/latex.php?latex=O%28g%28n%29%29+%3D+f%28n%29&bg=T&fg=000000&s=0' alt='O(g(n)) = f(n)' title='O(g(n)) = f(n)' class='latex' />, **se** existem constantes positivas  <img src='https://s0.wp.com/latex.php?latex=c&bg=T&fg=000000&s=0' alt='c' title='c' class='latex' />e  <img src='https://s0.wp.com/latex.php?latex=n_%7B0%7D&bg=T&fg=000000&s=0' alt='n_{0}' title='n_{0}' class='latex' />tais que  <img src='https://s0.wp.com/latex.php?latex=0+%5Cleq%7B%7D+f%28n%29+%5Cleq%7B%7D+cg%28n%29&bg=T&fg=000000&s=0' alt='0 \leq{} f(n) \leq{} cg(n)' title='0 \leq{} f(n) \leq{} cg(n)' class='latex' />para todo <img src='https://s0.wp.com/latex.php?latex=n+%5Cgeq%7B%7D+n_%7B0%7D&bg=T&fg=000000&s=0' alt='n \geq{} n_{0}' title='n \geq{} n_{0}' class='latex' />.

#### A notação <img src='https://s0.wp.com/latex.php?latex=%5COmega%7B%7D&bg=T&fg=000000&s=0' alt='\Omega{}' title='\Omega{}' class='latex' />

Lê-se _“omega maiúsculo de gê de ene”_. Para quando há apenas um **limite assintótico inferior**.

<img src='https://s0.wp.com/latex.php?latex=%5COmega%7B%7D%28g%28n%29%29+%3D+f%28n%29&bg=T&fg=000000&s=0' alt='\Omega{}(g(n)) = f(n)' title='\Omega{}(g(n)) = f(n)' class='latex' />, **se** existem constantes positivas  <img src='https://s0.wp.com/latex.php?latex=c&bg=T&fg=000000&s=0' alt='c' title='c' class='latex' />e  <img src='https://s0.wp.com/latex.php?latex=n_%7B0%7D&bg=T&fg=000000&s=0' alt='n_{0}' title='n_{0}' class='latex' />tais que  <img src='https://s0.wp.com/latex.php?latex=0+%5Cleq%7B%7D+cg%28n%29+%5Cleq%7B%7D+f%28n%29&bg=T&fg=000000&s=0' alt='0 \leq{} cg(n) \leq{} f(n)' title='0 \leq{} cg(n) \leq{} f(n)' class='latex' />para todo <img src='https://s0.wp.com/latex.php?latex=n+%5Cgeq%7B%7D+n_%7B0%7D&bg=T&fg=000000&s=0' alt='n \geq{} n_{0}' title='n \geq{} n_{0}' class='latex' />.

#### A notação <img src='https://s0.wp.com/latex.php?latex=o&bg=T&fg=000000&s=0' alt='o' title='o' class='latex' />

Lê-se _“ó minúsculo de gê de ene”_. Para quando há apenas um **limite assintótico superior**, sem permitir que <img src='https://s0.wp.com/latex.php?latex=f%28n%29+%3D+cg%28n%29&bg=T&fg=000000&s=0' alt='f(n) = cg(n)' title='f(n) = cg(n)' class='latex' />. Utiliza-se a notação  <img src='https://s0.wp.com/latex.php?latex=o&bg=T&fg=000000&s=0' alt='o' title='o' class='latex' />para denotar um limite superior que não é assintoticamente restrito.

<img src='https://s0.wp.com/latex.php?latex=o%28g%28n%29%29+%3D+f%28n%29&bg=T&fg=000000&s=0' alt='o(g(n)) = f(n)' title='o(g(n)) = f(n)' class='latex' />, **se** _para qualquer constante_ <img src='https://s0.wp.com/latex.php?latex=c+%3E+0&bg=T&fg=000000&s=0' alt='c > 0' title='c > 0' class='latex' />, existe uma constante  <img src='https://s0.wp.com/latex.php?latex=n_%7B0%7D+%3E+0&bg=T&fg=000000&s=0' alt='n_{0} > 0' title='n_{0} > 0' class='latex' />tal que  <img src='https://s0.wp.com/latex.php?latex=0+%5Cleq%7B%7D+f%28n%29+%5Cleq%7B%7D+cg%28n%29&bg=T&fg=000000&s=0' alt='0 \leq{} f(n) \leq{} cg(n)' title='0 \leq{} f(n) \leq{} cg(n)' class='latex' />para todo <img src='https://s0.wp.com/latex.php?latex=n+%5Cgeq%7B%7D+n_%7B0%7D&bg=T&fg=000000&s=0' alt='n \geq{} n_{0}' title='n \geq{} n_{0}' class='latex' />.

#### A notação <img src='https://s0.wp.com/latex.php?latex=%5Comega%7B%7D&bg=T&fg=000000&s=0' alt='\omega{}' title='\omega{}' class='latex' />

Lê-se _“omega minúsculo de gê de ene”_. Para quando há apenas um **limite assintótico inferior**, sem permitir que <img src='https://s0.wp.com/latex.php?latex=cg%28n%29+%3D+f%28n%29&bg=T&fg=000000&s=0' alt='cg(n) = f(n)' title='cg(n) = f(n)' class='latex' />. Utiliza-se a notação  <img src='https://s0.wp.com/latex.php?latex=%5Comega%7B%7D&bg=T&fg=000000&s=0' alt='\omega{}' title='\omega{}' class='latex' />para denotar um limite inferior que não é assintoticamente restrito.

<img src='https://s0.wp.com/latex.php?latex=%5Comega%7B%7D%28g%28n%29%29+%3D+f%28n%29&bg=T&fg=000000&s=0' alt='\omega{}(g(n)) = f(n)' title='\omega{}(g(n)) = f(n)' class='latex' />, **se** _para qualquer constante_ <img src='https://s0.wp.com/latex.php?latex=c+%3E+0&bg=T&fg=000000&s=0' alt='c > 0' title='c > 0' class='latex' />, existe uma constante  <img src='https://s0.wp.com/latex.php?latex=n_%7B0%7D+%3E+0&bg=T&fg=000000&s=0' alt='n_{0} > 0' title='n_{0} > 0' class='latex' />tal que  <img src='https://s0.wp.com/latex.php?latex=0+%5Cleq%7B%7D+cg%28n%29+%5Cleq%7B%7D+f%28n%29&bg=T&fg=000000&s=0' alt='0 \leq{} cg(n) \leq{} f(n)' title='0 \leq{} cg(n) \leq{} f(n)' class='latex' />para todo <img src='https://s0.wp.com/latex.php?latex=n+%5Cgeq%7B%7D+n_%7B0%7D&bg=T&fg=000000&s=0' alt='n \geq{} n_{0}' title='n \geq{} n_{0}' class='latex' />.

Para analisar problemas mais complexos como, por exemplo, recorrências, existem métodos bastante interessantes, como o Teorema Mestre que o Cormen apresenta no Capítulo 4. É uma boa leitura pra quem se interessou.

* * *

Podemos criar várias comparações entre estas funções, mas isto não vem ao caso. O importante é saber em que notação a nossa função se encontra. Com o tempo vamos compreendendo melhor essas fórmulas.

Vamos relembrar o custo de nosso algoritmo… <img src='https://s0.wp.com/latex.php?latex=T%28n%29+%3D+n%5E%7B2%7D+%2B+3n&bg=T&fg=000000&s=0' alt='T(n) = n^{2} + 3n' title='T(n) = n^{2} + 3n' class='latex' />.

Vamos ver em que notação ele pode se encaixar, sabendo que  <img src='https://s0.wp.com/latex.php?latex=g%28n%29&bg=T&fg=000000&s=0' alt='g(n)' title='g(n)' class='latex' />seria a **ordem de crescimento** (parte importante) do nosso custo; no caso, <img src='https://s0.wp.com/latex.php?latex=n%5E%7B2%7D&bg=T&fg=000000&s=0' alt='n^{2}' title='n^{2}' class='latex' />.

Testamos primeiro se ele encaixa na função <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28n%5E%7B2%7D%29&bg=T&fg=000000&s=0' alt='\Theta{}(n^{2})' title='\Theta{}(n^{2})' class='latex' />. Vamos substituir  <img src='https://s0.wp.com/latex.php?latex=f%28n%29&bg=T&fg=000000&s=0' alt='f(n)' title='f(n)' class='latex' />e  <img src='https://s0.wp.com/latex.php?latex=g%28n%29&bg=T&fg=000000&s=0' alt='g(n)' title='g(n)' class='latex' />(naquela função ali em cima, onde diz **A notação <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D&bg=T&fg=000000&s=0' alt='\Theta{}' title='\Theta{}' class='latex' />**) pelos valores que conhecemos.


<img src='https://s0.wp.com/latex.php?latex=c_%7B1%7Dn%5E%7B2%7D+%5Cleq%7B%7D+n%5E%7B2%7D+%2B+3+n+%5Cleq%7B%7D+c_%7B2%7D+n%5E%7B2%7D&bg=T&fg=000000&s=0' alt='c_{1}n^{2} \leq{} n^{2} + 3 n \leq{} c_{2} n^{2}' title='c_{1}n^{2} \leq{} n^{2} + 3 n \leq{} c_{2} n^{2}' class='latex' />

Se dividirmos tudo por <img src='https://s0.wp.com/latex.php?latex=n%5E%7B2%7D&bg=T&fg=000000&s=0' alt='n^{2}' title='n^{2}' class='latex' />, obteremos:


<img src='https://s0.wp.com/latex.php?latex=c_%7B1%7D+%5Cleq%7B%7D+1+%2B+%5Cfrac%7B3%7D%7Bn%7D+%5Cleq%7B%7D+c_%7B2%7D&bg=T&fg=000000&s=0' alt='c_{1} \leq{} 1 + \frac{3}{n} \leq{} c_{2}' title='c_{1} \leq{} 1 + \frac{3}{n} \leq{} c_{2}' class='latex' />

Agora separaremos as inequações.

**Inequação 1:** <img src='https://s0.wp.com/latex.php?latex=c_%7B1%7D+%5Cleq%7B%7D+1+%2B+%5Cfrac%7B3%7D%7Bn%7D&bg=T&fg=000000&s=0' alt='c_{1} \leq{} 1 + \frac{3}{n}' title='c_{1} \leq{} 1 + \frac{3}{n}' class='latex' />

**Inequação 2:** <img src='https://s0.wp.com/latex.php?latex=1+%2B+%5Cfrac%7B3%7D%7Bn%7D+%5Cleq%7B%7D+c_%7B2%7D&bg=T&fg=000000&s=0' alt='1 + \frac{3}{n} \leq{} c_{2}' title='1 + \frac{3}{n} \leq{} c_{2}' class='latex' />

Para satisfazer a **Inequação 1**, podemos quase automaticamente perceber que para qualquer <img src='https://s0.wp.com/latex.php?latex=n+%5Cgeq%7B%7D+1&bg=T&fg=000000&s=0' alt='n \geq{} 1' title='n \geq{} 1' class='latex' />, é válido  <img src='https://s0.wp.com/latex.php?latex=c_%7B1%7D+%3D+1&bg=T&fg=000000&s=0' alt='c_{1} = 1' title='c_{1} = 1' class='latex' />(ora, por mais que  <img src='https://s0.wp.com/latex.php?latex=%5Cfrac%7B3%7D%7Bn%7D&bg=T&fg=000000&s=0' alt='\frac{3}{n}' title='\frac{3}{n}' class='latex' />chegue perto de 0, sempre ainda vamos ter a constante 1 adicionada a ele). Para satisfazer a **Inequação 2**, podemos perceber facilmente que para qualquer <img src='https://s0.wp.com/latex.php?latex=n+%5Cgeq%7B%7D+1&bg=T&fg=000000&s=0' alt='n \geq{} 1' title='n \geq{} 1' class='latex' />, é válido  <img src='https://s0.wp.com/latex.php?latex=c_%7B2%7D+%3D+4&bg=T&fg=000000&s=0' alt='c_{2} = 4' title='c_{2} = 4' class='latex' />(a função só tende a diminuir a partir que  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />vai aumentando e com <img src='https://s0.wp.com/latex.php?latex=n%3D1&bg=T&fg=000000&s=0' alt='n=1' title='n=1' class='latex' />, <img src='https://s0.wp.com/latex.php?latex=c_%7B2%7D%3D4&bg=T&fg=000000&s=0' alt='c_{2}=4' title='c_{2}=4' class='latex' />). Com isso, agora chegamos as três constantes que precisávamos.

 <img src='https://s0.wp.com/latex.php?latex=n_%7B0%7D&bg=T&fg=000000&s=0' alt='n_{0}' title='n_{0}' class='latex' />(o menor valor de <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />) <img src='https://s0.wp.com/latex.php?latex=%3D+1&bg=T&fg=000000&s=0' alt='= 1' title='= 1' class='latex' />; <img src='https://s0.wp.com/latex.php?latex=c_%7B1%7D+%3D+1&bg=T&fg=000000&s=0' alt='c_{1} = 1' title='c_{1} = 1' class='latex' />; <img src='https://s0.wp.com/latex.php?latex=c_%7B2%7D+%3D+4&bg=T&fg=000000&s=0' alt='c_{2} = 4' title='c_{2} = 4' class='latex' />.

Logo, concluímos que <img src='https://s0.wp.com/latex.php?latex=f%28n%29+%3D+n%5E%7B2%7D+%2B+3n+%3D+%5CTheta%7B%7D%28n%5E%7B2%7D%29&bg=T&fg=000000&s=0' alt='f(n) = n^{2} + 3n = \Theta{}(n^{2})' title='f(n) = n^{2} + 3n = \Theta{}(n^{2})' class='latex' />. Uma função que pertence a <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D&bg=T&fg=000000&s=0' alt='\Theta{}' title='\Theta{}' class='latex' />, tem um **limite assintótico superior** e **inferior** e, portanto, pertenceria também a  <img src='https://s0.wp.com/latex.php?latex=O%28n%5E%7B2%7D%29&bg=T&fg=000000&s=0' alt='O(n^{2})' title='O(n^{2})' class='latex' />e <img src='https://s0.wp.com/latex.php?latex=%5COmega%7B%7D%28n%5E%7B2%7D%29&bg=T&fg=000000&s=0' alt='\Omega{}(n^{2})' title='\Omega{}(n^{2})' class='latex' />, mas nem é necessário testar os outros valores porque já identificamos nossa função como _“theta de ene ao quadrado”_, que é a função mais “retinha” que podemos esperar.

Bom… Nos próximos artigos, veremos que um mesmo problema pode ter várias soluções diferentes com custos ainda mais diferentes! Por isso, é crucial sabermos analisar, mesmo que por cima, qual o algoritmo que é mais eficiente. Vou ficando por aqui…

