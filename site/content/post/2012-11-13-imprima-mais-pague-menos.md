---
title: Imprima mais, pague menos
type: post
date: 2012-11-13T17:27:44+00:00
url: /2012/11/imprima-mais-pague-menos/
categories:
  - Matemática
tags:
  - cópias
  - funções
  - gráficas
  - gráficos
  - impressões
  - Matemática
  - vida real

---
Tabelas de preços de impressão são interessantes. É muito comum que quanto mais você imprima mais baratas as impressões fiquem, fazendo com que o gráfico de preço por impressões não seja monótono (isso é, você não necessariamente pague mais por um número maior de impressões).

Isso torna as gráficas boas candidatas de lugares para pensar em gráficos de funções de primeiro grau, assim como a [busca binária é uma boa candidata de aplicação para pensar sobre logaritmos][1].

Hoje fui imprimir uma partitura e me deparei com a seguinte tabela:

<table>
  <tr>
    <td>
      De 01 a 03 unidades
    </td>

    <td>
      R$ 0,70 cada
    </td>
  </tr>

  <tr>
    <td>
      De 04 a 10 unidades
    </td>

    <td>
      R$ 0,50 cada
    </td>
  </tr>

  <tr>
    <td>
      De 11 a 20 unidades
    </td>

    <td>
      R$ 0,40 cada
    </td>
  </tr>

  <tr>
    <td>
      De 21 a 50 unidades
    </td>

    <td>
      R$ 0,30 cada
    </td>
  </tr>

  <tr>
    <td>
      De 51 a 100 unidades
    </td>

    <td>
      R$ 0,25 cada
    </td>
  </tr>

  <tr>
    <td>
      Acima de 100 unidades
    </td>

    <td>
      R$ 0,20 cada
    </td>
  </tr>
</table>

<p style="text-align:center;">
  <small>(registrada em uma <a href="http://instagram.com/p/R-Zo0Si6sY/">foto de um bilhão de dólares</a>)</small>
</p>

Se desenharmos um gráfico de preço (eixo y — vertical) por número de impressões (eixo x — horizontal), temos:

{{< figure src="/wp-content/uploads/2012/11/grafico.png" title="Preço (eixo y) por número de impressões (eixo x)" >}}

Observando esse gráfico (feio), percebemos que há alguns números de impressões que economicamente não faz sentido fazer. Por exemplo, 3 impressões custam R$ 2,10 enquanto 4 impressões custam R$ 2,00. 20 impressões custam R$ 8,00 enquanto 21 impressões custam R$ 6,30. 100 impressões custam R$ 25,00 enquanto 101 impressões custam R$ 20,20.

Mas não só esses. Os valores que não faz sentido imprimir no gráfico são todos aqueles cujo existe algum ponto a direita na mesma altura ou mais baixo, ou seja, todos os que pintei de amarelo:

{{< figure src="/wp-content/uploads/2012/11/grafico2.png" title="O mesmo gráfico com pontos inúteis destacados" >}}

Um problema econômico interessante para quando se está numa gráfica imprimindo é, portanto, descobrir quando estamos nos pontos amarelos. É interessante porque, se estivermos nos pontos amarelos, podemos aproveitar para imprimir mais cópias ou pedir ao dono da gráfica um desconto. Afinal, é razoável esperar que o preço que a gente pague seja limitado por este gráfico:

{{< figure src="/wp-content/uploads/2012/11/grafico3.png" title="Gráfico corrigido" >}}

Descobrir se estamos numa região amarela é simples. Basta calcular o preço que pagaríamos a princípio (multiplicar o número de cópias pelo preço por cópias da região em que estamos) e comparar com o preço que pagaríamos se pedíssemos o menor número de cópias da região imediatamente mais barata. Por exemplo, faz sentido imprimir 15 cópias porque \\(15 \times 0.40=6.00\\) é menor do que \\(21 \times 0.30 = 6.30\\), mas não faz sentido imprimir 85 cópias porque \\(85 \times 0.25 = 21.25\\) é maior do que \\(101 \times 0.20 = 20.20\\).

* * *

Agora vamos inverter o problema. Vamos supôr que você é a gráfica e quer evitar esse tipo de cliente insuportável, fazendo o preço ir ficando mais barato proporcionalmente com o número de impressões, mas mantendo a função monótona (crescendo).

Poderíamos pensar em funções que crescem cada vez mais devagar…

{{< figure src="/wp-content/uploads/2012/11/grafico5.png" title="Função logarítmica (y = log x)" >}}

… mas parece complicado achar uma função que não nos dê prejuízo quando o cliente quiser muitas cópias e parece especialmente complicado explicar para o cliente que o preço de _x_ cópias é um monte de constantes multiplicadas pelo logaritmo de _x_.

Então talvez seja melhor pensar em funções de primeiro grau mesmo.

Se você separar todas as funções que encontramos na tabela de preços do problema anterior e colocá-las num gráfico, você vai ver que a interseção delas só acontece num ponto: o ponto _x_ = 0.

{{< figure src="/wp-content/uploads/2012/11/grafico4.png" title="Várias funções lineares com uma única interseção no ponto x = 0" >}}

(esse gráfico foi um oferecimento <a href="https://www.wolframalpha.com/input/?i=plot+{0.7x%2C+0.5x%2C+0.4x%2C+0.3x%2C+0.25x%2C+0.2x}">Wolfram Alpha</a>)

Uma forma de resolver o problema é fazer com que as interseções sejam nos pontos onde o preço das impressões muda. Isso se faz movendo cada uma das funções um pouquinho pra cima, isso é, adicionando constantes às funções de primeiro grau.

Por exemplo: 3 cópias custam R$ 2,10. Se a partir de 4 cópias quisermos que as cópias custem R$ 0,50 em vez de R$ 0,70, podemos forçar que 4 cópias custem R$ 2,10 + R$ 0,50 = R$ 2,60. R$ 2,60 é R$ 2,00 + R$ 0,60. Logo, em vez de usarmos a função de preço \\(f(x) = 0.5x\\) para _x_ entre 4 e 10, podemos usar a função \\(f(x) = 0.5x + 0.6\\).

Se repetirmos o mesmo raciocínio para as outras interseções, a tabela de preços final fica assim:

<table>
  <tr>
    <td>
      De 01 a 03 unidades
    </td>

    <td>
      R$ 0,70 cada
    </td>
  </tr>

  <tr>
    <td>
      De 04 a 10 unidades
    </td>

    <td>
      R$ 0,60 fixo + R$ 0,50 cada
    </td>
  </tr>

  <tr>
    <td>
      De 11 a 20 unidades
    </td>

    <td>
      R$ 1,60 fixo + R$ 0,40 cada
    </td>
  </tr>

  <tr>
    <td>
      De 21 a 50 unidades
    </td>

    <td>
      R$ 3,60 fixo + R$ 0,30 cada
    </td>
  </tr>

  <tr>
    <td>
      De 51 a 100 unidades
    </td>

    <td>
      R$ 6,10 fixo + R$ 0,25 cada
    </td>
  </tr>

  <tr>
    <td>
      Acima de 100 unidades
    </td>

    <td>
      R$ 11,10 fixo + R$ 0,20 cada
    </td>
  </tr>
</table>

<p style="text-align:center;">
  <small><strong>(Isso aqui é só um exercício. Por favor, não façam isso, donos de gráficas!)</strong></small>
</p>

Agora note que as coisas passam a fazer mais sentido (embora muito mais caras):

- 3 cópias custam R$ 2,10 e 4 cópias custam R$ 2,60;
- 10 cópias custam R$ 5,60 e 11 cópias custam R$ 6,00;
- 20 cópias custam R$ 9,60 e 21 cópias custam R$ 9,90;
- 50 cópias custam R$ 18,60 e 51 cópias custam R$ 18,85;
- 100 cópias custam R$ 31,10 e 101 cópias custam R$ 31,30.

O gráfico monótono (e bonito) comprova:

{{< figure src="/wp-content/uploads/2012/11/grafico6.png" title="Gráfico final (monótono)" >}}

 [1]: http://tiagomadeira.com/2012/10/o-predio-e-as-bolas/
