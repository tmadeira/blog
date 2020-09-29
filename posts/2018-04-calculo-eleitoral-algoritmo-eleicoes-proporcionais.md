---
title: Novo cálculo eleitoral e algoritmos para distribuir vagas de eleições proporcionais
type: post
date: 2018-04-25T07:44:49-03:00
url: /2018/04/calculo-eleitoral-algoritmo-eleicoes-proporcionais/
categorias:
  - Pensamentos aleatórios
tags:
  - eleições
  - TSE
  - D'Hondt
  - algoritmos
  - Brasil
  - busca binária
  - quociente eleitoral
  - menor sobra
description: O quociente eleitoral está morto; vida longa à menor sobra! Um exercício matemático e computacional sobre os métodos usados para alocar vagas nas eleições proporcionais.
---

Um exercício matemático e computacional sobre os métodos usados para alocar vagas nas eleições proporcionais do Brasil. Estava refletindo sobre isso uns dias atrás e estou colocando aqui para sistematizar, compartilhar e saber o que outras pessoas acham. A epígrafe é: _O quociente eleitoral está morto; vida longa à menor sobra!_

---

O Código Eleitoral brasileiro determina a forma como são eleitos os candidatos a cargos proporcionais (deputados e vereadores) no seu [capítulo IV](http://www.planalto.gov.br/ccivil_03/Leis/L4737.htm#art105). O método consiste, em resumo, em:

1. Calcular o **quociente eleitoral** $q$, definido como a soma do total de votos válidos (isso é, sem contar abstenções, brancos e nulos) $t$ dividida pela quantidade de vagas a preencher $s$, arredondada para o número inteiro mais próximo. Isso é, $q := \left[\frac{t}{s}\right]$.
2. Para cada partido ou coligação $i$, calcular o **quociente partidário** $p_i$, definido como o número de votos obtidos pelo partido ou coligação $v_i$ dividido (divisão inteira, ou seja, desprezada a fração) pelo quociente eleitoral $q$. Isso é, $p_i := \left\lfloor \frac{v_i}{q} \right\rfloor \forall i$. Então, $p_i$ é a quantidade inicial de vagas atribuídas ao partido ou coligação $i$.
3. Dividir as $s - \sum_{i} p_i$ vagas restantes de acordo com o **Cálculo das Sobras**, também conhecido como Cálculo das Médias. Tal método é definido pela repetição do seguinte processo enquanto houver vagas restantes (copiado da lei): _"o número de votos válidos atribuídos a cada partido político ou coligação será dividido pelo número de lugares por eles obtidos mediante o cálculo do quociente partidário mais um, cabendo ao partido político ou à coligação que apresentar a maior média um dos lugares a preencher, desde que tenha candidato que atenda à exigência de votação nominal mínima"_.

Para além desse algoritmo, vale fazer duas considerações importantes sobre o método que vão reaparecer em outros momentos deste texto:

1. Até a eleição de 2016, os partidos ou coligações $i$ que não tivessem quociente partidário $p_i \geq 1$ não participavam do Cálculo das Sobras. Tal restrição foi removida na reforma eleitoral de 2017.
2. A partir da eleição de 2016, foi imposta uma cláusula de barreira (aprovada em 2015) que exige que candidatos tenham 10% do quociente partidário para poderem ser eleitos (a não ser no caso em que não há candidatos nessa condição). Esse fato vai ser desprezado nesse artigo. Ou seja, vamos assumir que todos os partidos ou coligações que tiverem uma vaga de acordo com o método têm também candidatos aptos a serem eleitos.

A implementação do método descrito acima em C++ (escolhi essa linguagem para usar a fila de prioridades da STL) seria como segue:

```cpp
// Estrutura usada para ordenar partidos de acordo com suas sobras.
struct party {
  int index, votes, seats;
  bool operator < (const party &o) const {
    return votes / (double) (seats + 1) < o.votes / (double) (o.seats + 1);
  }
};

vector <int> codigoEleitoral(vector <int> v, int s) {
  // Pré-calculo de t, o número total de votos válidos.
  int t = 0;
  for (int i = 0; i < v.size(); i++) {
    t += v[i];
  }

  // Passo 1: calcular o quociente eleitoral.
  int q = round(t / (double) s);

  // Passo 2: calcular o quociente partidário e alocar primeiras vagas.
  priority_queue <party> Q;
  for (int i = 0; i < v.size(); i++) {
    s -= (int) (v[i] / q);
    Q.push((party) {i, v[i], v[i] / q});
  }

  // Passo 3: Cálculo das Sobras ou Médias.
  while (s--) {
    party p = Q.top();
    Q.pop();
    p.seats++;
    Q.push(p);
  }

  // Reconstrução do resultado.
  vector <int> result(Q.size(), 0);
  while (!Q.empty()) {
    party p = Q.top();
    result[p.index] = p.seats;
    Q.pop();
  }

  return result;
}
```

Sua complexidade é $\Theta((n+s) \log n)$, onde $n$ é o número de partidos ou coligações. O logaritmo vem do uso da _heap_ implementada pela STL (`priority_queue`).

A partir dessas definições e desse método, gostaria de compartilhar alguns pensamentos.

### Equivalência com D'Hondt

Primeiramente, é bom observar que o Método D'Hondt é _exatamente_ o que é chamado de Cálculo das Médias no Código Eleitoral. Como descreve a [Wikipedia](https://pt.wikipedia.org/wiki/M%C3%A9todo_D%27Hondt):

> O método [D'Hondt] consiste numa fórmula matemática, ou algoritmo, destinada a calcular a distribuição dos mandatos pelas listas concorrentes, em que cada mandato é sucessivamente alocado à lista cujo número total de votos dividido pelos números inteiros sucessivos, começando na unidade (isto é no número 1) seja maior. O processo de divisão prossegue até se esgotarem todos os mandatos e todas as possibilidades de aparecerem quocientes iguais aos quais ainda caiba um mandato.

A tabela abaixo, da distribuição de 8 vagas para 4 partidos, ajuda a visualizá-lo:

|           |     ÷ 1     |    ÷ 2     |    ÷ 3     |    ÷ 4     |  ÷ 5   |  ÷ 6   |  ÷ 7   |  ÷ 8   | Vagas |
| --------- | :---------: | :--------: | :--------: | :--------: | :----: | :----: | :----: | :----: | :---: |
| Partido A | **100.000** | **50.000** | **33.333** | **25.000** | 20.000 | 16.666 | 14.286 | 12.500 |   4   |
| Partido B | **80.000**  | **40.000** | **26.666** |   20.000   | 16.000 | 13.333 | 11.428 | 10.000 |   3   |
| Partido C | **30.000**  |   15.000   |   10.000   |   7.500    | 6.000  | 5.000  | 4.286  | 3.750  |   1   |
| Partido D |   20.000    |   10.000   |   6.666    |   5.000    | 4.000  | 3.333  | 2.857  | 2.500  |   0   |

Mais interessante do que perceber que o Cálculo das Médias do Código Eleitoral é o Método D'Hondt, porém, é observar que o método completo brasileiro (não apenas o cálculo das médias) é equivalente matematicamente ao Método D'Hondt, isso é, os dois métodos distribuem as vagas da mesma forma.

Creio que a forma mais fácil de provar isso consista em demonstrar que um partido ou coligação tem uma vaga pelo Código Eleitoral se e somente se tem tal vaga pelo Método D'Hondt. Talvez mostrar que o D'Hondt e o Código Eleitoral decidem as $\sum_i p_i$ primeiras vagas da mesma forma? Será que não bastaria provar que o quociente eleitoral é maior ou igual ao menor número negrito na tabela do D'Hondt (conceito que chamaremos de _menor sobra_ e definiremos melhor até o final desse artigo)? Intuitivamente isso parece não ser muito difícil, mas na prática não fiz e vou considerar que essa prova maravilhosa não cabe nas margens desse artigo.

O importante é que, aceitando esse fato, nota-se que o Código Eleitoral poderia ser simplificado deixando de lado o cálculo do quociente eleitoral e do quociente partidário, aplicando apenas o Cálculo das Sobras/Médias (ou Método D'Hondt) desde o princípio. Sua implementação poderia ser, assim, reduzida para:

```cpp
vector <int> dhondt(vector <int> v, int s) {
  priority_queue <party> Q;
  for (int i = 0; i < v.size(); i++) {
    Q.push((party) {i, v[i], 0});
  }

  // Cálculo das Sobras ou Médias (D'Hondt).
  while (s--) {
    party p = Q.top();
    Q.pop();
    p.seats++;
    Q.push(p);
  }

  // Reconstrução do resultado.
  vector <int> result(Q.size(), 0);
  while (!Q.empty()) {
    party p = Q.top();
    result[p.index] = p.seats;
    Q.pop();
  }

  return result;
}
```

A complexidade computacional claramente seria a mesma, mas reduzir o esforço mental para entender o cálculo e também o código --- evitando calcular os arredondamentos de quociente eleitoral e quociente partidário --- parece bom.

A verdade é que isso nos motiva a perceber que a única utilidade do quociente eleitoral $q$ tem a ver com as duas considerações que fiz acima e informei que iriam aparecer em outros momentos do texto. De fato, em 2018, a única utilidade do quociente eleitoral será barrar candidatos que não tenham 10% desse quociente.

Já o quociente partidário $p_i$ teria importância se ainda houvesse a necessidade dos partidos ou coligações $i$ terem $p_i \geq 1$ para participar do Cálculo das Médias. Sem tal mecanismo, já não serve para nada.

### A menor sobra é o xis da questão

O quociente eleitoral tinha importância porque era nele que se devia mirar para eleger o primeiro candidato de um partido ou coligação. Com a mudança no Código Eleitoral, o número fundamental da eleição deixa de ser o quociente eleitoral e passa a ser a **menor sobra** $x$, que defino como o menor número na tabela do Método D'Hondt que garante vaga.

Matematicamente, $x := \min_i \frac{v_i}{r_i}$, onde $v_i$ é a quantidade de votos do partido ou coligação $i$ e $r_i$ é o número de vagas alocadas ao partido ou coligação $i$ no final do processo.

A menor sobra não é importante apenas para que se saiba quantos votos são necessários para eleger o primeiro candidato de um partido ou coligação (como antes era o quociente eleitoral), mas para saber quantos candidatos cada partido ou coligação vai eleger. Com efeito, é fácil ver que o número de candidatos a serem eleitos por um partido ou coligação é $\left\lfloor\frac{v_i}{x}\right\rfloor$. Isso a torna especialmente interessante, muito mais útil do que o velho quociente.

Refletir sobre a importância da menor sobra sugere um algoritmo que evita a implementação do D'Hondt e da fila de prioridades: uma simples busca binária para encontrar $x$, dado que quanto menor [maior] é $x$ mais [menos] candidatos são eleitos.

```cpp
vector <int> menorSobra(vector <int> v, int s) {
  int a = 0, b = 0;

  // Encontrando o limite superior para a busca binária.
  for (int i = 0; i < v.size(); i++) {
    b = max(b, v[i] + 1);
  }

  // Busca binária para encontrar x.
  while ((b - a) > 1) {
    int x = (a + b) / 2, y = 0;
    for (int i = 0; i < v.size(); i++) {
      y += v[i] / x;
    }
    if (y < s) {
      b = x;
    } else {
      a = x;
    }
  }

  // Construção do resultado dividindo votos de cada partido por x.
  vector <int> result(v.size(), 0);
  int x = (a + b) / 2;
  for (int i = 0; i < v.size(); i++) {
    result[i] = v[i] / x;
  }

  return result;
}
```

Esse algoritmo tem complexidade $\Theta(n \log t)$, que me parece razoável.

Por tudo isso, exceto se a sua preocupação for com a cláusula de barreira de 2015 --- isso é, com fazer seu candidato atingir 10% do quociente eleitoral ---, pareceria que vale esquecer o quociente eleitoral e o algoritmo do TSE, dando centralidade à menor sobra.

Do ponto de vista prático, como, porém, estimar a menor sobra antes de ter os dados de uma eleição (que ainda não tenha acontecido, por exemplo)?

Bem, sabemos que ela é limitada superiormente pelo quociente eleitoral ($x \leq q$), que é fácil de estimar já que se conhece o tamanho do colégio eleitoral, o número de vagas a serem preenchidas e dá pra chutar uma proporção de votos válidos. Ao menos, é bem mais fácil do que estimar a configuração completa do resultado de uma eleição. Então, só por isso, talvez valha, ainda, não descartar o quociente eleitoral.
