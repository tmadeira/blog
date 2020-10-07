---
title: Álbum de Fotos
date: 2005-12-06T13:41:30+00:00
excerpt: Meu Flickr tá estourando e por isso resolvi criar um álbum de fotos pessoal que disponibilizarei como software livre. Estou desenvolvendo em PHP, com um banco de dados MySql e estou criando bastante recursos Ajax para exercitar um pouco e para o negócio ficar bem dinâmico.
url: /2005/12/album-de-fotos/
tags:
  - ajax
  - álbuns
  - blogger
  - cvs
  - flickr
  - fotos
  - html
  - javascript
  - mysql
  - php
  - programação orientada a objetos
  - projetos
  - software livre
  - wordpress
---

[Link para projeto em desenvolvimento…][1]

Meu [Flickr][2] tá estourando (depois de 200 fotos, começam a sumir fotos segundo seu FAQ) e por isso resolvi criar um álbum de fotos pessoal. Estou desenvolvendo em PHP, usando um banco de dados MySql e estou criando bastante recursos Ajax para exercitar um pouco e para o negócio ficar bem dinâmico (se estiver ficando muito exagerado, me avisem!). Este projeto que ainda não tem nome, mas que estou pensando em algo como **PhotoX** (gostou do nome? comente! não gostou? comente também!), deve ter todos os recursos do Flickr (tipo, All Sizes, Notes e Rotate) e o que surgir de idéias legais. Será um software livre, cada um instala em seu servidor (ex.: é um “[WordPress][3]“, não um “[Blogger][4]“) e por isso ele não tem limites de sets, tags, fotos, tamanhos ou qualquer coisa do tipo. Irá requerer PHP 4.3, está sendo desenvolvido usando classes (estou tentando exercitar programação orientada a objetos), usa a biblioteca GD (para trabalhar com as imagens) e é totalmente Web 2.0 (tableless, padrões HTML 4.01 Strict, Ajax, tagsonomia, simplicidade). Já estou o criando multi-linguagem, ele funciona com alguma coisa parecida com templates e deve sair em no máximo um mês.

Estou convidando programadores sem nada pra fazer pra me dar uma ajuda (claro que gratuita). O [Gustavo][5] é uma das pessoas que me deu uma ajuda fazendo um pedaço da classe **Foto** e da classe **Comentario** e aqui estendo o convite para qualquer pessoa que lê o meu blog e queira ajudar. O sistema é simples: eu te dou um login e senha no meu FTP e você desenvolve o que você conseguir (postando sempre que você muda uma letra o novo resultado, para que depois outra pessoa pegue e possa continuar).

<div>
  <h4>
    Atualizado
  </h4>

  <p>
    O Renato deu uma idéia legal aí num comentário que é hospedar o troço em alguns desses sites de projetos de software livre e usar CVS pro desenvolvimento. Acho que realmente faz sentido, eu não tinha pensado nisso… Hehehe… Vou criar algo a respeito e depois eu publico aqui!
  </p>
</div>

Se você for uma dessas pessoas dispostas, gostaria de pedir que você note alguns detalhes na construção dos meus arquivos:

- Tabulação é feita com “tabs”.
- As classes não imprimem nada na janela.
- Mesmo os arquivos não imprimem nada também, eles imprimem para a variável \$buf.
- Não vale mexer nos arquivos _config.php, index.php, ajax.php, scripts.js.php e style.css_ (por favor, deixe toda a parte de client-side, Ajax e configurações globais para mim :D ).
- Todas as coisas que você passar para a variável $buf não podem conter texto. (Se você quer escrever qualquer coisa além do que foi retornado do banco de dados, deve criar uma variável $LANG[‘NOMEDAVAR’] no arquivo **lang/pt_BR.php** e **lang/en_US.php**
- Se você não souber programar mas estiver afim de traduzir o projeto para alguma língua, me dê seu nome que quando tiver pronto eu vou querer muito sua ajuda.
- Se você não quiser traduzir e nem souber programar, colabore com idéias de coisas que você acha legal o projeto ter (o que falta no Flickr que seria legal os programadores colocarem, ou sei lá…)

Espero que todos tenham entendido o espírito. Me mandem e-mail com sugestões e quem puder ajudar, ajude. Quem quiser dar um nome ao projeto, pode me sugerir também! Tenho certeza que um software livre desenvolvido pela comunidade para um fim que ainda não existe algo parecido (alguém conhece algum software livre de álbum de fotos que faça tudo que o Flickr faz?) fará bastante sucesso e será bem aceito ao menos pelos programadores (grande parte deles usa o Flickr mas tem um servidor legal que suporta PHP e GD).

---

Agora vamos voltar ao blog.

Fiquei um tempo sem postar justamente por causa desse projeto, que estou me esforçando para fazer o mais rápido possível. Também estou lendo **“Java – Como Programar”**. Tô gostando bastante da didática e gostando também da linguagem Java. No mais, não estou fazendo muita coisa. Estou indo trabalhar todos os dias a tarde, viajei final de semana para Florianópolis e agora que meu primo foi embora, minha casa está bem vazia (o que é ótimo! :) )

[1]: http://fotos.tiagomadeira.net
[2]: http://www.flickr.com
[3]: http://www.wordpress.org
[4]: http://www.blogger.com
[5]: http://gustavocustodio.sosphp.com
