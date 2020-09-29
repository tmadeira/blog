---
title: Como baixar vídeos de Deutsche Welle (dw.de) e outros sites que usam RTMP
type: post
date: 2013-11-01T02:49:51+00:00
url: /2013/10/como-baixar-videos-de-deutsche-welle-dw-de-e-outros-sites-que-usam-rtmp/
categorias:
  - Dicas
---

**RTMP** ([Real Time Messaging Protocol][1]) é um protocolo desenvolvido pela Macromedia para fazer streaming de áudio e vídeo de um servidor para um Flash player.

Vou mostrar uma forma genérica para baixar vídeos de sites que usam RTMP usando como exemplo um vídeo do [Deutsche Welle][2]. Escolhi esse site porque ele não é suportado pela extensão [Video DownloadHelper][3] do Firefox. Porém, a dica funciona para vários outros sites que também usam esse protocolo.

---

Para começar, você vai precisar instalar dois programas livres: **Wireshark** e **RTMPDump**.

O primeiro serve para analisar os pacotes que estão passando na rede (quem manda para quem, que protocolo está sendo usado, qual seu conteúdo etc). O segundo baixa vídeos que estão disponíveis através do protocolo RTMP.

Para instalá-los no Ubuntu, basta escrever num terminal: `sudo apt-get install wireshark rtmpdump`. Em outras distribuições de Linux, use seu gerenciador de pacotes preferido.

No Windows ou outras plataformas onde é mais difícil instalar programas, você pode baixar esses programas (e seus códigos) em [wireshark.org][4] e [rtmpdump.mplayerhq.hu][5].

Antes que reclamem nos comentários, há muitos programas mais simples que poderiam substituir o Wireshark nessa dica, mas decidi usar o Wireshark porque ele permite muitas outras coisas que podem ser úteis no futuro. Com efeito, usando o Wireshark é fácil encontrar o endereço de vídeos de sites que usam Flash mas não usam RTMP, como por exemplo Globo.com (que usa HTTP mesmo). Além disso, o Wireshark pode ajudar você a capturar e analisar pacotes que estão passando pelo ar mas teoricamente não deveriam ser lidos por você numa rede WiFi. Porém, isso já foge do escopo deste post.

---

O vídeo que usarei como exemplo é o que aparece quando você clica na foto do Brasil (Organize a sua indignação) na reportagem [Alle Macht dem Volk?][6] Clique nessa imagem e deve aparecer uma tela como esta:

![Tela que aparece ao clicar num vídeo numa reportagem do Deutsche Welle.](/wp-content/uploads/2013/10/reportagem-650x365.jpg)

Neste momento, espere um pouco antes de clicar no botão _Play_ para começar a tocar o vídeo. Primeiro abra o Wireshark e comece a capturar na interface que você usa para acessar a Internet (ou escute em todas caso não saiba qual escolher). Para não ter que ficar vendo muitas coisas desnecessárias, filtre apenas mensagens do protocolo RTMP: escreva no campo _Filter_ o valor _rtmpt_ (não é erro de digitação, tem um “t” no final mesmo) e pressione _Enter_.

Agora você pode começar a tocar o vídeo. Porém, não é de seu interesse assistí-lo no navegador e você não quer que o Wireshark fique muito sobrecarregado capturando todos os milhares de pacotes que passam na rede para transferir um vídeo desse tamanho. Portanto, inicie o vídeo e, assim que ele começar a tocar, feche a aba para parar de baixá-lo.

Se tudo correu bem, você pode parar a captura no Wireshark (clicando no ícone vermelho com um X lá no seu menu). Na sua tela, você deve estar vendo alguns pacotes RTMP filtrados:

![Pacotes filtrados no Wireshark](/wp-content/uploads/2013/10/wireshark-650x388.jpg)

Lendo o conteúdo desses pacotes, você consegue descobrir qual é o endereço do vídeo no protocolo RTMP e então usar o RTMPDump para baixá-lo. Esse endereço está dividido em duas mensagens.

Na mensagem _connect_ enviada pelo cliente ao servidor para iniciar o _handshake_, você encontra o parâmetro **tcUrl**, que neste caso aponta para `rtmp://tv-od.dw.de/flash/`:

![Parâmetro tcUrl no Wireshark.](/wp-content/uploads/2013/10/tcurl-650x346.jpg)

Um pouco abaixo, na mensagem _play_, você encontra o resto do endereço (neste caso, `vdt_de/2013/bdeu131028_004_rioprotest_01i_sd_avc.mp4`):

![O resto do endereço do vídeo no corpo do RTMP.](/wp-content/uploads/2013/10/play-650x364.jpg)

Juntando as duas partes, temos o endereço completo: `rtmp://tv-od.dw.de/flash/vdt_de/2013/bdeu131028_004_rioprotest_01i_sd_avc.mp4`. Com ele, é hora de usarmos o RTMPDump. Essa parte é trivial. Basta abrir um terminal e digitar `rtmpdump` com os parâmetros `-r` (endereço) e `-o` (arquivo de saída). O resultado é este:

```
$ rtmpdump -r rtmp://tv-od.dw.de/flash/vdt_de/2013/bdeu131028_004_rioprotest_01i_sd_avc.mp4 -o a.mp4
RTMPDump v2.4
(c) 2010 Andrej Stepanchuk, Howard Chu, The Flvstreamer Team; license: GPL
Connecting ...
INFO: Connected...
Starting download at: 0.000 kB
INFO: Metadata:
INFO:   duration              242.58
INFO:   moovPosition          28.00
INFO:   width                 1280.00
INFO:   height                720.00
INFO:   videocodecid          avc1
INFO:   audiocodecid          mp4a
INFO:   avcprofile            66.00
INFO:   avclevel              31.00
INFO:   aacaot                2.00
INFO:   videoframerate        25.00
INFO:   audiosamplerate       48000.00
INFO:   audiochannels         2.00
INFO: trackinfo:
INFO:   length                6064000.00
INFO:   timescale             25000.00
INFO:   language              eng
INFO: sampledescription:
INFO:   sampletype            avc1
INFO:   length                11643904.00
INFO:   timescale             48000.00
INFO:   language              eng
INFO: sampledescription:
INFO:   sampletype            mp4a
46239.482 kB / 242.56 sec (99.9%)
Download complete
$
```

O vídeo usado no exemplo, para quem se interessar e entender alemão, foi parar no YouTube e agora pode ser incorporado em qualquer site:

[1]: https://en.wikipedia.org/wiki/Real_Time_Messaging_Protocol
[2]: http://dw.de/
[3]: https://addons.mozilla.org/en-US/firefox/addon/video-downloadhelper/
[4]: https://www.wireshark.org/
[5]: http://rtmpdump.mplayerhq.hu/
[6]: http://www.dw.de/themen/alle-macht-dem-volk/s-32349
