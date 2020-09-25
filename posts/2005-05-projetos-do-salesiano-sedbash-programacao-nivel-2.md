---
title: Projetos do Salesiano, SED/Bash, Programação Nível 2
type: post
date: 2005-05-20T13:32:47+00:00
excerpt: O título já descreve perfeitamente o que eu digo nesse post...
url: /2005/05/projetos-do-salesiano-sedbash-programacao-nivel-2/
categorias:
  - Cotidiano
tags:
  - bash
  - computação
  - escola
  - obi
  - obi 2005
  - olimpíadas
  - programação
  - salesiano
  - sed
  - shell
  - Trabalho

---
Em primeiro lugar, publiquei dois projetos do colégio (dentro dos padrões web, um que não funciona direito no IE) sexta-feira. O pessoal tava reclamando que a página tava desatualizada e tinha gente procurando por “ginsal 2005” no Google e chegando aqui, então estou postando os links para o projeto **Ginsal 2005** e **Páginas Literárias** aqui mesmo:

  * ~`GINSAL~~
  * ~~Páginas Literárias~~

(links perdidos com o tempo)

Eles não foram publicados antes porque tô com bastante coisa pra fazer lá no colégio, entre essas um site totalmente novo.

E mesmo que você não seja do colégio, dá uma olhada nos códigos totalmente dentro dos padrões nos dois sites. O Páginas Literárias usa até tags **q** e **cite** na página inicial! Legal também o rodapé que eu coloquei nos dois projetos, sugerindo “qualquer navegador”, sem ser IE.

Em segundo lugar, obrigado ao **Paulo Victor Eufrásio**, de Fortaleza, que me mandou uma síntese dos problemas da OBI2005 Programação Nível 2! Já fiz alguns e depois publicarei tudo junto. O nível não tá muito alto, mas achei difícil aquele problema Mochila (o povo que foi na Programação pra UNICAMP ano passado já sabia a solução, mas eu não!).

E finalizando, hoje dei meus primeiros passos no sed. Eu tava achando uma vergonha ter que passar pelo aplicativo php e usar ereg_replace nos meus programas Bash e adorei o sed! Criei um programinha bem legal para ouvir músicas. Postei os screenshots no Flickr e o código aqui embaixo.

```bash
#!/bin/bash
toca() {
       echo "^[[31m^[[1m$1"'a. ocorrência^[[0m'
       musica="`head -$1 ~/.tmp-musica | tail -1`"
       nome="`echo $musica | sed -e 's/(.*)/(.*)/([0-9]*) (.*).mp3/4/'`"
       autor="`echo $musica | sed -e 's/(.*)/(.*)/([0-9]*) (.*).mp3/1/'`"
       album="`echo $musica | sed -e 's/(.*)/(.*)/([0-9]*) (.*).mp3/2/'`"
       echo "Nome:    ^[[33m^[[1m$nome^[[0m"
       echo "Autor:   ^[[33m^[[1m$autor^[[0m"
       echo "Álbum:   ^[[33m^[[1m$album^[[0m"
       echo "Caminho: ^[[33m^[[1m$musica^[[0m"
       play "$path/$musica"
       echo ""
}
path="/mnt/ntfs/Documents and Settings/Tiago Madeira/My Documents/My Music"
echo "^[[36m^[[1mouvir 1.0 (c)^[[0m"
echo "^[[1mpor Tiago Madeira (contato em tiagomadeira.net^[[0m"
echo ""
echo "^[[1mEntrando no diretório das músicas...^[[0m"
cd "$path"
echo "^[[1mProcurando palavras-chave...^[[0m"
tree -f * | grep -i "$1.*.mp3" > ~/.tmp-musica

echo "^[[1mFormatando a(s) palavra(s)-chave...^[[0m"
sed -e 's/^[| -]*//' ~/.tmp-musica > ~/.tmp-music

mv ~/.tmp-music ~/.tmp-musica
echo "^[[1mContando número de ocorrências encontradas...^[[0m"
wc -l ~/.tmp-musica > ~/.wc-tmp-musica
echo "^[[1mFormatando número de ocorrências encontradas...^[[0m"
num=`sed -e 's/([0-9]*) (.*)/1/' ~/.wc-tmp-musica`

echo ""

echo "^[[34m^[[1mFoi(ram) encontrada(s) $num ocorrência(s):^[[0m"
cat -n ~/.tmp-musica | sed -e 's/^[[:blank:]]*([0-9]*)[[:blank:]]*(.*)/1: 2/'

echo ""

echo "^[[31m^[[1mDigite o número da música que você deseja ouvir,"
echo "ou 't' para tocar todas ou 's' para sair.^[[0m"
echo ""

while :; do
 printf "^[[31m^[[1m#: ^[[0m"
 read d
 case $d in
  's'|'S')
   break
   ;;
  't'|'T')
   i=1
   while [ "$i" -le "$num" ]; do
    toca $i
    i=`funcoeszz zzcalcula $i+1`
   done
   ;;
  *)
   toca $d
   ;;
 esac
done

rm ~/.tmp-nome > /dev/null
rm ~/.tmp-musica 2> /dev/null

echo "^[[1mAté a próxima!^[[0m"
```

Agora já modifiquei bastante esse programa e ele tá na minha seção **Portifólio**, mas essa aí foi a primeira versão.

Eu nunca tinha feito nada tão evoluído no Bash e agora tô até começando a me achar um programador bash. Incrível como é legal desenvolver nele! :)

No mais, não aconteceu nada de novo. Só tô decepcionado por ter errado um problema da OBI, cheio de trabalhos de escola mas desenvolvendo bastante coisa legal aqui agora que meus sistemas estão ficando estáveis.

