---
title: Como recuperar a inicialização do Linux depois de instalar Windows
date: 2008-06-20T20:59:28+00:00
url: /2008/06/como-recuperar-o-boot-do-linux-depois-de-instalar-o-windows/
tags:
  - boot
  - dicas
  - grub
  - hd
  - lilo
  - linux
  - livecd
  - mbr
  - partições
  - windows
---

Esse é um problema super comum que já resolvi para dezenas de pessoas e resolvi escrever aqui pra não ficar tendo que repetir a resolução toda vez que alguém me perguntar.

O caso é o seguinte: você tem Linux numa das suas partições e por algum motivo estranho instala Windows (ou reinstala) na outra. O Windows, como todo sistema operacional para idiotas, simplesmente limpa sua MBR (master boot record do HD) sem lhe perguntar nada e com isso deleta seu gerenciador de boots (neste post estarei tratando o Grub e o Lilo).

Aí você se vê triste, desiludido e em muitos casos resolve reinstalar o Linux só pra recuperar o boot. Péssimo, não? Mas não se preocupe: seus problemas acabaram.

Tudo o que você precisará para recuperar sua MBR (com Grub ou Lilo) é:

1. Um livecd (não precisa ser um daqueles pesadões, um disco 1 do Slackware ou Gentoo Minimal resolve) com a mesma arquitetura do seu Linux. Se você não tem, sugiro o Gentoo Minimal porque é leve: [o download você faz aqui][1]. Se você não sabe o que é arquitetura, você provavelmente usa x86.
2. Saber em que partição se encontra seu Linux (tipo: /dev/hda1, /dev/sda1, ou algo do gênero) e em que HD ele se encontra (tipo: /dev/hda, /dev/sda… é só tirar o número da partição)

Se você não sabe em que partição/hd está seu Linux, é fácil descobrir através do comando `fdisk -l`

Boote o livecd (considerarei que você sabe fazer isso, do contrário não teria conseguido instalar o Windows) e abra um terminal se seu livecd for gráfico (é aquela telinha preta, também pode ser chamado de Console).

Agora o que vamos fazer é montar a partição root do seu Linux (e considerarei que /boot não está numa partição separada, se estiver monte ela também), entrar nela e reinstalar o Grub ou o Lilo.

Se o seu terminal terminar com um caractere \$ (cifrão), digite “sudo su” para virar root. Agora pode digitar o que segue:

```
# mkdir linux
# mount /dev/hda1 linux
# mount -o bind /dev linux/dev
# mount -t proc none linux/proc
# chroot linux /bin/bash
# source /etc/profile
# cat /proc/mounts > /etc/mtab
```

Não se esqueça de substituir /dev/hda1 pela partição do seu Linux.

Agora, se você usa Grub (se não, provavelmente esse comando não dará problema, então se você estiver na dúvida pode chutar esse):

```
# grub-install --recheck /dev/hda
```

(substituindo /dev/hda pelo device do seu hd)

**Ou** se você usa Lilo:

```
# lilo
```

E pronto! Limpando a sujeira…

```
# exit
# umount linux/proc
# umount linux/dev
# umount linux
```

E pode rebootar pro seu velho Linux.

Se você não tinha Windows antes, o Windows não vai por mágica aparecer nas suas opções de boot. Então, no seu velho Linux, é só editar o arquivo /boot/grub/menu.lst (pra quem usa Grub) ou /etc/lilo.conf (pra quem usa Lilo) e colocar linhas para bootar o Windows, respectivamente:

```
title Windows
rootnoverify (hd0,1)
makeactive
chainloader +1
```

e

```
other=/dev/hda2
label=Windows
```

(assumindo que seu Windows está em /dev/hda2)

É importante que você note que o Grub inicia suas contagens a partir do 0. hda1 é (hd0,0), hda2 é (hd0,1), hdb1 é (hd1,0), hdc2 é (hd2,1). Deu pra entender? Letra antes da vírgula (a = 0, b = 1, c = 2, …) e número depois da vírgula (1 = 0, 2 = 1, 3 = 2, …)

Para editar um arquivo como root, escreva “su” para virar root e use “vim”, ou, se você não sabe fazer isso, sua distribuição provavelmente permite que você digite algo como: “sudo gedit arquivo” ou “sudo kwrite arquivo”.

Se você usa Lilo, é necessário que depois de salvar o arquivo você entre no terminal como root e digite:

```
# lilo
```

… para salvar suas alterações na MBR.

É isso. Reinicie seu computador e divirta-se com seu gerenciador de boots funcionando novamente. Qualquer dúvida, escrevam comentários.

[1]: http://www.gentoo.org/main/en/where.xml
