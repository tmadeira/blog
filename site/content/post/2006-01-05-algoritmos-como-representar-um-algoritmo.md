---
title: Como representar um algoritmo?
type: post
date: 2006-01-05T14:19:37+00:00
excerpt: No primeiro artigo, expliquei o que é um algoritmo e até citei exemplos do cotidiano, como "acordar" ou "falar com outra pessoa". Talvez você nem tenha se dado conta, mas usando listas numeradas eu representei os algoritmos ali presentes, inclusive destacando a entrada e a saída de cada situação-problema. Mas não é sempre assim que representamos algoritmos.
url: /2006/01/algoritmos-como-representar-um-algoritmo/
ordem:
  - eeeff
categories:
  - Básico
tags:
  - algoritmo
  - algoritmos
  - c
  - clrs
  - computação
  - definição
  - pascal
  - programação
  - pseudocódigo
  - representação

---
No [primeiro artigo desta série][1], expliquei o que é um algoritmo e até citei exemplos do cotidiano, como **acordar** ou **falar com outra pessoa**. Talvez você nem tenha se dado conta, mas usando _listas numeradas_ eu representei os algoritmos ali presentes, inclusive destacando a **entrada** e a **saída** de cada situação-problema. Porém, não é sempre assim que representamos algoritmos.

Não existe uma regra padrão para a representação de algoritmos. Cada pessoa escreve de forma diferente, mas o importante é ser legível e convencionado. Por exemplo, o livro **Algoritmos: Teoria e Prática*** traz nas páginas 14 e 15 convenções do [pseudocódigo][2] que utiliza no livro inteiro. Já eu, quando vou passar o mesmo algoritmo, utilizaria outro tipo de código, você pode utilizar outro, e por aí vai. Mas todos têm que ter o mesmo foco: legibilidade e fácil implementação para qualquer linguagem.

* A partir deste artigo, sempre que eu falar “Cormen”, “CLRS”, “Introduction to Algorithms” ou “Algoritmos: Teoria e Prática” estarei me referindo a um livro que é referência essencial nessa área. A versão que tenho (de onde tiro o número das páginas) é a tradução da segunda edição americana publicada pela Elsevier em 2002.

Os pseudocódigos costumam parecer um código em linguagem [Pascal][3] traduzido para a sua língua. :) Usam quase sempre estruturas que estamos acostumados a usar na programação, como **se**, **enquanto**, **para**, **arrays**, etc. Eles existem para que o algoritmo seja de fácil leitura para qualquer programador, que programe em qualquer linguagem _“normal”_. Veja o pseudocódigo do **Insertion Sort**, um algoritmo de ordenação de vetores bastante simples:

```
<strong>para</strong> <em>j</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> 2 <strong>até</strong> <em>comprimento do vetor</em>, <strong>faça</strong>
    <em>elemento</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>vetor[j]</em>
    <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>j</em> - 1
    <strong>enquanto</strong> <em>i</em> > 0 e <em>vetor[i]</em> > <em>elemento</em>, <strong>faça</strong>
        <em>vetor[i + 1]</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>vetor[i]</em>
        <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>i</em> - 1
    <strong>fim-enquanto</strong>
    <em>vetor[i + 1]</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>elemento</em>
<strong>fim-para</strong>
```

(Não se preocupe em entender o que ele faz, AINDA, pois veremos isso mais adiante)

Se você programa em qualquer linguagem, você não terá dificuldade em traduzir esse pseudocódigo para ela. O pseudocódigo é sempre uma maneira bem simples de escrever o código. Veja por exemplo, o mesmo código em C:

```c
for (j=2; vetor[j]!=NULL; j++) {
    elemento = vetor[j];
    for (i = j-1; i > 0 && vetor[i] > elemento; i--) {
        vetor[i+1] = vetor[i];
    }
    vetor[i+1] = elemento;
}
```

Você deve ter percebido que ao invés de usar três linhas com uma **declaração**, um **condicional** e um **incremento**, eu juntei todos num só **for**. Mas por isso o algoritmo é bem simples e sempre parte do princípio de que a sua linguagem é simples. Veja só a implementação do código em Pascal e compare-a com a do pseudocódigo:

```pascal
for j:=2 to comprimento, do begin
    elemento := vetor[j];
    i := j-1;
    while i>0 && vetor[i] > elemento, do begin
        vetor[i+1] := vetor[i];
        i := i-1;
    end;
    vetor[i] := elemento;
end;
```

Linha por linha ela é exatamente igual! A única diferença é que o pseudocódigo é traduzido… Geralmente os pseudocódigos são parecidos sempre com essa base e suas implementações não são muito diferentes. E vai ser sempre dessa maneira que eu vou representar os algoritmos (usando pseudocódigos e alguns traduzindo para C para mostrar implementações). No entanto, qualquer dúvida sobre essa representação, fique a vontade para perguntar através dos comentários.

 [1]: http://algoritmos.tiagomadeira.net/algoritmos-o-que-e-um-algoritmo
 [2]: http://pt.wikipedia.org/wiki/Pseudoc%C3%B3digo
 [3]: http://pt.wikipedia.org/wiki/Pascal_%28linguagem_de_programa%C3%A7%C3%A3o%29

