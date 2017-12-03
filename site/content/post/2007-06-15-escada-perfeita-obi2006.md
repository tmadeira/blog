---
title: Escada perfeita (OBI2006)
type: post
date: 2007-06-15T12:38:30+00:00
url: /2007/06/escada-perfeita-obi2006/
ordem:
  - eeess
categories:
  - Algoritmos gulosos
tags:
  - algoritmos
  - algoritmos gulosos
  - computação
  - escada perfeita
  - obi
  - obi 2006
  - pa
  - problemas
  - programação

---
Depois de meses sem postar, resolvi que a partir de agora darei mais atenção pra este blog. Muita gente me manda e-mail e comentários com dúvidas e gostaria de deixar bem claro que eu não faço trabalhos de faculdade pra ninguém, mas que se você tiver uma dúvida real onde eu possa ajudar eu ajudarei de bom grado.

Pensei muito sobre o que postar aqui, tenho rascunhos sobre buscas em grafos e sobre resoluções de problemas de grafos, mas resolvi quebrar toda a ordem e, a partir de um _scrap_ de orkut, acabei me lembrando do problema **Escada perfeita**, da [OBI 2006][1], e me deu vontade de resolvê-lo aqui.

### Por que o problema Escada Perfeita?

A programação deste problema é extremamente simples, mas a sua lógica (matemática pura) é muito inteligente. Tente resolver o problema antes de ver minha solução e, caso não consiga, depois veja como a solução é bonita.

### Vamos ao enunciado…

Uma construtora, durante a criação de um parque temático, encontrou no terreno um conjunto de várias pilhas de cubos de pedra. Ao invés de pagar pela remoção dos cubos de pedras, um dos arquitetos da empresa achou interessante utilizar as pedras para decoração do parque, determinando que as pedras fossem rearranjadas no formato de “escada”. para isso, os funcionários deveriam mover alguns cubos para formar os degraus das escadas. Só que o arquiteto decidiu que, entre uma pilha e outra de pedras deveria haver exatamente uma pedra de diferença, formando o que ele chamou de escada perfeita. O exemplo abaixo mostra um conjunto de cinco pilhas de pedras encontradas e as cinco pilhas como ficaram após a arrumação em escada perfeita.

[<img src="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2007/06/ilustraescada1.gif?resize=300%2C100" alt="" title="ilustraescada" class="aligncenter size-full wp-image-126" data-recalc-dims="1" />][2]

### Tarefa

Dada uma seqüência de pilhas de cubos de pedras com suas respectivas alturas, você deve determinar o número mínimo de pedras que precisam ser movidas para formar uma escada perfeita com exatamente o mesmo número de pilhas de pedras encontrado inicialmente (ou seja, não devem ser criadas ou eliminadas pilhas de pedras). O degrau mais baixo da escada deve sempre estar do lado esquerdo.

### Entrada

A entrada contém um único conjunto de testes, que deve ser lido do _dispositivo de entrada padrão_ (normalmente o teclado). A primeira linha contém um inteiro _n_ que indica o número de pilhas de pedras. A segunda linha contém _N_ números inteiros que indicam a quantidade de cubos de pedras em cada uma das pilhas, da esquerda para a direita.

### Saída

Seu programa deve imprimir, na _saída padrão_, uma única linha, contendo um inteiro: o número mínimo de cubos de pedras que devem ser movidos para transformar o conjunto de pilhas em uma escada perfeita, conforme calculado pelo seu programa. Caso não seja possível efetuar a transformação em escada perfeita, imprima como resultado o valor -1.

### Exemplos

#### Exemplo 1

```
<strong>Entrada</strong>
5
5 4 5 4 2

<strong>Saída</strong>
5
```

#### Exemplo 2

```
<strong>Entrada</strong>
6
9 8 7 6 5 4

<strong>Saída</strong>
9
```

#### Exemplo 3

```
<strong>Entrada</strong>
2
1 5

<strong>Saída</strong>
-1
```

* * *

OK. Estão prontos?

Depois de pensar um pouco, conclui-se que:

  1. A **escada perfeita** é uma <acronym title="Progressão aritmética">PA</acronym> de razão 1 (aumenta de um em um). Você lembra disso do seu primeiro ano do Ensino Médio? Senão, é bom dar uma [relembrada][3]. As fórmulas (simples e facilmente deduzíveis) da PA são:

    #### Termo geral da PA


<img src='https://s0.wp.com/latex.php?latex=a_%7Bn%7D+%3D+a_%7B1%7D+%2B+%28n-1%29.r&bg=T&fg=000000&s=0' alt='a_{n} = a_{1} + (n-1).r' title='a_{n} = a_{1} + (n-1).r' class='latex' />
    #### Soma de PA


<img src='https://s0.wp.com/latex.php?latex=%5Cdisplaystyle+S_%7Bn%7D+%3D+%28a_%7B1%7D%2Ba_%7Bn%7D%29.%5Cfrac%7Bn%7D%7B2%7D&bg=T&fg=000000&s=0' alt='\displaystyle S_{n} = (a_{1}+a_{n}).\frac{n}{2}' title='\displaystyle S_{n} = (a_{1}+a_{n}).\frac{n}{2}' class='latex' /> </li>

      * Sabemos quanto vale **n** (o número de pilhas, número de elementos da PA) e conseguimos calcular a **soma de todos os elementos** (podemos fazer isso até durante o loop da entrada, certo?)
      * Sabemos quanto vale a razão (r=1).
      * Substituindo o que sabemos nas fórmulas conseguimos formar um sistema de equações básico e desta forma torna-se fácil descobrir o valor do primeiro e do último termo da PA ( <img src='https://s0.wp.com/latex.php?latex=a_%7B1%7D&bg=T&fg=000000&s=0' alt='a_{1}' title='a_{1}' class='latex' />e <img src='https://s0.wp.com/latex.php?latex=a_%7Bn%7D&bg=T&fg=000000&s=0' alt='a_{n}' title='a_{n}' class='latex' />). Resumindo um pouco os cálculos, depois de alguma manipulação algébrica você chega a:
<img src='https://s0.wp.com/latex.php?latex=%5Cdisplaystyle+a_%7Bn%7D+%3D+%5Cfrac%7B%5Cfrac%7B2.S_%7Bn%7D%7D%7Bn%7D%2Bn-1%7D%7B2%7D&bg=T&fg=000000&s=0' alt='\displaystyle a_{n} = \frac{\frac{2.S_{n}}{n}+n-1}{2}' title='\displaystyle a_{n} = \frac{\frac{2.S_{n}}{n}+n-1}{2}' class='latex' />

<img src='https://s0.wp.com/latex.php?latex=%5Cdisplaystyle+a_%7B1%7D+%3D+1+%2B+a_%7Bn%7D+-+n&bg=T&fg=000000&s=0' alt='\displaystyle a_{1} = 1 + a_{n} - n' title='\displaystyle a_{1} = 1 + a_{n} - n' class='latex' /> </li>

          * Agora que já sabemos onde começa e onde termina a escada basta fazer um loop em cada fila de blocos e adicionar à uma variável _movimentos_ a quantidade de quadradinhos que estão sobrando nesta fileira (por exemplo, na primeira fileira da figura do enunciado está sobrando três quadradinhos para chegar ao <img src='https://s0.wp.com/latex.php?latex=a_%7B1%7D%3D2&bg=T&fg=000000&s=0' alt='a_{1}=2' title='a_{1}=2' class='latex' />). Ao mesmo tempo, adicionamos à outra variável (_moves_) a quantidade de quadradinhos que devem ser retirados **ou** colocados na fileira (porque depois se esta variável não for igual a 0 imprimimos -1). Ficou claro?</ol>

        ### Implementação

        #### Variáveis

          * **n**: número de degraus (fileiras de blocos)
          * **a**: <img src='https://s0.wp.com/latex.php?latex=a_%7B1%7D&bg=T&fg=000000&s=0' alt='a_{1}' title='a_{1}' class='latex' />, número de blocos do primeiro degrau.
          * **b**: <img src='https://s0.wp.com/latex.php?latex=a_%7Bn%7D&bg=T&fg=000000&s=0' alt='a_{n}' title='a_{n}' class='latex' />, número de blocos do último degrau.
          * **soma**: <img src='https://s0.wp.com/latex.php?latex=S_%7Bn%7D&bg=T&fg=000000&s=0' alt='S_{n}' title='S_{n}' class='latex' />, soma da PA.
          * **pilha[]**: vetor de degraus.
          * **movimentos** e **moves**: explicados no quinto passo da solução.
          * **i** e **j**: variáveis auxiliares para fazer os _loops_.

        #### Codeado em C

        ```c
#include <stdio.h>
#define PMAX 10001

int main() {
    int i, j;
    int n;
    int soma=0;
    int a, b;
    int pilha[PMAX];
    int moves=0;
    int movimentos=0;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &pilha[i]);
        soma+=pilha[i];
    }

    b=(((2*soma)/n)+(n-1))/2;
    a=1+b-n;

    for (i=0; i<n; i++) {
        moves+=(pilha[i]-(i+a));
        if (pilha[i]>i+a) {
            movimentos+=(pilha[i]-(i+a));
        }
    }

    if (moves!=0) {
        printf("-1n");
    } else {
        printf("%dn", movimentos);
    }

    return 0;
}
```

        Prontinho! Qualquer dúvida escrevam seus comentários.

 [1]: http://olimpiada.ic.unicamp.br
 [2]: https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2007/06/ilustraescada1.gif
 [3]: http://pt.wikipedia.org/wiki/Progress%C3%A3o_aritm%C3%A9tica

