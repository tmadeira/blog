---
title: Hoje é o dia!
date: 2007-01-19T15:47:09+00:00
url: /2007/01/hoje-e-o-dia/
tags:
  - acer
  - aspire 5050-3205
  - ati
  - fglrx
  - gentoo
  - linux
  - radeon
  - radeon xpress 1100
  - x
  - xorg
---

Hoje a noite eu espero poder postar um artigo feliz aqui dizendo que estou no meu laptop a 1280×780! Depois de varrer a internet e de dias tentando, acho que encontrei a solução para o **fglrx** funcionar com a **ATI Radeon Xpress 1100** do meu Acer Aspire 5050-3205.

A solução baseou-se, entre outros sites, em dois casos de caras com Ubuntu que tiveram problemas semelhantes: [esse][1] e [esse][2]. Depois de um tempão tentando fazer outras coisas, parece que o problema que estava me impedindo de tudo funcionar corretamente era a versão do Xorg (!). Estou com o xorg.conf do Elvish Legion, do primeiro fórum, e agora emergindo o meu Xorg para a 7.1 como fez o Berin do segundo!

O problema que eu estou tendo é exatamente igual o dele:

```
(WW) ****INVALID IO ALLOCATION**** b: 0x9000 e: 0x90ff correcting
(...)
Requesting insufficient memory window!: start: 0x9000 end: 0x90ff size 0xc0120100
Requesting insufficient memory window!: start: 0x9400 end: 0x94ff size 0xc0120100
Requesting insufficient memory window!: start: 0x9800 end: 0x98ff size 0xc0120100
Requesting insufficient memory window!: start: 0x9c00 end: 0x9cff size 0xc0120100
(EE) Cannot find a replacement memory range
(...)
(EE) fglrx(0): RegisterResources failed
SetVBEMode failed
(EE) fglrx(0): PreInit failed
```

Em breve novidades… ;-)

### Posts relacionados

- [Acer Aspire 5050-3205][3]
- [I’ve got the power!][4]
- [Pontinho verde][5] – eu rodei por uma hora aquele JScreenFix, não resolveu. Depois vou tentar rodar por mais tempo, mas o pontinho não atrapalha muito anyway… Mas valeu pelos comentários pessoal, foram muito bons!
- [Dor de cabeça][6]
- [emerge happiness][7]

Quando eu tiver um Linux totalmente configurado pro Acer Aspire 5050-3205, eu vou encher uma página de informações sobre como configurá-lo pras próximas vítimas serem mais felizes na estréia do laptop novo…

Ahhhh! Esse laptop está me rendendo um monte de paraquedistas! Parece um modelo novo que todo mundo tem pesquisado… e meu site tá bem localizado lá no [Google][8], tanto que eu sou o primeiro resultado em várias buscas de pessoas procurando por como fazer a ATI Radeon Xpress 1100 funcionar!

Olha… Se você chegou aqui procurando por esse laptop e sua compatibilidade com Linux, além de ler os posts relacionados, saiba que ele é difícil de ser configurado, mas que na teoria _tudo vai funcionar_!

[1]: http://ubuntuforums.org/showthread.php?t=24557&page=29
[2]: http://www.driverheaven.net/archive/index.php/t-119932.html
[3]: /2007/01/acer-aspire-5050-3205/
[4]: /2007/01/ive-got-the-power/
[5]: /2007/01/pontinho-verde/
[6]: /2007/01/dor-de-cabeca/
[7]: /2007/01/emerge-happiness/
[8]: http://google.com/
