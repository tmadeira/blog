---
title: 'PHP: Array de Caracteres != String'
type: post
date: 2006-01-02T13:31:15+00:00
excerpt: 'Já não é a primeira vez que eu vou fazer uma aplicação em PHP e quero usar uma função de arrays numa string. Como um bom dicípulo da linguagem C, aprendi que uma string é um array de chars. O PHP tenta fazer algo parecido com isso, aceitando que possamos acessar caracteres da string com $string[indice]; porém, não sei por quê, não podemos usar funções de array nas strings e vice-versa.'
url: /2006/01/php-array-de-caracteres-string/
categorias:
  - Pensamentos aleatórios
tags:
  - arrays
  - bug
  - char
  - php
  - shuffle
  - strings

---
Já não é a primeira vez que eu vou fazer uma aplicação em PHP e quero usar uma função de arrays numa string. Como um bom dicípulo da linguagem C, aprendi que uma string é um array de chars. O PHP tenta fazer algo parecido com isso, aceitando que possamos acessar caracteres da string com $string[indice]; porém, não sei por quê, não podemos usar funções de array nas strings e vice-versa.

Vamos supor que eu queira fazer algo simples: usar a função [shuffle()][1] numa string (criar um anagrama qualquer de uma string). Aí o PHP me força a fazer isso aqui:

```php
<?php
        $mensagem="anagrama";
        $array=Array();
        for ($i=0; $i<strlen($mensagem); $i++) {
                $array[]=$mensagem[$i];
        }
        shuffle($array);
        $mensagem="";
        for ($i=0; $i<count($array); $i++) {
                $mensagem.=$array[$i];
        }
?>
```

Pô… É um código muito feio! Quer dizer… Se o C tivesse a função **shuffle()** (ou o PHP “soubesse” que strings não passam de array de chars), bastaria fazer:

```php
<?php
$mensagem="anagrama";
shuffle($mensagem);
?>
```

Economia de cérebro, de banda, de código, de dedos… De tudo!

Então, cheguei a conclusão de que eu é que devo estar entendendo algo errado. Alguém conhece uma maneira do PHP tratar strings como arrays? Andei procurando no manual e achei a função [settype()][2], mas ela não faz o que eu quero, porque converte uma string para um array de strings!

 [1]: http://www.php.net/shuffle
 [2]: http://www.php.net/settype

