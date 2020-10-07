---
title: O prédio e as bolas
date: 2012-10-27T13:49:44+00:00
url: /2012/10/o-predio-e-as-bolas/
tags:
  - algoritmos
  - bolas
  - busca binária
  - curiosidades
  - matemática
  - prédios
  - problemas
---

Imagine-se num prédio de 100 andares com várias bolas. A partir de um determinado andar (desconhecido), quando você joga uma bola pela janela, a bola quebra. Você quer determinar precisamente qual é esse andar e a única coisa que pode fazer é jogar bolas de andares diferentes.

Se você tem muitas bolas e não se importa em quebrar quantas forem necessárias, você pode realizar uma busca binária. Uma busca binária, para começar com um exemplo, é aquilo que você faz naquele diálogo clássico:

--- Pense num número de 1 a 100 e eu vou tentar adivinhar. A cada palpite, você precisa me dizer se o número que você pensou é maior ou menor do que meu chute.  
--- Pensei.  
--- 50  
--- Maior.  
--- 75  
--- Menor.  
--- 63  
--- Menor.  
--- 57  
--- Menor.  
--- 54  
--- Menor.  
--- 52  
--- Menor.  
--- 51  
--- Acertou!

A cada passo numa busca binária você divide o intervalo de possibilidades por dois. Você descarta metade dos números que poderiam ser a solução. Por isso, mesmo que você pense num número de 1 a 1.000.000.000 (um bilhão) eu certamente não vou demorar mais de 30 (isso é, logaritmo de um bilhão na base dois) tentativas para acertar exatamente o número que você pensou.

Por que logaritmo de um bilhão na base dois? Como eu comentei anteriormente, a cada número que eu chuto e você diz se é maior ou menor do que o resultado eu corto meu intervalo por dois. Portanto, o número de chutes necessários (no pior caso) é precisamente a quantidade de vezes que preciso dividir um bilhão por dois até chegar a um (até sobrar um único número possível para eu chutar, que necessariamente vai ser o número que você pensou).

$$
1000000000 / 2 / 2 / \cdots / 2 = 1
$$

Nosso problema é encontrar quantos 2 tem aí. Dividir um número por 2 _k_ vezes é o mesmo que dividir por $2^k$. Logo, nosso problema é encontrar quanto vale _k_:

$$
\frac{1000000000}{2^k} = 1
$$

Multiplicando os dois lados da igualdade por $2^k$, temos:

$$
1000000000 = 2^k
$$

Tirando o logaritmo na base 2, concluímos:

$$
\log_2 1000000000 = k
$$

Ou seja, o logaritmo de _n_ na base 2 é o número de vezes que precisamos dividir _n_ por 2 para chegar em 1. Voltando ao problema inicial, como $log_2 100 < 7$, precisaremos jogar no máximo 7 bolas para determinar a partir de qual andar a bola quebrar. Quando você jogar uma bola, se ela quebrar é a mesma coisa que o seu amigo que pensou num número dizendo _"O número que eu pensei é menor."_ Se ela não quebrar, é equivalente ao seu amigo dizendo _"O número que eu pensei é maior."_

Realizando uma busca binária, o pior caso (aquele caso no qual quebraremos mais bolas -- e que jogaremos a maior quantidade de vezes) é quando a bola quebra no primeiro andar. Você joga as bolas dos andares 50 (poft!), 25 (poft!), 13 (poft!), 7 (poft!), 4 (poft!), 2 (poft!), 1, jogando um total de 7 e quebrando um total de 6 bolas.

Nada muito novo para quem já conhecia busca binária. Por isso, vamos modificar o problema: Suponha que você não tenha quantas bolas desejar, mas apenas duas bolas. Quando uma bola cai sem quebrar, você pode descer, pegá-la e jogá-la de novo. Qual a menor quantidade de vezes que você vai ter que jogar a bola para com certeza determinar a partir de qual andar as bolas começam a quebrar?

Fazer uma busca binária não funciona mais. No caso de a bola quebrar a partir do primeiro andar, assim que você joga uma bola do andar 50 (uma bola quebra) e outra do 25 (outra bola quebra), você não tem mais bolas e não tem ideia de qual é o andar a partir do qual as bolas começam a quebrar (tudo o que você sabe é que é algum andar entre 1 e 25).

Como usar as duas bolas para determinar exatamente o andar a partir do qual as bolas começam a quebrar jogando as bolas a menor quantidade possível de vezes? Qual é essa quantidade mínima de vezes que será necessário jogar bolas pela janela?

_Obrigado ao [David][1] por ter me apresentado o problema. A solução é bem legal!</small>_

**Editado para ficar mais claro:** A quantidade mínima que queremos é a do pior caso, isso é, a menor quantidade de vezes que será necessário jogar a bola independente de qual for o andar. Por exemplo, suponha que eu jogue uma bola do andar 5 e não quebre. Aí eu jogue do andar 10 e não quebre. Do 15 e não quebre. E assim sucessivamente (de 5 em 5) enquanto ela não quebrar. Quando ela quebrar, eu pego a outra bola e jogo no último valor que eu joguei menos 4, menos 3, menos 2 e menos 1. O pior caso para esse algoritmo é quando a bola quebrar a partir do andar 99. Jogarei nos andares 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 (poft!), 96, 97, 98, 99 (poft!), ou seja, 24 vezes. (Mas é possível usar um algoritmo mais esperto que isso: a resposta do problema é menor que 24.)

**Editado para programadores:** A generalização deste problema (para _n_ andares em vez de 100 e _k_ bolas em vez de 2) caiu na OBI 2010 (o problema se chama Altas Aventuras) e está no SPOJ para quem quiser resolver: [ALTAS2][2]. Quem me contou foi o [André][3].

[1]: https://www.facebook.com/david.marzagao
[2]: http://br.spoj.pl/problems/ALTAS2/
[3]: https://www.facebook.com/andrehpereira
