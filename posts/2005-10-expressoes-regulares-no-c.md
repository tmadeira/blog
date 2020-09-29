---
title: Expressões Regulares no C
type: post
date: 2005-10-09T17:43:11+00:00
excerpt: Em julho, na UNICAMP, um cara chamado Fernando Aires (e conhecido como Tchê), falou brevemente que o "scanf" suportava alguma coisa que é quase uma expressão regular no seu primeiro argumento. Mas a biblioteca regex.h é bem mais legal!
url: /2005/10/expressoes-regulares-no-c/
categorias:
  - Cotidiano
tags:
  - c
  - expressões regulares
  - funções zz
  - regex
---

Sem querer, visitando a página do cara que desenvolve as [Funções ZZ][1] com o [Aurélio][2], o Thobias, acabei descobrindo que o C possue uma biblioteca para expressões regulares! Não sei porquê, mas sempre pensei que o C não tivesse esse suporte e nunca parei pra investigar…

Agora descobri que o C tem uma biblioteca chamada **regex.h** com quatro funções simples para ERs:

```c
int regcomp(regex_t *preg, const char *regex, int cflags);
int regexec(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);
size_t regerror(int errcode, const regex_t *preg, char *errbuf, size_t errbuf_size);
void regfree(regex_t *preg)
```

Não vou aumentar muito esse assunto, mas deixar aqui o link do artigo do Thobias: [thobias.org/doc/er_c.html][3].

A propósito… A página dele é muito legal! Você se sente usando Linux modo-texto… :lol:

E já que falei sobre ERs e Funções ZZ, vou por último falar de um patch que eu fiz pra função ZZCalcula dar as respostas em notação científica e com precisão maior, o que é extremamente importante para eu não precisar ficar contando zeros no novo grupo de estudo de física (que fiz com o prof. Valdir, o Ivo e o John) onde estamos estudando principaplmente astronomia e ter respostas precisas. O patch está disponível aqui e serve para a última versão das ZZ (5.9): ~~Patch para Funções ZZ 5.9, para ZZCalcula resolver as operações com notações científicas e precisão mais alta~~ (infelizmente esse patch foi perdido com o tempo). Para quem já modificou muito seu arquivo das funções, ou não gosta de patches, publiquei também no meu servidor somente o código inteiro da nova função ZZCalcula com esse recurso: ~~zzcalcula.txt~~ (infelizmente esse arquivo foi perdido com o tempo)

Hmmm… Eu resolvi começar a floodar mais aqui no blog, isso é, usar a idéia de assuntos diferentes em posts diferentes… Espero que ninguém que recebe e-mails sempre que eu publico uma coisa nova se estresse muito; mas se tiver chato eu dou um jeito de fazer um cron (meu novo servidor tem suporte a cronjobs! E já que eu nunca usei, seria muito legal aprender…) ;)

[1]: http://funcoeszz.net
[2]: http://aurelio.net
[3]: http://www.thobias.org/doc/er_c.html
