---
title: Resultado da OBI2006
type: post
date: 2006-05-31T18:32:03+00:00
url: /2006/05/resultado-da-obi2006/
categorias:
  - Cotidiano
tags:
  - c
  - computação
  - ioi
  - obi
  - obi 2006
  - olimpíadas

---
Em breve, estarei divulgando o **how-to**: _Como perder uma viagem, um curso e uma oportunidade de representar o Brasil numa olimpíada internacional por um erro de digitação_… :(

Um dia depois do prazo que consta no [regulamento][1], a Comissão Organizadora da [OBI2006][2] divulgou o resultado da modalidade programação. Para minha surpresa, [fiz 20 pontos][3]: 10 no **Lobo Mau** e 10 no **Penalidade Mínima**.

No [último _post_][4] eu mencionei que estava mal no dia da prova e nem fiz o último problema, mas não esperava tão poucos pontos. Aí baixei os [testes do problema Lobo Mau][5] e, com poucos testes, percebi que o erro do meu programa estava na entrada. Os arquivos que a OBI está usando estão no formato DOS (tem um caracter estranho além do **n** a cada quebra de linha) e por isso o meu programa não pegava corretamente os dados (ele pega todos os caracteres da matriz com **scanf(“%c”);** e o caracter de quebra de linha da mesma maneira). Já mandei o pedido de correção ontem a noite mesmo e eles já disseram que vão recorrigir.

### Maldito erro de digitação!

<p id="malditoErroDeDigitacao" class="quote">
  Agoca… O pcoblema sécio veio depois. Ao lec o ródigo da minha solução*, pecrebi que eccei um racartec no acgumento rondirional de um loop! Tcoquei um “r” (rê) poc um “c” (ecce) <em>(veja a linha 63 do ródigo que está linkado no astecisro)</em>, racarteces que signifiravam as linhas e rolunas da matciz, cespertivamente. Maldito ecco de digitação!
</p>



<p style="font-size:85%;">
  <a href="javascript:arrumaErros('malditoErroDeDigitacao');">Corrija a frase acima, JavaScript!</a> (são as inutilidades que o vício em linguagens <em>client-side</em> pode fazer…)
</p>

Se eu não tivesse trocado esses caracteres, tiraria 30 pontos a mais do que eu já devo tirar com a solicitação das quebras de linha: **110** pontos, o suficiente para participar do curso e da prova **Seletiva para IOI**.

<p style="font-size:85%;">
  * Minha solução para o problema <strong>Lobo Mau</strong>: <s>lobo.c</s> (infelizmente esse arquivo foi perdido com o tempo)
</p>

Bom… Já que é a lógica do problema que é o desafio na OBI, vocês não acham que erros de digitação deveriam poder ser corrigidos? Além disso, acho que eles podiam somar essa nota com a nota da primeira fase (mesmo que ela tivesse um peso bem menor).

Eu já esperava ir mal, mas pensei que os 100 pontos do **Lobo Mau** estavam garantidos, pelo menos. :(

Por enquanto é isso aí… Me ferrei, mas agora pelo menos nunca mais vou errar uma coisa dessas numa prova de programação e nunca mais vou comer no Mc Donalds antes de uma prova… (tô tentando ser otimista, mas tá difícil… hehehe) Parabéns pra quem passou e boa sorte! Embora eu não tenha gostado do resultado, na verdade não tenho motivos lógicos para reclamar. Vacilei na segunda fase mesmo e provas são sempre traiçoeiras (com certeza elas não são a melhor maneira de avaliação).

 [1]: http://olimpiada.ic.unicamp.br/info_geral/regulamento
 [2]: http://olimpiada.ic.unicamp.br
 [3]: http://olimpiada.ic.unicamp.br/res_fase2_prog/programacao_n2/MostraLog?id=13
 [4]: /2006/05/resumao/
 [5]: http://olimpiada.ic.unicamp.br/res_fase2_prog/programacao_n2/gabaritos/lobo.zip

