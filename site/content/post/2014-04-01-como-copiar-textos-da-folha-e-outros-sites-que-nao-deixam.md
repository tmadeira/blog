---
title: Como copiar textos da Folha e outros sites que não deixam
type: post
date: 2014-04-01T16:51:59+00:00
url: /2014/04/como-copiar-textos-da-folha-e-outros-sites-que-nao-deixam/
featured_image: /wp-content/uploads/2014/04/folha-300x180.jpg
categories:
  - Dicas
tags:
  - códigos
  - computação
  - firefox
  - internet
  - javascript
  - programação
  - scripts
  - Software Livre

---
Alguns sites começaram a abusar de um recurso super interessante do JavaScript para acabar com uma das características mais importantes da Internet: **a capacidade de copiar/colar**.

O tratamento dos _clipboard events_ (`oncut`, `oncopy` e `onpaste`) deveria servir para permitir que os programadores façam coisas legais quando você copia/cola um texto (por exemplo, um processador de textos online pode inserir/remover formatação), mas tenho visto cada vez mais ele ser usado para [adicionar uma mensagem de _copyright_ no final de um texto copiado][1], impedir usuários leigos de copiarem textos na web e evitar que se cole coisas que você copiou em formulários.

O que mais me incomoda (e que me levou a escrever esta postagem) é que, hoje, quem copia um trecho de uma reportagem da Folha (para guardar, compartilhar numa rede social ou o que quer que seja) acaba colando:

> Para compartilhar esse conteúdo, por favor utilize o link http://www1.folha.uol.com.br/fsp/bla-bla-bla ou as ferramentas oferecidas na página. Textos, fotos, artes e vídeos da Folha estão protegidos pela legislação brasileira sobre direito autoral. Não reproduza o conteúdo do jornal em qualquer meio de comunicação, eletrônico ou impresso, sem autorização da Folhapress (pesquisa@folhapress.com.br). As regras têm como objetivo proteger o investimento que a Folha faz na qualidade de seu jornalismo. Se precisa copiar trecho de texto da Folha para uso privado, por favor logue-se como assinante ou cadastrado.

Não é incrível (e sintomático) que o grupo que gerencia o portal mais importante da Internet no Brasil (UOL) tenha uma concepção tão atrasada da rede? Ok, não dá nem pra dizer que isso nos surpreende depois da [censura da Falha][2] e do [paywall][3].

Sem mais delongas: isso merece ser hackeado. Neste post, proponho algumas soluções simples para você poder voltar a copiar e colar no seu navegador como sempre fez. Minha preferida, como sempre, é a última.

### Solução trivial para quem usa Linux

Antes de sugerir soluções _de verdade_, convém observar que quem usa Linux (X11) pode copiar selecionando um texto (sem apertar `Ctrl+C` ou qualquer outra combinação esdrúxula de teclas) e colar apertando o botão do meio do mouse. Quando se copia/cola dessa forma, o navegador não emite os temidos eventos `oncopy`/`onpaste` (ou seja, tudo funciona normalmente).

[Rodolfo Mohr][4] também observou que você pode copiar um texto selecionando-o, clicando com a tecla direita na seleção e em _“Pesquisar no Google”_. Uma aba vai abrir com a pesquisa no Google e você pode copiar o texto lá. É um _hack_ válido, embora incômodo.

### Somente Firefox: usando _about:config_

Se você usa Firefox, pode desabilitar os _clipboard events_ digitando, na barra de endereços, em `about:config`. Talvez ele diga que é perigoso e peça para você clicar num botão dizendo que sabe o que está fazendo. Pode confiar. Em seguida, procure a chave _dom.event.clipboardevents.enabled_ e clique duas vezes nela para mudar seu valor para _false_. Reiniciando o navegador, o recurso copiar/colar estará funcionando normalmente (ou talvez nem precise reiniciá-lo).

### Extensões (para Firefox<del>, Chrome</del> e Opera)

Não tem o que explicar. Simplesmente clique no nome do seu navegador e instale: [Firefox][5], <del><a href="https://chrome.google.com/webstore/detail/unblock-clipboard-interac/ojbadajhjbjecoojjkoddhnbobjgleib">Chrome</a></del>, [Opera][6].

<small><strong>Editado em 01/04/2014, 22:30:</strong> A extensão que eu havia colocado para Chrome só desabilita o tratamento de eventos `onpaste` em formulários. Se você conhecer alguma extensão similar a do Firefox ou a do Opera, me avise pelos comentários.</small>

### Desabilitando sob demanda via JavaScript

É muito importante ter em mente que aplicações web como processadores de texto podem usar os eventos `oncut`/`oncopy`/`onpaste` para coisas úteis. Por isso, é desejável desabilitar esses eventos somente em sites específicos.

Não encontrei nenhuma extensão que faça isso, mas um código simples em JavaScript para recuperar o comportamento padrão dos eventos em um determinado site (testei no Firefox e no Chrome) é:

```javascript
all = document.querySelectorAll("*");
fn = function(e) {
    e.stopPropagation();
    return true;
}
for (var i = 0; i < all.length; i++) {
    all[i].oncut = fn;
    all[i].oncopy = fn;
    all[i].onpaste = fn;
}
```

Se digitarmos isso no console (`Shift+Ctrl+J`), as funções copiar/colar devem voltar a funcionar.

### Userscript

A solução anterior nos permite criar um _userscript_ para desabilitar o tratamento dos eventos apenas no site da Folha:

```javascript
// ==UserScript==
// @name Permite copiar textos da Folha
// @include http://*.folha.uol.com.br/*
// ==/UserScript==

window.onload = function() {
    all = document.querySelectorAll("*");
    fn = function(e) {
        e.stopPropagation();
        return true;
    }
    for (var i = 0; i < all.length; i++) {
        all[i].oncut = fn;
        all[i].oncopy = fn;
        all[i].onpaste = fn;
    }
}

```

Portanto, se você quiser copiar do site da Folha sem preocupações (e sem desabilitar os eventos em outros sites), pode instalar as extensões [GreaseMonkey][7] (Firefox) ou [TamperMonkey][8] (Chrome), e então esse _userscript_ clicando neste link: [falha.user.js][9].

### Bookmarlet

Acho o método acima (do _userscript_) o melhor para copiar da Folha. No entanto, é conveniente ter um método mais genérico. Por isso, criei um _bookmarklet_, isso é, um pequeno script que podemos executar clicando num botão na barra de favoritos (neste caso, para restaurar o comportamento padrão das funções copiar/colar).

Aqui está ele: <a href="javascript:all=document.querySelectorAll('*');for(i=0;i<all.length;i++)all[i].oncopy=function(e){e.stopPropagation();return true};void(0)">Restaurar copiar/colar</a>

Para instalar, arraste esse link para sua barra de favoritos. Para usar, clique sempre que precisar copiar um texto e então copie normalmente.

Viva a Internet!

 [1]: http://bavotasan.com/2010/add-a-copyright-notice-to-copied-text/
 [2]: http://desculpeanossafalha.com.br/
 [3]: /2013/07/como-ler-noticias-ilimitadas-de-folha-estadao-e-globo-sem-cadastro/
 [4]: http://rodomundo.juntos.org.br/
 [5]: http://addons.mozilla.org/en-us/firefox/addon/nocopypaste/
 [6]: https://addons.opera.com/en-gb/extensions/details/clipboard-event-blocker/?display=en
 [7]: https://addons.mozilla.org/en-US/firefox/addon/greasemonkey/
 [8]: https://chrome.google.com/webstore/detail/tampermonkey/dhdgffkkebhmkfjojejmpbldmpobfkfo?hl=en
 [9]: /wp-content/uploads/2014/04/falha.user.js
