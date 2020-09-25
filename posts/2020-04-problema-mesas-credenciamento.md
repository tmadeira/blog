---
title: "Problema das mesas de credenciamento"
type: post
date: 2020-04-05T17:48:02-03:00
url: /2020/04/problema-mesas-credenciamento/
categorias:
  - Cotidiano
tags:
  - matemática
  - algoritmos
  - mesas de credenciamento
  - desvio padrão
  - algoritmos gulosos
  - programação dinâmica
description: "A partir de um problema do mundo real, discutimos duas técnicas para resolver problemas de otimização: algoritmos gulosos e programação dinâmica."

---

Eventos com inscrição prévia, do Fórum Internacional do Software Livre às plenárias do Congresso do PSOL nas grandes cidades, costumam ter mesas de credenciamento pelas quais os presentes precisam passar para pegar um crachá.

Quando há muitos participantes é comum que as letras do alfabeto sejam separadas entre essas mesas, de forma a dividir as pessoas pelas iniciais dos seus nomes e assim reduzir o tempo de espera nas filas que se formam.

> **Exemplo:** Se há três mesas de credenciamento, pode-se atribuir a elas os intervalos letras A-I, J-R e S-Z. Nesse caso, alguém com um nome que comece com B (como Bruno) deve se credenciar na mesa A-I, enquanto alguém com um nome que comece com T (como Tiago) deve se credenciar na mesa S-Z.

Uma dificuldade conhecida por todos que já organizaram eventos desse tipo é que alguns particionamentos do alfabeto podem levar a formar umas filas grandes e outras pequenas. Em particular, deixar o mesmo número de letras em cada conjunto costuma ser uma estratégia muito ineficiente, porque em português muitos nomes começam com as letras A, J e M, mas poucos começam com as letras Q, U e X.

O problema que surge a partir dessa constatação é: **Como dividir as letras do alfabeto de forma a garantir que o número de participantes por mesa esteja o mais equilibrado possível?**

Há uma restrição: As letras precisam ser divididas de forma que formem partições contíguas na ordem alfabética. Isso é, não se pode definir que A e C ficam num conjunto 1, enquanto B fica num conjunto 2. Se A e C estão no conjunto 1, todas as letras entre A e C (B, no caso) também precisam estar no conjunto 1.

Trata-se claramente de um problema de otimização. Para desenvolver um [algoritmo](https://tiagomadeira.com/2006/01/algoritmos-o-que-e-um-algoritmo/) (que nada mais é do que um procedimento computacional) para resolvê-lo, convém definir o que esperamos como entrada e o que esperamos como saída.

**Entrada:**

- $n$: número de letras no alfabeto
- $a_i$: número de participantes que começam com a $i$-ésima letra do alfabeto ($1 \leq i \leq n$).
- $k$: número de mesas de credenciamento (partições que devem ser formadas)

**Saída:**

- $c_i$: primeira letra da $i$-ésima partição do alfabeto ($1 \leq c_i \leq n$, $1 \leq i \leq k$)

> **Um parênteses**: Enquanto este texto era escrito, o governo do Distrito Federal começou uma campanha de vacinação contra a influenza dividindo idosos em 5 grupos a partir das suas iniciais. De acordo com a [Agência Brasil](https://agenciabrasil.ebc.com.br/saude/noticia/2020-03/campanha-de-vacinacao-contra-gripe-no-df-comeca-na-segunda-feira),
>
> - Na segunda-feira (23), devem ser vacinados os idosos cujo nome comece com as letras A, B, C, D e E.
> - Na terça-feira (24), pessoas com 60 anos ou mais com nomes iniciados pelas letras F, G, H, I e J.
> - Na quarta-feira (25), idosos que tenham nas letras iniciais do nome K, L, M, N e O.
> - Na quinta-feira (26), pessoas com 60 ou mais com o primeiro nome iniciado em P, Q, R, S e T.
> - Na sexta-feira (27), devem se vacinar os idosos com nomes que comecem com U, V, W, X, Y e Z.
>
> É fácil ver que esse governo teve que resolver o problema proposto aqui para separar as pessoas em 5 dias (que seriam equivalentes a mesas de credenciamento, na nossa formulação). Terá ele feito uma escolha ótima? Infelizmente acho difícil que os idosos que tenham nomes começando com letras entre A e E não tenham que esperar muito mais tempo na fila do que os idosos que tenham nomes começando com letras entre U e Z.

### Como definir equilíbrio?

Idealmente gostaríamos de dividir os conjuntos de nomes igualmente. Se $t = \sum a_i$ é o número total de participantes do evento (a soma dos números de participantes com cada letra do alfabeto) e $k$ é o número de mesas de credenciamento, então o número de participantes que gostaríamos de colocar em cada mesa é $\frac{t}{k}$.

Há diferentes formas de medir o quão longe um valor se encontra do seu valor esperado. Uma das medidas mais populares, que decidi usar aqui, é o [desvio padrão](https://pt.wikipedia.org/wiki/Desvio_padr%C3%A3o).

Se $x_i$ é o número de participantes que devem se credenciar na $i$-ésima mesa (para $i$ variando de 1 a $k$), então o desvio padrão dessa solução é:

$$\sigma := \sqrt{\frac{1}{k} \sum_{i=1}^k \left(x_i - \frac{t}{k}\right)^2}.$$

> **Exemplo:** Suponha que temos 42 nomes que começam com A, 25 nomes que começam com B e 33 nomes que começam com C. Então temos $a_1 = 42$, $a_2 = 25$, $a_3 = 33$ e $t = a_1 + a_2 + a_3 = 42 + 25 + 33 = 100$. Suponha que precisamos dividir esses nomes em duas mesas de credenciamento, portanto $k = 2$. Podemos dividir as pessoas de duas formas diferentes:
>
> 1. A e B-C.
> 2. A-B e C.
>
> Na primeira solução, temos uma mesa com 42 pessoas e outra mesa com 58 (25+33). Na segunda solução, termos uma mesa com 67 pessoas (42+25) e outra mesa com 33. Note que $\frac{t}{k} = \frac{100}{2} = 50$.
>
> Então o desvio padrão da primeira solução é
>
> $$\sigma_1 = \sqrt{\frac{1}{2} ((42-50)^2 + (58-50)^2)} = 8$$
>
> e o desvio padrão da segunda solução é
>
> $$\sigma_2 = \sqrt{\frac{1}{2} ((67-50)^2 + (33-50)^2)}  = 17.$$
>
> Como $\sigma_1 < \sigma_2$, dizemos que a primeira solução é _mais equilibrada_ do que a segunda. Nosso objetivo, portanto, é encontrar uma solução que minimize o desvio padrão.

(Note que o desvio padrão nunca é negativo e a solução ideal para o nosso problema, que divide os participantes perfeitamente, tem desvio padrão 0.)

**Se você quiser tentar resolver o problema antes de ler sobre a solução, pare de ler aqui. Caso contrário, pode continuar a leitura.**

### Abordagem gulosa

Uma solução que que alguém poderia sugerir é inicialmente dividir a lista de nomes em $k$ partes e aí tentar, para cada um dos cortes, decidir se é melhor deslocá-lo para frente ou para trás. Talvez uma forma razoável de tomar essa decisão seja ver qual delas minimiza o desvio padrão para o conjunto que estamos deixando para trás.

> **Exemplo:** Suponha que $a_1 = 42, a_2 = 25, a_3 = 27, a_4 = 18, a_5 = 38$ e $k = 3$. Então $\frac{t}{k} = \frac{150}{3} = 50$.
>
> {{< figure src="/wp-content/uploads/2020/03/mesas-a.png" title="Ilustração do exemplo descrito acima. Nomes com A, B, C, D e E são representados, respectivamente, pelas cores azul, vermelho, verde, laranja e azul claro." >}}
>
> A solução proposta inicialmente divide esses nomes em 3 partes iguais. Os cortes das divisões estariam (1) entre o oitavo e o nono nome da letra B e (2) entre o sexto e o sétimo nome da letra D.
>
> {{< figure src="/wp-content/uploads/2020/03/mesas-b.png" title="Ilustração das divisões entre os nomes. Note que o primeiro corte está entre o oitavo e o nono nome da letra B e o segundo corte está entre o sexto e o sétimo nome da letra D." >}}
>
> Para diminuir o desvio padrão do primeiro conjunto é melhor mover o primeiro corte para entre as letras A e B, porque 42 é mais próximo de 50 (diferença 8) do que 67 (diferença 17). Já para diminuir o desvio padrão do segundo conjunto é melhor mover o segundo corte para entre as letras C e D, porque 52 é mais próximo de 50 (diferença 2) do que 70 (diferença 20).
>
> A solução encontrada portanto separa as letras em A, B-C e D-E.
>
> {{< figure src="/wp-content/uploads/2020/03/mesas-c.png" title="Ilustração da solução encontrada." >}}

Esse tipo de solução é chamado, na Ciência da Computação, de "guloso" (_greedy_, em inglês). As técnicas gulosas são aquelas que procuram soluções locais ótimas na esperança de encontrarem uma solução global ótima. Note que na solução sugerida otimizamos corte por corte (localmente), sem pensar muito sobre o que nos espera no futuro (global).

Algoritmos gulosos, quando encontram a solução ótima, são uma beleza: normalmente são fáceis de escrever e super rápidos. Porém, nem sempre algoritmos gulosos que funcionam para alguns casos funcionam para todos. Para não nos enganarmos, é sempre bom provar a corretude de um algoritmo guloso, isso é, provar matematicamente que ele funciona para todas as entradas. Já para provar que um algoritmo guloso **não** funciona basta apresentar um contra-exemplo, isso é, uma entrada para o qual o algoritmo guloso não produz a saída esperada.

> **Uma tentativa de explicar melhor, em termos lógicos, o parágrafo acima:** Suponha que representemos nosso algoritmo como uma função $f$. Uma entrada é representada por $x$ e a saída esperada para $x$ é representada por $y$. Então, se o algoritmo funciona, esperamos que $\forall x (f(x) = y)$ (isso é, para todo $x$, o algoritmo leve $x$ em $y$). A negação dessa proposição lógica é $\exists x (f(x) \neq y)$ (isso é, existe $x$ tal que o algoritmo não leva $x$ em $y$). É por isso que para provar que um algoritmo não funciona para todas as entradas basta apresentar um contra-exemplo.

Afirmo que o algoritmo guloso apresentado acima não é capaz de encontrar a solução ótima para todas as entradas. Você é capaz de construir um contra-exemplo para provar isso?

**Se quiser tentar construir um contra-exemplo por sua conta, pare de ler aqui. Caso contrário, pode continuar a leitura para ver o meu contra-exemplo.**

> **Contra-exemplo:** Suponha que temos 120 nomes, sendo que 35 começam com A, 8 com B, 27 com C e 50 com D. Queremos dividí-los em três mesas de credenciamento. Então temos $a_1 = 35, a_2 = 8, a_3 = 27, a_4 = 50$ e $k = 3$.
>
> A abordagem gulosa inicialmente divide esses nomes em três partes iguais, conforme ilustração a seguir.
>
> {{< figure src="/wp-content/uploads/2020/03/mesas-d.png" title="Ilustração da divisão inicial entre os nomes." >}}
>
> Então, corte por corte, vamos tentar minimizar o desvio padrão do conjunto de nomes que estamos deixando para trás. Para minimizar o desvio padrão do primeiro conjunto é melhor mover o primeiro corte para entre as letras B e C, porque 43 (35+8) é mais próximo de 40 do que 35. Já para minimizar o desvio padrão do segundo conjunto é melhor mover o segundo corte para entre as letras C e D. A solução encontrada pelo algoritmo guloso é portanto separar as letras nos conjuntos A-B, C e D.
>
> {{< figure src="/wp-content/uploads/2020/03/mesas-e.png" title="Ilustração da solução encontrada pelo algoritmo guloso." >}}
>
> O desvio padrão dessa solução é:
>
> $$\sigma_g = \sqrt{\frac{1}{3} (3^2 + 13^2 + 10^2)} \approx 16.67.$$
>
> Essa solução não é ótima para essa entrada, porque se tivéssemos colocado o primeiro corte entre A e B conseguiríamos um desvio padrão menor:
>
> $$\sigma_\star = \sqrt{\frac{1}{3} (5^2 + 5^2 + 10^2)} \approx 12.25.$$
>
> {{< figure src="/wp-content/uploads/2020/03/mesas-f.png" title="Ilustração da solução ótima, que não foi encontrada pelo algoritmo guloso." >}}
>
> Logo, o algoritmo guloso não funciona para todas as entradas.

O contra-exemplo mostra como ótimos locais não implicam num ótimo global. A gulodice aqui não funcionou, por isso talvez seja melhor construir um algoritmo usando outras técnicas.

### Força bruta

Como o computador é uma máquina capaz de executar bilhões de instruções por segundo (é exatamente isso que é medido pelos _Hz_ que usamos para medir os processadores), uma forma de resolver problemas de otimização sem pensar muito é enumerar todas as soluções possíveis e compará-las. Essa abordagem é chamada, na Ciência da Computação, de força bruta (não confundir com bater nas pessoas para elas não reclamarem da fila de credenciamento).

Uma forma intuitiva de resolver este problema testando todas as soluções é construir um [algoritmo recursivo](https://tiagomadeira.com/2006/01/algoritmos-recursivos/) que, a cada passo, faça um novo corte dividindo as letras que restam. Isso é, no primeiro passo tentamos colocar um corte entre todo par adjacente de letras, nos restantes tentamos colocar um corte entre todo par adjacente de letras a direita dos cortes já feitos.

Construiremos uma função recursiva $f$ que recebe dois parâmetros: $s$ é o índice da primeira letra do que resta no alfabeto e $m$ é o número restante de mesas que devem ser formadas. $f(s, m)$ vai retornar uma variância não normalizada (que para todos os efeitos é igual ao desvio padrão, porque minimiza ele) da solução ótima considerando as letras a partir de $s$ e dividindo-as em $m$ mesas de credenciamento.

> **Uma nota sobre desvio padrão e variância:** A variância é o desvio padrão ao quadrado (isso é, sem tirar a raiz quadrada), ou seja, $\frac{1}{k} \sum_{i=1}^k \left(x_i - \frac{t}{k}\right)^2$. Como minimizar um número é a mesma coisa que minimizar ele ao quadrado, usamos a variância para não precisarmos nos preocupar em ficar tirando raízes no código. Esse valor $\frac{1}{k}$ é constante. Então o que chamei de variância não normalizada aí em cima é simplesmente $\sum_{i=1}^k \left(x_i - \frac{t}{k}\right)^2$. Minimizar esse valor é a mesma coisa que minimizar o desvio padrão. Nos parágrafos seguintes, chamarei simplesmente de variância o que aqui defini como variância não normalizada.

Vamos considerar que o vetor $a$ de números de nomes por letra é global, assim como o tamanho do alfabeto $n$ e o valor $\mu$ (`mu`, no código) que é a média $\frac{t}{k}$ que usaremos para computar a variância da solução. Estamos interessados na solução de $f(0, k)$, que é a solução do nosso problema porque é a variância da solução ótima considerando todas as letras e dividindo em $k$ mesas de credenciamento.

Essa recursão tem alguns casos-base para os quais podemos retornar imediatamente valores computados diretamente, a saber:

- $f(n, 0) = 0$ --- isso é, se não há letras para serem divididas em conjuntos e não há cortes a serem feitos, então a variância da solução é 0 (não há nada a ser feito).
- $f(s, 0) = \infty$ para qualquer $s \neq 0$ --- isso é, se há letras para serem divididas em conjuntos, mas não há mesas para colocá-las, então a variância da solução é infinita (o problema não tem solução).
- $f(n, m) = m \mu^2$ para qualquer $m \neq k$ --- isso é, se não há letras para serem divididas e há $m$ mesas, então a variância da solução é $m\mu^2$ porque estamos somando $m$ mesas vazias (com 0 pessoas).

Para os demais $s, m$, temos:

$$f(s, m) = \min_{i=s}^{n-1}\left(\left(\mu - \sum_{j=s}^{i} a_j\right)^2 + f(i+1, m-1)\right).$$

Ou seja, fazemos todos os cortes possíveis (eles são representados por $i$) e minimizamos a variância correspondente a fazê-los: estamos somando a variância do conjunto $[s, i]$ (primeiro parâmetro da soma) com a variância da solução ótima para o conjunto $[i+1, n)$ com $m-1$ mesas (segundo parâmetro da soma).

Então o código da solução usando força bruta, em Python (linguagem escolhida porque está na moda), ficaria como segue:

```python
a = [...]  # parâmetro de entrada (vetor com número de nomes por letra)
k = ...    # parâmetro de entrada (número de mesas)

n = len(a)       # tamanho do alfabeto
mu = sum(a) / k  # média usada para calcular as variâncias (t/k)

inf = float('inf')  # infinito

def f(s, m):
    if s == n and m == 0:
        return 0
    if m == 0:
        return inf
    if s == n:
        return m * mu * mu

    menor = inf
    soma = 0
    for i in range(s, n):
        soma += a[i]
        variancia = (mu - soma) ** 2
        resto = f(i+1, m-1)
        if variancia + resto < menor:
            menor = variancia + resto

    return menor

print("A variância da solução ótima é:", f(0, k))
```

Essa solução funciona (provar isso é um exercício de indução matemática: prova-se a solução dos casos-base e depois que subsoluções ótimas garantem soluções ótimas). Note que ela tem uma semelhança com o algoritmo guloso na medida em que a cada passo nos preocupamos com uma mesa (corte), porém ela testa todas as possibilidades possíveis de corte em vez de escolher gulosamente onde fazer cada corte.

O problema da força bruta é seu [tempo de execução](https://tiagomadeira.com/2006/01/analise-de-algoritmos/). Por mais rápido que sejam nossos computadores, custos exponenciais não são razoáveis para resolver problemas com entradas suficientemente grandes.

> **Uma observação sobre o universo:** Segundo o consenso científico, o número de átomos no universo observável é por volta de $10^{80}$. Já a idade do universo é cerca de 14 bilhões de anos ($1.4 \times 10^{10}$), o que equivale a cerca de $4.4 \times 10^{26}$ nanossegundos. Suponha que todos os átomos do universo estejam, desde o surgimento do universo, realizando uma instrução computacional por nanossegundo, ou seja, cada átomo do universo seja um computador operando a 1GHz. Então até agora eles teriam realizado cerca de $4.4 \times 10^{106}$ operações. Se o tempo de execução de um algoritmo é exponencial no tamanho da entrada, o universo todo não é capaz de executá-lo para entradas suficientemente grandes --- e "grande" nessa colocação são números que consideraríamos razoáveis, como 50 ou 100.

Testar todas as possibilidades costuma levar um tempo exponencial no tamanho da entrada, e no nosso problema não é diferente.

> **Um esboço relaxado para computar o tempo de execução da força bruta:** Para medir o custo de um algoritmo recursivo, temos que construir e resolver uma recorrência. No nosso caso, temos:
>
> $$T(n, k) = \sum_{i=1}^n T(n-i, k-1),$$
>
> onde $T(n, k)$ denota o número de operações necessárias para resolver o problema com entrada $n, k$. Com alguma manipulação algébrica, podemos ver que, para $n > 1$, vale:
>
> $$T(n, k) = T(n-1, k) + T(n-1, k-1),$$
>
> que é exatamente a propriedade dos coeficientes binomiais conforme conferimos no [Triângulo de Pascal](https://tiagomadeira.com/2011/05/triangulo-de-pascal-mod-m/). Os casos-base são um pouco diferentes dos coeficientes binomiais, por isso não se trata exatamente de dizer que o número de operações da solução seja ${n \choose k}$, mas dá para dizer que se aproxima disso por alguma constante. Portanto, o custo é exponencial no tamanho da entrada, na ordem de $2^n$.

Talvez seja razoável afirmar que a solução com força bruta é suficiente para o escopo do nosso problema quando estamos limitados ao alfabeto latino, que tem 26 letras. Porém, o que fazer caso o alfabeto seja maior --- tenha, digamos, 1000 letras? Um algoritmo exponencial não é capaz de terminar na idade do universo neste caso nem com todos os átomos do universo trabalhando para isso. Isso nos motiva a usar programação dinâmica.

### Programação dinâmica

Programação dinâmica, diferente do que o nome indica, não tem nada a ver (ao menos diretamente) com programação de computadores. Na verdade, há quem diga que um nome mais adequado para esse método de otimização de programas seria "recursão com uma tabela".

Muitas vezes um subproblema é resolvido diversas vezes dentro de um procedimento recursivo; em particular, é fácil ver que isso acontece na força bruta proposta na seção acima. Note que $f(1, 3$) precisa do resultado de $f(2, 2), f(3, 2), f(4, 2), \cdots$ e também que $f(2, 3)$ precisa do resultado de $f(3, 2), f(4, 2), \cdots$. A tabela abaixo, mostrando a árvore de recursão para resolver o problema para $n = 6$ e $k = 4$, mostra que várias computações estão sendo repetidas.

{{< figure src="/wp-content/uploads/2020/03/tree.png" title="Árvore de computações da força bruta. Os nós em vermelho denotam computações repetidas. Nota-se que grande parte das computações está sendo feita várias vezes." >}}

A ideia da programação dinâmica é simplesmente tabelar os resultados da recursão para não precisar recalculá-los várias vezes. Usando programação dinâmica, tudo que está em vermelho na ilustração acima pode ser diretamente retornado pela função --- não é preciso recomputar $f(s, m)$ mais de uma vez para nenhum par $s, m$.

A forma mais direta de implementar programação dinâmica em cima de um algoritmo recursivo é simplesmente guardar cada resultado da recursão numa tabela e usar os resultados já guardados previamente. Modificando o código da força bruta, temos:

```python
# A linha abaixo inicializa com -1 uma matriz (n+1)x(k+1). Python é esquisito.
pd = [[-1 for i in range(k+1)] for j in range(n+1)]

def f(s, m):
    if s == n and m == 0:
        return 0
    if m == 0:
        return inf
    if s == n:
        return m * mu * mu
    if pd[s][m] != -1:
        # Já temos o resultado de f(s, m) e podemos retorná-lo diretamente.
        return pd[s][m]

    menor = inf
    soma = 0
    for i in range(s, n):
        soma += a[i]
        variancia = (mu - soma) ** 2
        resto = f(i+1, m-1)
        if variancia + resto < menor:
            menor = variancia + resto

    return pd[s][m] = menor
```

O número de operações agora é proporcional a $kn^2$, que é um valor polinomial no tamanho da entrada --- ou seja, a programação dinâmica reduziu a complexidade exponencial do nosso problema e agora podemos resolvê-lo para alfabetos muito maiores. Para alfabetos de até mil letras e para até mil mesas de credenciamento um computador comum deve ser capaz de dar uma solução para o problema de forma eficiente em cerca de 1s. Mais importante, a medida que considerarmos alfabetos maiores o tempo de execução só aumenta por um fator polinomial --- não mais exponencial.

A recursão, na solução com programação dinâmica, pode facilmente ser transformada em iterações. Para fazer isso, basta garantir que a tabela seja preenchida na ordem correta: não podemos tentar acessar alguma coisa que ainda não foi computada. O código abaixo mostra como poderia ficar uma implementação iterativa da programação dinâmica:

```python
# Casos-base.
for m in range(k+1):
    pd[n][m] = m * mu * mu
for s in range(n+1):
    pd[s][0] = inf
pd[n][0] = 0

for s in range(n-1, -1, -1):
    for m in range(1, k+1):
        menor = inf
        soma = 0
        for i in range(s, n):
            soma += a[i]
            variancia = (mu - soma) ** 2
            resto = pd[i+1][m-1]
            if variancia + resto < menor:
                menor = variancia + resto
        pd[s][m] = menor
```

Por isso a programação dinâmica é muitas vezes apresentada como uma estratégia _bottom-up_ e não _top-down_.

Programação dinâmica é uma técnica recorrente em problemas de olimpíadas de programação, como OBI, ACM ICPC, TopCoder, CodeForces, Google Code Jam e Facebook Hacker Cup, e possui muitas aplicações no mundo real. A Wikipedia tem uma [lista de algoritmos clássicos que usam programação dinâmica](https://en.wikipedia.org/wiki/Dynamic_programming#Algorithms_that_use_dynamic_programming).

### Recuperando a solução

Nas seções anteriores apresentei alguns códigos que, embora encontrem o desvio padrão da solução ótima, não nos dizem qual é a solução --- isso é, onde devem ser feitos os cortes. Há diversas formas de recuperar a solução a partir dos algoritmos mostrados. Uma que demandaria uma alteração simples nos códigos seria criar uma outra matriz $n \times k$ que guarda, para cada par $(s, m)$ o ponto em que fizemos o $m$-ésimo corte.

Para recuperar a solução, basta usar essa informação. O código completo ficaria como segue:

```python
from typing import List

def final(a: List[int], k: int):
    """Exemplo de uso: final([35, 8, 27, 50], 3)"""
    n = len(a)       # tamanho do alfabeto
    mu = sum(a) / k  # média usada para calcular as variâncias (t/k)

    inf = float('inf')  # infinito

    pd = [[-1 for i in range(k+1)] for j in range(n+1)]
    sol = [[0 for i in range(k+1)] for j in range(n+1)]

    for m in range(k+1):
        pd[n][m] = m * mu * mu
    for s in range(n+1):
        pd[s][0] = inf
    pd[n][0] = 0

    for s in range(n-1, -1, -1):
        for m in range(1, k+1):
            menor = inf
            soma = 0
            for i in range(s, n):
                soma += a[i]
                variancia = (mu - soma) ** 2
                resto = pd[i+1][m-1]
                if variancia + resto < menor:
                    menor = variancia + resto
                    sol[s][m] = i
            pd[s][m] = menor

    print("A variância da solução ótima é:", pd[0][k])

    # soma[i] vale a soma dos numeros de a[0...i-1].
    soma = [0 for i in range(n+1)]
    soma[0] = 0
    for i in range(1, n+1):
        soma[i] = soma[i-1] + a[i-1]

    print("Partições:")
    s = 0
    for l in range(k):
        e = sol[s][k-l]
        print("%d. %d-%d (tamanho: %d)" % (l+1, s, e, soma[e+1] - soma[s]))
        s = e + 1
```

A saída desse programa para `final([35, 8, 27, 50], 3)` (entrada usada como contra-exemplo para o algoritmo guloso) é, como esperado:

```
A variância da solução ótima é: 150.0
Partições:
1. 0-0 (tamanho: 35)
2. 1-2 (tamanho: 35)
3. 3-3 (tamanho: 50)
```

(No alfabeto latino, A=0, B=1, C=2, D=3, etc.)

### Finalmente

A ideia desse artigo foi mostrar como um problema real pode ser solucionado por meio de diferentes técnicas de projeto de algoritmos. Conhecer essas técnicas é útil para se abordar diversos problemas; não à toa elas são tão valorizadas em competições de programação. Espero que o artigo tenha utilidade para os que se interessarem em estudar Ciência da Computação durante esse estranho período em que muitos estamos fisicamente isolados.

Agradecimentos ao Pedro, que me apresentou o problema; ao Ulysses, que comentou que o problema apareceu na distribuição das vacinas do governo do Distrito Federal; e a todo mundo que chegou até aqui, pela leitura. Comentários são muito bem-vindos.
