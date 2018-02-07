---
title: Only variables can be passed by reference
type: post
date: 2005-09-16T19:31:00+00:00
excerpt: Instalei o PHP 5.0.5 e para minha surpresa recebi vários erros! Que história é essa de "Only variables can be passed by reference"?
url: /2005/09/only-variables-can-be-passed-by-reference/
categorias:
  - Futilidades
tags:
  - bug
  - php

---
Instalei o **PHP 5.0.5** no servidor do Colégio Salesiano na semana passada. E descobri que criaram um novo erro agora (do tipo fatal) para quando eu passo uma função como argumento de outra. _“Fatal Error: Only variables can be passed by reference”_. Bom… Uma função nada mais é que uma variável, afinal é pra isso que serve o seu retorno. Mas agora o PHP nos força, por exemplo, a fazer:

```php
<?php
$variavel2=str_replace("a", "b", $variavel);
$variavel3=funcao($variavel2);
?>
```

… ao invés de fazer como eu sempre fiz para economizar linhas:

```php
<?php
$variavel3=funcao(str_replace("a", "b", $variavel));
?>
```

Realmente não entendi o porquê da mudança. Pra mim tava muito bom do jeito anterior… E não sou só eu que faço isso. Os caras que fizeram o phpBB também passaram várias vezes funções como argumentos de outras e isso fez com que eu perdesse algum tempo hoje trocando todos as funções dessa maneira que mostrei acima no fórum do Colégio…

Alguém entende esses caras?

