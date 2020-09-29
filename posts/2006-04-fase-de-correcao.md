---
title: Fase de Correção
type: post
date: 2006-04-19T23:50:32+00:00
excerpt: As tarefas da modalidade Programação estão sendo corrigidas. Já que acabou o período de submissão da modalidade de Programação, aqui também exponho minhas soluções.
url: /2006/04/fase-de-correcao/
categorias:
  - Cotidiano
tags:
  - códigos
  - computação
  - correção
  - obi
  - obi 2006
  - olimpíadas
  - resultado
---

OBI2006 em fase de correção…

_As tarefas da modalidade Programação estão sendo corrigidas. Os gabaritos das provas da modalidade iniciação estão disponíveis, por enquanto apenas para professores (algumas escolas atrasaram a realização da prova, por isso a demora na divulgação do gabarito). Solicitamos os professores que consultem a área de acesso restrito para informações de como proceder para enviar os resultados de sua escola._ (retirado do [site da OBI][1])

O pessoal da Iniciação já sabe como foram por aqui… [Meu colégio][2] até que teve um resultado legal: dois alunos da iniciação 1 (meu irmão é um deles) fizeram 12 de 16 e três alunos da iniciação 2 fizeram 19 de 22. Provavelmente esses vão pra segunda fase.

### E por falar em ir pra segunda fase…

Pensando um pouco, cheguei a conclusão de que todo competidor que acertou mais de uma questão (ou talvez até menos que isso) já deve estar na segunda fase.

Uns 20 competidores devem ir para Campinas (medalha de ouro). Outros 20 devem conseguir medalhas de prata, mais 30 medalhas de bronze e 30 menções honrosas. Então, no mínimo 100 **precisam** fazer a segunda fase.

Neste ano, 520 pessoas participaram da modalidade Programação 2. Grande parte desses falta na prova ou zera (digamos que seja metade). Dessa forma, sobram 260.

Já que essa prova de primeira fase foi só para acabar com os casos de cola (tanto que a pontuação dela nem soma com a da segunda fase para dar a nota final e decidir se o competidor vai ao curso de programação em Campinas), acho bem razoável que esses 260 participem da segunda fase para no fim ficarem os 100 melhores.

Mas é só um palpite…

### Meus códigos-fonte

Já que não é mais possível submeter resultados (as tarefas já estão sendo corrigidas), agora publiquei meus códigos-fonte na seção de [scripts][3] do meu site.

- [Truco][4]
- [Colheita de Caju][5]
- [Museu][6]
- [Jogo de Cartas][7]
- [Escada Perfeita][8]

### Colheita de Caju

Como vocês podem ver nos links aí em cima, a minha pior solução foi para o problema **Colheita de Caju**. A complexidade ficou um pouco (na verdade bastante) alta: O(L.C.(L-M).(C-N)). É a solução força bruta do negócio, bem simples de implementar e que com certeza funciona, mas para um caso com [L=1000, C=1000, M=1, N=1], ela demora um tempo no mínimo _razoável_… Mas tudo bem, os outros acho que passam talvez até com a pontuação máxima.

A solução _ótima_ seria usando programação dinâmica; um algoritmo que depois eu comento melhor.

### Nota esperada

Quase duas semanas depois da prova, meu chute para a nota da primeira fase é 420/500. Mas nunca se sabe… :)

[1]: http://olimpiada.ic.unicamp.br
[2]: http://www.salesianoitajai.g12.br
[3]: /wp-content/uploads/c/
[4]: /wp-content/uploads/c/truco.c
[5]: /wp-content/uploads/c/caju.c
[6]: /wp-content/uploads/c/museu.c
[7]: /wp-content/uploads/c/cartas.c
[8]: /wp-content/uploads/c/escada.c
