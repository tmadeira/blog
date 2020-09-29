---
title: Organizando sua biblioteca de músicas no formato MP3 utilizando Ruby e taglib
type: post
date: 2007-11-28T21:04:35+00:00
url: /2007/11/organizando-sua-biblioteca-de-musicas-no-formato-mp3-utilizando-ruby-e-taglib/
categorias:
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

```ruby
require "taglib"

`ls BEATLES`.split("n").each do |album|
  `ls "BEATLES/#{album}"`.split("n").each do |filename|
    path="BEATLES/#{album}/#{filename}"

    if filename.match(/mp3$/) then
      file=TagLib::File.new(path)

      a=filename.split(" - ")
      track=a[a.length-2].to_i

      title=a[a.length-1].gsub(/.mp3/, '')
      file.track=track
      file.genre="Pop/Rock"

      file.artist="The Beatles"
      file.album=album
      file.title=title
      file.save
      file.close
    else
      puts "Tem um lixo por aí... Delete '#{path}'!"
    end
  end
end
```

[1]: /2008/07/howto-como-baixar-filmes-com-legenda-na-internet/
[2]: http://www.mininova.org/tor/982312
[3]: http://www.hakubi.us/ruby-taglib/
