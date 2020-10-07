---
title: Como ler documentos do Scribd
date: 2013-08-17T15:33:04+00:00
url: /2013/08/como-ler-documentos-do-scribd/
tags:
  - códigos
  - computação
  - firefox
  - internet
  - javascript
  - paywall
  - programação
---

<span class="embed-youtube" style="text-align:center; display: block;"></span>

Depois de ouvir esse improviso do André Mehmari sobre Odeon e Choro pro Zé, fiquei com vontade de encontrar a partitura desse belo choro do Guinga. Porém, descobri que infelizmente [é extremamente difícil encontrar][1] o songbook “A música de Guinga”.

Procurando na rede, encontrei [um torrent][2] com um PDF com qualidade ruim e um [documento do Scribd][3] com qualidade boa. O problema é que o Scribd tem um [paywall][4] para não deixar as pessoas baixarem ou lerem os documentos que seus usuários colocam lá:

![Paywall do Scribd.](/wp-content/uploads/2013/08/free-preview-650x468.png)

Percebi que ele passa todas as imagens corretamente para o navegador e só no lado do cliente muda a opacidade das páginas para elas ficarem semitransparentes. Então escrevi um _userscript_ bem simples (usando [jQuery][6] por comodidade) para o [Greasemonkey][7] (uma dessas extensões indispensáveis do Firefox) para recuperar a opacidade das páginas do texto e, se necessário, remover essa mensagem “You’re reading a free preview”.

```javascript
// ==UserScript==
// @name Suppress Scribd Paywall
// @include http://*.scribd.com/doc/*
// @require http://code.jquery.com/jquery-2.0.3.min.js
// ==/UserScript==

(function ($) {
  $(document).ready(function () {
    window.setInterval(function () {
      $(".absimg").css("opacity", "1");
    }, 1000);
    $(".autogen_class_views_read_show_page_blur_promo").on("click", function (
      e
    ) {
      $(this).hide();
    });
  });
})(jQuery);
```

Para usar, é só instalar o Greasemonkey no Firefox e depois [baixar o userscript scribd.user.js][8]. Resultado:

![Partitura da música Choro pro Zé no songbook do Guinga no Scribd.](/wp-content/uploads/2013/08/choro-pro-ze-650x532.png)

[1]: http://www.violao.org/topic/6896-songbook-a-musica-de-guinga/
[2]: https://torrentz.eu/efd777a6a64d1dd7e53f358e388a6409925f5af6
[3]: http://pt.scribd.com/doc/47928303/Songbook-A-Musica-de-Guinga
[4]: /2013/07/como-ler-noticias-ilimitadas-de-folha-estadao-e-globo-sem-cadastro/
[6]: http://jquery.com/
[7]: https://addons.mozilla.org/en-US/firefox/addon/greasemonkey/
[8]: /wp-content/uploads/2013/08/scribd.user.js
