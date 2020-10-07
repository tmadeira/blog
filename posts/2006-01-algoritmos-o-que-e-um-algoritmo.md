---
title: O que é um algoritmo?
date: 2006-01-04T16:55:31+00:00
excerpt: Um algoritmo é um procedimento computacional definido que recebe um ou mais valores (entrada) e produz um ou mais valores (saída). O algoritmo é aquela fórmula matemática, aquele pedaço de código, que fica ali no meio da entrada e da saída para transformar o primeiro no segundo.
url: /2006/01/algoritmos-o-que-e-um-algoritmo/
tags:
  - algoritmo
  - algoritmos
  - computação
  - definição
  - entrada
  - lógica
  - o que é um algoritmo
  - programação
  - saída
  - variáveis
---

Um algoritmo é um procedimento computacional definido que recebe um ou mais valores **(entrada)** e produz um ou mais valores **(saída)**. O algoritmo é aquela fórmula matemática, aquele pedaço de código, que fica ali no meio da entrada e da saída para transformar o primeiro no segundo.

Vamos supôr por exemplo que temos a função:

$$
f(x) = \frac{x^{2}}{3}
$$

A sua entrada é o **x** e a sua saída é o **y** (ou **f(x)**, o valor que a função retorna).

O algoritmo aqui seria o seginte:

1. Entrada: Receber o valor X.
2. Elevar X ao quadrado e guardar o número resultante como Z.
3. Dividir Z por 3 e guardar o número resultante como Y.
4. Saída: Imprimir o valor Y.

O algoritmo, portanto, é a lógica do nosso problema matemático, ou, informático. É a seqüência de passos que eu faço na minha cabeça (ou, quando é complexo, no papel) antes de escrever, em C, a função **f**:

```c
int f(int x) {
   int z, y;
   z = pow(x, 2);
   y = z/3;
   return y;
}
```

Se formos pensar, veremos que tudo o que fazemos é um algoritmo, é um procedimento que recebe uma entrada e envia uma saída. Não só no computador, mas na vida. Quando eu falo com alguém, eu espero sua entrada (o que a pessoa fala pra mim), então penso e transformo essa entrada numa saída (a resposta que vou dar pra pessoa). E assim é com várias outras coisas. Podemos dizer também que acordar é um algoritmo, por exemplo:

1. Entrada: Meu cérebro disse que eu estou acordado!
2. Percebi que acordei, mas estou com sono. Espero um pouco.
3. Saída: Abrir os olhos.
4. Saída: Se espreguiçar.
5. Saída: Tirar a coberta.
6. Saída: Sentar na cama.
7. Saída: Sair da cama.

Podem existir vários algoritmos diferentes para resolver o mesmo problema. No caso de **Acordar**, cada um acorda de forma diferente, por exemplo. Foi até um exemplo meio estranho esse aí, mas outro algoritmo poderia dar outra saída, como por exemplo simplesmente abrir os olhos e cair da cama. Ou no caso acima da função matemática, poderíamos ter um algoritmo que fizesse a mesma coisa de maneira diferente também.

O algoritmo que usamos depende principalmente do tempo que ele demora pra ser executado e a memória que ele gasta no computador. Chamamos isso de **custo**. Quando começarmos a ver os algoritmos de ordenação de vetores (arrays), veremos que cada algoritmo faz uma coisa diferente, mas todos servem para o mesmo propósito: ordenar o vetor. Para uma entrada pequena, um pode ser mais rápido… Para uma maior, outro. Portanto, o algoritmo que queremos usar (o tempo que ele vai demorar pra ser executado e a memória que ele vai gastar no computador) depende principalmente do tamanho da entrada (que chamamos de **n** e no exemplo da função seria lá em cima seria a variável **x**).

Na maioria dos casos (e vai ser sempre assim aqui nos meus artigos), a entrada será o teclado (por exemplo, o usuário digita o X para a função) e a saída será a tela (por exemplo, o programa imprime o resultado da função, o Y, para a tela). Essas são a entrada e saída padrão (**st**andar**d** **i**nput **o**utput do C), que é usada nas olimpíadas e na maioria dos problemas que resolvemos no computador.

Em resumo, portanto, um algoritmo é a lógica de um programa computacional. Nos próximos artigos, isso deverá ser mais esclarecido e começaremos a ver algoritmos “de verdade” ;)

Qualquer dúvida, sugestão ou notificação de erro; poste um comentário ou me envie um e-mail (não só nesse, mas também nos próximos artigos). Espero que gostem.
