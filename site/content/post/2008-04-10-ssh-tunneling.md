---
title: 'HOWTO: Como usar Pandora Radio no Brasil'
type: post
date: 2008-04-10T20:47:58+00:00
url: /2008/04/ssh-tunneling/
categories:
  - Dicas
tags:
  - brasil
  - dicas
  - howto
  - linux
  - pandora
  - pandora radio
  - shell
  - ssh
  - ssh tunneling
  - unix

---
O projeto [Pandora][1] é uma rádio on-line que funciona como um catálogo bem categorizado de milhares de CDs e é capaz de reproduzir músicas parecidas com o tipo que você diz para ele que gosta. Ficou confuso? É assim: eu entro lá e escrevo que gosto de Chico Buarque. Aí ele me diz: vamos tocar uma música do Chico que tem suas características principais como canto em português, violão leve, etc. Responda se você gostou ou não e baseado nessa escolha tocaremos outro estilo ou continuaríamos no mesmo.

É uma idéia muito legal porque no fim você ouve apenas o que gosta, mas também descobre novas músicas (porque ele não fica repetindo artista, álbum, música, mas só as características da música ou do artista que você selecionou a princípio).

Fazia tempo que eu não usava o Pandora porque num esforço comunitário de minha família, digitalizamos algumas centenas de CDs criando uma biblioteca de 35 gb em MP3. Porém, meu desktop (Durion 1.1) que era meu servidor de música (MPD) recentemente morreu (a placa-mãe deu pau) e, cansado de ouvir as poucas músicas que tinha aqui no laptop, resolvi ver como andava o Pandora.

Porém, fui surpreendido por uma mensagem dizendo que por causa de copyright brasileiros não podem mais usar o Pandora. Isso é um problema que eles dizem estar conversando com as autoridades para resolver, mas por hora não podem aceitar IPs brasileiros, o que me levou a buscar uma solução.

A primeira coisa que pensei foi procurar um servidor de proxy nos Estados Unidos. É fácil se você entrar no [Public Proxy Servers][2], mas a velocidade deles realmente não me agrada, ainda mais pra ouvir uma rádio on-line. Então, pesquisei um pouco e depois de algum tempo encontrei a solução: SSH tunneling (túneis de SSH?)

Eu uso SSH todo dia e nunca tinha me dado conta que ele tem uma opção super interessante que é numa dada porta criar um tunelamento que pode ser usado como servidor SOCKS (proxy). Aí você pensa: mas qual a vantagem? De qualquer jeito você terá que usar um servidor proxy e ficar com a internet mais lenta. Sim, é verdade, mas o meu servidor na Dreamhost é sem dúvidas muito mais rápido que um proxy público e eu tenho certeza que minhas informações ficam seguras. Aliás, é por segurança que a maioria das pessoas usa SSH tunneling (ex.: pessoas com laptop numa rede wireless pública)

Vamos ao prático:

```
$ ssh -C -D 666 -N user@host
```

E configure seu navegador para usar Socks (eu usei V5, mas a V4 deve funcionar também) para o endereço: 127.0.0.1 (isso mesmo, não é o host que você colocou no SSH, é a sua máquina, porque ela que criou o servidor) na porta que você especificou com o parâmetro -D (nesse caso 666)

As opções do SSH que eu utilizei no exemplo são:

  * **-C**: comprime entrada e saída. Nos exemplos que eu peguei vinha, acredito que seja pras transferências serem mais rápidas.
  * **-D [bind:]port**: porta (e um endereço opcional) pro servidor rodar
  * **-N**: não executa nenhum comando (ie não abre um shell)

Esta dica funciona em sistemas operacionais que tem SSH (Linux, FreeBSD e provavelmente qualquer outro Unix-like). Para usá-la no Windows, você deve usar o [PuTTy][3].

 [1]: http://www.pandora.com/
 [2]: http://www.publicproxyservers.com/
 [3]: http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html

