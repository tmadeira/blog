---
title: O Poder do Ajax
date: 2005-10-06T21:57:23+00:00
excerpt: Ajax é a sigla de Asynchronous JavaScript and XML. Não é uma linguagem, nem uma tecnologia; como eu antes pensava. É simplesmente uma maneira de trabalhar com o cliente e o servidor juntos, usando XmlHttpRequest do JavaScript.
url: /2005/10/o-poder-do-ajax/
tags:
  - ajax
  - css
  - firefox
  - javascript
  - php
  - png
  - xmlhttp
---

Ontem, pela primeira vez, desenvolvi um sistema em Ajax. Já vinha estudando há pouco mais de uma semana e hoje temos votação do Grêmio Estudantil no Colégio, e achei interessante fazer usando Ajax, e aproveitar algumas coisas como:

- Todos usam Mozilla Firefox.
- O servidor fica do lado dos computadores… É rede, não internet!

… para abusar de Ajax, já que eu podia fazer uma coisa que buscasse bastante no servidor e que só funcionasse no Gecko. O resultado ficou bem legal. Embora eu não tenha conseguido fazer um trechinho do script sem um _IFRAME_ que atuliza sem parar, todo o esquema foi feito com JavaScript e aprendi umas coisas bem legais. Além disso, o formuláro ficou muito bonito, posicionado e desenvolvido em CSS. Os botões de _radio_ estão com a propriedade **display**:none e os labels estão com **opacity:0.5;** Quando eu clico neles (onclick), eles deixam todos os outros com opacity:0.5 e se dão opacity:1. Quando o visitante clica no submit do formulário, o XmlHttp IMEDIATAMENTE pega os dados do servidor e joga na tela. Ficou uma coisa muito massa. E ainda aproveitei pra usar PNGs transparentes!

Não vou colocar o código aqui agora, ainda queria ajustar algumas coisas porque ontem fiz na pressa, mas confiram um screenshot! (o SS mais legal seria o do “Voto Confirmado”, quando um div com fundo PNG alpha aparece em cima de tudo, mas eu fiz um sistema de segurança para só quem tá dentro do Lab. de Informática poder votar – testando IPs – e agora estou em casa).

![Screenshot da votação do Grêmio](https://farm1.staticflickr.com/28/50181099_82979ab12d.jpg)

Ajax é muito power. Desenvolvendo com ele dá pra fazer umas coisas que antes eu nem imaginava… Agora tô estudando bastante JavaScript, porque com a parte de servidor/PHP não há problemas, mas nunca estudei muito o lado client-side (estudei tableless, mas não DOM/JavaScript!). Já li dois artigos do [Elcio][2], do Tableless.com.br: Um sobre [DHTML Crossbrowser][3] e outro que é o conhecido [Ajax para quem só ouviu falar][4]. Agora estou acabando o segundo artigo dele sobre Ajax, [Ajax: Encarando o Mundo Real][5]. O bom é que a sintaxe das coisas no JavaScript são bem parecidas com as do PHP…

---

Tenho lido umas coisas [desse cara][6] e tô achando muito bom. Sugiro que quem goste de software livre ou quem quer aprender mais sobre ele, leia os artigos também. :)

[2]: http://www.elcio.com.br
[3]: http://elcio.com.br/crossbrowser/
[4]: http://www.tableless.com.br/ajaxdemo
[5]: http://www.tableless.com.br/ajaxdemo2
[6]: http://falcondark.blogspot.com
