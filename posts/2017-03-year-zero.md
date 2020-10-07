---
title: Year Zero
date: 2017-03-07T17:16:57+00:00
url: /2017/03/year-zero/
tags:
  - assange
  - cia
  - open whisper systems
  - signal
  - snowden
  - vault7
  - vigilância
  - wikileaks
  - year zero
  - zero day
---

Hoje de manhã o WikiLeaks começou a publicar a maior série de vazamentos da CIA da história, “Vault 7”.

A primeira parte, publicada hoje, se chama “Year Zero” e tem 8761 documentos da divisão hacker da CIA: mais páginas do que todos os vazamentos de Snowden sobre a NSA publicados desde 2013.

Como diz o [release para a imprensa][1]:

> “Recently, the CIA lost control of the majority of its hacking arsenal including malware, viruses, trojans, weaponized “zero day” exploits, malware remote control systems and associated documentation. This extraordinary collection, which amounts to more than several hundred million lines of code, gives its possessor the entire hacking capacity of the CIA. The archive appears to have been circulated among former U.S. government hackers and contractors in an unauthorized manner, one of whom has provided WikiLeaks with portions of the archive. “Year Zero” introduces the scope and direction of the CIA’s global covert hacking program, its malware arsenal and dozens of “zero day” weaponized exploits against a wide range of U.S. and European company products, include Apple’s iPhone, Google’s Android and Microsoft’s Windows and even Samsung TVs, which are turned into covert microphones.”

<small>[Em engenharia de software, uma vulnerabilidade “zero day” é uma vulnerabilidade desconhecida pelos desenvolvedores de software]</small>

Os documentos vazados têm vários manuais de operação da CIA (organizados num tipo de wiki interno) e explicações de como vários sistemas funcionam, que falhas eles têm e como explorá-las.

![A imagem é um quadro com os exploits que eles usam para invadir diferentes versões do iOS (sistema operacional usado pelo iPhone).](/wp-content/uploads/2017/03/hack.png)

A consequência do vazamento é, por um lado, uma democratização das ciberarmas da CIA. Por outro, a obsolescência delas e, consequentemente, enfraquecimento da agência. De um lado um extenso arsenal de armas da CIA pode estar sendo usado por outros agentes para invadir nossos computadores e celulares. De outro a CIA perde a vantagem que tinha e a médio prazo essas falhas tendem a ser corrigidas por atualizações dos sistemas.

> “Still working through the publication, but what @Wikileaks has here is genuinely a big deal. Looks authentic.”

<small>(Edward Snowden <a href="https://twitter.com/Snowden/status/839157182872576000">sobre o vazamento</a>)</small>

---

**Update** (15h52):

Um dos documentos da CIA vazados pelo WikiLeaks é uma [lista de coisas que os desenvolvedores de malware devem fazer e não fazer][4]. Tem dicas como:

- DO NOT leave dates/times such as compile timestamps, linker timestamps, build times, access times, etc. that correlate to general US core working hours (i.e. 8am-6pm Eastern time)
- DO NOT use US-centric timestamp formats such as MM-DD-YYYY. YYYYMMDD is generally preferred.

(entre muitas outras)

Se os caras se preocupam com isso, “evidências” podem apontar que um software escrito pela CIA tenha sido feito, sei lá, por russos...

---

**Update** (17h43):

A [nota da Open Whisper Systems][5] sobre o #Vault7 é otimista e mostra como, contraditoriamente, estamos avançando em segurança digital:

> “A reportagem CIA/WikiLeaks de hoje é sobre colocar malware nos telefones; nenhum dos exploits é no Signal ou quebra a criptografia do protocolo do Signal. A reportagem não é sobre Signal ou WhatsApp, mas na medida em que ela é, nós a vemos como a confirmação de que o que estamos fazendo está funcionando. Criptografia de ponta a ponta em toda parte está empurrando as agências de inteligência da vigilância em massa não detectável para ataques caros, de alto risco e direcionados.”

[1]: https://wikileaks.org/ciav7p1/
[3]: https://wikileaks.org/ciav7p1/cms/page_13205587.html
[4]: https://wikileaks.org/ciav7p1/cms/page_14587109.html
[5]: https://twitter.com/whispersystems/status/839204973921501184
