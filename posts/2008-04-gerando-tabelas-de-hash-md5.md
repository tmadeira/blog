---
title: Gerando tabelas de hash MD5
type: post
date: 2008-04-11T03:26:24+00:00
url: /2008/04/gerando-tabelas-de-hash-md5/
categorias:
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

```ruby
require "md5"

100.times do |ano|
  12.times do |j|
    mes = j+1

    31.times do |i|
      dia = i+1
      string = sprintf("%02d%02d%02d", dia, mes, ano)

      md5 = MD5.new(string).to_s
      puts "#{string}: #{md5}"
    end
  end
end
```

É funcional e até eficiente…

```
tiago@flick ~ $ time ruby genmd5.rb > hashes-ruby

real    0m1.662s
user    0m0.620s
sys     0m0.028s
```

Mas minha geekialidade não permitiu que eu parasse por aqui. Nesse momento eu já nem me lembrava do freelance que estava fazendo e resolvi ver como usar MD5 em C. Meu primeiro chute foi um `man md5` no terminal, que já me retornou a resposta da vida, do universo e tudo mais: o cabeçalho openssl/md5.h e sua função MD5:

```c
unsigned char *MD5(const unsigned char *d, unsigned long n,
                 unsigned char *md);
```

Então lá fui eu pro programa:

```c
#include <stdio.h>
#include <openssl/md5.h>

int main() {
  int dia, mes, ano;
  unsigned char string[STRING_LENGTH], md[MD5_DIGEST_LENGTH];
  for (ano = 0; ano < 100; ano++) {
    for (mes = 0; mes < 12; mes++) {
      for (dia = 0; dia < 31; dia++) {
        sprintf(string, "%02d%02d%02d", dia+1, mes+1, ano);
        printf("%sn", MD5(string, sizeof(string), md));
      }
    }
  }
  return 0;
}
```

Ao rodar, recebi saídas com caracteres estranhos e nenhum resultado visível. Corri pro Google. Procurei, procurei, e NINGUÉM usa essa maldita função MD5 do C num programa simples e não há exemplos nem howto de como utilizá-la. Depois de uns 30 minutos quebrando a cabeça (pra mais), percebi que alguns códigos que usavam isso na internet usavam %x (é o código pro printf imprimir inteiros hexadecimais) para imprimir caracteres do MD5 na tela. Aí encontrei algo assim:

```c
printf("%x%x...%x%x", md[0], md[1], ..., md[14], md[15]);
```

(e pior que estou falando sério… tem gente na internet que não conhece `for`!)

E caiu a ficha. O MD5 tem 16 inteiros hexadecimais de um byte, 32 caracteres. Escrever o código abaixo me tomou bastante tempo, mas uma aprendizagem interessante e um ânimo pra voltar pro meu freelance:

```c
#include <stdio.h>
#include <openssl/md5.h>

#define STRING_LENGTH 6

int main() {
  int dia, ano, mes;
  int i;
  unsigned char md[MD5_DIGEST_LENGTH], string[STRING_LENGTH];

  for (ano = 0; ano < 100; ano++) {
    for (mes = 0; mes < 12; mes++) {
      for (dia = 0; dia < 31; dia++) {
        sprintf(string, "%02d%02d%02d", dia+1, mes+1, ano);
        MD5(string, sizeof(string), md);
        printf("%s: ", string);
        for (i = 0; i < 16; i++) {
          printf("%02x", md[i]); /* Note isso aqui! */
        }
        printf("n");
      }
    }
  }
  return 0;
}
```

O “Note isso aqui!” ainda foi uma sacanagem incrível, o código que eu disse do cara que imprimia %x%x%x… não funciona na prática, porque quando um dos dígitos é 0X, ele só imprime X.

Enfim compilei meu código com `-lssl` (importante para C-zeiros de primeira viagem) e _voi lá_:

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

(i.e. ou eu errei nos dois ou eu não errei em nenhum)

Útil, não? Não. Na verdade isso não serve pra absolutamente nada, a não ser que você roube o banco de dados de alguém e esse alguém usa como senha a data de nascimento da sua mãe. Mas aí ele merece mesmo que você pegue sua senha, então isso não muda nada.

Dá pra adaptar o código pra gerar outras tabelas, mas por favor não use isso pra nada maligno, e falo sério. Meus fins foram absolutamente educacionais/acadêmicos (eu queria aprender a trabalhar com a função MD5 da biblioteca OpenSSL, não dominar o mundo) e estou postando aqui para ajudar os que também vão querer usar essa função.

_Comentários de crackers serão ignorados._

 [1]: http://www.php.net/
 [2]: http://www.google.com/search?q=81811b48cc07432fc550cb42d4ab3e8f

