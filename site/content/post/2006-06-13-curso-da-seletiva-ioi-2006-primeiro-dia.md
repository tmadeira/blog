---
title: 'Curso da Seletiva IOI 2006: Primeiro Dia'
type: post
date: 2006-06-13T22:48:53+00:00
url: /2006/06/curso-da-seletiva-ioi-2006-primeiro-dia/
categories:
  - Cotidiano
tags:
  - algoritmos
  - campinas
  - computação
  - conjectura de goldbach
  - crivo de eratóstenes
  - ioi
  - lcs
  - mdc
  - obi
  - obi 2006
  - olimpíadas
  - problemas
  - programação dinâmica
  - unicamp

---
Estou hospedado na casa do meu irmão, em Campinas, desde ontem de manhã (viajei domingo a noite de ônibus). Hoje foi o primeiro dia do curso preparatório para a seletiva da IOI2006, que começou às 9h00 devagarinho.

O dia hoje serviu para “nivelar” os participantes e treinar um pouquinho a resolução de problemas. De manhã, algumas pessoas tiveram uma aula sobre estruturas de dados, grafos e o básico de programação dinâmica e outras (a maioria) resolveram três problemas da [Universidade de Valladollid][1]:

### 412 – Pi

[Enunciado][2] – [Minha Solução][3]

Não é um problema muito complexo, mas eu usava um algoritmo muito demorado para determinar se dois números tinham ou não um fator comum, que não passava por tempo limite excedido. Então, o [Fábio Dias Moreira][4] nos passou uma propriedade bem interessante de **MDC** (Máximo Divisor Comum):

```
mdc(x, y) = mdc(x%y, y)
```

(onde o **%** é o resto da divisão, no C)

Aí dá pra fazer uma função recursiva **mdc** bem rápida, que eu apliquei na [minha solução][3].

### 441 – Lotto

[Enunciado][5] – [Minha Solução][6]

Esse problema nem tem muito o que comentar. Implementação de dois minutos… hehehe… Eu podia ter feito uma função recursiva pra ficar um pouco mais “decente” (e poder mudar de 6 para outro número no futuro), mas não tinha necessidade, então ficou assim mesmo (e passou de primeira no site).

### 543 – Goldbach’s Conjecture

[Enunciado][7] – [Minha Solução][8]

O objetivo é provar a [Conjectura de Goldbach][9] para todos os pares menores que 1000000. Meu programa ainda não roda dentro do tempo, mas depois vou continuar a adapta-lo. Eu posso, por exemplo, ir fazendo a média entre o maior possível e o menor possível (aquele “algoritmo” que usamos quando alguém fala: “Pensei num número de 1 a 100. Tente advinhar…”) ao invés desses loops, o que já vai tornar o programa mais rápido (não sei se o suficiente).

Nesse problema, o Fábio me lembrou do [Crivo de Eratóstenes][10]. Bem interessante, nunca tinha implementado. :)

* * *

Provavelmente pela primeira vez, o almoço dos participantes do curso não foi no “bandeijão”, mas sim num restaurante _chique_ perto do IC. Achei bem legal… Além de andar menos, o ambiente é melhor e a comida também.

Durante a tarde, o Fábio nos passou o algoritmo de **Longest Common Subsequence** (esse eu já sabia… hehehe) e depois o algoritmo que resolve o problema **Subseqüências** que caiu na prova da segunda fase (esse um pouquinho mais complicado!). Esse segundo eu pretendo implementar e depois até fazer um artigo sobre…

Depois, o Fábio nos deu algumas dicas, principalmente sobre os cálculos problemáticos que o computador faz com pontos flutuantes (algo bem interessante, que eu não entendia porque acontecia). Por exemplo, quando criamos um **double x=0.1** o seu valor não é 0.1, mas sim o 1/1010 (em binário) que dá uma dízima periódica! E isso não é muito agradável, pode gerar até _loops_ infinitos… Então, ele sugeriu que criássemos uma função para comparar dois números reais, com um código como esse:

```c
/*
USO: Substituir...
x == y <==> cmp(x, y) == 0
x != y <==> cmp(x, y) != 0
x < y <==> cmp(x, y) < 0
x ### y <==> cmp(x, y) ### y

O "###" é "qualquer-coisa". Hehehe...
*/

#include <math.h>

const double EPS = 1.0e-10

int cmp(double x, double y) {
	if (fabs(x-y)<EPS) {
		return 0;
	} else if (x>y) {
		return 1;
	} else {
		return -1;
	}
}
```

Foi um bom ponto de partida legal, começamos de leve. Ainda não sei sobre o quê será a aula de amanhã…

### Seletiva IOI

Neste ano vão haver **quatro provas** para selecionar os quatro participantes que irão representar o Brasil na [Olimpíada Internacional de Informática][11] em agosto, no México. As três primeiras, identificadas como “testes” no [calendário da seletiva][12], terão apenas um problema e durarão duas horas cada uma. A última será no domingo, às 7h45min, terá três questões e durará cinco horas (pô, vou perder o comecinho do jogo de Brasil contra Austrália!). Achei legal esse método, mas como o [César Kawakami][13] disse: dessa maneira, não treinamos a estratégia, que é algo importante para a prova da IOI.

* * *

Por enquanto é só. Se der tempo, pretendo colocar um _post_ por dia sobre o curso até o final dessa semana. :)

 [1]: http://acm.uva.es/p/
 [2]: http://acm.uva.es/p/v4/412.html
 [3]: http://tiagomadeira.net/scripts/412.c
 [4]: http://dias.moreira.nom.br/
 [5]: http://acm.uva.es/p/v4/441.html
 [6]: http://tiagomadeira.net/scripts/441.c
 [7]: http://acm.uva.es/p/v5/543.html
 [8]: http://tiagomadeira.net/scripts/543.c
 [9]: http://pt.wikipedia.org/wiki/Conjectura_de_Goldbach
 [10]: http://pt.wikipedia.org/wiki/Erat%C3%B3stenes
 [11]: http://olympiads.win.tue.nl/ioi/
 [12]: http://www.google.com/calendar/feeds/olimpinf@gmail.com/public/basic
 [13]: http://www.firer.info

