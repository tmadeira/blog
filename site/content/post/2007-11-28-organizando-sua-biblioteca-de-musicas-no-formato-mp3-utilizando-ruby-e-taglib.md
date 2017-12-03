---
title: Organizando sua biblioteca de músicas no formato MP3 utilizando Ruby e taglib
type: post
date: 2007-11-28T21:04:35+00:00
url: /2007/11/organizando-sua-biblioteca-de-musicas-no-formato-mp3-utilizando-ruby-e-taglib/
categories:
  - Dicas
tags:
  - biblioteca
  - códigos
  - mp3
  - músicas
  - ruby
  - scripts
  - taglib

---
Vamos fingir que você é um cara mau que ao invés de comprar CDs legalmente (como eu sempre faço e você também) [baixa discografias completas na internet][1], como por exemplo [a do Beatles][2]. Ao terminar de baixar 3 GB com mais de 20 CDs você nota que os arquivos não estão corretamente taggeados e com isso você bagunçaria a organização perfeita do seu computador, do seu iPod ou de qualquer outro aparelho que você use pra ouvir música. **O que fazer?** Apelar para o Ruby com a [Taglib][3], é claro! (Ubuntu: _apt-get install libtagc0-ruby_)

Vejam como é simples e adaptem para as suas necessidades:

<pre class="ruby"><span style="color: rgb(204, 0, 102); font-weight: bold;">require</span> <span style="color: rgb(153, 102, 0);">"taglib"</span>
 
<span style="color: rgb(153, 102, 0);">`ls BEATLES`</span>.<span style="color: rgb(204, 0, 102); font-weight: bold;">split</span><span style="color: rgb(0, 102, 0); font-weight: bold;">(</span><span style="color: rgb(153, 102, 0);">"<span style="color: rgb(0, 0, 153);">n</span>"</span><span style="color: rgb(0, 102, 0); font-weight: bold;">)</span>.<span style="color: rgb(153, 0, 204);">each</span> <span style="color: rgb(153, 102, 204); font-weight: bold;">do</span> |album|
        <span style="color: rgb(153, 102, 0);">`ls "BEATLES/#{album}"`</span>.<span style="color: rgb(204, 0, 102); font-weight: bold;">split</span><span style="color: rgb(0, 102, 0); font-weight: bold;">(</span><span style="color: rgb(153, 102, 0);">"<span style="color: rgb(0, 0, 153);">n</span>"</span><span style="color: rgb(0, 102, 0); font-weight: bold;">)</span>.<span style="color: rgb(153, 0, 204);">each</span> <span style="color: rgb(153, 102, 204); font-weight: bold;">do</span> |filename|
                path=<span style="color: rgb(153, 102, 0);">"BEATLES/#{album}/#{filename}"</span>

                <span style="color: rgb(153, 102, 204); font-weight: bold;">if</span> filename.<span style="color: rgb(153, 0, 204);">match</span><span style="color: rgb(0, 102, 0); font-weight: bold;">(</span>/mp3$/<span style="color: rgb(0, 102, 0); font-weight: bold;">)</span> <span style="color: rgb(153, 102, 204); font-weight: bold;">then</span>
                        file=TagLib::File.<span style="color: rgb(153, 0, 204);">new</span><span style="color: rgb(0, 102, 0); font-weight: bold;">(</span>path<span style="color: rgb(0, 102, 0); font-weight: bold;">)</span>

                        a=filename.<span style="color: rgb(204, 0, 102); font-weight: bold;">split</span><span style="color: rgb(0, 102, 0); font-weight: bold;">(</span><span style="color: rgb(153, 102, 0);">" - "</span><span style="color: rgb(0, 102, 0); font-weight: bold;">)</span>
                        track=a<span style="color: rgb(0, 102, 0); font-weight: bold;">[</span>a.<span style="color: rgb(153, 0, 204);">length</span><span style="color: rgb(0, 102, 102);">-2</span><span style="color: rgb(0, 102, 0); font-weight: bold;">]</span>.<span style="color: rgb(153, 0, 204);">to_i</span>

                        title=a<span style="color: rgb(0, 102, 0); font-weight: bold;">[</span>a.<span style="color: rgb(153, 0, 204);">length</span><span style="color: rgb(0, 102, 102);">-1</span><span style="color: rgb(0, 102, 0); font-weight: bold;">]</span>.<span style="color: rgb(204, 0, 102); font-weight: bold;">gsub</span><span style="color: rgb(0, 102, 0); font-weight: bold;">(</span>/.<span style="color: rgb(153, 0, 204);">mp3</span>/, ''<span style="color: rgb(0, 102, 0); font-weight: bold;">)</span>
                        file.<span style="color: rgb(153, 0, 204);">track</span>=track
                        file.<span style="color: rgb(153, 0, 204);">genre</span>=<span style="color: rgb(153, 102, 0);">"Pop/Rock"</span>

                        file.<span style="color: rgb(153, 0, 204);">artist</span>=<span style="color: rgb(153, 102, 0);">"The Beatles"</span>
                        file.<span style="color: rgb(153, 0, 204);">album</span>=album
                        file.<span style="color: rgb(153, 0, 204);">title</span>=title
                        file.<span style="color: rgb(153, 0, 204);">save</span>
                        file.<span style="color: rgb(153, 0, 204);">close</span>

                <span style="color: rgb(153, 102, 204); font-weight: bold;">else</span>
                        <span style="color: rgb(204, 0, 102); font-weight: bold;">puts</span> <span style="color: rgb(153, 102, 0);">"Tem um lixo por aí... Delete '#{path}'!"</span>
                <span style="color: rgb(153, 102, 204); font-weight: bold;">end</span>
        <span style="color: rgb(153, 102, 204); font-weight: bold;">end</span>
<span style="color: rgb(153, 102, 204); font-weight: bold;">end</span>
```

 [1]: http://tiagomadeira.com/2008/07/howto-como-baixar-filmes-com-legenda-na-internet/
 [2]: http://www.mininova.org/tor/982312
 [3]: http://www.hakubi.us/ruby-taglib/
