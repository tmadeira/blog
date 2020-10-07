---
title: OBI2007 – Primeira fase
date: 2007-03-18T11:27:16+00:00
url: /2007/03/obi2007-primeira-fase/
tags:
  - computação
  - obi
  - obi 2007
  - olimpíadas
  - problemas
  - programação
---

Não divulgarei minhas soluções (aka gabarito… :p) até sexta-feira, que é quando os professores já vão ter enviado a prova para a comissão organizadora da Olimpíada Brasileira de Informática.

Ontem, sábado 17 de março, foi a primeira fase da OBI. Eu resolvi a Iniciação Nível 1 para me divertir, vi a prova da Programação Nível 1 (que a [Carol][1] resolveu, com uma noção de C muito boa adquirida em um mês) e solucionei a prova da Programação Nível 2. Só vou falar sobre ela por enquanto, depois crio outros posts para falar sobre as outras.

Pra começar, a prova estava fácil. Eu resolvi em duas horas. Isso foi uma opinião de todos que fizeram a prova. Creio que estava mais fácil que a do ano passado. O caderno de tarefas era composto por cinco questões:

- **Chocolate** – Uma barra de chocolate é dividida várias vezes. O objetivo do programa é contar a quantidade de pedaços em que ela foi dividida. Basta ir pegando os números e ir somando-os -1.
- **Repositório** – Uma lista de números de programas e a versão em que estão instalados num computador. Depois, uma lista de números de programas e a versão em que eles estão disponíveis na internet. Decidir que programas devem ser atualizados no computador (determinar sempre a maior versão) e imprimí-los.
- **Pastas** – Dada uma lista de inteiros, verificar se os números aparecem a mesma quantidade de vezes (ex.: 1, 1, 2, 2, 3, 3 é válido; mas 1, 2, 2, 3, 3 não é).
- **Móbile** – Interpretei como um problema de grafos. Sabe o que é um móbile? Você tem que ver se todos as peças de um mesmo “nível” tem a mesma quantidade de filhos. Eu fiz um BFS (busca em largura) para determinar o nível de cada um e depois foi só ver se todos de cada nível tinham a mesma quantidade de filhos.
- **Sacoleiro** – Um cara quer comprar presentes para seus filhos. Em cada cidade há presente para um ou para outro, com preços diferentes. Ele quer ser justo. Seguindo um trajeto possível, passando por uma cidade e comprando um ou mais presentes ou até nenhum, qual a menor diferença possível entre os preços dos presentes? Sem dúvidas o problema mais difícil da prova (creio que o único difícil). Ainda não conheço a solução ideal, que deve usar programação dinâmica. Implementei um DFS (busca em profundidade) que testa todas as possibilidades.

No [orkut][2] já me disseram que cometi um erro ridículo:

> No terceiro parágrafo do Repositórios, ele diz: “Um programa deve verificar então qual a versão de cada programa instalado nos computadores (todos eles possuem os mesmos aplicativos instalados e nas mesmas versões) e INSTALAR TODOS AQUELES QUE AINDA NÃO FORAM INSTALADOS ou cuja versão instalada seja anterior a versão mais recente.” Portanto, se um programa disponível na internet não está instalado nos computadores, ele deve ser instalado.

E meu **Sacoleiro** provavelmente não vai passar no tempo. Então espero 300 pontos e alguns quebrados.

O resultado sairá até o dia 7 de abril lá no [site deles][3]. Eu gero uma lista de classificação quando sair. :)

[1]: http://malvicioso.com/
[2]: http://www.orkut.com/CommMsgs.aspx?cmm=17760&tid=2521449173521240978&start=1
[3]: http://olimpiada.ic.unicamp.br
