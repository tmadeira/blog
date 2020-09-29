---
title: Novo site do Colégio!
type: post
date: 2005-09-20T21:36:28+00:00
excerpt: Publiquei hoje o novo site do Colégio Salesiano, um site tableless totalmente administrável que usa a linguagem PHP e o banco de dados MySql.
url: /2005/09/novo-site-do-colegio/
categorias:
  - Cotidiano
tags:
  - expressões regulares
  - greasemonkey
  - javascript
  - mysql
  - php
  - regex
  - salesiano
  - Trabalho
---

Publiquei hoje o novo site do **Colégio Salesiano Itajaí**, um site totalmente administrável (até o título pode ser mudado via formulários) que usa a linguagem PHP e o banco de dados MySql. O site também segue os padrões web, mesmo com formulários rich text que às vezes deixam o site pouco semântico (é que os monitores do Colégio devem poder atualizar) e está disponível em: [salesianoitajai.g12.br][1].

A notícia de estréia da página está disponível [aqui][2] e conta com um lindo screenshot do meu Fluxbox com Mrxvt e o Vim com três splits. Embora o site já esteja publicado, ainda tenho que arrumar alguns detalhes como por exemplo o Sitemap que eu cito nesta notícia.

Uma coisa bem legal que eu coloquei no site foi um JavaScript, usando a função addGlobalStyle do **Dive into Greasemonkey**, que nos Mozillas _(ereg(“Gecko/”, \$\_SERVER[“HTTP\_USER_AGENT”]))_ faz o site ficar maior se o usuário usar uma resolução igual ou maior a 1024×768. Dá pra fazer pra todos os navegadores, mas eu sou meio newbie em JavaScript e por isso só usei esse código do Greasemonkey, que só funciona nos Mozillas mesmo… Mas o resultado ficou ótimo! :)

Ontem o Sr. Paulo Matias me ensinou como trabalhar com operadores bit-a-bit no C. Achei muito massa! Agora comecei até a economizar fazendo:

```c
numero = outronumero << 1;
```

... ao invés de simplesmente:

```c
numero = outronumero * 2;
```

... para meus programas serem mais rápidos! Hehehe :D Fiz uma função que converte de decimal para binário, e depois vou postar aqui.

<p style="font-size:11px; font-style:italic;">
  <strong>Observação:</strong> Tenho que descobrir porque os emoticons não funcionam quando tem código... Quer dizer, descobrir eu já descobri, mas preciso ver como eu faço pra resolver de forma boa essas expressões regulares...
</p>

### Editado!

Corrigi o problema... Confira abaixo o novo trecho de ERs da função de emoticons, onde **\$o** é o vetor de origem (com as carinhas originais), **\$d** é o vetor de desgino (com o <img src...) e **replace()** é uma função que eu criei para substituir os emoticons:

```php
<?php
if (!ereg("<code", $texto)) {
	$texto=replace($o, $d, $texto);
} else {
	preg_match_all("/</code>(.+)<code/sU", $texto, $mat1);
	for ($i=0; $i<sizeof($mat1[1]); $i++) {
		$texto=str_replace($mat1[1][$i], replace($o, $d, $mat1[1][$i]), $texto);
	}
	preg_match("/^(.+)<code/sU", $texto, $mat2);
	$texto=str_replace($mat2[1], replace($o, $d, $mat2[1]), $texto);
	$rev=strrev($texto); //Tenho medo do PHP5.0.5
	preg_match("/^(.+)>edoc/</sU", $rev, $mat3); //Nossa, que código louco!
	$rev=strrev($mat3[1]); //Repito... Tenho medo do PHP5.0.5
	$texto=str_replace($rev, replace($o, $d, $rev), $texto);
}
?>
```

Ficou _feio_, né? Não consegui pensar em outra coisa mais fácil que usar o **strrev()** ali... :blink:

[1]: http://www.salesianoitajai.g12.br
[2]: http://www.salesianoitajai.g12.br/?sp=vernoticia&id=31
