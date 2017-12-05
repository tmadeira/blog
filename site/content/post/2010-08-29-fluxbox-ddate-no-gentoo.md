---
title: fluxbox-ddate no Gentoo
type: post
date: 2010-08-29T14:05:07+00:00
url: /2010/08/fluxbox-ddate-no-gentoo/
featured_image: /wp-content/uploads/2010/08/a21.png
categories:
  - Software Livre
tags:
  - ddate
  - fluxbox
  - gentoo
  - portage

---
Criei um ebuild para o Fluxbox com uma USE flag “ddate” baseado no fluxbox-1.1.1-r2 (que é o último ebuild no Portage neste exato momento). Usando ele, é possível ter [o calendário santo-discordiano no Fluxbox do Gentoo][1].

Siga os passos abaixo para ter Fluxbox com suporte a ddate no seu Gentoo.

### Baixando o ebuild e colocando ele num overlay

```bash
% wget http://tiagomadeira.com/wp-content/2010/08/portage-fluxbox-1.1.1-0.tar.bz2
% su
% mkdir -p /usr/local/portage/x11-wm
% tar xjvf portage-fluxbox-1.1.1-0.tar.bz2 -C /usr/local/portage/x11-wm
```

### Modificando o /etc/make.conf pra adicionar suporte ao overlay

Abra com seu editor preferido (e obviamente como root) o /etc/make.conf e adicione ao final dele:

```bash
PORTDIR_OVERLAY="/usr/local/portage"
```

Depois disso é necessário rodar um `emerge --sync` (ou `eix-sync` se você usa o eix :))

```bash
% emerge --sync
```

### ACCEPT_KEYWORDS e USE flag

Marquei o pacote como instável. Para usar, se seu /etc/make.conf não tem `ACCEPT\_KEYWORDS=”~amd64″` (ou `~suaarquitetura` se você não usa amd64), edite (criando, caso não exista) o arquivo `/etc/portage/package.keywords` adicionando:

```
=x11-wm/fluxbox-1.1.1-r10 ~amd64
```

(substitua _~amd64_ por _~suaarquitetura_)

Se você também não tem uma USE flag “ddate” no /etc/make.conf, é necessário editar o arquivo `/etc/portage/package.use` (também crie se não existir), adicionando:

```
x11-wm/fluxbox ddate
```

### E agora?

Basta instalar o Fluxbox usando o emerge, como você faria com qualquer pacote normal:

```bash
% emerge -av fluxbox
These are the packages that would be merged, in order:

Calculating dependencies... done!
[ebuild   U   ] x11-wm/fluxbox-1.1.1-r10  USE="ddate imlib nls slit toolbar truetype vim-syntax -gnome -newmousefocus -xinerama" 0 kB [1]
```

(note que a versão é 1.1.1-r10 e tem a USE flag **ddate**)

Ele não baixa o pacote inteiro do ddate, mas apenas aplica, além dos patches do Gentoo, um pequeno patch (de umas 40 linhas) que altera o ClockTool.cc.

{{< figure src="/wp-content/uploads/2010/08/a2.png" title="Screenshot do emerge" >}}

Divirta-se!

 [1]: http://tiagomadeira.com/2010/08/calendario-santo-discordiano-no-fluxbox/
