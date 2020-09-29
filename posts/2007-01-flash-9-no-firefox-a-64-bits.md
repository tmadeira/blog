---
title: Flash 9 no Firefox a 64 bits
type: post
date: 2007-01-30T13:54:00+00:00
url: /2007/01/flash-9-no-firefox-a-64-bits/
categorias:
  - Dicas
tags:
  - 64 bits
  - adobe
  - firefox
  - flash
  - flash 9
  - gentoo
  - linux
  - nspluginwrapper
---

Para rodar o plug-in do Flash num Gentoo a 64 bits, baixe o plug-in para 32 bits na [página da Adobe][1]. Descompacte o .tar.gz e na pasta onde você descompactou, escreva:

```
# echo net-www/nspluginwrapper ~arch >> /etc/portage/package.keywords
```

… para desbloquear o “nspluginwrapper” do seu sistema, esse é o programa que vai transformar a lib de 32bits em uma lib de 64.

Então instale o nspluginwrapper:

```
# emerge nspluginwrapper
```

E agora é só instalar o plugin usando o nspluginwrapper:

```
# nspluginwrapper --install libflashplayer.so
```

Reinicie o Firefox e se divirta!

Se sua distribuição não for Gentoo, é só instalar o _nspluginwrapper_ de outra maneira como **installpkg**, **apt-get** ou coisas do tipo. ;)

A dica foi do **Renato** e foi obtida no [Gentoo Wiki][2], que é muito útil; realmente uma grande vantagem de quem usa Gentoo.

[1]: http://www.adobe.com/shockwave/download/download.cgi?P1_Prod_Version=ShockwaveFlash
[2]: http://gentoo-wiki.com/HOWTO_Flash_9_and_Firefox
