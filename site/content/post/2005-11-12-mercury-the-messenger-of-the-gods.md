---
title: 'Mercury: The Messenger of the Gods'
type: post
date: 2005-11-13T02:10:50+00:00
excerpt: 'Continuando com os programas para imigrantes (mas não só pra eles), aí está mais um excelente programa para Linux (e em Windows também funciona!): Mercury.'
url: /2005/11/mercury-the-messenger-of-the-gods/
categories:
  - Dicas
tags:
  - java
  - linux
  - mercury
  - microsoft
  - msn

---
Continuando com os programas para imigrantes (mas não só pra eles), aí está mais um excelente programa para Linux (e em Windows também funciona!)

Conheci hoje um cliente para a rede do [MSN Messenger][1] chamado [Mercury][2]. Foi feito em [Java][3], é multi-plataforma e tem **todas** as funcionalidades do cliente proprietário da [Microsoft][4].

O cliente [permite que você use winks, emoticons personalizados, mensagens particulares, webcam, “o que você está ouvindo” na mensagem particular, etc e ainda uma série de exclusividades, como a personalização da lista de contatos (usando HTML), mensagem de away, saber quem te excluiu da lista, skins, plugins, aliases (apelidos), conversação em abas e vários outros frufrus][5].

Descobri ele quando meu irmão estava tendo problemas com o aMSN CVS no desktop de casa e fiquei de boca aberta. Como é que eu não conhecia isso antes?

O cara que fez o Mercury o fez de uma maneira bem organizada e, mesmo ele não sendo um software livre, é um excelente programa que merece uma citação aqui no blog. O programa trabalha com vários arquivos XML (pra fazer quase tudo) e suas configurações chegam até a ser chatas de tantas opções que o usuário tem. Por exemplo, ele te dá a opção até de colocar um comando de shell para colocar uma música de outro player (!= Winamp e iTunes) na mensagem particular, e eu fiz pro [AmaroK][6]:

```bash
#!/bin/bash
# playing.sh | AmaroK, what's playing?

resultado=`dcop amarok player nowPlaying`
if [ "$resultado" = "call failed" ]; then
        echo ""
else
        echo $resultado
fi
```

A instalação do Mercury é super simples (é um arquivo binário, aonde você vai dando “Nexts”) e um _“defeito”_ do programa seria não colocar um ícone no System Tray automaticamente; defeito que corrigi adicionando ao início do arquivo **~/runMercury:**

```
options="-Djava.library.path=/home/usuario/Mercury"
```

Meu irmão criou uma [comunidade no Orkut][7] para o mensageiro.

 [1]: http://messenger.msn.com
 [2]: http://www.mercury.to
 [3]: http://java.sun.com
 [4]: http://www.microsoft.com
 [5]: http://www.mercury.to/index.php?sub=WhatIsMercury
 [6]: http://amarok.kde.org
 [7]: http://www.orkut.com/Community.aspx?cmm=6447843

