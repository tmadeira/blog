---
title: Instalando winprinters no Slackware
type: post
date: 2005-08-10T20:00:07+00:00
excerpt: Provavelmente serve pra outras distros Linux também... Um guia de como instalar uma impressora "for Windows" (PPA), como as HP Deskjets 710C, 720C, 722C, 820Cse, 820Cxi, 1000Cse e 1000Cxi.
url: /2005/08/instalando-winprinters-no-slackware/
categorias:
  - Dicas
tags:
  - cups
  - dicas
  - ghostscript
  - impressoras
  - linux
  - slackware
  - winprinters

---
**Este artigo é um pouco velho (de janeiro deste ano) e foi originalmente postado no [SOSPHP][1]. Mas percebi que ainda não tinha colocado ele aqui no site (na época em que escrevi ainda nem tinha o site). Já que eu tô sem HD e, por causa disso, sem fazer nada de útil/novo no computador, resolvi colá-lo aqui. Não mudei o texto e nem _re-testei_ a dica. Qualquer coisa, comentem.**

Baseando-me num problema recente que tive com a minha HP Deskjet 820Cxi que é uma winprinter (a diferença entre ela e uma impressora normal é como a de modem e winmodem) que usa PPA ao invés do PLD das HPs (e que é um sistema muito pior – coisa que não sabia quando comprei – e inclusive eles já pararam de fabricar esse tipo de impressora), resolvi escrever esse pequeno artigo que é meio que uma tradução [deste site][2] porque não consegui encontrar material em português sobre a instalação de winprinters (consegui encontrar, mas só notícias ruins sobre ela e maneiras que não davam totalmente certo).

Algumas distros (acho que o Kurumin e o Knoppix) já possuem suporte nativo para essas impressoras, mas no meu Slackware não foi mole instalar.

Esta receita foi testada somente no Slackware 10 (testei com o Kernel 2.6.9, mas acho que funciona com a série 2.4 também) e não tive problema algum seguindo estes passos.

Este artigo serve para instalar as impressoras:

  * HP Deskjet 710C
  * HP Deskjet 720C
  * HP Deskjet 722C
  * HP Deskjet 820Cse
  * HP Deskjet 820Cxi
  * HP Deskjet 1000Cse
  * HP Deskjet 1000Cxi

E para instalar a impressora você precisará: (clique no link para entrar na página dele e fazer download)

  * [Ghostscript][3]
  * [Ghostscript Fonts][3]
  * [CUPS][3]
  * [foomatic-rip][4] e [foomatic-gswrapper][5]
  * [Driver CUPS PPD da sua impressora][6]
  * [pnm2ppa][7]

### Instalação em alguns passos:

  1. Baixe e instale todos os arquivos dos locais descritos acima. Na maioria dos Linux, já tem Ghostscript e CUPS.

    <small>O pnm2ppa precisa ser compilado usando # make e # make install. Daí vá em /etc/pnm2ppa.conf e altere o valor da primeira variável que aparece no arquivo (VERSION=0) para a versão da sua impressora (no meu caso VERSION=820)<br /> O driver CUPS PPD da impressora deve ser baixado e copiado para sua pasta de modelos da CUPS (no meu Slackware é /usr/share/cups/model)<br /> Os foomatics precisam ser copiados para /usr/local/bin e depois linkados na pasta de filtros do cups (# ln -s /usr/local/bin/foomatic-rip /usr/lib/cups/filter/foomatic-rip e a mesma coisa com o outro)</small>
  2. Inicie o daemon do cups escrevendo **\# cupsd** no console e abra no Firefox, Lynx ou qualquer browser de sua preferência o endereço http://localhost:631.
  3. Adicione a impressora (a localização é /dev/lp0, /dev/lp1… ou no meu caso foi smb://windows/hp820c porque tá configurada no meu Windows 98; o nome pode ser o de sua preferência – sem espaços – coloquei hp820c)

Se tudo tiver dado certo, quando chegar na parte de driver vai existir lá o driver da sua impressora e a instalação vai sair sem problemas.

 [1]: http://www.sosphp.com.br/forum/index.php?showtopic=2971
 [2]: http://brendan.sdf-eu.org/articles/install_winprinter.php
 [3]: http://www.cups.org/software.html
 [4]: http://www.linuxprinting.org/download.cgi?filename=foomatic-rip&show=0
 [5]: http://www.linuxprinting.org/download.cgi?filename=foomatic-gswrapper&show=0
 [6]: http://www.linuxprinting.org/show_driver.cgi?driver=pnm2ppa
 [7]: http://sourceforge.net/projects/pnm2ppa/
