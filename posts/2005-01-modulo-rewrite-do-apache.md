---
title: Módulo Rewrite do Apache
date: 2005-01-31T11:59:02+00:00
excerpt: Uma forma bem legal de organizar a estrutura de uma página...
url: /2005/01/modulo-rewrite-do-apache/
tags:
  - apache
  - metablogagem
  - rewrite
  - web
---

Como sempre por acaso, encontrei a “solução” para o desaparecimento de meu site no Google e uma forma muito legal de organizar os links do site. Descobri o módulo ReWrite do Apache! É uma coisa super legal que usa expressões regulares pra fazer redirecionamentos direto no .htaccess. Usando as simples regras abaixo:

```apache
RewriteEngine On

RewriteRule ^link/(.+)$ http://tableless.tiagomadeira.net/index.php?l=$1
RewriteRule ^post/([0-9]+)$ http://tableless.tiagomadeira.net/index.php?l=artigo&id=$1
RewriteRule ^script/(.+)$ http://tableless.tiagomadeira.net/index.php?l=script&script=$1
```

… estou com um site com endereços bem mais fáceis e bem mais simples (além de mais seguro se eu não tivesse colocado as regras aqui).

Achei bem interessante esse método de expressões regulares e acho que asism o site parece mais “organizado” pois os links ficam mais fáceis.
