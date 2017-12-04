---
title: Como usar SSH quando seu roteador bloqueia que você faça conexões à porta 22
type: post
date: 2017-11-25T20:35:00+00:00
url: /2017/11/como-usar-ssh-quando-seu-roteador-bloqueia-que-voce-faca-conexoes-a-porta-22/
categories:
  - Dicas
tags:
  - bitbucket
  - firewall
  - git
  - github
  - isp
  - net
  - ssh
  - tunnel
  - vpn

---
Alguns roteadores distribuídos pela NET (como alguns da marca TechniColor, mas possivelmente outros) estão bloqueando conexões para a porta 22, o que atrapalha bastante quem precisa fazer conexões via SSH.

A solução óbvia para o problema seria reconfigurar o roteador. Porém, a NET parece estar dificultando cada vez mais o acesso aos roteadores dela.

E é difícil explicar na central de relacionamento que você precisa do usuário e senha para acessar a configuração do roteador e por que você precisa disso… eu tentei, mas acho que meu interlocutor entendeu que eu queria a chave do Wi-Fi e no fim não consegui nada!

Então, sem paciência para resolver o problema da forma correta, resta fazer gambiarras. Felizmente, tais gambiarras podem também ser usadas em outros lugares que bloqueiam conexões para a porta 22 (por exemplo, algumas universidades, escolas e aeroportos, locais de trabalho etc).

* * *

A gambiarra trivial seria usar alguma VPN, mas isso não valeria um post.

Então, aqui quero falar de outras duas que encontrei buscando uma solução mais elegante para o problema.

### A primeira requer que você possa mudar a porta SSH de algum servidor que tenha acesso

Se você puder mudar o SSH para uma porta alternativa (tipo 2222) em algum servidor **alice.com** em que você seja _root_, pode usá-lo como túnel (ok, essa solução é meio parecida com VPN, mas foi mais fácil & barata no meu caso).

Para mudar a porta nesse servidor é só editar `/etc/sshd_config`, mudar a linha `Port 22` para `Port 2222` e reiniciar o serviço do SSH — algo como `service ssh restart` (a depender da distribuição que você estiver usando).

Aí, pra usar esse servidor como túnel, você pode fazer duas coisas (do lado do cliente).

Se você só quer acessar um servidor **bob.com**, pode usar, como sugerido [aqui][1]:

```bash
$ ssh -N -L 3333:bob.com -p 2222 alice.com

# em outro terminal
$ ssh -p 3333 127.0.0.1
```

Se você quer acessar vários servidores — não só **bob.com**, mas também **charlie.com** (me parece mais útil), pode criar um proxy do tipo SOCKS num terminal e usá-lo em outros:

```bash
$ ssh -D 3333 -N -p 2222 alice.com

# em outros terminais
$ ssh -o ProxyCommand='nc -x 127.0.0.1:3333 %h %p' bob.com
$ ssh -o ProxyCommand='nc -x 127.0.0.1:3333 %h %p' charlie.com
```

Pra evitar lembrar da sintaxe desse `ProxyCommand`, que usa _netcat_ e copiei [daqui][2], você poderia adicioná-lo em `~/.ssh/config`:

```
ProxyCommand nc -x 127.0.0.1:3333 %h %p
```

Aí, depois de criado o túnel, basta usar SSH normalmente:

```bash
$ ssh -D 3333 -N -p 2222 alice.com

# em outros terminais
$ ssh bob.com
$ ssh charlie.com
```

### A segunda é para caso você só precise acessar GitHub e Bitbucket

Resolve o problema pra maioria dos usos de Git via SSH e o bom dela é que você pode fazer uma vez e esquecer.

Felizmente, esses serviços disponibilizam servidores/portas alternativas que você pode usar para se conectar neles.

O GitHub [oferece][3] conexão SSH na porta 443 do servidor **ssh.github.com**; o Bitbucket [oferece][4] conexão SSH na porta 443 do servidor **altssh.bitbucket.org**.

Como 443 é a porta de HTTPS (TLS), é bem difícil essa porta estar bloqueada na rede em que você estiver.

Pra evitar ter que editar os _remotes_ de todos os seus repositórios, você pode resolver o problema pra sempre adicionando o seguinte no seu `~/.ssh/config`:

```
Host bitbucket.org
  HostName altssh.bitbucket.org
  Port 443

Host github.com
  HostName ssh.github.com
  Port 443
```

Se conhecer outras soluções interessantes, fique à vontade para compartilhar na caixa de comentários!

 [1]: https://randyfay.com/content/git-over-ssh-tunnel-through-firewall-or-vpn
 [2]: https://www.jethrocarr.com/2013/03/13/ssh-via-socks-proxies/
 [3]: https://help.github.com/articles/using-ssh-over-the-https-port/
 [4]: http://www.garbers.co.za/2014/03/03/connecting-to-bitbucket-on-https-port/
