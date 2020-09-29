---
title: WhatsApp anuncia criptografia de ponta a ponta
type: post
date: 2016-04-05T17:20:27+00:00
url: /2016/04/whatsapp-anuncia-criptografia-de-ponta-a-ponta/
categorias:
  - Pensamentos aleatórios
tags:
  - criptografia
  - edward snowden
  - end to end
  - open whisper systems
  - ponta a ponta
  - telegram
  - whatsapp
---

A criptografia de ponta-a-ponta do WhatsApp, muito aguardada por mais de um ano, é uma ótima notícia para a nossa privacidade. Ser de ponta-a-ponta significa que, a partir de agora, nenhum intermediário consegue ler ou ouvir nossas conversas, nem mesmo o próprio WhatsApp.

Tecnicamente, o celular A encripta cada uma das mensagens que envia diretamente com a chave pública do celular B; ou seja, é como se a mensagem fosse protegida por um cadeado que apenas o celular B pode abrir. A segurança de que só B pode abrir é garantida pela dificuldade de problemas matemáticos antigos que a humanidade não sabe como resolver de forma eficiente, como fatorar um número composto grande em primos ou encontrar o logaritmo discreto sobre um grupo bem escolhido.

A implementação do WhatsApp foi desenvolvida em conjunto com a Open Whisper Systems, empresa muito respeitada e conhecida pelo Signal, aplicativo que é recomendado por Edward Snowden, Laura Poitras e Bruce Schneier, entre outros especialistas em privacidade e criptografia. Alguns detalhes dessa parceria e da implementação foram [explicados][1] no blog da Open Whisper Systems e na página de [segurança do WhatsApp][2].

Diferentemente da implementação do Telegram, a do WhatsApp suporta criptografia de ponta a ponta em chats em grupo, anexos, mensagens de voz e chamadas de voz nas várias plataformas nas quais ele está disponível (incluindo até o Nokia S40). Além disso, as conversas são automaticamente encriptadas, i.e., não é preciso fazer nada para usar criptografia de ponta a ponta (como se faz no Telegram com a criação de secure chats).

Dessa forma, para quem se preocupa com grampo, não existe motivo de segurança para se preferir o aplicativo russo, ainda que possam existir vários outros motivos ignorando-se a questão da segurança (suporte a grupos com até 5000 pessoas, stickers, links para pessoas se adicionarem a grupos, nicknames etc).

A única questão ainda não resolvida pela qual eu acho que alguns poderiam preferir Telegram é a trivial auto-destruição de mensagens. Esse simples recurso ajuda os usuários a não guardarem as mensagens recebidas nos seus próprios celulares, protegendo-os no caso em que seus celulares são invadidos tempos depois de mensagens terem sido recebidas (seja por meios virtuais — tipo uma falha no Android — ou físicos — tipo a polícia). Acho esse recurso legal, mas não suficiente para preferir o Telegram sobre a implementação de criptografia ponta-a-ponta mais confiável e completa lançada pelo WhatsApp.

<small>Publicado originalmente no <a href="https://www.facebook.com/timadeira/posts/10209199118593847">Facebook</a>.</small>

[1]: https://whispersystems.org/blog/whatsapp-complete/
[2]: https://www.whatsapp.com/security/
