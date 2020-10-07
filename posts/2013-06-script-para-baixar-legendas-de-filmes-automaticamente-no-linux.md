---
title: "downloadsubtitle: script para baixar legendas de filmes automaticamente no shell do GNU/Linux"
date: 2013-06-28T05:34:39+00:00
url: /2013/06/script-para-baixar-legendas-de-filmes-automaticamente-no-linux/
tags:
  - c
  - códigos
  - download
  - hash
  - legendas
  - legendas.tv
  - linux
  - opensubtitles
  - scripts
  - shell
  - spider
---

Me acostumei a usar o **legendas.tv** para baixar legendas de filmes e acabei nunca me perguntando se haveria um jeito mais fácil de baixá-las. Hoje fui assistir um filme e, ao entrar no navegador para baixar sua legenda, me deparei com a mensagem de que o site estava fora do ar:

![Mensagem do legendas.tv fora do ar.](/wp-content/uploads/2013/06/legendas.png)

A situação me obrigou a procurar outros sites e outras formas de baixar legendas. Minha primeira ideia foi usar o **opensubtitles.org**, que já havia usado algumas outras vezes. Chegando lá e procurando pelo filme que eu desejava, vi muitas opções e não estava muito claro que legenda baixar para a versão do filme que eu tinha.

Então resolvi dar uma fuçada na pesquisa avançada do site, onde acabei encontrando uma pesquisa por _hash_. _Hash_, em computação, é uma função que “resume” uma informação gigante (tipo um arquivo bem grande) numa informação bem pequena (tipo 16 caracteres) que o represente de forma única (ou quase única). A pesquisa por _hash_, no caso desse site, consiste em procurar uma legenda utilizando esse “ID” do arquivo (ou seja, não importa seu nome).

Achei a possibilidade tão legal que resolvi fazer um programa para nunca mais precisar abrir o navegador quando eu quiser baixar a legenda de um filme. Escrevi um minúsculo programa em C chamado `oshash` (de **O**pen**S**ubtitles **Hash**) para calcular o _hash_ de um filme de acordo com a [especificação do site][2] (que não requer nada, a não ser um compilador de C e a biblioteca padrão) e um _script_ (bem tosco, mas funcional) chamado `downloadsubtitle` que usa o programa `oshash` (e pequenos programas que todo mundo tem, tipo `grep`, `sed`, `wget` e `unzip`) para baixar a legenda.

**O funcionamento ficou bem fácil:** para baixar uma legenda em qualquer língua, basta você digitar `downloadsubtitle arquivo.avi` para baixar a legenda do “arquivo.avi” (que já vai ser automaticamente nomeada como “arquivo.srt”). Se você quiser especificar uma língua (por exemplo, português do Brasil), é só digitar `downloadsubtitle arquivo.avi pob` (_pob_ é o código do português do Brasil). Se você quiser baixar uma legenda em inglês **ou** espanhol, pode usar `downloadsubtitle arquivo.avi eng,esp`.

#### Exemplo de funcionamento

```
$ ls
Amelie [Amélie Poulain].2001.BRRip.x264.AAC[5.1]-VLiS.mkv
$ downloadsubtitle Amelie\ \[Amélie\ Poulain\].2001.BRRip.x264.AAC\[5.1\]-VLiS.mkv pob
Requested language: pob
Movie hash: bcdc90cf4873c09b
Subtitle ID: 4642726
Subtitle: Amelie [Amélie Poulain].2001.BRRip.x264.AAC[5.1]-VLiS.srt
$ ls
Amelie [Amélie Poulain].2001.BRRip.x264.AAC[5.1]-VLiS.mkv  Amelie [Amélie Poulain].2001.BRRip.x264.AAC[5.1]-VLiS.srt
$
```

E aí o filme está pronto para você assistir com o `mplayer` ou com o seu programa favorito.

#### Código

Este é o código inicial. Está aqui para fins históricos. Não será atualizado. Use a próxima seção (Download) para baixar a última versão, com bugs corrigidos, tratamento de erros e possivelmente novas funcionalidades.

```c
#include <stdio.h>
#include <stdlib.h>

void usage(char *name) {
    printf("Usage: %s <file>\n", name);
    exit(1);
}

int main(int argc, char *argv[]) {
    unsigned long long buf[16384], c = 0;
    FILE *in;
    int i;
    if (argc != 2) {
        usage(argv[0]);
    }
    in = fopen(argv[1], "rb");
    if (in == NULL) {
        usage(argv[0]);
    }
    fread(buf, 8192, 8, in);
    fseek(in, -65536, SEEK_END);
    fread(&buf[8192], 8192, 8, in);
    for (i = 0; i < 16384; i++) {
        c+= buf[i];
    }
    c+= ftell(in);
    fclose(in);
    printf("%016llx\n", c);
    return 0;
}
```

```bash
#!/bin/bash

usage() {
    echo "Usage: $0 <file> [lang]"
    echo "Examples:"
    echo "$ $0 movie.avi pob         # brazilian portuguese"
    echo "$ $0 movie.avi por,pob     # any portuguese"
    echo "$ $0 movie.avi eng         # english"
    echo "$ $0 movie.avi all         # any language"
    exit
}

if [ $# -lt 1 ]; then
    usage
elif [ $# -gt 2 ]; then
    usage
fi

if [ $# = 2 ]; then
    lang=$2
else
    lang="any"
fi

echo "Requested language: $lang"
output=$(echo "$1" | sed 's/\.[^.]*$/.srt/')
oshash=$(oshash "$1")
echo "Movie hash: $oshash"
subid=$(wget "http://www.opensubtitles.org/en/search/sublanguageid-$lang/moviehash-$oshash/rss_2_00" -q -O - \
    | grep '<link />.*en/subtitles' | sed 's|.*en/subtitles/||; s|/.*||' | head -n1)
echo "Subtitle ID: $subid"
wget "http://www.opensubtitles.org/en/subtitleserve/sub/$subid" -q -O - | gunzip > "$output" 2> /dev/null
echo "Subtitle: $output"
```

#### Download

Criei um repositório no Github para colocar o código: [github.com/tmadeira/downloadsubtitle][3]

Para quem tem `git`, é possível baixar com `git clone https://github.com/tmadeira/downloadsubtitle.git`

Para quem não tem, dá pra baixar em ZIP daqui: [github.com/tmadeira/downloadsubtitle/archive/master.zip][4]

O programa ainda não está empacotado bonitinho (não tem nem Makefile ou instruções de instalação). Se futuramente vier a ter, este post será atualizado. Em resumo, basta compilar o código em C (digitando `gcc oshash.c -o oshash`) e colocar os arquivos `oshash` e `downloadsubtitle` numa pasta do seu `$PATH` (por exemplo, `/usr/local/bin`).

Sugestões e correções são bem-vindas.

[2]: http://trac.opensubtitles.org/projects/opensubtitles/wiki/HashSourceCodes
[3]: https://github.com/tmadeira/downloadsubtitle
[4]: https://github.com/tmadeira/downloadsubtitle/archive/master.zip
