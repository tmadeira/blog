---
title: There and back again…
date: 2006-06-25T12:45:06+00:00
url: /2006/06/there-and-back-again/
tags:
  - computação
  - croácia
  - ioi
  - obi
  - obi 2006
  - olimpíadas
  - problemas
  - programação
  - programação dinâmica
  - programming challenges
  - provas
  - resultado
---

Eu até tentei escrever um artigo por dia na semana passada, durante o curso da [seletiva brasileira][1] para a [Olimpíada Internacional de Informática][2], mas não deu tempo… Então aqui vai um resumo feito uma semana depois do final do curso, separado em tópicos, com o título pouco criativo _“There and back again…”_

### Nível mais alto

Comparando a prova da segunda fase da [OBI2006][3] com a prova da OBI do ano passado, já era possível perceber que o nível esse ano subiu. E, como já esperado, o nível do curso e das pessoas também subiu, o que é excelente para o Brasil.

### Mais prática, menos teoria

Neste ano não aconteceu a programação “normal” que tivemos nos últimos dois anos: **aula teórica** (só um professor apresentando slides e nós anotando, sem computadores) durante a manhã e **aula prática** durante a tarde.

Nos dois períodos nossas aulas foram no laboratório, com computadores, onde resolvemos uma porção de problemas do [treinamento para a ACM da Universidade de Valladollid][4].

Criei uma pasta no meu servidor com todos os problemas que eu consegui resolver (alguns deles ficaram pela metade): ~~tiagomadeira.net/pub/uva/~~ (essa pasta infelizmente foi perdida com o tempo).

### Problemas sobre mais de um conteúdo

Uma característica interessante dos problemas desse ano (do treinamento e da prova) foi o uso de mais de um tipo de algoritmo para fazer a solução. A combinação mais comum foi **geometria + grafos**, que caiu inclusive na prova da Seletiva, no problema [Labirinto][5].

### A Prova

#### Primeiro Dia – Quadrado Romano

[[Enunciado]][6] 30 minutos tentando pensar em algum tipo de recorrência, 1h implementando uma solução força bruta! No final, pensei que faria uns 50 pontos (perderia um pouco por causa do tempo), mas perdi alguns pontos por resposta errada, ainda não sei por quê!

**Solução:** ~~romano.c~~ (infelizmente foi perdido com o tempo)

**Pontos:** 10/100

#### Segundo Dia – Euros

[[Enunciado]][8] Durante as duas horas da prova fiquei procurando uma recorrência. Descobri que estou muito _newbie_ em programação dinâmica. Não programei uma linha de código…

**Pontos:** 0/100

#### Terceiro Dia – Labirinto

[[Enunciado]][5] Olhei o enunciado e já saquei o que o problema queria. Eu tenho uma boa noção de grafos (embora precise estudar fluxos) e o curso trabalhou bastante algoritmos geométricos, então sem maiores problemas fiz o algoritmo, testei várias vezes, achei que ia tirar 100. No fim, não sei o que houve, se foi falta de tempo ou resposta errada. Só vi que fiz 40 pontos…

**Solução:** ~~labirinto.c~~ (infelizmente foi perdido com o tempo)

**Pontos:** 40/100

#### Quarto Dia – Prova Final

[[Caderno de Tarefas]][10] Li todos os problemas e achei que poderia ir bem na prova (o primeiro problema eu tinha certeza que não conseguiria, mas o segundo e o terceiro dava pra fazer). Então, fui direto para o segundo problema, acreditando que era o mais fácil. Mas depois de bolar vários algoritmos, ter respostas erradas e tempos muito altos, tive que ficar com uma solução precária, um **Floyd Warshall** para cada troca de vértices (resultado: [tex]O(n^{5})[/tex]!) Aí depois não deu tempo de fazer o terceiro problema, mesmo eu tendo esboçado sua solução.

**Solução do Teletransporte:** ~~tele.c~~ (infelizmente foi perdido com o tempo)

**Pontos:** 40/300

### Conclusão

O legal é que esse curso sempre dá vontade de estudar, além de ensinar bastante… Aqui ficam registrados meus objetivos e metas pro segundo semestre de 2006 e primeiro semestre de 2007.

#### Objetivos

- Medalha de ouro na [Olimpíada Brasileira de Informática][3] do ano que vem.
- Visitar a **Croácia** representando o Brasil na [Olimpíada Internacional de Informática][12] do ano que vem.
- Vencer a [Olimpíada Regional de Matemática][13] (não dá pra ficar sem nenhuma medalha nesse ano, né?)

#### Metas

- Comprar e ler **Programming Challenges**.
- Estudar **programação dinâmica**. Conhecer os algoritmos mais comuns.
- Estudar **fluxos em rede** e **ordenação topológica**.
- Estudar **matemática**, inclusive recorrências e geometria (que não ajudam só para olimpíada de matemática, mas pras olimpíadas de informática também)

[1]: http://olimpiada.ic.unicamp.br/
[2]: http://www.ioi2006.org/
[3]: http://olimpiada.ic.unicamp.br
[4]: http://acm.uva.es/p/
[5]: http://olimpiada.ic.unicamp.br/seletivaIOI/pdf/provas/ProvaOBI2006_sele_d3.pdf
[6]: http://olimpiada.ic.unicamp.br/seletivaIOI/pdf/provas/ProvaOBI2006_sele_d1.pdf
[8]: http://olimpiada.ic.unicamp.br/seletivaIOI/pdf/provas/ProvaOBI2006_sele_d2.pdf
[10]: http://olimpiada.ic.unicamp.br/seletivaIOI/pdf/provas/ProvaOBI2006_sele_final.pdf
[12]: http://olympiads.win.tue.nl/ioi/
[13]: http://orm.mtm.ufsc.br
