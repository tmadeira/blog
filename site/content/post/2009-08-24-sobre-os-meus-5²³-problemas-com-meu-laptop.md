---
title: Sobre os meus 5²³ problemas com meu laptop
type: post
date: 2009-08-25T00:40:43+00:00
url: /2009/08/sobre-os-meus-5²³-problemas-com-meu-laptop/
categories:
  - Cotidiano
tags:
  - alice
  - amazon
  - compal
  - funtoo
  - gentoo
  - hardware
  - kernel
  - l92
  - linux
  - notebook
  - reiserfs
  - windows

---
Comprei [na Fnac][1] no dia 15 de janeiro deste ano um [Amazon PC Slim L92 12”][2] com as seguintes especificações:

  * **Processador:** Intel(R) Core(TM)2 Duo CPU T5750 @ 2.00GHz
  * **Placa-mãe:** Compal JFT00 (versão da bios: 1.05A)
  * **Disco rígido:** Samsung HM250JI (250GB)
  * **Memória RAM:** 4GB DDR2 SODIMM (dois pentes de 2GB)

O resto é irrelevante para este post, mas pros _geeks desocupados_ deixo aqui o **lspci** e o **lsusb**:

```
root@alice ~ # lspci -nn
00:00.0 Host bridge [0600]: Intel Corporation Mobile PM965/GM965/GL960 Memory Controller Hub [8086:2a00] (rev 03)
00:02.0 VGA compatible controller [0300]: Intel Corporation Mobile GM965/GL960 Integrated Graphics Controller [8086:2a02] (rev 03)
00:02.1 Display controller [0380]: Intel Corporation Mobile GM965/GL960 Integrated Graphics Controller [8086:2a03] (rev 03)
00:1a.0 USB Controller [0c03]: Intel Corporation 82801H (ICH8 Family) USB UHCI Controller #4 [8086:2834] (rev 03)
00:1a.7 USB Controller [0c03]: Intel Corporation 82801H (ICH8 Family) USB2 EHCI Controller #2 [8086:283a] (rev 03)
00:1b.0 Audio device [0403]: Intel Corporation 82801H (ICH8 Family) HD Audio Controller [8086:284b] (rev 03)
00:1c.0 PCI bridge [0604]: Intel Corporation 82801H (ICH8 Family) PCI Express Port 1 [8086:283f] (rev 03)
00:1c.1 PCI bridge [0604]: Intel Corporation 82801H (ICH8 Family) PCI Express Port 2 [8086:2841] (rev 03)
00:1c.2 PCI bridge [0604]: Intel Corporation 82801H (ICH8 Family) PCI Express Port 3 [8086:2843] (rev 03)
00:1d.0 USB Controller [0c03]: Intel Corporation 82801H (ICH8 Family) USB UHCI Controller #1 [8086:2830] (rev 03)
00:1d.1 USB Controller [0c03]: Intel Corporation 82801H (ICH8 Family) USB UHCI Controller #2 [8086:2831] (rev 03)
00:1d.2 USB Controller [0c03]: Intel Corporation 82801H (ICH8 Family) USB UHCI Controller #3 [8086:2832] (rev 03)
00:1d.7 USB Controller [0c03]: Intel Corporation 82801H (ICH8 Family) USB2 EHCI Controller #1 [8086:2836] (rev 03)
00:1e.0 PCI bridge [0604]: Intel Corporation 82801 Mobile PCI Bridge [8086:2448] (rev f3)
00:1f.0 ISA bridge [0601]: Intel Corporation 82801HEM (ICH8M) LPC Interface Controller [8086:2815] (rev 03)
00:1f.1 IDE interface [0101]: Intel Corporation 82801HBM/HEM (ICH8M/ICH8M-E) IDE Controller [8086:2850] (rev 03)
00:1f.2 SATA controller [0106]: Intel Corporation 82801HBM/HEM (ICH8M/ICH8M-E) SATA AHCI Controller [8086:2829] (rev 03)
00:1f.3 SMBus [0c05]: Intel Corporation 82801H (ICH8 Family) SMBus Controller [8086:283e] (rev 03)
01:00.0 Ethernet controller [0200]: Atheros Communications Inc. AR242x 802.11abg Wireless PCI Express Adapter [168c:001c] (rev 01)
02:00.0 Ethernet controller [0200]: Marvell Technology Group Ltd. 88E8055 PCI-E Gigabit Ethernet Controller [11ab:4363] (rev 12)
```

```
root@alice ~ # lsusb
Bus 002 Device 002: ID 0bda:0158 Realtek Semiconductor Corp. Mass Stroage Device
Bus 002 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 006 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 005 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 004 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 001 Device 002: ID 04f2:b052 Chicony Electronics Co., Ltd
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 003 Device 002: ID 147e:2016
Bus 003 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
```

**Alice** (é o nome do laptop) veio com Windows Vista 64 bits e a primeira coisa que notei nela foi um estranho desligamento do nada (no seu primeiro dia de vida), antes mesmo de eu instalar Linux! (ou seja, nos seus primeiros minutos, pois obviamente a primeira coisa a fazer quando se recebe um computador com Windows é instalar um Linux)

{{< figure src="/wp-content/uploads/2009/08/1244.jpg" title="Compal JFT00" >}}

Pensei ser problema do sistema operacional e não dei bola. Mas aí a coisa ficou estranha: coloquei um CD minimal do Gentoo amd64 e quando ele iniciava o computador desligava do nada.

Para não precisar resolver o problema na hora, instalei um Ubuntu 32 bits (que, estranhamente, não desligava) e entrei na internet para pesquisar.

A página que melhor refletiu esse problema foi essa: [64-bit Intrepid automatic permanent reboot loop related to having exactly 4GB of memory][4] (Ubuntu Bug #272530) e talvez também [essa][5].

Como o laptop estava com lacres de garantia, ao invés de abrir e tirar 2GB de memória pra testar levei-a até a divisa entre Florianópolis e São José (um local lá perto de onde o [Peterson][6] vive) para a _Wil Informática_, única autorizada da Amazon PC na região.

Lá chegando o cara do suporte falou que tinha outros laptops da Amazon dando problema e que podia ser devido aos 4GB de memória. Trocou os pentes e pensou que funcionaria. Funcionou por alguns minutos na mão dele. Chegando em casa notei que o problema continuava e, como não tinha mais lacres, tirei um pente.

O laptop com 2GB de memória RAM não teve problema algum. Instalei Gentoo, pesquisei mais um pouco e encontrei a opção _mem=4000M_ que deveria passar para o Kernel só reconhecer 3 e com isso funcionar com 64 bits.

{{< figure src="/wp-content/uploads/2009/08/amazonPC.jpg" title="Amazon PC" >}}

Continuei pesquisando, entrei em contato com a Amazon (que não ajudou em nada a não ser sugerir [algo equivalente a mem=4000M pra Windows][8]) e troquei e-mails com o Wil (que prometeu passar minha queixa para a Amazon trocar minha placa-mãe e desde 9 de fevereiro não me respondeu). No fim, não tive opção senão ficar com o laptop e, como ele não dava problemas com 3GB, resolvi deixar pra lá.

Há cerca de dois meses, porém, o laptop começou a apresentar outro problema. De vez em quando (quando eu fazia-o processar muito), ele desligava do nada. Quem tem noção de como é o Gentoo sabe que fazer o computador processar muito faz parte do dia-a-dia.

Estranhando o comportamento, mas atribuindo-o a eu estar usando versões bleeding edge (hard masked) de Kernel, GCC & etc, resolvi usar um Ubuntu 32 bits por um tempo até ter disponibilidade pra reinstalar um Gentoo com carinho.

Nos primeiros dias de Ubuntu ele travava com frequência, mas acreditei que fosse por culpa da placa de vídeo (tinha duas opções no Ubuntu: usava Compiz — blacklisted pa minha placa de vídeo — ou tinha um lag infernal pra trocar de área de trabalho no Gnome. Fiquei com a primeira), então não dei bola. Curiosamente os problemas cessaram e continuei usando o Ubuntu [razoavelmente-]feliz por mais algum tempo. De vez em quando o computador desligava quando eu fazia operações bastante pesadas e eu estranhava, mas pensava que era coincidência.

{{< figure src="/wp-content/uploads/2009/08/funky.png" title="Funtoo" >}}

Nesse fim de semana ouvi falar do [Funtoo][10] e, mesmo com a agenda cheia, resolvi parar de usar Ubuntu de uma vez e fazer a Alice voltar a ter um sistema firme e forte. Baixei o stage 3 do <a href"http://dev.funtoo.org/linux/~funtoo/core2\_32/">~core2\_32</a>, caprichei nos arquivos de configuração e quando rodei um `emerge -DN world` **surpresa!** O laptop desligou.

Superaquecimento? Podia ser, o cooler fazia um barulho desumano, embora o tempo em São Paulo fosse muito frio. O ACPI não me ajudava, porque a temperatura da thermal zone ficava oscilando entre 42, 55, 63, 68, 73 e 79 graus celsius o tempo todo, assim como o barulho do cooler.

Deixei-a desligada por um dia, coloquei-a com as pontas apoiadas em livro, super ventilada, e fui compilar o Gentoo. Novamente, o laptop desligou.

_Só pode ser o problema da BIOS_, pensei. Vou ver se tem uma versão nova… [E não é que tem?][11]

{{< figure src="/wp-content/uploads/2009/08/1195_540.jpg" title="Windows na privada" >}}

Ótimo, sofro um pouco mas instalo o Vista, atualizo a BIOS e depois isso vai estar corrigido. Alterei minha tabela de partições, criei uma partição primária especialmente pro Windows (porque sei que ele é chato com isso), iniciei com enorme desgosto a instalação do Vista e depois de digitar a _product key_ mais de uma vez cheguei a conclusão que [não ia conseguir instalá-lo][13]. E depois ainda dizem que Linux é que é difícil…

Bom… _Vou tentar instalar o Gentoo 64 bits, afinal ele já tinha funcionado no início do ano._ Baixei e queimei um **system rescue cd**, o stage 3 do [~core2][14] e fui à luta. Resultado: desligamento sempre que tentava compilar alguma coisa pesada. Notava uma mensagem estranha muitas vezes: **gcc internal compiler error**

Está trabalhando demais? <a href"http://twitter.com/tmadeira/status/3486060876">Vou tentar compilar com MAKEOPTS=”-j1″</a>. Porém, mesmo resultado.

Resolvi voltar lá, configurei o Kernel e fui compilar. Em vários pontos dava essa _segmentation fault_ (eu ia retirando as partes que davam esse erro), um deles (o último que eu anotei, aí resolvi desistir) foi no **reiserfs**:

```
fs/reiserfs/dir.c:231: internal compiler error: Segmentation fault
```

Pensei que só podia ser porque estava usando versões de Kernel e GCC muito novas, potencialmente instáveis (2.6.30-gentoo-r5 e 4.4). Mas por via das dúvidas resolvi procurar na internet. [Eis o que encontrei][15]:

```
- Random segfaults during compilation. These are signalled by compilation
  failing at undetermined points. Often trying to recompile will succesfully
  compile the file it was complaining about, but will fail for another. This is
  in general a sign of hardware problems.
...
There are multiple causes that can cause the above symptoms:
- Flaky hardware. This is showstopper number one. The cause can be either:
  - Insufficient power supply. To detect this try to unplug as many auxiliary
    devices (like cd-players, usb devices, etc.)  as possible and see whether
    the problem persists
  - Overclocked memory or CPU's can show random anomalous behaviour. Worse some
    hardware has these problems even at "factory speed". Lowering the clockspeed
    would be the solution to this problems
  - Overheated CPU's. CPU's have several calculation units which have a specific
    location on the chip. Compilation tends to intensively use a few of those
    units. This can cause heat problems within these units even when the overall
    chip temperature is within limits. If overheating is a problem a better cpu
    cooler often works. (Underclocking also works as heat increases with
    frequency)
  - Broken chipsets. There are some chipsets on motherboards which are broken.
    sometimes the os (read linux kernel) can work around some of these bugs,
    sometimes the only solution is a new motherboard.
```

Resolvi ainda testar o Funtoo estável pra desencargo de consciência, mas dessa vez **o system rescue cd não bootou!!!** Suponho então _Broken chipset ou overclocked memory or CPU_. Qual dessas? Apostaria na primeira, mas de fato não faço muita ideia, porque não entendo nada de hardware.

Resignado, [ontem enviei e-mails][16] detalhados para quatro assistências técnicas de São Paulo. Acabou o horário comercial há duas horas e [nenhuma delas me respondeu][17].

Minha grande dificuldade é explicar isso pras assistências técnicas que, em geral, são compostas por pessoas que não entendem nada de Linux, nada de compilação e não compreendem nem mesmo o problema que tenho. Não que a última seja fácil, nem eu entendo esse problema (mas eu pelo menos sei que há algo errado). Elas testam deixando o computador ligado por algumas horas e, notando que ele não desliga, pensam que está tudo normal.

{{< figure src="/wp-content/uploads/2009/08/that-damntechsupportguy.gif" title="Computer Technical Support Hotline" >}}

Creio inclusive que há outros Compal JFT00 (a Intelbras produziu vários desses, além da Amazon) com o mesmo defeito, mas usuários comuns de computador nem devem notar.

Solução? Amanhã telefonarei pra Amazon e incomodarei eles até eles consertarem Alice de vez ou me prometerem um laptop novo. Por sorte Alice ainda está na garantia, que vai até janeiro de 2010. Espero que até lá eu já tenha resolvido tudo isso…

 [1]: http://www.fnac.com.br/amz-pc-core-2-duo-t5750-4gb-250gb-dvdrw-tela-12-1-FNAC,,informatica-507195-8427.html
 [2]: http://www.amazonpc.com.br/portal/portal/Amazon-PC-Slim-12-L92-AMZL92T57216P2/D28/?PROD=17
 [4]: https://bugs.launchpad.net/ubuntu/+source/linux/+bug/272530
 [5]: http://forum.notebookreview.com/showthread.php?t=252367
 [6]: http://orkutcidio.deliriocoletivo.org/
 [8]: /wp-content/uploads/2009/08/Alteração-na-configuração-do-Vista-no-L92.doc
 [10]: http://www.funtoo.org/
 [11]: http://www.compal.com/Download/NB/JFT00/BIOS/
 [13]: http://twitter.com/tmadeira/status/3485974146
 [14]: http://dev.funtoo.org/linux/~funtoo/core2/
 [15]: http://bugs.gentoo.org/show_bug.cgi?id=20600
 [16]: http://twitter.com/tmadeira/status/3492868176
 [17]: http://twitter.com/tmadeira/status/3519985264

