---
title: Mini-Poker
type: post
date: 2006-01-13T16:58:45+00:00
excerpt: "Uma pausa nos algoritmos de ordenação para usar nossos conhecimentos de forma prática solucionando um problema que caiu na prova da categoria Programação Nível 2 da Olimpíada Brasileira de Informática do ano passado: Mini-Poker."
url: /2006/01/mini-poker/
ordem:
  - eeemn
categorias:
  - Básico
tags:
  - algoritmos
  - mini-poker
  - obi
  - olimpíadas
  - ordenação
  - poker
  - problemas
  - programação
  - pseudocódigos
---

Resolvi fazer uma pausa nos algoritmos de ordenação para mostrar como podemos usar os conhecimentos já adquiridos de maneira prática. Vamos neste artigo resolver o problema **Mini-Poker**, que caiu na prova da **Programação Nível 2** (categoria para pessoas até 19 anos ou primeiro ano da faculdade) da **Olimpíada Brasileira de Informática** de 2005.

Esse post ficou gigante, mas é muito simples. Leia com atenção e acho que você não terá problemas… ;)

### Objetivos

Com esta resolução de problema, espero treinar com vocês o conceito de:

- Interpretação do Probema
- Entrada e Saída
- Ordenação por Inserção
- Pseudocódigo

Acho que será legal para pôrmos em prática o que já estudamos sobre algoritmos.

O problema é bem simples, mas é só pra iniciar.

### Enunciado

Mini-Poker é o nome do jogo de cartas que é uma simplificação de Poker, um dos mais famosos jogos de cartas do mundo. Mini-Poker é jogado com um baralho normal de 52 cartas, com quatro naipes (copas, paus, espadas e ouro), cada naipe compreendendo treze cartas (Ás, 2, 3, 4, 5, 6, 7, 8, 9, 10, Valete, Dama, Rei).

No início do jogo, cada jogador recebe cinco cartas. O conjunto de cinco cartas vale um certo número de pontos, de acordo com as regras descritas abaixo. Diferentemente do jogo de Poker normal, em Mini-poker o naipe das cartas é desconsiderado. Assim, para simplificar a descrição do jogo, vamos utilizar os números de 1 a 13 para identificar as cartas do baralho, na ordem dada acima. Uma outra diferença é que pode ocorrer empate entre mais de um vencedor; nesse caso os vencedores dividem o prêmio.

As regras para pontuação em Mini-Poker são as seguintes:

1. Se as cinco cartas estão em seqüência a partir da carta $x$ (ou seja, os valores das cartas são $x$, $x+1$, $x+2$, $x+3$ e $x+4$), a pontuação é $x+200$ pontos. Por exemplo, se as cartas recebidas são 10, 9, 8, 11 e 12, a pontuação é 208 pontos.
2. Se há quatro cartas iguais $x$ (uma _quadra_, ou seja, os valores das cartas são $x$, $x$, $x$, $x$ e $y$), a pontuação é $x+180$ pontos. Por exemplo, se as cartas recebidas são 1, 1, 1, 10 e 1, a pontuação é 181 pontos.
3. Se há três cartas iguais $x$ e outras duas cartas iguais $y$ (uma _trinca_ e um _par_, ou seja, os valores das cartas são $x$, $x$, $x$, $y$ e $y$), a pontuação é $x+160$ pontos. Por exemplo, se as cartas recebidas são 10, 4, 4, 10 e 4, a pontuação é 164 pontos.
4. Se há três cartas iguais $x$ e duas outras cartas diferentes $y$ e $z$ (uma _trinca_, ou seja, os valores das cartas são $x$, $x$, $x$, $y$ e $z$), a pontuação é $x+140$ pontos. Por exemplo, se as cartas recebidas são 2, 3, 2, 2 e 13, a pontuação é 142 pontos.
5. Se há duas cartas iguais $x$, duas outras cartas iguais $y$ ($x \neq{} y$) e uma outra carta distinta $z$ (dois _pares_, ou seja, os valores das cartas são $x$, $x$, $y$, $y$ e $z$), a pontuação é $3 \times{} x + 2 \times{} y + 20$ pontos, em que $x > y$. Por exemplo, se as cartas recebidas são 12, 7, 12, 8 e 7, a pontuação é 70 pontos.
6. Se há apenas duas cartas iguais $x$ e as outras são distintas (um _par_, ou seja, os valores das cartas são $x$, $x$, $y$, $z$ e $t$), a pontuação é $x$ pontos. Por exemplo, se as cartas recebidas são 12, 13, 5, 8 e 13, a pontuação é 13 pontos.
7. Se todas as cartas são distintas, não há pontuação.

#### Tarefa

Escreva um programa que, fornecidas as cartas dadas a um jogador, calcule a pontuação do jogador naquela jogada.

#### Entrada

A entrada é composta por vários casos de teste, cada um correspondendo a uma jogada. A primeira linha da entrada contém um número inteiro $N$ que indica o número de casos de teste ($1 \leq{} N \leq{} 100$). Cada uma das $N$ linhas seguintes contém cinco números inteiros $C\_{1}$, $C\_{2}$, $C\_{3}$, $C\_{4}$ e $C\_{5}$, representando as cinco cartas recebidas por um jogador ($1 \leq{} C\_{1}, C\_{2}, C\_{3}, C\_{4}, C\_{5} \leq{} 13$).

_A entrada deve ser lida do dispositivo de entrada padrão (normalmente o teclado)._

#### Saída

Para cada caso de teste da entrada, seu programa deve produzir três linhas na saída. A primeira linha deve conter um identificador do caso de teste, no formato _“Teste n”_, onde _n_ é numerado seqüencialmente a partir de 1. A segunda linha deve conter a pontuação do jogador considerando as cinco cartas recebidas. A terceira linha deve ser deixada em branco. A grafia mostrada no Exemplo de Saída, abaixo, deve ser seguida rigorosamente.

_A saída deve ser escrita no dispositivo de saída padrã (normalmente a tela)_.

#### Restrições

$1 \leq{} N \leq{} 100$
$1 \leq{} C\_{1}, C\_{2}, C\_{3}, C\_{4}, C\_{5} \leq{} 13$

#### Exemplo de Entrada

```
2
12 3 10 3 12
1 2 3 5 4
```

#### Saída para o Exemplo de Entrada

```
Teste 1
62

Teste 2
201
```

---

### Comentários sobre os problemas de olimpíadas

Todos os problemas passados em competições de programação tem um enunciado parecido com o desse. São especificados todos os limites (restrições), é dito exatamente como será a entrada e como deve ser a saída e geralmente tem uma historinha no começo… :D

Bom… Todos esses dados são fundamentais. Alguns limites nem vamos usar, não tem importância para a nossa solução, mas pode ter importância para outra pessoa que queira implementar um algoritmo diferente. A sintaxe da entrada e da saída são extremamente importantes. Na prova da _Seletiva IOI_ do ano passado, eu quase perdi 60 pontos (6 casos de teste) na solução de um problema simples porque meu programa desprezava um espaço no início de uma frase quando imprimia uma saída. E mesmo a historinha do começo é fundamental. Ela sempre dá boas dicas e algumas vezes até ilustra o problema (às vezes a gente nem lê o enunciado e já sabe que é um problema de grafos!)

Mas vamos a solução deste problema…

### Por onde começar?

Com o tempo você pode decidir fazer um caminho diferente, mas eu sugiro começar sempre pelo recebimento da entrada. Aliás, acho que isto é atípico, porque a maioria das pessoas prefere ler bastante o problema e desenvolver todo o algoritmo a mão antes de botar a mão na massa. Eu acho que depois que a gente recebe a entrada, fica bem mais fácil fazer o resto e a gente pode ir pensando enquanto a gente recebe a entrada! Então, depois que lemos o problema e já entendemos tudo o que ele quer, vamos fazer a entrada!

O problema fala que começa nos dando um número _N_ que será o número de casos de teste que teremos que receber depois. Sem dificuldade podemos escrever o \_pseudo_código a seguir:

**recebe** N  
**para** _nteste_ $\leftarrow{}$ 1 **até** _N_, **faça**  
**fim-para**

Já chamo a variável que loopa como _nteste_, porque já li a saída do problema e sei que vou precisar imprimir o número de caad caso de teste… ;)

Aí o enunciado diz que <q>Cada uma das $N$ linhas seguintes contém cinco números inteiros $C\_{1}$, $C\_{2}$, $C\_{3}$, $C\_{4}$ e $C\_{5}$, representando as cinco cartas recebidas por um jogador ($1 \leq{} C\_{1}, C\_{2}, C\_{3}, C\_{4}, C\_{5} \leq{} 13$).</q> Então, vamos receber os cinco números em cada iteração e colocá-los num vetor, é claro!

**recebe** N  
**para** _nteste_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;**recebe** $C_{1}, C_{2}, C_{3}, C_{4}, C_{5}$  
**fim-para**

E a entrada está pronta.

### Desenvolvimento

O programa se baseia em encontrarmos valores iguais nos elementos do vetor. O que podemos fazer para facilitar essa tarefa?

Isso mesmo: A ordenação! :D Se os elementos estiverem ordenados, ficará bem mais fácil para procurarmos quatro números iguais, porque eles não poderão ser qualquer uma das possibilidades, mas somente $C_{1}, C_{2}, C_{3}, C_{4}$ ou $C_{2}, C_{3}, C_{4}, C_{5}$.

Aí que algoritmos devemos implementar para ordenar? Isso é uma conclusão que vamos chegar no final de nossa série, mas para este algoritmo não tem solução melhor que a **Ordenação por Inserção**. É um caso pequeno (n=5) e a **Ordenação por Inserção** é mais rápida que a por **Seleção**, porque o seu melhor caso é uma função linear. Então, vamos implementar o **Insertion Sort** no nosso algoritmo:

**recebe** N  
**para** _nteste_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;**recebe** $C_{1}, C_{2}, C_{3}, C_{4}, C_{5}$  
 &emsp;_// início da ordenação por inserção_  
 &emsp;**para** _j_ $\leftarrow{}$ 2 **até** _5_  
 &emsp;&emsp;_elemento_ $\leftarrow{}$ $C_{j}$  
 &emsp;&emsp;_i_ $\leftarrow{}$ _j-1_  
 &emsp;&emsp;**enquanto** _i_ > 0 **e** $C_{i}$ > _elemento_, **faça**  
 &emsp;&emsp;&emsp;$C_{i+1}$ $\leftarrow{}$ $C_{i}$  
 &emsp;&emsp;&emsp;$i$ $\leftarrow{}$ $C_{i-1}$  
 &emsp;&emsp;**fim-enquanto**  
 &emsp;&emsp;$C_{i+1}$ $\leftarrow{}$ _elemento_  
 &emsp;**fim-para**  
 &emsp;_// fim da ordenação por inserção_  
**fim-para**

O bom desses algoritmos de ordenação é que sua lógica é muito simples e por isso é fácil decorá-los… Ao menos o **Insertion Sort** e o **Selection Sort** são algoritmos básicos que todo programador deve conhecer bem. Bom… Acredito que vocês não tenham tido dificuldade pra entender até aqui. A cor vermelha no pseudocódigo eu vou usar daqui pra frente para um comentário, que aliás, é uma excelente prática de boa programação.

O resto do problema precisa calcular quantos pontos o cara fez, baseado em suas cartas, agora já ordenadas. Para isto vamos criar uma função para testar vários **se** e retornar o resultado.

Eu poderia tirar os **se** aninhados, mas assim fica mais fácil a compreensão.

Como vamos ver com os pseudocódigos a seguir, é fácil testar cada uma das regras com o vetor ordenado:

#### Primeira Regra – Seqüência

Se as cinco cartas estão em seqüência a partir da carta $x$(ou seja, os valores das cartas são $x$, $x+1$, $x+2$, $x+3$ e $x+4$), a pontuação é $x+200$ pontos. Por exemplo, se as cartas recebidas são 10, 9, 8, 11 e 12, a pontuação é 208 pontos.

**se** $C_{1} = C_{2}-1$ e $C_{2} = C_{3}-1$ e $C_{3}=C_{4}-1$ e $C_{4}=C_{5}-1$, **então**  
 &emsp;**retorna** $C_{1}+200$  
**fim-se**

#### Segunda Regra – Quadra

Se há quatro cartas iguais $x$ (uma _quadra_, ou seja, os valores das cartas são $x$, $x$, $x$, $x$ e $y$), a pontuação é $x+180$ pontos. Por exemplo, se as cartas recebidas são 1, 1, 1, 10 e 1, a pontuação é 181 pontos.

**se** $C_{1} = C_{2} = C_{3} = C_{4}$ ou $C_{2} = C_{3} = C_{4} = C_{5}$, **então**  
 &emsp;**retorna** $C_{2}+180$  
**fim-se**

Aqui retornamos $C\_{2}$ porque ele será sempre parte da quadra (ela começando em $C\_{1}$ ou $C\_{2}$).

#### Terceira e Quarta Regra – Trinca

Se há três cartas iguais $x$ e outras duas cartas iguais $y$ (uma _trinca_ e um _par_, ou seja, os valores das cartas são $x$, $x$, $x$, $y$ e $y$), a pontuação é $x+160$ pontos. Por exemplo, se as cartas recebidas são 10, 4, 4, 10 e 4, a pontuação é 164 pontos.

**se** $C_{1} = C_{2} = C_{3}$ ou $C_{2} = C_{3} = C_{4}$ ou $C_{3} = C_{4} = C_{5}$, **então**  
 &emsp;**se** ( $C_{1} \neq{} C_{3}$ e $C_{1} = C_{2}$ ) ou ( $C_{3} \neq{} C_{5}$ e $C_{4} = C_{5}$ ), **então**  
 &emsp;&emsp;**retorna** $C_{3}+160$

Se há três cartas iguais $x$ e duas outras cartas diferentes $y$ e $z$ (uma _trinca_, ou seja, os valores das cartas são $x$, $x$, $x$, $y$ e $z$), a pontuação é $x+140$ pontos. Por exemplo, se as cartas recebidas são 2, 3, 2, 2 e 13, a pontuação é 142 pontos.

&emsp;**senão**  
 &emsp;&emsp;**retorna** $C_{3} + 140$  
 &emsp;**fim-se**  
**fim-se**

Note que aqui retornamos $C\_{3}$ porque ele será sempre parte da trinca (o mesmo motivo que retornarmos $C\_{2}$ para a quadra).

#### Quinta Regra – Duas Duplas

Se há duas cartas iguais $x$, duas outras cartas iguais $y$ ($x \neq{} y$) e uma outra carta distinta $z$ (dois _pares_, ou seja, os valores das cartas são $x$, $x$, $y$, $y$ e $z$), a pontuação é $3 \times{} x + 2 \times{} y + 20$ pontos, em que $x > y$. Por exemplo, se as cartas recebidas são 12, 7, 12, 8 e 7, a pontuação é 70 pontos.

**se** $C_{1} = C_{2}$ ou $C_{2} = C_{3}$, **então**  
 &emsp;**se** $C_{3} = C_{4}$ ou $C_{4} = C_{5}$, **então**  
 &emsp;&emsp;**retorna** $3 \times{} C_{4} + 2 \times{} C_{2} + 20$  
 &emsp;**fim-se**  
**fim-se**

$C\_{2}$ será sempre elemento da menor dupla e $C\_{4}$ será sempre elemento da maior dupla. Por isso usamos eles como $y$ e $x$, respectivamente.

#### Sexta Regra – Dupla

Se há apenas duas cartas iguais $x$ e as outras são distintas (um _par_, ou seja, os valores das cartas são $x$, $x$, $y$, $z$ e $t$), a pontuação é $x$ pontos. Por exemplo, se as cartas recebidas são 12, 13, 5, 8 e 13, a pontuação é 13 pontos.

**se** $C_{1} = C_{2}$ ou $C_{2} = C_{3}$, **então**  
 &emsp;**retorna** $C_{2}$  
**senão se** $C_{3} = C_{4}$ ou $C_{4} = C_{5}$, **então**  
 &emsp;**retorna** $C_{4}$  
**fim-se**

Separei em dois **SE**s porque senão não saberíamos que valor retornar.

#### Sétima Regra

Se todas as cartas são distintas, não há pontuação.

**retorna** 0

#### Função Inteira

Juntando todos os **SE**s, temos:

**função** _pontua_ (_C_)  
 &emsp;_// primeira regra_  
 &emsp;**se** $C_{1} = C_{2}-1$ e $C_{2} = C_{3}-1$ e $C_{3}=C_{4}-1$ e $C_{4}=C_{5}-1$, **então**  
 &emsp;&emsp;**retorna** $C_{1}+200$  
 &emsp;**fim-se**  
 &emsp;  
 &emsp;_// segunda regra_  
 &emsp;**se** $C_{1} = C_{2} = C_{3} = C_{4}$ ou $C_{2} = C_{3} = C_{4} = C_{5}$, **então**  
 &emsp;&emsp;**retorna** $C_{2}+180$  
 &emsp;**fim-se**  
 &emsp;  
 &emsp;_//terceira e quarta regra_  
 &emsp;**se** $C_{1} = C_{2} = C_{3}$ ou $C_{2} = C_{3} = C_{4}$ ou $C_{3} = C_{4} = C_{5}$, **então**  
 &emsp;&emsp;**se** ( $C_{1} \neq{} C_{3}$ e $C_{1} = C_{2}$ ) ou ( $C_{3} \neq{} C_{5}$ e $C_{4} = C_{5}$ ), **então**  
 &emsp;&emsp;&emsp;**retorna** $C_{3}+160$  
 &emsp;&emsp;**senão**  
 &emsp;&emsp;&emsp;**retorna** $C_{3} + 140$  
 &emsp;&emsp;**fim-se**  
 &emsp;**fim-se**  
 &emsp;  
 &emsp;_// quinta regra_  
 &emsp;**se** $C_{1} = C_{2}$ ou $C_{2} = C_{3}$, **então**  
 &emsp;&emsp;**se** $C_{3} = C_{4}$ ou $C_{4} = C_{5}$, **então**  
 &emsp;&emsp;&emsp;**retorna** $3 \times{} C_{4} + 2 \times{} C_{2} + 20$  
 &emsp;&emsp;**fim-se**  
 &emsp;**fim-se**  
 &emsp;  
 &emsp;_// sexta regra_  
 &emsp;**se** $C_{1} = C_{2}$ ou $C_{2} = C_{3}$, **então**  
 &emsp;&emsp;**retorna** $C_{2}$  
 &emsp;**senão se** $C_{3} = C_{4}$ ou $C_{4} = C_{5}$,  
 &emsp;**então**  
 &emsp;&emsp;**retorna** $C_{4}$  
 &emsp;**fim-se**  
 &emsp;  
 &emsp;_// sétima regra_  
 &emsp;**retorna** 0  
**fim-função**

Já que a função retorna assim que encontra um resultado, não há risco de ocorrer nada errado (por exemplo, uma quadra é sempre uma trinca, que é sempre uma dupla). Agora basta colocarmos esta função no nosso código e adaptar para a saída ser igual a que o problema pede.

### Saída

Para chegar a saída, basta fazermos o programa imprimir **Teste _nteste_** e depois o retorno da função **pontua**. Com isto, temos:

**recebe** N  
**para** _nteste_ $\leftarrow{}$ 1 **até** _N_, **faça**  
 &emsp;**recebe** $C_{1}, C_{2}, C_{3}, C_{4}, C_{5}$  
 &emsp;_// início da ordenação por inserção_  
 &emsp;**para** _j_ $\leftarrow{}$ 2 **até** _5_  
 &emsp;&emsp;_elemento_ $\leftarrow{}$ $C_{j}$  
 &emsp;&emsp;_i_ $\leftarrow{}$ _j-1_  
 &emsp;&emsp;**enquanto** _i_ > 0 **e** $C_{i}$ > _elemento_, **faça**  
 &emsp;&emsp;&emsp;$C_{i+1}$ $\leftarrow{}$ $C_{i}$  
 &emsp;&emsp;&emsp;$i$ $\leftarrow{}$ $C_{i-1}$  
 &emsp;&emsp;**fim-enquanto**  
 &emsp;&emsp;$C_{i+1}$ $\leftarrow{}$ _elemento_  
 &emsp;**fim-para**  
 &emsp;_// fim da ordenação por inserção_

&emsp;**imprime** "Teste "  
 &emsp;**imprime linha** testen  
 &emsp;**imprime linha** pontua(C)  
 &emsp;**imprime linha**  
**fim-para**

Fiz essa saída assim pra se parecer com Pascal, mas para cada linguagem ela pode ser bem diferente… Vejamos dois exemplos…

#### C

```c
printf("Teste %d\n%d\n\n", nteste, pontua(C));
```

#### PHP

```c
echo "Teste ".$nteste."\n".pontua($C)."\n\n";
```

### Comentários sobre o problema

Este problema é muito chato. É trivial, mas perdemos um tempo enorme escrevendo **se**s. Ninguém gosta de um problema como esse, mas quando cai numa olimpíada somos obrigados a resolver… hehehe… Mas, para a felicidade geral de todos, saibam que a maioria dos problemas de olimpíadas não são assim. Exigem mais lógica e menos código. Com o tempo, vamos pegando problemas mais difíceis. Espero só ter cumprido meu objetivo dando uma utilidade pra **ordenação**, **entrada e saída** e que vocês tenham entendido tudo.

Sugiro que quem esteja aprendendo algoritmos com meus artigos e já saiba programar um pouquinho, resolva alguns problemas simples do [site da OBI][1], que separei especialmente pra vocês!

- [Bits Trocados][2]
- [Calculando][3]
- [Cofrinhos da Vó Vitória][4]
- [Quermesse][5]

E, gostaria de fixar, mais importante é a interpretação e o seu pensamento… Programar é fácil!

[1]: http://olimpiada.ic.unicamp.br
[2]: http://olimpiada.ic.unicamp.br/programacao/tarefas/bits_trocados
[3]: http://olimpiada.ic.unicamp.br/programacao/tarefas/calculando
[4]: http://olimpiada.ic.unicamp.br/programacao/tarefas/cofre
[5]: http://olimpiada.ic.unicamp.br/programacao/tarefas/quermesse
