---
title: Crivo de Eratóstenes
type: post
date: 2007-06-17T13:40:53+00:00
url: /2007/06/crivo-de-eratostenes/
ordem:
  - eeenn
categories:
  - Curiosidades
tags:
  - algoritmos
  - c
  - crivo de eratóstenes
  - Matemática
  - números primos
  - primos
  - raiz quadrada
  - usaco

---
Encontrar números primos é um problema comum em olimpíadas e maratonas de programação. Até hoje não existe uma maneira fácil de determinar se um número é ou não primo, mas para resolver estes problemas é indispensável o conhecimento de alguns algoritmos clássicos e simples, como o **Crivo de Eratóstenes**.

O **Crivo de Eratóstenes** é um método bastante prático para encontrar os primos de _2_ até um _valor limite_, que pode ser feito a mão e é fácil de implementar.

O algoritmo consiste em:

  1. Determinar (ou receber na entrada do programa) o **valor limite**, isto é, o maior número que desejamos saber se é primo.
  2. Fazer a raiz quadrada do valor limite. Pode-se arredondar para baixo caso a raiz não seja exata (e quase nunca é).
  3. Criar um vetor (lista) com os números de 2 até o valor limite.
  4. Para **i=2** até **raiz do valor limite**, caso o número (**i**) não esteja riscado insira-o na lista dos primos (ou imprima-o, ou não faça nada, isso depende da utilidade que você quer dar para o crivo) e risque todos os seus múltiplos na lista.

Há várias maneiras de implementar este algoritmo. Eu _pseudocodaria_ (meu pseudocódigo é bem próximo de uma linguagem normal, porque acho que assim é mais fácil de entender e depois implementar) ele assim:

```
/* Primeiro passo */
<strong>recebe</strong> valorLimite

/* Segundo passo */
raiz <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow&bg=T&fg=000000&s=0' alt='\leftarrow' title='\leftarrow' class='latex' /> <img src='https://s0.wp.com/latex.php?latex=%5Csqrt%7BvalorLimite%7D&bg=T&fg=000000&s=0' alt='\sqrt{valorLimite}' title='\sqrt{valorLimite}' class='latex' />

/* Terceiro passo */
<strong>para</strong> <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow&bg=T&fg=000000&s=0' alt='\leftarrow' title='\leftarrow' class='latex' /> 2 <strong>até</strong> <em>valorLimite</em>
    <em>vetor[i]</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow&bg=T&fg=000000&s=0' alt='\leftarrow' title='\leftarrow' class='latex' /> <em>i</em>
<strong>fim-para</strong>

/* Quarto passo */
<strong>para</strong> <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow&bg=T&fg=000000&s=0' alt='\leftarrow' title='\leftarrow' class='latex' /> 2 <strong>até</strong> <em>raiz</em>
    <strong>se</strong> <em>vetor[i] = i</em>
        <strong>imprima</strong> "O número " <em>i</em> " é primo."
        <strong>para</strong> <em>j</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow&bg=T&fg=000000&s=0' alt='\leftarrow' title='\leftarrow' class='latex' /> <em>i+i</em> até <em>valorLimite</em>, de <em>i</em> e <em>i</em>
            <em>vetor[j]</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow&bg=T&fg=000000&s=0' alt='\leftarrow' title='\leftarrow' class='latex' /> 0
        <strong>fim-para</strong>
    <strong>fim-se</strong>
<strong>fim-para</strong>
```

Vêem como é simples?

### Crivo de Eratóstenes implementado em C

```c
#include <stdio.h>
#include <math.h> // necessário para raiz

#define NMAX 1000000 // valor máximo para o valor máximo

int main() {
    int i, j, vetor[NMAX];
    int valorMaximo, raiz;

    // Primeiro passo
    scanf("%d", &valorMaximo);

    // Segundo passo
    raiz=sqrt(valorMaximo);

    // Terceiro passo
    for (i=2; i<=valorMaximo; i++) {
        vetor[i]=i;
    }

    // Quarto passo
    for (i=2; i<=raiz; i++) {
        if (vetor[i]==i) {
            printf("%d é primo!n", i);
            for (j=i+i; j<=valorMaximo; j+=i) {
                vetor[j]=0; // removendo da lista
            }
        }
    }

    return 0;
}
```

No [USACO Training Program Gateway][1] (programa de treinamento para olimpíadas dos estado-unidenses) há um [problema muito interessante][2] (_Prime Palindromes_) cujo objetivo é determinar palíndromos primos de X a Y. Uma das melhores situações que já encontrei para usar o Crivo e sem dúvidas é um ótimo treinamento. Além de determinar primos, você terá que determinar palíndromos e é outro ótimo exercício lógico-matemático.

Divirtam-se e qualquer dúvida usem os comentários!

 [1]: http://train.usaco.org/usacogate
 [2]: http://ace.delos.com/usacoanal2?a=8Z8Pqa7IVqm&S=pprime

