---
title: udev e suas regras maravilhosas
type: post
date: 2006-09-12T20:17:49+00:00
url: /2006/09/udev-e-suas-regras-maravilhosas/
categories:
  - Dicas
tags:
  - dicas
  - freebsd
  - hardware
  - hotplug
  - kernel
  - linux
  - linuxchix
  - piter punk
  - slackware
  - udev

---
Participei nos dias 8 e 9 do [IV Encontro Nacional Linuxchix Brasil][1] em Florianópolis. O evento teve umas palestras interessantes, entre as quais destaco as do pessoal do [FreeBSD][2], a do [Luiz Fernando Capitulino][3] sobre o desenvolvimento do Kernel, a do [Hélio Castro][4] sobre interfaces gráficas 3D, mas em especial a do [Piter PUNK][5] sobre o [udev][6] (talvez porque eu sou um usuário [Slackware][7] =). E é sobre o **udev** que eu resolvi falar nesse artigo…

* * *

Tenho até vergonha de dizer que até semana passada eu não tinha percebido que o **hotplug** não estava mais sendo inicializado no meu [Slackware][7]… Só depois da palestra que aprendi que o [Kernel][8] 2.6 acaba com a necessidade do **hotplug** substituindo por um novo e poderoso aplicativo chamado **udev**. Isso é uma mudança e tanto, que traz alguns prós e contras (na verdade, eu só vi prós).

### O que é o udev?

Bom… Segundo a <cite><a href="http://en.wikipedia.org">Wikipedia</a></cite>, <q><a href="http://en.wikipedia.org/wiki/Udev">udev</a> is the device manager for the Linux 2.6 kernel series. Its primary function is managing device nodes in /dev. It is the successor of devfs and hotplug, which means that it handles the /dev directory and all user space actions when adding/removing devices, including firmware load</q>.

### Como funciona o udev

Na inicialização do sistema, o **udev** vê no **/sys** que dispositivos foram encontrados pelo Kernel e adiciona os dispositivos ao **/dev** (por enquanto, vou fingir que ele só adiciona os dispositivos ao /dev).

Depois, seu _daemon_ fica rodando para adicionar novos dispositivos assim que eles aparecerem.

É bem mais rápido que no **hotplug** e parece funcionar bem.

### E onde está a mágica?

O **udev** possue um diretório de regras (_/etc/udev/rules.d_) onde adicionamos arquivos de texto com uma sintaxe super fácil para dizer o que queremos fazer com cada dispositivo que é adicionado ao sistema.

#### E o que queremos fazer com cada dispositivo que é adicionado ao sistema?

Hmmm… Isso depende muito da sua necessidade, mas deixe-me citar algumas possibilidades das regras do **udev**:

  * **Dar nome aos dispositivos** – Pra que uma pasta /dev cheia de nomes difíceis que você não entende? Com o **udev**, você pode chamar seu **sda1** de **pendrive** ou o seu **hdc** de **cdrom**.
  * **Dar nomes diferentes para dispositivos _iguais_** – Hoje em dia vivemos pluggando _pendrives_, _máquinas digitais_, _MP3 players_, etc. em nossas placas USB. Com o **udev**, podemos fazer com que a nossa _máquina_ da Canon chame-se _/dev/canon_, a nossa _máquina_ da Sony chame-se _/dev/sony_, o _pendrive_ da mamãe chame-se _/dev/mamae_ e o nosso _MP3 Player_ chame-se _/dev/mp3player_.
  * **Adicionar links simbólicos aos dispositivos** – Podemos fazer nosso CD-ROM ter vários links como _cdrom, dvd, cdrw, cdwriter_…
  * **Mudar permissões dos dispositivos** – Podemos fazer com que o _pendrive_ da mamãe possa, logo que for pluggado em qualquer porta USB, ser acessado por ela (e somente por ela).
  * **Executar comandos quando ocorrem alterações nos dispositivos** – Sempre que a mamãe colocar o seu _pendrive_ numa porta USB podemos montá-lo para ela e já abrir o dispositivo no [Konqueror][9] e quando ela pluggar a sua máquina digital da Canon podemos mudar suas permissões, linká-la para /dev/camera e abrir o [digiKam][10].
  * … entre provavelmente muitas outras coisas que eu não me lembro ou não sei fazer (eu só conheço o **udev** há quatro dias!)

Claro que o _udev_ pode ser útil para servidores também, para trocar hardware ou reiniciar o computador com segurança (ex.: você pode dizer que o HD principal seja sempre /dev/principal e assim mesmo que ele passe a ser o seu **Second Slave** ele funciona), mas estou focando mais o uso doméstico. A “mamãe” é um usuário leigo que não precisa saber montar dispositivos ou qual o nome do programa que baixa as fotos da máquina. Ela simplesmente plugga a sua máquina e o digiKam abre.

#### Legal… E como é que eu faço essas regras?

A sintaxe dos arquivos em **/etc/udev/rules.d** é muito simples. Você simplesmente separa por vírgulas as condições que você quer para que as ações que você quer fazer e as ações.

#### A máquina fotográfica da mamãe

```
ACTION=="add", BUS=="usb", SYSFS{product}=="Canon Digital Camera",
GROUP="camera", MODE="0660", SYMLINK+="camera", RUN:="/bin/su mamae -c
'/usr/bin/abredigikam.sh'"
```

Aqui em casa, usei um “abredigikam.sh” assim:

```bash
#!/bin/bash

export DISPLAY=":0"
/opt/kde/bin/digikam
```

##### Sinais do exemplo

  * Os dois iguais (==) são para expressar condição, como no C (e em um monte de linguagens derivadas dele).
  * O “=” atribui
  * O “+=” atribui “mais uma coisa” (_append_)
  * O “:=” atribui uma coisa como constante (ou seja, neste caso eu ou os scripts de regras da minha distro não conseguem mais mudar o valor do “RUN”).

##### Variáveis do exemplo

  * **ACTION**: A ação que está sendo feita com o dispositivo (neste caso é a adição dele – _add_)
  * **BUS**: Barramento. Neste caso, a USB.
  * **SYSFS**: Variáveis específicas deste dispositivo (depois vou mostrar como encontramos elas)
  * **GROUP**: Grupo em que o dispositivo está.
  * **MODE**: Permissões do dispositivo.
  * **SYMLINK**: Links simbólicos para o dispositivo.
  * **RUN**: Comando Shell para executar.

Não conheço todas as variáveis, mas para saber mais você pode consultar o [Writing udev rules][11] (o objetivo desse post não é entrar em detalhes).

#### udevmonitor

O **udevmonitor** é um aplicativo que imprime os eventos recebidos pelo Kernel e o evento que o **udev** manda depois do proessamento de regras em tempo real. Veja o que acontece, por exemplo, quando pluggo uma máquina digital na minha porta USB:

```
UEVENT[1158086870.385094] add@/devices/pci0000:00/0000:00:02.0/usb1/1-1
UEVENT[1158086870.388950] add@/devices/pci0000:00/0000:00:02.0/usb1/1-1/1-1:1.0
UEVENT[1158086870.389571] add@/class/usb_device/usbdev1.3
UDEV  [1158086870.390983] add@/devices/pci0000:00/0000:00:02.0/usb1/1-1
UDEV  [1158086870.404378] add@/devices/pci0000:00/0000:00:02.0/usb1/1-1/1-1:1.0
```

É interessante para acompanharmos os dispositivos que são encontrados pelo **udev**. Veja agora o **udevmonitor** quando eu despluggo a minha máquina:

```
UEVENT[1158089965.438657] remove@/devices/pci0000:00/0000:00:02.0/usb1/1-1/1-1:1.0
UEVENT[1158089965.438765] remove@/class/usb_device/usbdev1.3
UEVENT[1158089965.438794] remove@/devices/pci0000:00/0000:00:02.0/usb1/1-1
UDEV  [1158089965.440899] remove@/devices/pci0000:00/0000:00:02.0/usb1/1-1/1-1:1.0
UDEV  [1158089965.443341] remove@/class/usb_device/usbdev1.3
UDEV  [1158089965.444795] remove@/devices/pci0000:00/0000:00:02.0/usb1/1-1
```

#### udevinfo

O **udevinfo** imprime informações sobre um dispositivo. Para descobrir que o **SYSFS{product}** da minha máquina era **Canon Digital Camera** foi este comando que eu utilizei, da seguinte maneira:

```
<strong># udevinfo -q all -n usbdev1.4</strong>
P: /class/usb_device/usbdev1.4
N: usbdev1.4
S: bus/usb/1/4
```

(descobri que ela estava na **usbdev1.4** usando o **udevmonitor**)

Aí agora sabendo o _path_ eu descobri todo o resto: (a saída é grande, use a barra de rolagem)

```
# udevinfo -a -p /class/usb_device/usbdev1.4
Udevinfo starts with the device specified by the devpath and then
walks up the chain of parent devices. It prints for every device
found, all possible attributes in the udev rules key format.
A rule to match, can be composed by the attributes of the device
and the attributes from one single parent device.

  looking at device '/class/usb_device/usbdev1.4':
    KERNEL=="usbdev1.4"
    SUBSYSTEM=="usb_device"
    DRIVER==""
    SYSFS{dev}=="189:3"

  looking at parent device '/devices/pci0000:00/0000:00:02.0/usb1/1-1':
    ID=="1-1"
    BUS=="usb"
    DRIVER=="usb"
    SYSFS{configuration}==""
    SYSFS{product}=="Canon Digital Camera"
    SYSFS{manufacturer}=="Canon Inc."
    SYSFS{maxchild}=="0"
    SYSFS{version}==" 1.10"
    SYSFS{devnum}=="4"
    SYSFS{speed}=="12"
    SYSFS{bMaxPacketSize0}=="8"
    SYSFS{bNumConfigurations}=="1"
    SYSFS{bDeviceProtocol}=="00"
    SYSFS{bDeviceSubClass}=="00"
    SYSFS{bDeviceClass}=="00"
    SYSFS{bcdDevice}=="0001"
    SYSFS{idProduct}=="30f9"
    SYSFS{idVendor}=="04a9"
    SYSFS{bMaxPower}=="  2mA"
    SYSFS{bmAttributes}=="c0"
    SYSFS{bConfigurationValue}=="1"
    SYSFS{bNumInterfaces}==" 1"

  looking at parent device '/devices/pci0000:00/0000:00:02.0/usb1':
    ID=="usb1"
    BUS=="usb"
    DRIVER=="usb"
    SYSFS{configuration}==""
    SYSFS{serial}=="0000:00:02.0"
    SYSFS{product}=="OHCI Host Controller"
    SYSFS{manufacturer}=="Linux 2.6.17.11 ohci_hcd"
    SYSFS{maxchild}=="4"
    SYSFS{version}==" 1.10"
    SYSFS{devnum}=="1"
    SYSFS{speed}=="12"
    SYSFS{bMaxPacketSize0}=="64"
    SYSFS{bNumConfigurations}=="1"
    SYSFS{bDeviceProtocol}=="00"
    SYSFS{bDeviceSubClass}=="00"
    SYSFS{bDeviceClass}=="09"
    SYSFS{bcdDevice}=="0206"
    SYSFS{idProduct}=="0000"
    SYSFS{idVendor}=="0000"
    SYSFS{bMaxPower}=="  0mA"
    SYSFS{bmAttributes}=="e0"
    SYSFS{bConfigurationValue}=="1"
    SYSFS{bNumInterfaces}==" 1"

  looking at parent device '/devices/pci0000:00/0000:00:02.0':
    ID=="0000:00:02.0"
    BUS=="pci"
    DRIVER=="ohci_hcd"
    SYSFS{modalias}=="pci:v000010B9d00005237sv0000103Csd00000024bc0Csc03i10"
    SYSFS{local_cpus}=="1"
    SYSFS{irq}=="10"
    SYSFS{class}=="0x0c0310"
    SYSFS{subsystem_device}=="0x0024"
    SYSFS{subsystem_vendor}=="0x103c"
    SYSFS{device}=="0x5237"
    SYSFS{vendor}=="0x10b9"

  looking at parent device '/devices/pci0000:00':
    ID=="pci0000:00"
    BUS==""
    DRIVER==""
```

### Os contras

Hmmm… Na verdade, pelo que eu me lembro da palestra, o **udev** só tem um contra. Ele vai detectando os dispositivos e jogando-os no **/dev** na ordem em que ele vai encontrando-os. Então, às vezes a minha placa de rede SiS pode ser detectada como **eth0** e a Realtek como **eth1** e no outro dia o contrário. Mas contornar isso é muito simples, usando aquelas regras (e inclusive podemos dar os nomes **/dev/placa-sis** e **/dev/placa-realtek** para nossas placas). =)

### Encontrou um erro?

Eu ainda tô conhecendo o **udev** (como eu disse, conheci ele nesse final de semana), então meu texto pode ter alguma falha ou pode estar faltando alguma informação. Por favor, comente se encontrar algum erro ou quiser sugerir algo legal… =)

### Para mais informações…

```
$ man udev
```

… e a [página do udev][12]

 [1]: http://www.linuxchix.org.br/?q=node/71
 [2]: http://www.fug.com.br
 [3]: http://www.linuxchix.org.br/?q=programacao#kernel
 [4]: http://www.linuxchix.org.br/?q=programacao#kde
 [5]: http://www.piterpunk.info02.com.br
 [6]: http://www.linuxchix.org.br/?q=programacao#udev
 [7]: http://www.slackware.com
 [8]: http://www.kernel.org
 [9]: http://konqueror.kde.org
 [10]: http://www.digikam.org
 [11]: http://www.reactivated.net/writing_udev_rules.html
 [12]: http://www.kernel.org/pub/linux/utils/kernel/hotplug/udev.html

