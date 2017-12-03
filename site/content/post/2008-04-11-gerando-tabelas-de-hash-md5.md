---
title: Gerando tabelas de hash MD5
type: post
date: 2008-04-11T03:26:24+00:00
url: /2008/04/gerando-tabelas-de-hash-md5/
categories:
  - Códigos aleatórios
tags:
  - c
  - hash
  - hash tables
  - md5
  - openssl
  - php
  - ruby
  - sha
  - tabelas

---
A idéia veio do nada. Na verdade, eu estava fazendo um freelance e procurando uma função pra “ordenar” um vetor aleatoriamente no PHP (no fim usei `usort`, que recebe uma função de comparação tipo o `qsort` do C) e me deparei com um comentário lá no [PHP.net][1] de um cara que usou geração de números aleatórios para criar um algoritmo de criptografia pra usar no lugar de MD5 e SHA, porque ele não confiava mais no MD5 e no SHA porque segundo ele existem tabelas na internet, o que torna um sistema muito vulnerável (para quem tem acesso ao banco de dados).

Procurei na internet e na verdade eu não encontrei muitos bancos de dados com vários MD5 não, ao menos não visíveis no Google quando se procura por um hash. Só pra strings como “1234”, mas não achei nem pra “060790” (minha data de nascimento). Veja você mesmo: [81811b48cc07432fc550cb42d4ab3e8f][2]

Então pensei: são 31 dias por mês, 12 meses por ano, 100 anos considerando que os anos são representados por dois dígitos. Isso me dá 31 x 12 x 100 = apenas 37200 hashes. O custo pra gerar isso deve ser minúsculo, por que ninguém faz?

A idéia de fazer com essas datas de nascimento veio do fato de vários usuários leigos que conheço utilizarem data de nascimento pra suas senhas (muito também pelo fato de eles usarem essa mesma senha nas senhas de seis dígitos numéricos do banco e esse tipo de coisa). Então lá fui eu pro código. A princípio escrevi em cerca de 30 segundos – 1 minuto o seguinte código em Ruby:

<pre class="ruby"><span style="color: rgb(204, 0, 102); font-weight: bold;">require</span> <span style="color: rgb(153, 102, 0);">"md5"</span>
 
<span style="color: rgb(0, 102, 102);">100</span>.<span style="color: rgb(153, 0, 204);">times</span> <span style="color: rgb(153, 102, 204); font-weight: bold;">do</span> |ano|
        <span style="color: rgb(0, 102, 102);">12</span>.<span style="color: rgb(153, 0, 204);">times</span> <span style="color: rgb(153, 102, 204); font-weight: bold;">do</span> |j|
                mes = j<span style="color: rgb(0, 102, 102);">+1</span>

                <span style="color: rgb(0, 102, 102);">31</span>.<span style="color: rgb(153, 0, 204);">times</span> <span style="color: rgb(153, 102, 204); font-weight: bold;">do</span> |i|
                        dia = i<span style="color: rgb(0, 102, 102);">+1</span>
                        <span style="color: rgb(204, 0, 102); font-weight: bold;">string</span> = <span style="color: rgb(204, 0, 102); font-weight: bold;">sprintf</span><span style="color: rgb(0, 102, 0); font-weight: bold;">(</span><span style="color: rgb(153, 102, 0);">"%02d%02d%02d"</span>, dia, mes, ano<span style="color: rgb(0, 102, 0); font-weight: bold;">)</span>

                        md5 = MD5.<span style="color: rgb(153, 0, 204);">new</span><span style="color: rgb(0, 102, 0); font-weight: bold;">(</span><span style="color: rgb(204, 0, 102); font-weight: bold;">string</span><span style="color: rgb(0, 102, 0); font-weight: bold;">)</span>.<span style="color: rgb(153, 0, 204);">to_s</span>
                        <span style="color: rgb(204, 0, 102); font-weight: bold;">puts</span> <span style="color: rgb(153, 102, 0);">"#{string}: #{md5}"</span>
                <span style="color: rgb(153, 102, 204); font-weight: bold;">end</span>

        <span style="color: rgb(153, 102, 204); font-weight: bold;">end</span>
<span style="color: rgb(153, 102, 204); font-weight: bold;">end</span>
```

É funcional e até eficiente…

```
tiago@flick ~ $ time ruby genmd5.rb > hashes-ruby

real    0m1.662s
user    0m0.620s
sys     0m0.028s
```

Mas minha geekialidade não permitiu que eu parasse por aqui. Nesse momento eu já nem me lembrava do freelance que estava fazendo e resolvi ver como usar MD5 em C. Meu primeiro chute foi um `man md5` no terminal, que já me retornou a resposta da vida, do universo e tudo mais: o cabeçalho openssl/md5.h e sua função MD5:

```
unsigned char *MD5(const unsigned char *d, unsigned long n,
                 unsigned char *md);

```

Então lá fui eu pro programa:

<pre class="c"><span style="color: rgb(51, 153, 51);">#include <stdio.h></span>
<span style="color: rgb(51, 153, 51);">#include <openssl/md5.h></span>
 
<span style="color: rgb(153, 51, 51);">int</span> main<span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>

        <span style="color: rgb(153, 51, 51);">int</span> dia, mes, ano;
        <span style="color: rgb(153, 51, 51);">unsigned</span> <span style="color: rgb(153, 51, 51);">char</span> <span style="color: rgb(153, 51, 51);">string</span><span style="color: rgb(102, 204, 102);">[</span>STRING_LENGTH<span style="color: rgb(102, 204, 102);">]</span>, md<span style="color: rgb(102, 204, 102);">[</span>MD5_DIGEST_LENGTH<span style="color: rgb(102, 204, 102);">]</span>;
        <span style="color: rgb(177, 177, 0);">for</span> <span style="color: rgb(102, 204, 102);">(</span>ano = <span style="color: rgb(204, 102, 204);"></span>; ano < <span style="color: rgb(204, 102, 204);">100</span>; ano++<span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>

                <span style="color: rgb(177, 177, 0);">for</span> <span style="color: rgb(102, 204, 102);">(</span>mes = <span style="color: rgb(204, 102, 204);"></span>; mes < <span style="color: rgb(204, 102, 204);">12</span>; mes++<span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>
                        <span style="color: rgb(177, 177, 0);">for</span> <span style="color: rgb(102, 204, 102);">(</span>dia = <span style="color: rgb(204, 102, 204);"></span>; dia < <span style="color: rgb(204, 102, 204);">31</span>; dia++<span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>

                                sprintf<span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(153, 51, 51);">string</span>, <span style="color: rgb(255, 0, 0);">"%02d%02d%02d"</span>, dia<span style="color: rgb(204, 102, 204);">+1</span>, mes<span style="color: rgb(204, 102, 204);">+1</span>, ano<span style="color: rgb(102, 204, 102);">)</span>;
                                <a href="http://www.opengroup.org/onlinepubs/009695399/functions/printf.html"><span style="color: rgb(0, 0, 102);">printf</span></a><span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(255, 0, 0);">"%s<span style="color: rgb(0, 0, 153); font-weight: bold;">n</span>"</span>, MD5<span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(153, 51, 51);">string</span>, <span style="color: rgb(153, 51, 51);">sizeof</span><span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(153, 51, 51);">string</span><span style="color: rgb(102, 204, 102);">)</span>, md<span style="color: rgb(102, 204, 102);">)</span><span style="color: rgb(102, 204, 102);">)</span>;
                        <span style="color: rgb(102, 204, 102);">}</span>

                <span style="color: rgb(102, 204, 102);">}</span>
        <span style="color: rgb(102, 204, 102);">}</span>
        <span style="color: rgb(177, 177, 0);">return</span> <span style="color: rgb(204, 102, 204);"></span>;
<span style="color: rgb(102, 204, 102);">}</span>
```

Ao rodar, recebi saídas com caracteres estranhos e nenhum resultado visível. Corri pro Google. Procurei, procurei, e NINGUÉM usa essa maldita função MD5 do C num programa simples e não há exemplos nem howto de como utilizá-la. Depois de uns 30 minutos quebrando a cabeça (pra mais), percebi que alguns códigos que usavam isso na internet usavam %x (é o código pro printf imprimir inteiros hexadecimais) para imprimir caracteres do MD5 na tela. Aí encontrei algo assim:

<pre class="c"><a href="http://www.opengroup.org/onlinepubs/009695399/functions/printf.html"><span style="color: rgb(0, 0, 102);">printf</span></a><span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(255, 0, 0);">"%x%x...%x%x"</span>, md<span style="color: rgb(102, 204, 102);">[</span><span style="color: rgb(204, 102, 204);"></span><span style="color: rgb(102, 204, 102);">]</span>, md<span style="color: rgb(102, 204, 102);">[</span><span style="color: rgb(204, 102, 204);">1</span><span style="color: rgb(102, 204, 102);">]</span>, ..., md<span style="color: rgb(102, 204, 102);">[</span><span style="color: rgb(204, 102, 204);">14</span><span style="color: rgb(102, 204, 102);">]</span>, md<span style="color: rgb(102, 204, 102);">[</span><span style="color: rgb(204, 102, 204);">15</span><span style="color: rgb(102, 204, 102);">]</span><span style="color: rgb(102, 204, 102);">)</span>;
```

(e pior que estou falando sério… tem gente na internet que não conhece `for`!)

E caiu a ficha. O MD5 tem 16 inteiros hexadecimais de um byte, 32 caracteres. Escrever o código abaixo me tomou bastante tempo, mas uma aprendizagem interessante e um ânimo pra voltar pro meu freelance:

<pre class="c"><span style="color: rgb(51, 153, 51);">#include <stdio.h></span>
<span style="color: rgb(51, 153, 51);">#include <openssl/md5.h></span>
 
<span style="color: rgb(51, 153, 51);">#define STRING_LENGTH 6</span>
 
<span style="color: rgb(153, 51, 51);">int</span> main<span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>

        <span style="color: rgb(153, 51, 51);">int</span> dia, ano, mes;
        <span style="color: rgb(153, 51, 51);">int</span> i;
        <span style="color: rgb(153, 51, 51);">unsigned</span> <span style="color: rgb(153, 51, 51);">char</span> md<span style="color: rgb(102, 204, 102);">[</span>MD5_DIGEST_LENGTH<span style="color: rgb(102, 204, 102);">]</span>, <span style="color: rgb(153, 51, 51);">string</span><span style="color: rgb(102, 204, 102);">[</span>STRING_LENGTH<span style="color: rgb(102, 204, 102);">]</span>;

 
        <span style="color: rgb(177, 177, 0);">for</span> <span style="color: rgb(102, 204, 102);">(</span>ano = <span style="color: rgb(204, 102, 204);"></span>; ano < <span style="color: rgb(204, 102, 204);">100</span>; ano++<span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>
                <span style="color: rgb(177, 177, 0);">for</span> <span style="color: rgb(102, 204, 102);">(</span>mes = <span style="color: rgb(204, 102, 204);"></span>; mes < <span style="color: rgb(204, 102, 204);">12</span>; mes++<span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>

                        <span style="color: rgb(177, 177, 0);">for</span> <span style="color: rgb(102, 204, 102);">(</span>dia = <span style="color: rgb(204, 102, 204);"></span>; dia < <span style="color: rgb(204, 102, 204);">31</span>; dia++<span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>
                                sprintf<span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(153, 51, 51);">string</span>, <span style="color: rgb(255, 0, 0);">"%02d%02d%02d"</span>, dia<span style="color: rgb(204, 102, 204);">+1</span>, mes<span style="color: rgb(204, 102, 204);">+1</span>, ano<span style="color: rgb(102, 204, 102);">)</span>;
                                MD5<span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(153, 51, 51);">string</span>, <span style="color: rgb(153, 51, 51);">sizeof</span><span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(153, 51, 51);">string</span><span style="color: rgb(102, 204, 102);">)</span>, md<span style="color: rgb(102, 204, 102);">)</span>;
                                <a href="http://www.opengroup.org/onlinepubs/009695399/functions/printf.html"><span style="color: rgb(0, 0, 102);">printf</span></a><span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(255, 0, 0);">"%s: "</span>, <span style="color: rgb(153, 51, 51);">string</span><span style="color: rgb(102, 204, 102);">)</span>;
                                <span style="color: rgb(177, 177, 0);">for</span> <span style="color: rgb(102, 204, 102);">(</span>i = <span style="color: rgb(204, 102, 204);"></span>; i < <span style="color: rgb(204, 102, 204);">16</span>; i++<span style="color: rgb(102, 204, 102);">)</span> <span style="color: rgb(102, 204, 102);">{</span>

                                        <a href="http://www.opengroup.org/onlinepubs/009695399/functions/printf.html"><span style="color: rgb(0, 0, 102);">printf</span></a><span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(255, 0, 0);">"%02x"</span>, md<span style="color: rgb(102, 204, 102);">[</span>i<span style="color: rgb(102, 204, 102);">]</span><span style="color: rgb(102, 204, 102);">)</span>; <span style="color: rgb(128, 128, 128); font-style: italic;">/* Note isso aqui! */</span>
                                <span style="color: rgb(102, 204, 102);">}</span>
                                <a href="http://www.opengroup.org/onlinepubs/009695399/functions/printf.html"><span style="color: rgb(0, 0, 102);">printf</span></a><span style="color: rgb(102, 204, 102);">(</span><span style="color: rgb(255, 0, 0);">"<span style="color: rgb(0, 0, 153); font-weight: bold;">n</span>"</span><span style="color: rgb(102, 204, 102);">)</span>;
                        <span style="color: rgb(102, 204, 102);">}</span>

                <span style="color: rgb(102, 204, 102);">}</span>
        <span style="color: rgb(102, 204, 102);">}</span>
        <span style="color: rgb(177, 177, 0);">return</span> <span style="color: rgb(204, 102, 204);"></span>;
<span style="color: rgb(102, 204, 102);">}</span>
```

O “Note isso aqui!” ainda foi uma sacanagem incrível, o código que eu disse do cara que imprimia %x%x%x… não funciona na prática, porque quando um dos dígitos é 0X, ele só imprime X.

Enfim compilei meu código com `-lssl` (importante para C-zeiros de primeira viagem) e voi lá:

```
tiago@flick ~ $ time ./md5 > hashes-c

real    0m0.397s
user    0m0.136s
sys     0m0.028s
```

Confesso que é coisa de nerd mesmo querer otimizar um código que só serve pra gerar um arquivo de hashes e já o fez, mas no momento em que terminei esse teste, pensei: preciso postar isso no blog pra documentar o uso da função MD5 no C, antes que mais alguém perca o tempo que eu perdi.

Pra quem se pergunta se eu realmente fiz tudo certo:

```
tiago@flick ~ $ diff senhas-c senhas-ruby
tiago@flick ~ $ 
```

(ie. ou eu errei nos dois ou eu não errei em nenhum)

Útil, não? Não. Na verdade isso não serve pra absolutamente nada, a não ser que você roube o banco de dados de alguém e esse alguém usa como senha a data de nascimento da sua mãe. Mas aí ele merece mesmo que você pegue sua senha, então isso não muda nada.

Dá pra adaptar o código pra gerar outras tabelas, mas por favor não use isso pra nada maligno, e falo sério. Meus fins foram absolutamente educacionais/acadêmicos (eu queria aprender a trabalhar com a função MD5 da biblioteca OpenSSL, não dominar o mundo) e estou postando aqui para ajudar os que também vão querer usar essa função.

_Comentários de crackers serão ignorados._

 [1]: http://www.php.net/
 [2]: http://www.google.com/search?q=81811b48cc07432fc550cb42d4ab3e8f

