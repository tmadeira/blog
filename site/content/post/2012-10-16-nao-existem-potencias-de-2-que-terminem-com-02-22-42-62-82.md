---
title: Não existem potências de 2 que terminem com 02, 22, 42, 62, 82
type: post
date: 2012-10-17T02:33:20+00:00
url: /2012/10/nao-existem-potencias-de-2-que-terminem-com-02-22-42-62-82/
categories:
  - Matemática
tags:
  - demonstrações
  - futilidades
  - Matemática
  - potências
  - praia

---
Esses dias, tomando banho de mar, me vi pensando na forma das potências de dois em base dez.

É fácil ver que não existe potência de 2 que termine em 0, já que qualquer número que termina em 0 é múltiplo de 5.

Na verdade, é fácil ver (com um raciocínio indutivo com módulo 10) que o último algarismo das potências de 2 vai seguindo a sequência (2, 4, 8, 6) infinitamente, de tal forma que o último algarismo de  <img src='https://s0.wp.com/latex.php?latex=2%5Ek&bg=T&fg=000000&s=0' alt='2^k' title='2^k' class='latex' />(k > 0) é:

– 6, se o resto da divisão de k por 4 for 0

– 2, se o resto da divisão de k por 4 for 1

– 4, se o resto da divisão de k por 4 for 2

– 8, se o resto da divisão de k por 4 for 3

Mas aí fiquei pensando em potências de 2 que acabassem com uma porção de doises. Algo como 3103912840123891294805398108310312222 (esse número aí não tem nada de especial, foi só eu batendo no teclado loucamente e terminando com 2222). Como eu faria pra encontrá-las? Será que existem?

Comecei pensando em coisas do tipo 222…222, isto é <img src='https://s0.wp.com/latex.php?latex=2+%5Ctimes+10%5En+%2B+2+%5Ctimes+10%5E%7Bn-1%7D+%2B+2+%5Ctimes+10%5E%7Bn-2%7D+%2B+%5Ccdots+%2B+2+%5Ctimes+10%5E0&bg=T&fg=000000&s=0' alt='2 \times 10^n + 2 \times 10^{n-1} + 2 \times 10^{n-2} + \cdots + 2 \times 10^0' title='2 \times 10^n + 2 \times 10^{n-1} + 2 \times 10^{n-2} + \cdots + 2 \times 10^0' class='latex' />

Podemos colocar 20 em evidência, ficando com <img src='https://s0.wp.com/latex.php?latex=20+%5Ctimes+%2810%5E%7Bn-1%7D+%2B+10%5E%7Bn-2%7D+%2B+%5Ccdots+%2B+10%5E0%29+%2B+2&bg=T&fg=000000&s=0' alt='20 \times (10^{n-1} + 10^{n-2} + \cdots + 10^0) + 2' title='20 \times (10^{n-1} + 10^{n-2} + \cdots + 10^0) + 2' class='latex' />.

A princípio isso não parece ajudar muito, mas vejam que interessante:

 <img src='https://s0.wp.com/latex.php?latex=20+%5Ctimes+x+%2B+2+%3D+2%2810x%2B1%29&bg=T&fg=000000&s=0' alt='20 \times x + 2 = 2(10x+1)' title='20 \times x + 2 = 2(10x+1)' class='latex' />(x é qualquer número inteiro > 0)

Bem…  <img src='https://s0.wp.com/latex.php?latex=10x%2B1&bg=T&fg=000000&s=0' alt='10x+1' title='10x+1' class='latex' />certamente não é uma potência de 2 (porque termina em 1).

Logo,  <img src='https://s0.wp.com/latex.php?latex=2%2810x%2B1%29&bg=T&fg=000000&s=0' alt='2(10x+1)' title='2(10x+1)' class='latex' />também não é uma potência de 2, independente da maluquice que a gente coloque no lugar de <img src='https://s0.wp.com/latex.php?latex=x&bg=T&fg=000000&s=0' alt='x' title='x' class='latex' />.

Portanto, **não existem** potências de 2 que terminem em 22! Mais que isso: não existem potências da forma 20x+2, ou seja, não existem potências de 2 que terminem em 02, 22, 42, 62 ou 82! Não é incrível? Não é nada muito revolucionário ou complexo, mas nunca tinha parado pra pensar nisso.

Lá no início tínhamos visto que o último algarismo de  <img src='https://s0.wp.com/latex.php?latex=2%5Ek&bg=T&fg=000000&s=0' alt='2^k' title='2^k' class='latex' />é 2 se e somente se o resto da divisão de k por 4 for 1. Logo, concluímos (e dá pra imaginar várias outras provas simples pra esse fato, pensando bem, por exemplo notando que <img src='https://s0.wp.com/latex.php?latex=12+%5Ctimes+16+%5Cequiv+12+%5Cmod+20&bg=T&fg=000000&s=0' alt='12 \times 16 \equiv 12 \mod 20' title='12 \times 16 \equiv 12 \mod 20' class='latex' />) que para todo k > 0 tal que o resto da divisão de k por 4 seja 1 vale que o resto da divisão de 2^k por 20 é 12.

As primeiras potências de 2 que terminam em 2 são:

–  <img src='https://s0.wp.com/latex.php?latex=2%5E1+%3D+2&bg=T&fg=000000&s=0' alt='2^1 = 2' title='2^1 = 2' class='latex' />(que ignorei aí em cima quando falei que x > 0 no 20x+2)

– <img src='https://s0.wp.com/latex.php?latex=2%5E5+%3D+32&bg=T&fg=000000&s=0' alt='2^5 = 32' title='2^5 = 32' class='latex' />

– <img src='https://s0.wp.com/latex.php?latex=2%5E9+%3D+512&bg=T&fg=000000&s=0' alt='2^9 = 512' title='2^9 = 512' class='latex' />

– <img src='https://s0.wp.com/latex.php?latex=2%5E%7B13%7D+%3D+8192&bg=T&fg=000000&s=0' alt='2^{13} = 8192' title='2^{13} = 8192' class='latex' />

– <img src='https://s0.wp.com/latex.php?latex=2%5E%7B17%7D+%3D+131072&bg=T&fg=000000&s=0' alt='2^{17} = 131072' title='2^{17} = 131072' class='latex' />

– <img src='https://s0.wp.com/latex.php?latex=2%5E%7B21%7D+%3D+2097152&bg=T&fg=000000&s=0' alt='2^{21} = 2097152' title='2^{21} = 2097152' class='latex' />

– <img src='https://s0.wp.com/latex.php?latex=2%5E%7B25%7D+%3D+33554432&bg=T&fg=000000&s=0' alt='2^{25} = 33554432' title='2^{25} = 33554432' class='latex' />

O que parece nos indicar que, da mesma forma que o último algarismo das potências de 2 seguem a sequência (2, 4, 8, 6), o penúltimo algarismo das potências de 2 que acabam em 2 seguem a sequência (9, 7, 5, 3, 1). Isso é fácil de ver: basta fazer umas multiplicações por 16 dentro do módulo 100.

