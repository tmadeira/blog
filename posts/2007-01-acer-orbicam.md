---
title: Acer Orbicam
type: post
date: 2007-01-26T17:57:34+00:00
url: /2007/01/acer-orbicam/
categorias:
  - Cotidiano
tags:
  - acer
  - acer orbicam
  - aspire 5050-3205
  - gentoo
  - gspca
  - hardware
  - kernel
  - linux
  - microdia
  - Ov7670
  - sn9c201
  - sonix
  - webcam

---
Agora que já estou com o Acer Aspire 5050-3205 quase totalmente configurado com Gentoo, estou resolvendo os últimos problemas de hardware, que creio que são os mais difíceis: wireless e webcam.

Estou conseguindo gravar DVDs, usar ponto de interrogação (eba!) = AltGr+W, o som hda-intel já está funcionando (embora eu não consiga salvar as configurações entre as sessões – alsactl store/restore), estou a 1280×800 usando drivers proprietários da ATI e chegando a 1600fps com a ATI Radeon Xpress 1100. O sistema está quase redondo e bem rápido.

Acabei de entrar em contato com o Michel Xhaard, doutor francês responsável pelo [GSPCA][1], que é o driver que suporta as câmeras no Linux. A câmera do Acer Aspire 5050-3205 no **lsusb -v** é reconhecida como:

```
idVendor           0x0c45 Microdia
 idProduct          0x6260
 bcdDevice            1.00
 iManufacturer           0
 iProduct                1 USB20 Camera
```

Na resposta do e-mail que eu mandei pra ele (e que ele respondeu em menos de meia hora, achei super legal!), ele disse que isso é igual uma _Sonix USB2.0 sn9c201+Ov7670_. O GSPCA ainda não a suporta, mas segundo o Michel, ele deve suportar em breve. Então, se você tem uma câmera embutida da Acer como a minha, o lance é ficar ligado e esperar pelo “sn9c20x” na lista de drivers suportados. ;)

 [1]: http://mxhaard.free.fr/download.html

