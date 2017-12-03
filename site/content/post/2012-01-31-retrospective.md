---
title: 'Retrospective: new plugin for WordPress'
type: post
date: 2012-02-01T00:20:03+00:00
url: /2012/01/retrospective/
featured_image: /wp-content/uploads/2012/01/wordpresssc1.jpg
categories:
  - WordPress
tags:
  - códigos
  - css
  - html
  - javascript
  - php
  - plugin
  - programação
  - retrospective
  - scripts
  - Software Livre
  - wordpress

---
I’ve just wrote my first WordPress public plugin, that I’m licensing under GPL v3. This post is to make it public. I’m writing in English because the [WordPress plugin directory][1] asks me to provide a plugin page to host the files there and I’ll provide the URL of this post. **Update:** The plugin is now in the WordPress plugin directory: [wordpress.org/extend/plugins/retrospective/][2]

* * *

The website of the brazilian newspaper O Estado de São Paulo has a nice way to display news in a retrospective-style (check [this screenshot][3] or [this link][4] — Flash required).

Wouldn’t it be nice if we could display WordPress posts in our pages and categories in the same way just by using a shortcode? The possibilities are many. That’s why I wrote the **Retrospective** plugin for WordPress.

It has at least two advantages over the version you just saw:

  1. Does not require Flash (its implementation uses only CSS and JavaScript/jQuery)
  2. Has a option to respect the (time-)scale of the posts.

Its use is very simple. Wherever you add the shortcode [`retrospective`] the plugin will draw that cool retrospective. The shortcode supports several attributes:

  * `count` — limit the number of posts to be displayed (default = 10; use -1 to display all)
  * `cat` — display posts with category IDs comma-separated (default = display all posts)
  * `width` — the width of the timeline in pixels (default = 600)
  * `delay` — the time of the focus change animation in milisseconds (default = 1000)
  * `scale` — if set, respect the time scale in the distances between the points in the timeline (default = false)
  * `image_width, image_height` — the dimensions of the thumbnail images in pixels (default = 300×180)
  * `image_border_size` — the size of the image’s border in pixels (default = 7)
  * `image_border_color` — the color of the image’s border in hexa RGB (default = 000000)
  * `image_margin` — the space between the images (default = 5)
  * `date_format` — the date format in [PHP format][5] (default = d/m/Y)

For example, here is a [`retrospective count=5 cat=20 image_border_color=2F5971`] call:

<div style="padding-left:40px;">
  <div id="retro-4a577c6ef517f4c7837a4fc7d265b88b" class="retrospective">
    <!-- TIMELINE -->

    <ul class="time">
      <li rel="0">
        <a href="https://tiagomadeira.com/2012/01/retrospective/" style="left:0px;"><span>31/01/2012</span></a>
      </li>
      <li rel="1">
        <a href="https://tiagomadeira.com/2012/03/como-mostrar-o-ultimo-post-de-cada-categoria-no-wordpress/" style="left:150px;"><span>13/03/2012</span></a>
      </li>
      <li rel="2">
        <a href="https://tiagomadeira.com/2012/03/admin-anti-forget-alarm/" style="left:300px;"><span>15/03/2012</span></a>
      </li>
      <li rel="3">
        <a href="https://tiagomadeira.com/2012/11/e-books-devem-ampliar-nossa-liberdade-nao-reduzi-la/" style="left:450px;"><span>20/11/2012</span></a>
      </li>
      <li rel="4">
        <a href="https://tiagomadeira.com/2014/09/script-para-baixar-documentos-do-issuu-no-gnulinux/" style="left:600px;"><span>26/09/2014</span></a>
      </li>
    </ul>

    <!-- PHOTOS -->

    <div class="photos">
      <ul>
        <li rel="0">
          <a href="https://tiagomadeira.com/2012/01/retrospective/" title="Retrospective: new plugin for WordPress"><img src="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/wordpresssc1.jpg?resize=300%2C180&ssl=1" class="attachment-300x180 size-300x180 wp-post-image" alt="" title="Retrospective: new plugin for WordPress" srcset="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/wordpresssc1.jpg?resize=300%2C180&ssl=1 300w, https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/wordpresssc1.jpg?w=500&ssl=1 500w" sizes="(max-width: 300px) 100vw, 300px" data-recalc-dims="1" /></a>
        </li>
        <li rel="1">
          <a href="https://tiagomadeira.com/2012/03/como-mostrar-o-ultimo-post-de-cada-categoria-no-wordpress/" title="Como mostrar o último post de cada categoria no WordPress?"><img src="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/wordpresssc1.jpg?resize=300%2C180&ssl=1" class="attachment-300x180 size-300x180 wp-post-image" alt="" title="Como mostrar o último post de cada categoria no WordPress?" srcset="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/wordpresssc1.jpg?resize=300%2C180&ssl=1 300w, https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/wordpresssc1.jpg?w=500&ssl=1 500w" sizes="(max-width: 300px) 100vw, 300px" data-recalc-dims="1" /></a>
        </li>
        <li rel="2">
          <a href="https://tiagomadeira.com/2012/03/admin-anti-forget-alarm/" title="WordPress plugin: Admin Anti-forget Alarm"><img src="https://i2.wp.com/tiagomadeira.com/wp-content/uploads/2012/03/wordpress-plugin.jpg?resize=271%2C180&ssl=1" class="attachment-300x180 size-300x180 wp-post-image" alt="" title="WordPress plugin: Admin Anti-forget Alarm" srcset="https://i2.wp.com/tiagomadeira.com/wp-content/uploads/2012/03/wordpress-plugin.jpg?w=475&ssl=1 475w, https://i2.wp.com/tiagomadeira.com/wp-content/uploads/2012/03/wordpress-plugin.jpg?resize=300%2C199&ssl=1 300w" sizes="(max-width: 271px) 100vw, 271px" data-recalc-dims="1" /></a>
        </li>
        <li rel="3">
          <a href="https://tiagomadeira.com/2012/11/e-books-devem-ampliar-nossa-liberdade-nao-reduzi-la/" title="E-books devem ampliar nossa liberdade, não reduzí-la"><img src="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/11/stallman1.article.jpg?resize=300%2C180&ssl=1" class="attachment-300x180 size-300x180 wp-post-image" alt="" title="E-books devem ampliar nossa liberdade, não reduzí-la" srcset="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/11/stallman1.article.jpg?resize=300%2C180&ssl=1 300w, https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/11/stallman1.article.jpg?w=460&ssl=1 460w" sizes="(max-width: 300px) 100vw, 300px" data-recalc-dims="1" /></a>
        </li>
        <li rel="4">
          <a href="https://tiagomadeira.com/2014/09/script-para-baixar-documentos-do-issuu-no-gnulinux/" title="Script para baixar documentos do Issuu no GNU/Linux"></a>
        </li>
      </ul>
    </div>

    <!-- POSTS -->

    <ul class="posts">
      <li rel="0">
        <a href="https://tiagomadeira.com/2012/01/retrospective/" title="Retrospective: new plugin for WordPress">

        <h2>
          Retrospective: new plugin for WordPress <span>(31/01/2012)</span>
        </h2>

        <p>
          I've just wrote my first WordPress public plugin, that I'm licensing under GPL v3. This post is to make it public. I'm writing in English because the WordPress plugin directory asks me to provide a plugin page to host the files there and I'll provide the URL of this post. Update: The plugin is now in the WordPress plug ...
        </p></a>
      </li>

      <li rel="1">
        <a href="https://tiagomadeira.com/2012/03/como-mostrar-o-ultimo-post-de-cada-categoria-no-wordpress/" title="Como mostrar o último post de cada categoria no WordPress?">

        <h2>
          Como mostrar o último post de cada categoria no WordPress? <span>(13/03/2012)</span>
        </h2>

        <p>
          O WordPress é um dos meus programas preferidos e um dos que mais consome as madrugadas já faz alguns anos. Escrevi inúmeros temas, alguns plugins (um único genérico o suficiente para ser público) e já modifiquei algumas partes do código (embora hoje seja raro isso ser necessário). Acho muito simples e me di ...
        </p></a>
      </li>

      <li rel="2">
        <a href="https://tiagomadeira.com/2012/03/admin-anti-forget-alarm/" title="WordPress plugin: Admin Anti-forget Alarm">

        <h2>
          WordPress plugin: Admin Anti-forget Alarm <span>(15/03/2012)</span>
        </h2>

        <p>
          I wrote a small WordPress plugin to prevent users from publishing a post without excerpt or thumbnail, or with a too big excerpt, or with a too small thumbnail, or with an uppercase-only title. This screenshot is showing some of the messages the plugin displays in portuguese. For some of my websites it's impo ...
        </p></a>
      </li>

      <li rel="3">
        <a href="https://tiagomadeira.com/2012/11/e-books-devem-ampliar-nossa-liberdade-nao-reduzi-la/" title="E-books devem ampliar nossa liberdade, não reduzí-la">

        <h2>
          E-books devem ampliar nossa liberdade, não reduzí-la <span>(20/11/2012)</span>
        </h2>

        <p>
          Li o texto "E-books must increase our freedom, not decrease it" (de Richard Stallman) no boletim da Free Software Foundation de julho/2012. É sobre os livros digitais e os dispositivos (como o Kindle, da Amazon) que estamos usando para lê-los. O texto foi escrito especialmente para o jornal britânico The Guardian, ...
        </p></a>
      </li>

      <li rel="4">
        <a href="https://tiagomadeira.com/2014/09/script-para-baixar-documentos-do-issuu-no-gnulinux/" title="Script para baixar documentos do Issuu no GNU/Linux">

        <h2>
          Script para baixar documentos do Issuu no GNU/Linux <span>(26/09/2014)</span>
        </h2>

        <p>
          Tive necessidade de baixar um documento do Issuu. Segue um script simples que escrevi para baixar as páginas, convertê-las para PDF e mesclá-las. Ele não tem checagem de erros, mas pode ser útil para mais pessoas: #!/bin/bash if [ $# -lt 1 ]; then echo "Uso: $0 " exit fi tmp=$(mktemp -d) ech ...
        </p></a>
      </li>
    </ul>
  </div>
</div>

* * *

### Some screenshots

Here is a screenshot from [juntos.org.br][6] with `scale=true` (in the link you can see it working):

<img src="https://i1.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/ss1.jpg?resize=604%2C404" alt="" title="ss1" class="aligncenter size-full wp-image-967" srcset="https://i1.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/ss1.jpg?w=639&ssl=1 639w, https://i1.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/ss1.jpg?resize=300%2C200&ssl=1 300w" sizes="(max-width: 604px) 100vw, 604px" data-recalc-dims="1" />

And here is a screenshot from a fresh WordPress install (TwentyEleven theme without modifications):

<img src="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/01/ss2-650x345.jpg?resize=604%2C321" alt="" title="ss2" class="aligncenter size-large wp-image-968" data-recalc-dims="1" />

* * *

### Customizing

#### Post thumbnails

For better results, I suggest always adding post thumbnails to your posts and using [registered image sizes][7] in `image_width` and `image_height` attributes.

#### Styling retrospectives

The generated HTML is very easy to style (but just be careful with margins and paddings, they’re set with `!important` attribute — I did it to try not to break with any theme). Here is a sample:

```html4strict
<div id="retro-uniquehash" class="retrospective">
  <!-- TIMELINE -->


  <ul class="time">
    <li rel="0">
      <a href="permalink" style="left:0px;"><span>date</span></a>
    </li>


    <li rel="1">
      <a href="permalink" style="left:300px;"><span>date</span></a>
    </li>


    <li rel="2">
      <a href="permalink" style="left:600px;"><span>date</span></a>
    </li>

  </ul>



  <!-- PHOTOS -->


  <div class="photos">
    <ul>
      <li rel="0">
        <a href="permalink" title="title">
                        <img src="file" class="wp-post-image" /></a>
      </li>


      <li rel="1">
        <a href="permalink" title="title">
                        <img src="file" class="wp-post-image" /></a>
      </li>


      <li rel="2">
        <a href="permalink" title="title">
                        <img src="file" class="wp-post-image" /></a>
      </li>

    </ul>

  </div>



  <!-- POSTS -->


  <ul class="posts">
    <li rel="0">
      <a href="permalink" title="title">

      <h2>
        Title <span>(date)</span>
      </h2>


      <p>
        Excerpt
      </p></a>
    </li>


    <li rel="1">
      <a href="permalink" title="title">

      <h2>
        Title <span>(date)</span>
      </h2>


      <p>
        Excerpt
      </p></a>
    </li>


    <li rel="2">
      <a href="permalink" title="title">

      <h2>
        Title <span>(date)</span>
      </h2>


      <p>
        Excerpt
      </p></a>
    </li>

  </ul>

</div>
```

#### Styling a specific retrospective

The generated hash takes in consideration all the attributes sent to the shortcode and also how many retrospectives appeared before in the parsing of the actual page. I made it that way to allow users to set up two exactly equal retrospectives in the same page. Because of that, I don’t recommend setting styles for `#retro-uniquehash`. I think a reasonable solution for this issue is to make something like

```html4strict
<div id="something_that_makes_sense">
  <div id="retro-d5f52562788e36501e34423eb22d1c14" class="retrospective">
    <!-- TIMELINE -->


    <ul class="time">
      <li rel="0">
        <a href="https://tiagomadeira.com/2016/06/62-anos-da-morte-de-alan-turing/" style="left:0px;"><span>07/06/2016</span></a>
      </li>


      <li rel="1">
        <a href="https://tiagomadeira.com/2016/07/javier-toret-visita-porto-alegre/" style="left:66px;"><span>05/07/2016</span></a>
      </li>


      <li rel="2">
        <a href="https://tiagomadeira.com/2016/07/a-decisao-da-juiza-que-bloqueou-o-acesso-de-todo-pais-ao-whatsapp/" style="left:133px;"><span>19/07/2016</span></a>
      </li>


      <li rel="3">
        <a href="https://tiagomadeira.com/2016/08/luciana-genro-e-a-mais-citada-pelas-redes-sociais-durante-o-debate-da-radio-gaucha/" style="left:200px;"><span>16/08/2016</span></a>
      </li>


      <li rel="4">
        <a href="https://tiagomadeira.com/2016/11/discussao-sobre-noticias-falsas/" style="left:266px;"><span>15/11/2016</span></a>
      </li>


      <li rel="5">
        <a href="https://tiagomadeira.com/2017/03/year-zero/" style="left:333px;"><span>07/03/2017</span></a>
      </li>


      <li rel="6">
        <a href="https://tiagomadeira.com/2017/05/enredo-de-mr-robot/" style="left:400px;"><span>12/05/2017</span></a>
      </li>


      <li rel="7">
        <a href="https://tiagomadeira.com/2017/07/novo-site-da-revista-movimento/" style="left:466px;"><span>26/07/2017</span></a>
      </li>


      <li rel="8">
        <a href="https://tiagomadeira.com/2017/10/sobre-o-novo-ataque-krack-no-wpa/" style="left:533px;"><span>17/10/2017</span></a>
      </li>


      <li rel="9">
        <a href="https://tiagomadeira.com/2017/11/como-usar-ssh-quando-seu-roteador-bloqueia-que-voce-faca-conexoes-a-porta-22/" style="left:600px;"><span>25/11/2017</span></a>
      </li>


    </ul>


    <!-- PHOTOS -->


    <div class="photos">
      <ul>
        <li rel="0">
          <a href="https://tiagomadeira.com/2016/06/62-anos-da-morte-de-alan-turing/" title="62 anos da morte de Alan Turing"></a>
        </li>


        <li rel="1">
          <a href="https://tiagomadeira.com/2016/07/javier-toret-visita-porto-alegre/" title="Javier Toret visita Porto Alegre"></a>
        </li>


        <li rel="2">
          <a href="https://tiagomadeira.com/2016/07/a-decisao-da-juiza-que-bloqueou-o-acesso-de-todo-pais-ao-whatsapp/" title="A decisão da juíza que bloqueou o acesso de todo país ao WhatsApp"></a>
        </li>


        <li rel="3">
          <a href="https://tiagomadeira.com/2016/08/luciana-genro-e-a-mais-citada-pelas-redes-sociais-durante-o-debate-da-radio-gaucha/" title="Luciana Genro é a mais citada pelas redes sociais durante o debate da Rádio Gaúcha"></a>
        </li>


        <li rel="4">
          <a href="https://tiagomadeira.com/2016/11/discussao-sobre-noticias-falsas/" title="Discussão sobre notícias falsas"></a>
        </li>


        <li rel="5">
          <a href="https://tiagomadeira.com/2017/03/year-zero/" title="Year Zero"></a>
        </li>


        <li rel="6">
          <a href="https://tiagomadeira.com/2017/05/enredo-de-mr-robot/" title="Enredo de Mr. Robot"></a>
        </li>


        <li rel="7">
          <a href="https://tiagomadeira.com/2017/07/novo-site-da-revista-movimento/" title="Novo site da Revista Movimento"></a>
        </li>


        <li rel="8">
          <a href="https://tiagomadeira.com/2017/10/sobre-o-novo-ataque-krack-no-wpa/" title="Sobre o novo ataque (KRACK) no WPA"></a>
        </li>


        <li rel="9">
          <a href="https://tiagomadeira.com/2017/11/como-usar-ssh-quando-seu-roteador-bloqueia-que-voce-faca-conexoes-a-porta-22/" title="Como usar SSH quando seu roteador bloqueia que você faça conexões à porta 22"></a>
        </li>


      </ul>

    </div>


    <!-- POSTS -->


    <ul class="posts">
      <li rel="0">
        <a href="https://tiagomadeira.com/2016/06/62-anos-da-morte-de-alan-turing/" title="62 anos da morte de Alan Turing">

        <h2>
          62 anos da morte de Alan Turing <span>(07/06/2016)</span>
        </h2>

        <p>
          Hoje completa 62 anos a morte de Alan Turing, personagem fundamental da história da computação e um dos maiores gênios do século XX.

          Turing formalizou os conceitos de "algoritmo" e "computação" ao criar a máquina universal abstrata que serve de modelo para nossos computadores digitais.

          Além disso, inaugu ...
        </p></a>
      </li>


      <li rel="1">
        <a href="https://tiagomadeira.com/2016/07/javier-toret-visita-porto-alegre/" title="Javier Toret visita Porto Alegre">

        <h2>
          Javier Toret visita Porto Alegre <span>(05/07/2016)</span>
        </h2>

        <p>
          Obrigado pela visita a Porto Alegre e pelo intercâmbio de idéias, Toret!

          [caption id="attachment_3011" align="aligncenter" width="604"] Com Javier Toret no Café República, em Porto Alegre[/caption] ...
        </p></a>
      </li>


      <li rel="2">
        <a href="https://tiagomadeira.com/2016/07/a-decisao-da-juiza-que-bloqueou-o-acesso-de-todo-pais-ao-whatsapp/" title="A decisão da juíza que bloqueou o acesso de todo país ao WhatsApp">

        <h2>
          A decisão da juíza que bloqueou o acesso de todo país ao WhatsApp <span>(19/07/2016)</span>
        </h2>

        <p>
          A decisão da juíza que bloqueou o acesso de todo país ao WhatsApp é uma ameaça à nossa segurança.

          Segundo o G1, ela pede que o Facebook implemente um backdoor para que mensagens sejam passadas para a justiça em tempo real ou que use algoritmos mais fracos que possam ser quebrados.

          Argumenta que "se as dec ...
        </p></a>
      </li>


      <li rel="3">
        <a href="https://tiagomadeira.com/2016/08/luciana-genro-e-a-mais-citada-pelas-redes-sociais-durante-o-debate-da-radio-gaucha/" title="Luciana Genro é a mais citada pelas redes sociais durante o debate da Rádio Gaúcha">

        <h2>
          Luciana Genro é a mais citada pelas redes sociais durante o debate da Rádio Gaúcha <span>(16/08/2016)</span>
        </h2>

        <p>
          [caption id="attachment_3007" align="aligncenter" width="595"] Grafo montado a partir de interações (respostas e retuítes) entre usuários no Twitter durante o debate da Rádio Gaúcha.[/caption]

          Luciana Genro venceu o primeiro debate no rádio e nas redes. Foi a candidata mais eloquente, mostrou algumas proposta ...
        </p></a>
      </li>


      <li rel="4">
        <a href="https://tiagomadeira.com/2016/11/discussao-sobre-noticias-falsas/" title="Discussão sobre notícias falsas">

        <h2>
          Discussão sobre notícias falsas <span>(15/11/2016)</span>
        </h2>

        <p>
          As eleições municipais no Brasil foram repletas de boatos contra as candidaturas do PSOL.

          Luciana Genro foi atacada o tempo todo por compartilhamentos de notícias falsas que a acusavam de todo tipo de absurdo. Marcelo Freixo chegou até a ter que lançar um site "A Verdade sobre Freixo" devido à enorme quantidad ...
        </p></a>
      </li>


      <li rel="5">
        <a href="https://tiagomadeira.com/2017/03/year-zero/" title="Year Zero">

        <h2>
          Year Zero <span>(07/03/2017)</span>
        </h2>

        <p>
          Hoje de manhã o WikiLeaks começou a publicar a maior série de vazamentos da CIA da história, "Vault 7".

          A primeira parte, publicada hoje, se chama "Year Zero" e tem 8761 documentos da divisão hacker da CIA: mais páginas do que todos os vazamentos de Snowden sobre a NSA publicados desde 2013.

          Como diz o rele ...
        </p></a>
      </li>


      <li rel="6">
        <a href="https://tiagomadeira.com/2017/05/enredo-de-mr-robot/" title="Enredo de Mr. Robot">

        <h2>
          Enredo de Mr. Robot <span>(12/05/2017)</span>
        </h2>

        <p>
          Um ransomware comprometeu mais de 45 mil computadores em 74 países, e o número não para de crescer. As redes do NHS (sistema de saúde britânico) e da Telefónica (multinacional espanhola) estão entre as atingidas de forma mais pesada.

          O ataque, chamado #WannaCry, é baseado no exploit EternalBlue que apareceu  ...
        </p></a>
      </li>


      <li rel="7">
        <a href="https://tiagomadeira.com/2017/07/novo-site-da-revista-movimento/" title="Novo site da Revista Movimento">

        <h2>
          Novo site da Revista Movimento <span>(26/07/2017)</span>
        </h2>

        <p>
          No dia 11/7 lançamos o site da Revista Movimento, um desenho da Adria Meira que implementei em cima do WordPress. Como pode ser lido na página Sobre, a Revista Movimento é uma publicação teórico-política orientada para o debate de ideias entre os socialistas, a elaboração programática e a ação política. [. ...
        </p></a>
      </li>


      <li rel="8">
        <a href="https://tiagomadeira.com/2017/10/sobre-o-novo-ataque-krack-no-wpa/" title="Sobre o novo ataque (KRACK) no WPA">

        <h2>
          Sobre o novo ataque (KRACK) no WPA <span>(17/10/2017)</span>
        </h2>

        <p>
          O interessante ataque KRACK mostra uma falha grave no WPA, protocolo de segurança para redes sem fio usado em toda parte -- e que segue sendo o mais seguro que temos disponível, mesmo depois desse ataque.

          Bruce Schneier definiu o ataque como brilhante: "embora a vulnerabilidade seja óbvia depois que alguém apont ...
        </p></a>
      </li>


      <li rel="9">
        <a href="https://tiagomadeira.com/2017/11/como-usar-ssh-quando-seu-roteador-bloqueia-que-voce-faca-conexoes-a-porta-22/" title="Como usar SSH quando seu roteador bloqueia que você faça conexões à porta 22">

        <h2>
          Como usar SSH quando seu roteador bloqueia que você faça conexões à porta 22 <span>(25/11/2017)</span>
        </h2>

        <p>
          Alguns roteadores distribuídos pela NET (como alguns da marca TechniColor, mas possivelmente outros) estão bloqueando conexões para a porta 22, o que atrapalha bastante quem precisa fazer conexões via SSH.

          A solução óbvia para o problema seria reconfigurar o roteador. Porém, a NET parece estar dificultando c ...
        </p></a>
      </li>


    </ul>

  </div>

</div>
```

when inserting the shortcode and then styling `#something_that_makes_sense .retrospective`.

* * *

### Download

**Here is the code for download:*** [retrospective.zip][8]

<small><strong>* Warning:</strong> Please consider I’m using a <a href="http://catb.org/~esr/writings/homesteading/">bazaar approach</a> here. Be aware that the plugin probably has a lot of bugs (and please tell me if you catch any).</small>

I hope you enjoy it. Have fun and please let me have your feedback! :)

 [1]: https://wordpress.org/extend/plugins/add/
 [2]: https://wordpress.org/extend/plugins/retrospective/
 [3]: http://tiagomadeira.com/wp-content/uploads/2012/01/estadao.jpg
 [4]: http://www.estadao.com.br/especiais/choque-nas-ruas,158638.htm
 [5]: http://php.net/date
 [6]: http://juntos.org.br/juntos/internet/
 [7]: https://codex.wordpress.org/Function_Reference/add_image_size
 [8]: http://tiagomadeira.com/wp-content/uploads/2012/01/retrospective.zip

