---
title: Windows é mais fácil?
date: 2006-12-09T17:59:31+00:00
url: /2006/12/windows-e-mais-facil/
tags:
  - dicas
  - facilidade
  - funções zz
  - imagemagick
  - linux
  - shell
  - unix
  - windows
---

Na minha opinião, a **facilidade** de uma ação depende da **praticidade** de execução da mesma (ou seja, do tempo que ela demora pra ser executada). Quando eu converso com algum leigo sobre Linux, depois de eu convencê-lo com vários argumentos que o Linux não só tem muito mais recursos como ainda tem uma filosofia muito mais bonita, ele sempre diz: _“Mas Linux é muito difícil!”_

Eu não acho que Linux seja difícil, eu acho que é diferente do que elas estão acostumadas. E as pessoas precisam ter mais disposição pra testar e aprender o novo! É claro que no início elas vão ter dificuldade, mas o Linux não é nenhum bicho de sete cabeças!

Porém, o foco desse pequeno _post_ não é questionar a dificuldade por esse aspecto, mas questionar a praticidade de uso dos dois sistemas.

Vou propôr um problema básico: baixei 500 fotos de uma viagem (com uma qualidade foda, tipo 2048×1536) para o meu computador. Elas estão muito grandes e quero diminuí-las para publicá-las no meu site. As imagens para a web não precisam ser muito grandes e nem ter uma qualidade muito alta. Eu não quero que elas tenham aquele nome feio DSC\_….JPG que elas têm e quero que os arquivos tenham nomes em minúsculas do tipo viagem-N.jpg. Isso não é nenhuma realidade distante, é algo que eu sempre preciso fazer…

No meu [Linux][1] (com [Funções ZZ][2] e [ImageMagick][3]), eu simplesmente escreveria:

```
$ zzarrumanome *
$ zznomefoto -p viagem- *.jpg
$ mkdir fotosnovas
$ for i in *.jpg; do
> convert -geometry 640 -quality 75 $i fotosnovas/$i
> done
```

Como fazer isso no Windows? Se alguém conhece uma maneira, me ensine nos comentários. Eu gostaria muito de saber pra ensinar aos meus amigos que sempre precisam disso! :-)

**[update]** E vejam o que o [MeioBit][4] acabou de postar… eu ainda acho a minha maneira **muito mais fácil**! **[/update]**

[1]: http://www.slackware.com
[2]: http://funcoeszz.net
[3]: http://www.imagemagick.org
[4]: http://www.meiobit.com/audio_video_fotografia/reduzindo_varias_fotos_ao_mesmo_tempo
