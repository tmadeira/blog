---
title: Escada perfeita (OBI2006)
type: post
date: 2007-06-15T12:38:30+00:00
url: /2007/06/escada-perfeita-obi2006/
ordem:
  - eeess
categorias:
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

{{< figure src="/wp-content/uploads/2007/06/ilustraescada1.gif" title="Ilustração do problema" >}}

### Tarefa

Dada uma seqüência de pilhas de cubos de pedras com suas respectivas alturas, você deve determinar o número mínimo de pedras que precisam ser movidas para formar uma escada perfeita com exatamente o mesmo número de pilhas de pedras encontrado inicialmente (ou seja, não devem ser criadas ou eliminadas pilhas de pedras). O degrau mais baixo da escada deve sempre estar do lado esquerdo.

### Entrada

A entrada contém um único conjunto de testes, que deve ser lido do _dispositivo de entrada padrão_ (normalmente o teclado). A primeira linha contém um inteiro _n_ que indica o número de pilhas de pedras. A segunda linha contém _N_ números inteiros que indicam a quantidade de cubos de pedras em cada uma das pilhas, da esquerda para a direita.

### Saída

Seu programa deve imprimir, na _saída padrão_, uma única linha, contendo um inteiro: o número mínimo de cubos de pedras que devem ser movidos para transformar o conjunto de pilhas em uma escada perfeita, conforme calculado pelo seu programa. Caso não seja possível efetuar a transformação em escada perfeita, imprima como resultado o valor -1.

### Exemplos

#### Exemplo 1

```
Entrada
5
5 4 5 4 2

Saída
5
```

#### Exemplo 2

```
Entrada
6
9 8 7 6 5 4

Saída
9
```

#### Exemplo 3

```
Entrada
2
1 5

Saída
-1
```

* * *

OK. Estão prontos?

Depois de pensar um pouco, conclui-se que:

1. A **escada perfeita** é uma <acronym title="Progressão aritmética">PA</acronym> de razão 1 (aumenta de um em um). Você lembra disso do seu primeiro ano do Ensino Médio? Senão, é bom dar uma [relembrada][3]. As fórmulas (simples e facilmente deduzíveis) da PA são:

#### Termo geral da PA

$$a\_{n} = a\_{1} + (n-1).r$$

#### Soma de PA

$$S\_{n} = (a\_{1}+a\_{n}).\frac{n}{2}$$

2. Sabemos quanto vale **n** (o número de pilhas, número de elementos da PA) e conseguimos calcular a **soma de todos os elementos** (podemos fazer isso até durante o loop da entrada, certo?)

3. Sabemos quanto vale a razão (r=1).

4. Substituindo o que sabemos nas fórmulas conseguimos formar um sistema de equações básico e desta forma torna-se fácil descobrir o valor do primeiro e do último termo da PA (\\(a\_{1}\\) e \\(a\_{n}\\)). Resumindo um pouco os cálculos, depois de alguma manipulação algébrica você chega a:

$$a\_{n} = \frac{\frac{2.S\_{n}}{n}+n-1}{2}$$

$$a\_{1} = 1 + a\_{n} - n$$

5. Agora que já sabemos onde começa e onde termina a escada basta fazer um loop em cada fila de blocos e adicionar à uma variável _movimentos_ a quantidade de quadradinhos que estão sobrando nesta fileira (por exemplo, na primeira fileira da figura do enunciado está sobrando três quadradinhos para chegar ao \\(a\_{1}=2\\)). Ao mesmo tempo, adicionamos à outra variável (_moves_) a quantidade de quadradinhos que devem ser retirados **ou** colocados na fileira (porque depois se esta variável não for igual a 0 imprimimos -1). Ficou claro?

### Implementação

#### Variáveis

  * **n**: número de degraus (fileiras de blocos)
  * **a**: \\(a\_{1}\\), número de blocos do primeiro degrau.
  * **b**: \\(a\_{n}\\) , número de blocos do último degrau.
  * **soma**: \\(S\_{n}\\) , soma da PA.
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
        printf("-1\n");
    } else {
        printf("%d\n", movimentos);
    }

    return 0;
}
```

Prontinho! Qualquer dúvida escrevam seus comentários.

 [1]: http://olimpiada.ic.unicamp.br
 [3]: http://pt.wikipedia.org/wiki/Progress%C3%A3o_aritm%C3%A9tica

