---
title: Feeds RSS para fotologs
type: post
date: 2006-10-21T18:56:55+00:00
url: /2006/10/feeds-rss-para-fotologs/
categorias:
  - Códigos aleatórios
tags:
  - bloglines
  - dreamhost
  - feeds
  - php
  - rss
  - scripts

---
Não tenho programado absolutamente nada, a não ser nos trabalhos remunerados. Eu vejo a programação como uma arte… Programar é como compôr uma música, pintar, atuar; é preciso haver inspiração. Eu não ando inspirado para programar, mas nesse caso a necessidade me levou a criação de um _script_ que pode ter utilidade para algum leitor perdido…

No ano passado, eu [escrevi um script][2] que gerava feeds RSS para fotologs do [fotolog.net][3]. O tempo passou, o meu usuário na UNICAMP foi deletado e nessa semana eu voltei a ter a necessidade de acompanhar um fotolog. Então, resolvi reescrever o _script_, agora com mais funcionalidades:

  * Compatível com [Bloglines][4]
  * Tem como descrição o “título” que o usuário coloca no Fotolog.net.
  * É atualizado sempre que há novos comentários nos últimos 6 posts.
  * Você pode comentar de dentro do seu leitor de feeds (ele copia o formulário de comentário pro feed).
  * Ele faz _cache_ de **tudo**.

Resolvi presentear todo mundo usando o presente que a [Dreamhost][5] me deu no mês passado: 200gb de espaço e 2tb de banda tinham que servir pra alguma coisa no meu servidor. Então, ao invés de disponibilizar o código, eu criei uma página PHP que gera o feed que você quiser para você:

<p style="font-weight:bold;">
  http://fotolog.tiagomadeira.net/USUARIO
</p>

Para ver um feed em ação no Bloglines, entre no [meu diretório de feeds][6] e procure um feed com prefixo “fotolog.com/”.

Depois de acabar de criar o script, ainda lembrei que o [IE7][7] foi lançado nessa semana com suporte a feeds! Então, esse negócio pode ser útil pra bastante gente.

Acompanhe os fotologs dos seus amigos no [Bloglines][8], divulgue aos seus amigos, comente sugerindo melhorias; aproveite enquanto eu ainda estou inspirado pra corrigir os defeitos! =)

 [2]: /2005/11/fotolognet-feed/
 [3]: http://www.fotolog.net
 [4]: http://www.bloglines.com/
 [5]: http://www.dreamhost.com
 [6]: http://www.bloglines.com/public/tmadeira
 [7]: http://www.microsoft.com
 [8]: http://www.bloglines.com

