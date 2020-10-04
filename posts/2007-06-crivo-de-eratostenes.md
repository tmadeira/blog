---
title: Crivo de Eratóstenes
type: post
date: 2007-06-17T13:40:53+00:00
url: /2007/06/crivo-de-eratostenes/
ordem:
  - eeenn
categorias:
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

/_ Primeiro passo _/  
**recebe** valorLimite

/_ Segundo passo _/  
raiz $\leftarrow$ $\sqrt{valorLimite}$

/_ Terceiro passo _/  
**para** _i_ $\leftarrow$ 2 **até** _valorLimite_  
 &emsp;_vetor[i]_ $\leftarrow$ _i_  
**fim-para**

/_ Quarto passo _/  
**para** _i_ $\leftarrow$ 2 **até** _raiz_  
 &emsp;**se** _vetor[i] = i_  
 &emsp;&emsp;**imprima** "O número " _i_ " é primo."  
 &emsp;&emsp;**para** _j_ $\leftarrow$ _i+i_ até _valorLimite_, de _i_ e _i_  
 &emsp;&emsp;&emsp;_vetor[j]_ $\leftarrow$ 0  
 &emsp;&emsp;**fim-para**  
 &emsp;**fim-se**  
**fim-para**

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
