---
title: emerge happiness
type: post
date: 2007-01-18T12:38:34+00:00
url: /2007/01/emerge-happiness/
categorias:
  - Cotidiano
tags:
  - alsa
  - ati
  - aticonfig
  - emerge
  - gentoo
  - linux
  - radeon
  - radeon xpress 1100
---

[Gentoo][1] tem se mostrado uma ótima distribuição. Não sei por quê, eu achava que ele era difícil, mas não… Talvez a instalação a partir da **minimal** seja, mas do jeito que eu estou fazendo está tudo bem, com exceção da [dor de cabeça pra configurar os drivers][2] aqui no meu Acer Aspire 5050-3205.

Instalar os drivers proprietários da ATI foi muito fácil:

```
# emerge ati-drivers
```

Baixou, instalou, eu rodei o **aticonfig** e ele já alterou o **/etc/X11/xorg.conf** pra mim. O problema é que esse driver não roda a minha **ATI Radeon Xpress 1100**. Trecho do log do Xorg:

```
(II) Primary Device is: PCI 01:05:0
(II) ATI Proprietary Linux Driver Version Identifier:8.32.5
(II) ATI Proprietary Linux Driver Release Identifier: LGDr8.32g1
(II) ATI Proprietary Linux Driver Build Date: Dec 12 2006 17:18:49
(II) ATI Proprietary Linux Driver Build Information: autobuild-rel-r6-8.32.2.1.2.3-driver-lnx-x86-x86_64-313294
(--) Assigning device section with no busID to primary device
(--) Chipset ATI Radeon Xpress Series (RS482 5975 Generic 5975) found
(II) resource ranges after xf86ClaimFixedResources() call:
...
(II) Setting vga for screen 0.
(II) fglrx(0): === [atiddxPreInit] === begin, [x]
(II) Loading sub module "vgahw"
(II) LoadModule: "vgahw"
(II) Loading /usr/lib64/xorg/modules/libvgahw.so
(II) Module vgahw: vendor="X.Org Foundation"
        compiled for 7.0.0, module version = 0.1.0
        ABI class: X.Org Video Driver, version 0.8
(II) fglrx(0): PCI bus 1 card 5 func 0
(EE) fglrx(0): RegisterResources failed
SetVBEMode failed
(EE) fglrx(0): PreInit failed
(II) fglrx(0): === [atiddxPreInit] === end
(II) UnloadModule: "fglrx"
(II) UnloadModule: "vgahw"
(II) Unloading /usr/lib64/xorg/modules/libvgahw.so
(EE) Screen(s) found, but none have a usable configuration.
.
Fatal server error:
no screens found
```

Agora o **alsa** não tá funcionando, não sei por quê. Já recompilei o Kernel umas 20 vezes… mas isso tudo bem. O problema é a placa de vídeo mesmo… Ninguém tem essa placa pra me ajudar?

Concluindo, falta uma coisa na portage do Gentoo para quem usa placas de vídeo da ATI e tela com widescreen:

```
# emerge paracetamol
```

[1]: http://www.gentoo.org/
[2]: /2007/01/dor-de-cabeca/
