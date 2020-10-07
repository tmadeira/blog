---
title: O HD chegou!
date: 2005-08-19T23:55:15+00:00
excerpt: Finalmente chegou o HD novo... De volta a toda com o laptop!
url: /2005/08/o-hd-chegou/
tags:
  - hardware
  - hd
  - linux
  - slackware
  - windows
---

Finalmente de HD novo, já intalei WinXP e Slackware (aliás, coloquei umas fotos no Flickr). Dessa vez, dividi o HD em sete partições.

- hda1 – 10gb, Linux ext3, Slackware
- hda2 – 7,5gb, NTFS, Windows XP
- hda3 – 7,5gb, FAT32, Windows 98\*
- hda5 – 5gb, Linux, \*\*
- hda6 – 1gb, Linux Swap
- hda7 – 5gb, FAT32, \*\*\*
- hda8 – 4gb, Linux ext3, homes\*\*\*\*

\* – Ainda não instalei o Windows 98 nela, mas farei-o em breve. “Por que você quer ter um Win98 aí?” Porque eu gosto do DOS e quero fazer uns testes lá.  
\*\* – É uma partição que eu criei pra instalar outros sistemas para testar. O hda1 sempre vai ser alguma coisa mais estável, como esse Slackware que eu tô usando agora.  
\*\*\* – Uma FAT para passar dados do NTFS para o Linux e vice-versa. “Por que não uso o do Win98?” Pelo mesmo motivo que eu separo o home do sistema (veja abaixo o \*\*\*\*)  
\*\*\*\* – Resolvi deixar as Home fora dos sistemas, porque além de poder acessar das duas partições o mesmo home (os mesmos arquivos de configuração, por exemplo), quando eu quero formatar um sistema ou reinstalar, fico mais tranquilo.

Ficou legal, né?

Baixei o Grub (agora só tô usando ele em todos os computadores que tenho instalado Linux), refiz alguns programas em Bash, reconfigurei todo o sistema, coloquei até as extensões no meu Firefox e aqui estou de volta outra vez.

Ultimamente, já que estava sem computador, andei brincando com dois computadores. O primeiro, do laboratório de informática do Colégio, é o que eu vou usar a partir de agora para fazer o site. Instalei Slackware, Fluxbox e tá bem legalzinho. O segundo é o computador que meu pai usa no trabalho. Um Pentium 4 animal, instalei Slack com KDE (que pra abrir o sistema inteiro, porque coloquei o runlevel dele pra 4, demora uns 20s).

Além disso, andei fazendo outras coisas legais também, como apresentando o fórum do Colégio para os alunos: [Quer saber?][1] e iniciando um projeto de software livre para leigos: http://sl.tiagomadeira.net. [Aqui][2] tem a explicação de porquê estou criando essa página.

Bom, por enquanto é isso. Ontem foi a primeira vez que desenvolvi um problema lógico desde o curso da OBI (também, não deu tempo, o computador pifado aqui!), que foi de geometria (ver se um ponto está dentro ou fora de um polígono). Mas ainda estou corrigindo-o, então depois coloco na seção de códigos.

[1]: http://www.salesianoitajai.g12.br/quersaber
[2]: http://www.salesianoitajai.g12.br/quersaber/viewtopic.php?t=36
