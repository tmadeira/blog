---
title: LiveSearch no WordPress
type: post
date: 2006-01-04T01:03:13+00:00
excerpt: Aprenda a usar uma busca dinâmica no seu Wordpress utilizando Ajax...
url: /2006/01/livesearch-no-wordpress/
categories:
  - Códigos aleatórios
tags:
  - ajax
  - códigos
  - css
  - javascript
  - livresearch
  - php
  - scripts
  - wordpress

---
O [Cosme][1] me apresentou hoje um projeto chamado [LiveSearch][2]. É uma aplicação Ajax bem simples (eu mesmo conseguiria fazer), mas uma idéia que eu ainda não havia tido.

Resolvi então implementar o negócio no meu blog e estou escrevendo esse artigo pra explicar como instalamos o LiveSearch de forma que ele funcione com o WordPress e dentro dos padrões de XHTML Strict (ele pede originalmente que utilizamos **name** num **form** e exige que o nome de um campo seja “q” ao invés do “s” do WordPress).

Então, mãos a obra!

### 1. livesearch.php

Para começar, você deve criar um arquivo e chamá-lo **livesearch.php**. O seu conteúdo deve ser:

```php
<?php if (have_posts()) : ?>


<ul class="LSRes">
  <?php while (have_posts()) : the_post(); ?>


  <li class="LSRow">
    <a href="<?php the_permalink(); ?>"><?php the_title(); ?></a>

  </li>


  <?php endwhile; ?>

</ul>


<?php endif; ?>
```

Para facilitar para quem quer aprender PHP, vou explicar linha por linha:

  1. <span style="color:red;">Se houver posts, faça:</span>
  2. <span style="color:blue;">Lista HTML</span>
  3. <span style="color:green;">Enquanto houver posts: Execute a função the_post().</span>
  4. <span style="color:orange;">Item da Lista HTML</span>
  5. Linca para o permalink do post com o texto do link = seu título.
  6. <span style="color:orange;">Fim do “Item da Lista HTML”</span>
  7. <span style="color:green;">Fim do “Enquanto houver posts”</span>
  8. <span style="color:blue;">Fim da “Lista HTML”</span>
  9. <span style="color:red;">Fim do “Se houver posts”</span>

<p style="font-size:11px; font-style:italic;">
  <strong>Observação:</strong> As cores são só para reforçar a hierarquia.
</p>

O que este arquivo faz, portanto, é criar uma lista com o título dos posts. Essas funções são todas do WordPress (have\_posts, the\_title, the_permalink, etc.). Se você quisesse colocar outras coisas na lista que vai aparecer no resultado, pode colocar aí nesse arquivo.

No fim, salve esse arquivo em **/wp-content/themes/SEU_TEMA/livesearch.php**.

### 2. Redirecionar para livesearch.php se for uma pesquisa “live”

Coloque no início do arquivo **/wp-content/themes/SEU_TEMA/search.php** o seguinte conteúdo:

```php
<?php if ($_GET["live"]) {
		include("livesearch.php");
		die();
	} ?>
```

  1. <span style="color:red;">Se a query string <strong>live</strong> “existir”, faça:</span>
  2. Inclua o arqiuvo **livesearch.php** nessa página.
  3. Morra!!! :D Isso significa para ele parar de executar qualquer coisa que esteja debaixo disso.
  4. <span style="color:red;">Fim do “Se”</span>

Isso serve para que possamos fazer as buscas de duas maneiras. Uma é a busca normal, que é acessada por **/?s=queries** e outra é a live que será acessada por **/?live=1&s=queries** (ou seja, a mesma coisa mas dando valor à variável “live”).

### 3. JavaScripts

Baixe o arquivo [livesearch.js][3] e coloque-o na pasta **/wp-content/themes/SEU_TEMA/**.

Agora faremos uma série de mudanças pra manter o negócio nos padrões web… Substitua as seguintes linhas pelo texto que aparece depois do seu número:

  * 122: if (liveSearchLast != document.getElementBy(‘livesearch’).value) {
  * 126: if ( document.getElementById(‘livesearch’).value == “”) {
  * 136: liveSearchReq.open(“GET”, liveSearchRoot + “/?live=1&s=” + document.getElementById(‘livesearch’).value + liveSearchParams2);
  * 137: livesearchLast = document.getElementById(“livesearch”).value;

Isso serve para ele não depender do nome do formulário e da query, mas somente do ID do campo do formulário e para ele abrir no xmlHttpRequest _/?live=1&s=QUERY_ ao invés do padrão _/livesearch.php?q=QUERY_.

### 4. Eventos JavaScript nos documentos

No seu arquivo **/wp-content/themes/SEU_TEMA/header.php**, adicione o evento **onload** à tag _BODY_:

```
<body onload="liveSearchInit()">
```

No mesmo arquivo, dentro da tag _HEAD_ linke para o script:

```
<script type="text/javascript" src="/wp-content/themes/SEUTEMA/livesearch.js"></script>
```

Agora, no arquivo **/wp-content/themes/SEU_TEMA/searchform.php**, adicione um evento **onsubmit** ao _FORM_

```
<form onsubmit="return liveSearchSubmit()" ...
```

E, no mesmo arquivo, adicione um evento **onKeyPress** ao _INPUT_ e também um **id**:

```
<input id="livesearch" onKeyPress="liveSearchStart();"
```

E ao final desse arquivo, coloque:

```
<div id="LSResult" style="display: none;">
<div id="LSShadow">
</div>
</div>
```

Se você fez tudo certo e eu não errei aqui no tutorial, o seu script deve sair funcionando! Agora personalize usando estilos pra fazer um negócio bonito! (algo que eu não fiz porque tô pra trocar totalmente o design do meu site)

* * *

### A Lógica do Negócio

O arquivo **search.php** recebe todas as buscas. O que eu fiz criando o **livesearch.php** foi formatar o resultado da busca de forma diferente para ele aparecer ali debaixo do formulário de busca.

O script é bem simples. Um Ajax que simplesmente faz um xmlHttpRequest a cada _keypress_ do cara no campo. Aliás, acho que dá pra fazer um script bem menor pra só fazer isso.

Deixei o meu site meio feio com isso aí (uma lista de bullets normais e tal…), mas é porque eu tô pra trocar o design em breve e aí vou arrumar isso tudo! (inclusive, devo colocar mais Ajax!)

Qualquer dúvida, comente ou me mande um e-mail.

 [1]: http://www.cosmeweb.com.br
 [2]: http://blog.bitflux.ch/wiki/LiveSearch
 [3]: http://blog.bitflux.ch/livesearch.js

