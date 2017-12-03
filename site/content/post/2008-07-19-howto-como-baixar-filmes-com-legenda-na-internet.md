---
title: Como baixar e assistir filmes completos na internet
type: post
date: 2008-07-19T22:40:12+00:00
url: /2008/07/howto-como-baixar-filmes-com-legenda-na-internet/
categories:
  - Dicas
tags:
  - ares
  - azureus
  - bittorrent
  - copyright
  - deluge
  - fasttrack
  - filmes
  - gift
  - gnutella
  - howto
  - kazaa
  - legendas
  - linux
  - mplayer
  - openft
  - opennap
  - p2p

---
Todo mundo gosta de assistir filmes, principalmente durante férias ou feriados chuvosos. Se você não tem dinheiro para comprar filmes, acha caro e chato sair para alugar um filme, seus problemas acabaram: ao fim deste artigo você estará qualificado para ser capaz de baixar e assistir qualquer filme (inclusive ainda não lançados aqui no Brasil) sem levantar da sua confortável cadeira de computador.

### P2P

Disponibilizar um filme na internet é crime, violação de direitos autorais. Então se você quisesse baixar algum filme que não está disponível sob uma licença livre, você não encontraria o filme que quer baixar simplesmente procurando no Google por “Baixar filme do Harry Potter” ou “Baixar Shrek 3”. Ao invés de procurar na internet convencional, você teria que aprender a se conectar a outras pessoas. Isso é feito através de P2P, peer-to-peer, e existem vários programas neste ramo: Napster (um dos primeiros – acho que o programa não existe mais, mas a rede OpenNap ainda existe), Kazaa (bastante popular, sua rede FastTrack tem um bom conteúdo), Gnutella (rede livre – GNU – onde funcionam vários programas: Limewire, Frostwire, gtk-gnutella, entre vários outros), OpenFT, Ares, etc, etc, etc

Depois de usar durante bastante tempo o [giFT][1], que já foi capaz de se conectar ao mesmo tempo nestas cinco redes (OpenNap, FastTrack, Gnutella, OpenFT e Ares), descobri um novo protocolo, novo e bem mais eficaz: o [Bittorrent][2].

### Bittorrent

Segundo a Wikipedia, _BitTorrent é um protocolo que permite às utilizadoras e aos utilizadores fazerem download de arquivos indexados em websites. Essa rede introduziu o conceito “partilhe o que já descarregou” maximizando muito o desempenho e possibilitando downloads rápidos e imediatos. Foi criado por Bram Cohen em 2003 e tem sido o alvo nº1 de empresas que lutam em defesa da propriedade intelectual, devido a alegações de violação de copyright de alguns arquivos transmitidos pela rede._

O Bittorrent é provavelmente o mais inteligente dos partilhadores de arquivo da internet. Ele fragmenta os arquivos em pequenos pedaços e você ao mesmo tempo baixa e compartilha o seu arquivo (chamado torrent, com extensão .torrent).

Existem diversos clientes de Bittorrent, entre quais posso recomendar os três que eu já usei: [Bittorrent][2] (o original, de Bram Cohen), [Azureus][3] (provavelmente o mais pop. Multiplataforma, feito em Java, muitos sites partem do princípio de que você usa ele para distribuir seu torrent) e [Deluge][4] (parecido com o Azureus, mas em GTK)

Para baixar seu filme, você deve baixar um destes clientes (programas que abrem os arquivos _.torrent_).

### Encontrando o filme e escolhendo a versão

Existe uma porção de sites que arquivam os _.torrent_ disponibilizados internet a fora. Eu costumo usar o [Mininova][5], mas ao fim deste artigo você encontra outros links interessantes.

Entre no Mininova e procure por [“harry potter and the order of the phoenix”][6] em filmes (movies). Sua busca retornou 74 resultados.

**Como escolher qual baixar?** _Seeders_ são pessoas que estão compartilhando o arquivo, _leechers_ são os que estão baixando. O mais importante é baixar um que tenha bastante seeders, para que seu download não falhe (não acabe de baixar) por falta de partilhadores. Em segundo lugar, veja que existem vários formatos diferentes de vídeo e tamanhos. Você pode optar por um vídeo que caiba num CD, por exemplo (700mb).

Escolhido seu torrent, clique nele, faça download do .torrent e abra com o seu cliente que você baixou no passo anterior. Em algumas horas, dias, meses, anos ou décadas (dependendo da velocidade da sua conexão e do número de seeders e de leechers) o seu filme estará baixado.

Também é bastante fácil [baixar livros][7], seriados americanos, softwares e outros materiais ilegais em redes de torrent.

### Encontrando e baixando a legenda

Existem vários sites para baixar legendas (subtitles) dos vídeos que você baixa na internet. Um deles é o [Opensubtitles][8] e outro é o [Legendas.TV][9] (em geral, é o que eu uso). Crie uma conta lá e procure pelo filme que você quer.

Procure pela mesma versão que você baixou o filme (o nome completo, exemplo nome-Xvid-aXXo-mavericK…), porque aí não há risco da legenda ficar mal sincronizada. Se não achar, não se preocupe: o player pode ressincronizar a legenda.

### Usando o MPLAYER para assistir o vídeo

<pre class="bash">% mplayer <span style="color: #66cc66;">[</span>ARQUIVO DO FILME<span style="color: #66cc66;">]</span>
```

#### » Legenda

Para adicionar a legenda ao seu filme basta usar a opção **-sub [ARQUIVO DA LEGENDA]** ao comando do **mplayer**:

<pre class="bash">% mplayer -sub <span style="color: #66cc66;">[</span>ARQUIVO DA LEGENDA<span style="color: #66cc66;">]</span> <span style="color: #66cc66;">[</span>ARQUIVO DO FILME<span style="color: #66cc66;">]</span>
```

O mplayer é um programa muito mais versátil do que parece. É possível mudar a fonte, a cor e a posição da legenda, ente muitas outras coisas. A maioria dessas opções de legenda são alteradas usando o ASS. Eu costumo assistir os filmes com uma legenda grande amarela embaixo da área do filme widescreen (na faixa preta, porque a leitura torna-se mais fácil):

<pre class="bash">% mplayer -ass -ass-color FFFF0000 -ass-font-scale <span style="color: #cc66cc;">1.2</span>
-ass-force-style <span style="color: #0000ff;">FontName=</span>Arial,Default.<span style="color: #0000ff;">Bold=</span><span style="color: #cc66cc;">1</span> -ass-use-margins
-ass-bottom-margin <span style="color: #cc66cc;">80</span> -sub <span style="color: #66cc66;">[</span>ARQUIVO DA LEGENDA<span style="color: #66cc66;">]</span>

<span style="color: #66cc66;">[</span>ARQUIVO DO FILME<span style="color: #66cc66;">]</span>
```

**Se a legenda estiver fora do tempo do filme,** use as teclas _x_ e _z_ dentro do mplayer para alterar o _delay_.

#### » Tela cheia

Adicionando **-fs -zoom** ao comando **mplayer** você executa o vídeo em tela cheia:

<pre class="bash">% mplayer -fs -zoom <span style="color: #66cc66;">[</span>ARQUIVO DO FILME<span style="color: #66cc66;">]</span>
```

#### » Meu comando completo

<pre class="bash">% mplayer -fs -zoom -ass -ass-color FFFF0000 -ass-font-scale <span style="color: #cc66cc;">1.2</span>
-ass-force-style <span style="color: #0000ff;">FontName=</span>Arial,Default.<span style="color: #0000ff;">Bold=</span><span style="color: #cc66cc;">1</span> -ass-use-margins
-ass-bottom-margin <span style="color: #cc66cc;">80</span> -sub <span style="color: #66cc66;">[</span>ARQUIVO DA LEGENDA<span style="color: #66cc66;">]</span>

<span style="color: #66cc66;">[</span>ARQUIVO DO FILME<span style="color: #66cc66;">]</span>
```

### Dicas para uma melhor sessão de cinema

  * Tem um amplificador ou um aparelho de som? Compre adaptadores pra ligar a saída da sua placa de som neles. São baratos e o som fica muito melhor.
  * Se você tiver um laptop ou um computador com uma placa de vídeo que tenha saída S-VIDEO, ligue o computador na TV. A imagem fica ótima e você se sente assistindo a um DVD de verdade.

### Links úteis relacionados

  * [Cinecombo][10] (site brasileiro com vários torrents para legenda e um sistema de pedidos de filmes)</a>
  * [Bittorrent.com][2] (site do cliente oficial e também busca torrents)
  * [Mininova][5] (indexador de torrents)
  * [TorrentSpy][11] (outro bom indexador e buscador de torrents)
  * [Legendas.tv][9] (baixe legendas em português do Brasil)
  * [Mplayer][12] (player de vídeo para Linux)

<div style="font-size:11px;">
  <h3>
    Importante! Não seja um fora-da-lei.
  </h3>

  <p>
    Não use o que eu escrevi neste artigo para baixar ilegalmente filmes, livros e outros conteúdos protegidos por copyright.
  </p>
</div>

 [1]: http://gift.sourceforge.net/
 [2]: http://www.bittorrent.com/
 [3]: http://azureus.sourceforge.net/
 [4]: http://www.deluge-torrent.org/
 [5]: http://www.mininova.org/
 [6]: http://www.mininova.org/search/harry+potter+and+the+order+of+the+phoenix/4
 [7]: http://tiagomadeira.com/2007/07/como-baixar-harry-potter-7/
 [8]: http://www.opensubtitles.org/pt
 [9]: http://www.legendas.tv/
 [10]: http://cinecombo.blogspot.com/
 [11]: http://www.torrentspy.com/
 [12]: http://www.mplayerhq.hu/

