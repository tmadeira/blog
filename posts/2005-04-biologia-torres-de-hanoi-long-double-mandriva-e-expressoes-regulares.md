---
title: Biologia, Torres de Hanói, Long Double, Mandriva e Expressões Regulares
type: post
date: 2005-04-07T23:17:30+00:00
excerpt: São muitos assuntos pra descrever em tão pouco espaço! Leia logo o artigo completo!
url: /2005/04/biologia-torres-de-hanoi-long-double-mandriva-e-expressoes-regulares/
categorias:
  - Cotidiano
tags:
  - biologia
  - c
  - expressões regulares
  - linux
  - long double
  - mandriva
  - regex
  - Software Livre
  - torres de hanói
---

Hoje fiz uma prova de biologia. Minha média em biologia estava em 7,93 (8 em um trabalho, 5,8 em uma prova, 10 em participação) e acho que com essa prova vai continuar na mesma, se não piorar. Acredito que eu vá tirar no mínimo 8,5 nessa prova e no máximo 9,5. Pelo menos foi melhor que na outra em que eu tirei 5,8. Bom, só pra não parecer que eu sou burro, minhas notas nas outras matérias nas provas que eu recebi essa semana foram:

- 10 em inglês
- 10 em português (e mais 10 numa redação)
- 10 em matemática
- 10 em geografia
- 10 em história
- 9,5 em química (e mais 10 num trabalho)
- 9,5 em física

Hmmm… Acho que dá pra perceber que meu problema é biologia mesmo…

Sinceramente, eu odeio essa matéria. Nas outras disciplinas a gente aprende e desenvolve raciocínio lógico. Biologia é só uma decoreba. Não compreendo qual é a utilidade de saber a função das bactérias para nossa vida ou, como um enunciado da prova dizia, “Se você capturasse exemplares de piranhas no Pantanal Mato-grossense, o que você faria pra descobrir de que cadeia alimentar elas fazem parte com base somente nesses exemplares?” Qual a utilidade disso aí? Se eu quisesse ser biólogo até beleza, mas isso aí é inútil. Em matemática, aprendemos coisas úteis. Em biologia, só aprendemos coisas assim… Se ainda fosse como ano passado onde estudávamos atualidades biológicas como células-tronco, AIDS, DSTs, Gripe do Frango, etc., tava ótimo mas esse ano tá um “saco”.

Acho que essa gente que gosta de biologia só pensa no vestibular ao dizer que ela é útil… O básico dela até pode ser útil, mas metade do que a gente aprende na escola de biologia não é útil.

#### Bom, parando de falar sobre isso… Vamos para as Torres de Hanói

Ontem eu deixei o laptop a noite inteira fazendo as Torres de Hanói com 30 pinos. Utilizando o algoritmo que está implementado em torresdehanoi.c o programa ficou 728 minutos (12 horas) testando e não conseguiu chegar a um fim. Com outros testes, consegui os seguintes tempos:

- 10 pinos – 0 s
- 15 pinos – 1 s
- 20 pinos – 20 s
- 25 pinos – 20 min
- 30 pinos – mais de 12 horas

É assombroso a maneira com que vai aumentando…

Bom, utilizando o tipo long double do C eu fiz a conta de 2^64 para ver o custo da “Lenda de Brama” (é esse o nome?)

2^64=18.446.744.073.709.551.616

Ou seja, 18 quinquilhões e meio… Isso é muita coisa.

O interessante é que eu nunca tinha usado o **long double** com números tão grandes e então fiz alguns testes. Eu cheguei ao resultado de 2^1000, 2^10000 e cheguei a conclusão de que o último número que ele consegue escrever sem dizer que é inf (infinito?) é 2^16383, ou seja, 2^(2^14-1). Saiu umas 40 linhas no console, é muito grande!

Hmmm, demonstrei mais alguns teoremas como a Relação Fundamental da Trigonometria (usando o teorema de Pitágoras – basta dividir os dois lados por a^2), fórmula de Bhaskara, o volume de um cubo inscrito numa esfera pode ser calculado através do raio da esfera, etc. (não lembro de todos). Na verdade, não fui eu que demonstrei. Demonstramos no treino da Olimpíada de Matemática. Eu, o Vavá e o Bruno.

A Mandrakesoft comprou a Conectiva, formando o Mandriva. Eu achei uma pena que uma distribuição importante do Brasil (a primeira) acabou assim. Ela foi muito importante no software livre do Brasil, da América Latina e do mundo. Porém, acredito que a distro Mandriva vai crescer e se popularizar. Quando sair alguma, eu queimo um CD pra testar.

Peguei a música Estrada do Sol (Tom Jobim) no piano (uma versão muito boa escrita por Paulo Jobim e disponível no site www.tomjobim.com.br) e estou pegando Falando de Amor. Assim que der tempo, eu queria gravar algumas músicas que eu toco pra colocar aqui…

Acabei de ler o livro do Aurélio sobre expressões regulares e aprendi bastante coisa interessante. Expressões Regulares são MUITO úteis!
