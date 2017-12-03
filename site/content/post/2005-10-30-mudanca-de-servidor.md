---
title: Mudança de Servidor
type: post
date: 2005-10-30T20:52:19+00:00
excerpt: 'A Nerdhost ficou mais de uma semana fora do ar sem dar explicações... É mole? Mas ainda bem que me livrei logo daquele servidor. Depois de googlar um pouco, encontrei a solução: Dreamhost.'
url: /2005/10/mudanca-de-servidor/
categories:
  - Metablogagem
tags:
  - debian
  - digitalminds
  - dreamhost
  - globalhosts
  - kurumin
  - linux
  - nerdhost
  - servidor
  - ubuntu
  - wordpress

---
Eu já conhecia a [Dreamhost][1] há algum tempo. Já cliquei algumas vezes no link da página do [Bruno Torres][2], que me levava pra esse servidor “louco” que dá quase 5gb de espaço, 120gb de banda e o preço é igual o da [GlobalHosts][3] (aquela que eu usava até mês passado), mas depois de me confrontar com a **taxa de setup** (US$ 50!) tinha resolvido que não precisava de tudo isso (pô, o servidor tem o dobro de espaço em disco que a [Nerdhost][4] tinha de banda) e não valia a pena.

Mas acontece que hoje, procurando por servidores de hospedagem com SSH, encontro um post de semana passada do [Danilo Medeiros][5], no [DigitalMinds][5] com justamente o que eu sonhava: [DreamHost sem taxa de setup][6]. O negócio é bom pra ele e pra mim: Ele ganha US$ 47,00 por eu ter me cadastrado pelo site dele e eu ganho os outros US$ 50,00 (na Dreamhost, quando alguém se cadastra, o cara que sugeriu o site a ele ganha US$ 97,00!). Mas pra mim é melhor, porque finalmente eu tenho um servidor confiável (conheço vários usuários felizes), barato e tem bem mais recursos até do que eu precisava.

_Nessa semana aconteceram muitas coisas…_ Vou começar falando do [Ubuntu][7]. A distribuição, com fama de simples, impressionou até a minha mãe!

Pra mim, ele não é nada demais. Não acho mais simples do que [Kurumin][8] (que também é baseado em Debian, é em português e tem um monte de ícones mágicos pra facilitar ainda mais a vida) ou do que o [Debian BR-CDD][9] (esse segundo tem até o design da instalação e usa o [Gnome][10], exatamente igual a ele, e é em português!). Acho que só pode ser por causa do seu significado _“humanity to others”_ ou por ser bonitinho e a gente poder [pedir gratuitamente CDs][11] pelo site. Mas independente dessa questão, o que importa é que tá todo mundo gostando do Ubuntu.

Meu irmão menor, de 11 anos, instalou o sistema quase sozinho no desktop de casa. O único problema que ele teve foi o de configuração de rede (ele não sabia que IP colocar) e o particionamento, em que eu tive que dar uma pequena ajuda, mas acho que na próxima ele já vai conseguir fazer sozinho.

Além disso, levei uns cds pro Colégio e estamos com projeto de instalar em seis computadores: os três da biblioteca (uso apenas da internet por alunos) e os três da sala dos professores (uso apenas do Word). A reação da maioria das pessoas (já instalamos em dois computadores) foi muito legal. Só que anotei algumas dificuldades pra talvez até modificar em futuras versões do Ubuntu ou pra caso alguém quiser criar uma distribuição fácil se lembrar… Hehehe… :)

  * **Configuração da Rede** – Meu irmão não soube o que colocar no IP para se conectar a nossa rede local… Acho que faltou naquela tela uma pergunta _“Você quer configurar a rede agora?”_
  * **Particionamento do Disco** – Isso sempre é difícil para os usuários leigos. Não sei como podia ser mais simples, mas sei que a maioria das pessoas desiste de instalar nessa parte…
  * **Configuração do Fuso Horário** – Esse era um problema que eu realmente não esperava. Porém, até professores do Colégio tiveram dificuldade com a escolha de fuso horário… Acho que deve ficar mais claro na instalação, como fica na maioria dos formulários na internet. _GMT -2 : São Paulo, Brasília, etc._ ao invés de _Leste, Oeste, outro_.
  * **Menu do Gnome** – As três pessoas que tiveram o primeiro contato com sua nova máquina com Ubuntu clicaram no ícone de _“Mostrar área de trabalho”_. Não seria mais sensato para o Gnome colocar o menu de aplicações embaixo para quem está vindo do sistema corporativo da Microsoft se acostumar de forma mais leve?
  * **NumLock** – Todo mundo tá acostumado com o NumLock ligado por padrão.
  * **Pacotes pt-BR** – O Ubuntu pergunta na instalação se queremos baixar os pacotes. Porém, considerando que eu uso ADSL PPPoE e não pude configurar minha internet durante a instalação, como faço pra instalar os pacotes brasileiros depois? Deveria ter um ícone pra isso no menu depois…
  * **Conectar ADSL** – Pô… A instalação tudo bem, mas depois eu ter que entrar no console e digitar **pppoeconf** pra configurar o ADSL (porque obviamente já usei outros Linuxes e conhecia o rp-pppoe) é difícil, né? Que tipo de usuário leigo consegue conectar-se ao seu serviço PPPoE num Ubuntu?

Alguns dos problemas acima são específicos do Ubuntu; outros dos GNU/Linux em geral. Algumas coisas são questão de preferência, mas será que não seria importante deixar o GNU/Linux mais fácil até nesses pontos (bem específicos) para os usuários acostumados com o Windows?

Por essa e por outras, disse acima que preferia o Kurumin, mas de qualquer maneira, o Ubuntu tá muito legal e o povo tá começando a usar aqui… O software livre, até pra fins educativos, é muito legal. Agora estou baixando o [Edubuntu][12] pra ver se não dá pra instalar nos computadores do **Laboratório de Informática** do Colégio… :D

Outro fato dessa semana foi o final do [JEI2005][13]. [Salesiano campeão-geral][14] novamente, com a ajuda do voleibol juvenil masculino… :D

E para finalizar, talvez o mais importante dos fatos: a mudança do sistema de blog do meu site. Estou agora utilizando o [WordPress][15]. É meio estranho alguém que estava fazendo um sistema de blogs semana retrasada passar a usar um outro sistema, né? Mas é que eu desisti de fazer o _Semantic Blog_, porque o projeto tava meio parado (o Gustavo e o Hélio são muito ocupados) e recebi finalmente meu invite no [WordPress.com][16], onde testei o sistema e gostei bastante. Um recurso legal é que tem vários plugins. Estou para instalar o plugin do [GeSHi][17] e já instalei o plugin do [LaTeX Render][18]. Realmente recomendo… :)

**[update]** Agora instalei também o plugin do GeSHi! **[/update]**

 [1]: http://www.dreamhost.com
 [2]: http://www.brunotorres.net
 [3]: http://www.globalhosts.com.br
 [4]: http://www.nerdhost.com.br
 [5]: http://www.digitalminds.com.br
 [6]: http://www.digitalminds.com.br/posts/2033
 [7]: http://www.ubuntu.com
 [8]: http://www.kurumin.com.br
 [9]: http://cdd.debian-br.org/project/
 [10]: http://www.gnome.org
 [11]: http://shipit.ubuntu.com
 [12]: http://www.edubuntu.org/
 [13]: http://www.correeventos.com.br/jei2005
 [14]: http://www.salesianoitajai.g12.br/?sp=vernoticia&id=72
 [15]: http://www.wordpress.org
 [16]: http://www.wordpress.com
 [17]: http://dev.wp-plugins.org/wiki/GeshiSyntaxColorer
 [18]: http://sixthform.info/steve/wordpress/index.php?p=13

