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

Em matemática, o número fatorial de  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />é igual a: <img src='https://s0.wp.com/latex.php?latex=n+%5Ctimes%7B%7D+n-1+%5Ctimes%7B%7D+n-2+%5Ctimes%7B%7D+%5Cldots%7B%7D+2+%5Ctimes%7B%7D+1&bg=T&fg=000000&s=0' alt='n \times{} n-1 \times{} n-2 \times{} \ldots{} 2 \times{} 1' title='n \times{} n-1 \times{} n-2 \times{} \ldots{} 2 \times{} 1' class='latex' />.

Logo, por exemplo,  <img src='https://s0.wp.com/latex.php?latex=5%21&bg=T&fg=000000&s=0' alt='5!' title='5!' class='latex' />(cinco fatorial) seria igual a: <img src='https://s0.wp.com/latex.php?latex=5+%5Ctimes%7B%7D+4+%5Ctimes%7B%7D+3+%5Ctimes%7B%7D+2+%5Ctimes%7B%7D+1+%3D+120&bg=T&fg=000000&s=0' alt='5 \times{} 4 \times{} 3 \times{} 2 \times{} 1 = 120' title='5 \times{} 4 \times{} 3 \times{} 2 \times{} 1 = 120' class='latex' />.

* * *

Um exemplo bom e simples de recursão é um algoritmo para determinar números fatoriais:

```
1. <strong>função</strong> <em>fatorial</em> (<em>n</em>)
2.  <strong>se</strong> <img src='https://s0.wp.com/latex.php?latex=n+%3D+1&bg=T&fg=000000&s=0' alt='n = 1' title='n = 1' class='latex' />, <strong>então</strong>
3.      <strong>retorna</strong> <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />
4.  <strong>senão</strong>
5.      <strong>retorna</strong> <img src='https://s0.wp.com/latex.php?latex=n+%5Ctimes%7B%7D+fatorial%28n-1%29&bg=T&fg=000000&s=0' alt='n \times{} fatorial(n-1)' title='n \times{} fatorial(n-1)' class='latex' />
6.  <strong>fim-se</strong>
7. <strong>fim-função</strong>
```

**Domínio de nossa função:** <img src='https://s0.wp.com/latex.php?latex=n+%5Cin%7B%7D+%5Cmathbf%7BN%7D+%2F+n+%5Cgeq%7B%7D+1&bg=T&fg=000000&s=0' alt='n \in{} \mathbf{N} / n \geq{} 1' title='n \in{} \mathbf{N} / n \geq{} 1' class='latex' />.

### Qual o custo desse algoritmo?

Vamos abrir um grande parênteses aqui até a próxima linha horizontal para descobrir qual o custo do nosso algoritmo antes de continuar com a conversa sobre **recursão** e relembrar/reforçar o post sobre [Análise de Algoritmos][1]. Vou colocar o número de vezes que cada instrução é executada, usando o esquema que será o padrão para as próximas vezes que veremos custos:

**Número da linha: Número de vezes que é executada.**.

  1. <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />
  2. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />
  3. <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />
  4. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />
  5. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />


<img src='https://s0.wp.com/latex.php?latex=T%28n%29+%3D+%28n%29+%2B+%28n-1%29+%2B+%281%29+%2B+%28n-1%29+%2B+%28n-1%29+%3D+4n+-+2&bg=T&fg=000000&s=0' alt='T(n) = (n) + (n-1) + (1) + (n-1) + (n-1) = 4n - 2' title='T(n) = (n) + (n-1) + (1) + (n-1) + (n-1) = 4n - 2' class='latex' />

Uma **função linear**, o tipo de algoritmo mais simples que podemos encontrar, com excessão dos que são uma **função constante**. Mas o parênteses na verdade não serviu só pra isso. Eu queria aproveitar pra _escovar uns bits_ de nosso código. Você percebeu que o primeiro condicional é executado  <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />vezes, mas só entramos nele **uma** vez? Então vamos inverter nosso condicional.

```
1. <strong>função</strong> <em>fatorial</em> (<em>n</em>)
2.  <strong>se</strong> <img src='https://s0.wp.com/latex.php?latex=n+%3E+1&bg=T&fg=000000&s=0' alt='n > 1' title='n > 1' class='latex' />, <strong>então</strong>
3.      <strong>retorna</strong> <img src='https://s0.wp.com/latex.php?latex=n+%5Ctimes%7B%7D+fatorial%28n-1%29&bg=T&fg=000000&s=0' alt='n \times{} fatorial(n-1)' title='n \times{} fatorial(n-1)' class='latex' />
4.  <strong>senão</strong>
5.      <strong>retorna</strong> <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />
6.  <strong>fim-se</strong>
7. <strong>fim-função</strong>
```

#### Novo custo

  1. <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />
  2. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />
  3. <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />
  4. <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />
  5. <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />


<img src='https://s0.wp.com/latex.php?latex=T%28n%29+%3D+%28n%29+%2B+%28n-1%29+%2B+%28n-1%29+%2B+%281%29+%2B+%281%29+%3D+3n&bg=T&fg=000000&s=0' alt='T(n) = (n) + (n-1) + (n-1) + (1) + (1) = 3n' title='T(n) = (n) + (n-1) + (n-1) + (1) + (1) = 3n' class='latex' />

Claro que continua uma **função linear**, não houve nenhuma grande mudança. Os dois continuam com a mesma ordem de crescimento e tal…  <img src='https://s0.wp.com/latex.php?latex=4n%2B2&bg=T&fg=000000&s=0' alt='4n+2' title='4n+2' class='latex' />comparado com  <img src='https://s0.wp.com/latex.php?latex=3n&bg=T&fg=000000&s=0' alt='3n' title='3n' class='latex' />é uma diferença pequena, mas essa solução ficou bem mais elegante. ;) Poxa, diminuímos o custo do algoritmo em <img src='https://s0.wp.com/latex.php?latex=%5Cfrac%7B1%7D%7B4%7D&bg=T&fg=000000&s=0' alt='\frac{1}{4}' title='\frac{1}{4}' class='latex' />! Hehehe…

Agora, antes de continuar, só vamos definir a **notação assintótica** desse nosso novo custo!

A fórmula do  <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D&bg=T&fg=000000&s=0' alt='\Theta{}' title='\Theta{}' class='latex' />é: <img src='https://s0.wp.com/latex.php?latex=0+%5Cleq%7B%7D+c_%7B1%7D+g%28n%29+%5Cleq%7B%7D+f%28n%29+%5Cleq%7B%7D+c_%7B2%7D+g%28n%29&bg=T&fg=000000&s=0' alt='0 \leq{} c_{1} g(n) \leq{} f(n) \leq{} c_{2} g(n)' title='0 \leq{} c_{1} g(n) \leq{} f(n) \leq{} c_{2} g(n)' class='latex' />

Substituindo pela nossa função, temos: <img src='https://s0.wp.com/latex.php?latex=c_%7B1%7Dn+%5Cleq%7B%7D+3n+%5Cleq%7B%7D+c_%7B2%7Dn&bg=T&fg=000000&s=0' alt='c_{1}n \leq{} 3n \leq{} c_{2}n' title='c_{1}n \leq{} 3n \leq{} c_{2}n' class='latex' />. É trivial, que podemos escolher para as duas constantes  <img src='https://s0.wp.com/latex.php?latex=c_%7B1%7D%3Dc_%7B2%7D%3D3&bg=T&fg=000000&s=0' alt='c_{1}=c_{2}=3' title='c_{1}=c_{2}=3' class='latex' />e para <img src='https://s0.wp.com/latex.php?latex=n_%7B0%7D%3D0&bg=T&fg=000000&s=0' alt='n_{0}=0' title='n_{0}=0' class='latex' />. Com isso pretendi mostrar-lhes uma conclusão óbvia que no outro artigo não tinha mostrado para não complicar muito: uma função reta (linear) pertence sempre a notação  <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28n%29&bg=T&fg=000000&s=0' alt='\Theta{}(n)' title='\Theta{}(n)' class='latex' />e uma função quadrática pertence sempre a notação  <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28n%5E%7B2%7D%29&bg=T&fg=000000&s=0' alt='\Theta{}(n^{2})' title='\Theta{}(n^{2})' class='latex' />(ora, façam um gráfico das funções e vejam se isso não é óbvio!). Mas vamos aprendendo mais sobre **análise de algoritmos** com o tempo…

* * *

Bom… Continuando com a recursão… Nossa função cria um loop consigo mesma, ao invés de usar um **para** (for) ou **enquanto** (while). Ela se repete diminuindo um de  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />a cada iteração, até que chegue ao valor mínimo  <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />aonde a resposta é trivial: <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />.

O que é necessário para criarmos uma **recursão**? Apenas um ponto de parada! Temos que tomar cuidado para não criarmos _loops infinitos_ cuidando sempre com cada entrada que o usuário pode colocar. Nesse caso, eu determinei que o domínio da função é <img src='https://s0.wp.com/latex.php?latex=n+%5Cin%7B%7D+%5Cmathbf%7BN%7D+%2F+n+%5Cgeq%7B%7D+1&bg=T&fg=000000&s=0' alt='n \in{} \mathbf{N} / n \geq{} 1' title='n \in{} \mathbf{N} / n \geq{} 1' class='latex' />. Se o cara colocasse <img src='https://s0.wp.com/latex.php?latex=n%3D0&bg=T&fg=000000&s=0' alt='n=0' title='n=0' class='latex' />, minha função iria diminuindo infinitamente… e nunca iria retornar nada!

Para fazer a recursão portanto, precisamos analisar o domínio de nossa função e mais: precisamos conhecer um valor (que vai ser o limite; no caso do **fatorial**, o valor que sabíamos é que <img src='https://s0.wp.com/latex.php?latex=1%21+%3D+1&bg=T&fg=000000&s=0' alt='1! = 1' title='1! = 1' class='latex' />).

Acredito que vocês tenham achado tudo simples e que não tenham problema com isso. Funções recursivas vão ser extremamente úteis para nós nos próximos artigos. Vou finalizar mostrando-lhes alguns casos básicos de algoritmos em que podemos usar a recursão:

### Números de Fibonacci

```
1. <strong>função</strong> <em>fibonacci</em> (<em>n</em>)
2.  <strong>se</strong> <img src='https://s0.wp.com/latex.php?latex=n+%5Cgeq%7B%7D+3&bg=T&fg=000000&s=0' alt='n \geq{} 3' title='n \geq{} 3' class='latex' />, <strong>então</strong>
3.      <strong>retorna</strong> <img src='https://s0.wp.com/latex.php?latex=fibonacci%28n-1%29+%2B+fibonacci%28n-2%29&bg=T&fg=000000&s=0' alt='fibonacci(n-1) + fibonacci(n-2)' title='fibonacci(n-1) + fibonacci(n-2)' class='latex' />
4.  <strong>senão</strong>
5.      <strong>retorna</strong> <img src='https://s0.wp.com/latex.php?latex=1&bg=T&fg=000000&s=0' alt='1' title='1' class='latex' />
6.  <strong>fim-se</strong>
7. <strong>fim-função</strong>
```

**Domínio de fibonacci(n)**: <img src='https://s0.wp.com/latex.php?latex=n+%5Cin%7B%7D+N+%2F+n+%5Cgeq%7B%7D+1&bg=T&fg=000000&s=0' alt='n \in{} N / n \geq{} 1' title='n \in{} N / n \geq{} 1' class='latex' />

_Depois descobriremos como calcular os **números de Fibonacci** mais rápido, mas por enquanto nosso objetivo é a recursão!_

### Substituir um loop

Vamos supor que você quer imprimir os números de **n** a **1** e esqueceu a sintaxe do **para**… :D

```
1. <strong>função</strong> <em>imprime_ate</em> (<em>n</em>)
2.  <strong>imprima</strong> <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />
3.  <strong>se</strong> <img src='https://s0.wp.com/latex.php?latex=n%3E1&bg=T&fg=000000&s=0' alt='n>1' title='n>1' class='latex' />, <strong>então</strong>
4.      <strong>imprime_ate</strong>(<em>n-1</em>)
5.  <strong>fim-se</strong>
6. <strong>fim-função</strong>
```

**Domínio de imprime_ate(n)**: <img src='https://s0.wp.com/latex.php?latex=n+%5Cin%7B%7D+N+%2F+n+%5Cgeq%7B%7D+1&bg=T&fg=000000&s=0' alt='n \in{} N / n \geq{} 1' title='n \in{} N / n \geq{} 1' class='latex' />

Todo loop pode ser uma recursão e tem alguns que ficam bem mais fáceis se forem! Nesse caso, é claro que seria mais simples usarmos um **para**!

### Outros exemplos, para concluir

  * Ordenação por Intercalação (Merge Sort)
  * Busca em Profundidade (Depth-First Search) em Grafos
  * Union/Find
  * … entre vários outros casos!

 [1]: http://algoritmos.tiagomadeira.net/analise-de-algoritmos

