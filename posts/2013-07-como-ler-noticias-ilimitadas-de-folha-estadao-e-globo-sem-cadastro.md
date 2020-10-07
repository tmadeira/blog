---
title: Como ler notícias ilimitadas de Folha, Estadão e Globo sem cadastro
date: 2013-07-20T22:15:18+00:00
url: /2013/07/como-ler-noticias-ilimitadas-de-folha-estadao-e-globo-sem-cadastro/
tags:
  - códigos
  - computação
  - estadão
  - firefox
  - folha
  - globo
  - internet
  - javascript
  - paywall
  - programação
  - scripts
  - web
---

**TL;DR**: Instale o [Adblock Plus][1] em seu navegador, entre nas suas opções, peça para adicionar seu próprio filtro e adicione o filtro: _\*paywall\*_. Você agora deve ser capaz de ler notícias de Folha, Estadão e Globo sem cadastro. Caso tenha interesse em saber o caminho que levou a solução até aqui, continue lendo o post.

---

A mídia tradicional mudou a forma como publica na internet. A regra agora é que sem cadastro você só pode acessar um determinado número (pequeno) de notícias. O nome do sistema é [paywall][2]. Ao chegar no limite, você recebe mensagens como as seguintes:

![Paywall da Folha de São Paulo](/wp-content/uploads/2013/07/folha.png)

![Paywall do Estado de São Paulo](/wp-content/uploads/2013/07/estadao.png)

![Paywall do jornal O Globo](/wp-content/uploads/2013/07/globo.png)

No caso da Folha, só o cadastro pago dá acesso ilimitado. Nos outros, aparentemente um cadastro gratuito é suficiente. De qualquer forma, por que dar seus dados para esses sites saberem quem você é, como navega e o que gosta de ler? Para quem esses sites vão dar essas informações?

Para além da preocupação com privacidade e anonimato, esse sistema funciona como um bloqueio para que as pessoas não possam ler e disseminar as notícias da internet. Torna a circulação de informações mais difícil e o espaço internético mais privado e menos democrático. Por isso, compartilho aqui um pouco sobre o funcionamento do paywall e algumas formas de contorná-lo.

---

Os sites não querem que buscadores tenham dificuldade de acessar e indexar seu conteúdo. Tampouco querem bloquear endereços de IP, já que a quantidade de pessoas que usa internet via NAT (compartilhando o mesmo endereço de IP com outras pessoas numa mesma rede) é enorme. Por isso, eles fazem todo o controle não no computador deles (servidor), mas no seu computador (cliente).

Para fazer isso, eles contam com a ajuda do seu navegador. Eles mandam a página sempre da mesma forma e o seu navegador é que faz o trabalho sujo. Roda um programa escrito em JavaScript para olhar pros dados que ele mesmo já tinha registrado anteriormente (os chamados cookies). Baseado nesses dados, redireciona você para outra página (no caso de Folha e Estadão, simplesmente coloca um fundo preto semi-transparente em cima do conteúdo do site).

Isso torna não só possível, como trivial contornar o bloqueio. Basta dizer para o seu navegador não registrar cookies, desativar a execução de JavaScript ou rodar outro programa para anular a ação do programa da grande mídia. Abaixo vou mostrar diversas formas de fazer isso usando o Mozilla Firefox, mas em outros navegadores há formas semelhantes de fazer o mesmo. Como sempre, a última forma é a que eu considero melhor.

### Usar janela de navegação privada

A forma mais simples de acessar um conteúdo bloqueado é acessar a página numa janela de navegação privada. Para abrir tal janela, basta usar o atalho Ctrl+Shift+P no Firefox (ou Ctrl+Shift+N no Chromium). Como essa janela não vai usar os cookies que seu navegador tem registrado na janela principal, você vai conseguir acessar o conteúdo proibido normalmente (como se nunca tivesse acessado nenhuma notícia antes). Há pessoas que usam só o modo de navegação privada o tempo todo (uma opção razoável para evitar rastreamento).

### Remover cookies individuais

No Firefox, você pode usar **Editar → Preferências → Privacidade → Remover cookies individuais** para remover cookies registrados no seu computador. Se você remover todos, vai sair automaticamente de todos os sites onde está logado. Como seu objetivo é contornar o paywall, você pode remover cookies somente dos sites que deseja acessar (no caso, procurar _globo, folha e estadao_ na barra de busca da remoção de cookies).

### Desativar JavaScript

É possível desativar a execução de programas enviados pelos sites que você acessa no Firefox desmarcando a caixa **Permitir JavaScript** no menu **Editar → Preferências → Conteúdo** do Firefox. Dessa forma, você vai perder muitas funcionalidades dos sites, mas navegar mais rápido e não ter que encarar paywall algum.

A extensão [NoScript][3] do Firefox torna mais fácil ativar/desativar scripts de determinados domínios.

### Desativar CSS

Se você não se importar com leiaute e diagramação da página, **Exibir → Estilos da página → Nenhum estilo** vai fazer tudo ficar feio, mas o texto legível.

### Usar extensão Web Developer

Instalar a extensão [Web Developer][4] no Firefox torna ainda mais simples remover cookies de um determinado domínio e desativar JavaScript ou CSS (aparece uma barra embaixo da barra de endereço com botões pra executar essas ações).

### Remover lightbox

No caso de Folha e Estadão (que sobrepõe um fundo preto semi-transparente e uma lightbox na página ao invés de redirecionar você para outra página como faz o Globo), é possível fazer a lightbox desaparecer (sem mexer nos cookies ou no JavaScript) usando o modo de inspeção (Ctrl+Shift+I), selecionando os elementos que quer remover e adicionando o CSS _display:none;_ neles. Por meio de um _userscript_ do [Greasemonkey][5] seria possível automatizar isso.

### Forma definitiva (minha preferida): filtros no Adblock Plus

[Adblock Plus][6] é uma extensão do Firefox extremamente eficiente para bloquear publicidades e scripts não desejados. Os seguintes filtros bloqueiam os scripts de paywall de Folha, Estadão e O Globo:

```
||paywall.estadao.com.br^
||estadao.com.br/paywall/*
||www1.folha.uol.com.br/folha/furniture/paywall/*
||static.folha.com.br/paywall/*
||oglobo.globo.com/servicos/inc/payWall.Conteudo.js
||oglobo.globo.com/plataforma/js/*/minificados/paywall/registraConteudosLidos.js
```

<small>(Depois de escrever, fiquei pensando que talvez seja razoável bloquear simplesmente <strong>_paywall_</strong> de uma vez.)</small>

Para usar, basta ter instalado o Adblock Plus, copiar essas regras (todas juntas) e colá-las em **Ferramentas → Adblock Plus → Preferências de filtros → Filtros personalizados**.

[1]: https://adblockplus.org/
[2]: https://en.wikipedia.org/wiki/Paywall
[3]: https://addons.mozilla.org/en/firefox/addon/noscript/
[4]: https://addons.mozilla.org/en-US/firefox/addon/web-developer/
[5]: https://addons.mozilla.org/en-US/firefox/addon/greasemonkey/
[6]: https://addons.mozilla.org/en-US/firefox/addon/adblock-plus/
