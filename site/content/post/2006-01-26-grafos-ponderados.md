---
title: Grafos Ponderados
type: post
date: 2006-01-26T12:31:20+00:00
excerpt: Um grafo é ponderado quando suas arestas possuem um peso, quando há um custo para ir de um vértice a outro. Vamos ver como representar um grafo ponderado...
url: /2006/01/grafos-ponderados/
ordem:
  - eeerr
categorias:
  - Grafos
tags:
  - algoritmos
  - computação
  - grafos
  - grafos ponderados
  - pseudocódigos
  - teoria

---
Um grafo é _ponderado_ quando suas arestas possuem um **peso**. O que significa isso? Bom… Vamos supor que eu queira ir de um lugar pra outro, mas o mais importante pra mim não seja a distância entre eles mas o pedágio que vou ter que pagar para pegar cada aresta (estrada). Nesse caso, o **peso** de cada aresta seria o **custo** que eu tenho pra passar pela estrada. O problema então seria calcular o caminho onde eu pago menos (o caminho que tem a menor soma de preços) e não o menor caminho no grafo “não-ponderado” (onde consideramos aresta=1 e nada=0).

{{< figure src="/wp-content/uploads/2006/01/GRVIZ04113_001.png" title="Grafo ponderado" >}}

Neste grafo, por exemplo, o menor caminho de 0 a 3 não é a aresta 0–3, mas sim a aresta 0–2 e depois a aresta 2–3.

Para representar um grafo ponderado usando a matriz de adjacência, onde antes marcávamos “1”, marcamos o peso que temos de ir de um vértice para o outro e onde marcávamos “0” marcamos \\(\infty{}\\) (infinito).

<table>
  <tr>
    <td>
    </td>
    <td>
      <strong></strong>
    </td>
    <td>
      <strong>1</strong>
    </td>
    <td>
      <strong>2</strong>
    </td>
    <td>
      <strong>3</strong>
    </td>
    <td>
      <strong>4</strong>
    </td>
    <td>
      <strong>5</strong>
    </td>
  </tr>
  <tr>
    <td>
      <strong></strong>
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      3
    </td>
    <td>
      5
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
  </tr>
  <tr>
    <td>
      <strong>1</strong>
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      2
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
  </tr>
  <tr>
    <td>
      <strong>2</strong>
    </td>
    <td>
      3
    </td>
    <td>
      2
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      1
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
  </tr>
  <tr>
    <td>
      <strong>3</strong>
    </td>
    <td>
      5
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      1
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
  </tr>
  <tr>
    <td>
      <strong>4</strong>
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      7
    </td>
  </tr>
  <tr>
    <td>
      <strong>5</strong>
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      \(\infty\)
    </td>
    <td>
      7
    </td>
    <td>
      \(\infty\)
    </td>
  </tr>
</table>

Na verdade, só fazemos isso do infinito porque neste caso iríamos querer o **menor caminho** e o 0 poderia atrapalhar, porque poderíamos ter um caminho sem pedágio, por exemplo, mas isso sempre depende do caso.

Usando listas de adjacência, podemos representar as ligações de cada vértice com dois vetores (um para dizer a qual ele se liga e outro o peso desta ligação) ou com um vetor de <em>struct</em>s como:

```cpp
struct edge {
  int destino, peso;
};
```

