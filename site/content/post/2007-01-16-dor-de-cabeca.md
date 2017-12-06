---
title: Dor de cabeça
type: post
date: 2007-01-16T13:46:14+00:00
url: /2007/01/dor-de-cabeca/
categories:
  - Cotidiano
tags:
  - 64 bits
  - acer
  - aspire 5050-3205
  - ati
  - dor de cabeça
  - firefox
  - flash
  - gentoo
  - hdaudio
  - notebook
  - radeon
  - radeon xpress 1100
  - slackware
  - xmodmap

---
Anteontem formatei o [laptop][1] e instalei o **slamd64**. Por ordem de prioridade, lá vão os problemas…

**Problema 1:** placa ATI Radeon Xpress 1100. O “ati” do [Xorg][2] não suporta. Eu não consigo instalar os drivers proprietários. Baixei lá do site da [ATI][3] e rodei normalmente o arquivo e ele não abre o instalador gráfico que deveria abrir:

```
root@laptop:~# ./ati-driver-installer-8.32.5-x86.x86_64.run
Creating directory fglrx-install
Verifying archive integrity... All good.
Uncompressing ATI Proprietary Linux Driver-8.32.5..............................
==================================================
 ATI Technologies Linux Driver Installer/Packager
==================================================
Detected configuration:
Architecture: x86_64 (64-bit)
X Server: X.Org 6.9.x 64-bit
Removing temporary directory: fglrx-install
root@laptop:~#
```

(e, sim, não estou em _root_ por **su**, o que poderia fazer eu não ter um DISPLAY, mas entrei no X como root mesmo)

Essa série 1100 parece ser nova porque há pouca informação sobre ela na internet. Alguém sabe ajudar?

Sem configurar a placa, não consegui usar 1280×800, aí tudo está “gordo” e desfigurado, porque estou usando 1024×768 num monitor widescreen (driver vesa).

**Problema 2:** 64 bits. Firefox com Flash, codecs proprietários do mplayer, Java. Achei que fosse mais fácil… O [hlegius][4] fez um [comentário][5] bem pessimista lá no outro post… E ele tem razão. Estou com o live-cd do Gentoo amd64 baixado esperando um CD virgem pra gravar (devo comprar hoje a tarde), todo mundo fala bem do Gentoo pra 64bits. Ainda tô baixando também o Ubuntu pra 64bits pra ver como é que é…

Eu não sei como se faz pra emular um subsistema de 32bits pra rodar Flash por exemplo. Depois também vou precisar de ajuda… mas a prioridade agora é o monitor mesmo.

**Problema 3:** Resto do hardware. Gravador de DVD, webcam, wireless. **Nunca** useu nenhum dos três. Vai ser uma experiência nova super divertida, com mais dor de cabeça ainda.

**Problema 4:** Teclado. Depois tenho que dar uma olhada no Xmodmap (acho que é isso que eu tenho que usar) pra fazer o ponto de interrogação (Altgr+W) funcionar.

**Problema 5:** O som hdaudio funciona, mas dá um monte de erro quando o udev detecta e inicia o alsa. Depois tenho que verificar…

**Conclusão:** Pelo visto esse mês (no mínimo) vai ser só dor de cabeça. Mas o aprendizado com certeza vai ser grande. ;) Quem já tiver passado por esses problemas e quiser me ajudar nessa aventura será muito bem recompensado (por Deus ou algum cara assim que você acreditar, porque meu dinheiro acabou na compra desse laptop… hehehe).

 [1]: /2007/01/ive-got-the-power/
 [2]: http://www.x.org
 [3]: http://www.ati.com/
 [4]: http://www.hlegius.pro.br/
 [5]: /2007/01/ive-got-the-power/#comment-1012

