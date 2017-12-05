---
title: Combatendo a censura com algoritmos
type: post
date: 2011-12-24T18:11:42+00:00
url: /2011/12/combatendo-a-censura-com-algoritmos/
categories:
  - Curiosidades
tags:
  - acm
  - algoritmos
  - censura
  - computação
  - Mohammad Mahdian
  - oriente médio
  - política
  - proxy
  - redes de confiança
  - traduções
  - xrds

---
<p style="text-align:right;">
  <em>Mohammad Mahdian *</em> (tradução: Tiago Madeira)
</p>

{{< figure src="/wp-content/uploads/2011/12/18.2_Mahdian_med.jpg" title="Mãos algemadas digitando num teclado de computador" >}}

Os levantes recentes no Oriente Médio demonstraram a eficácia da internet em ajudar ativistas políticos e sociais a organizarem protestos, disseminarem informações para o público e enviarem notícias de prisões e repressões ao restante do mundo. Ameaçados por esse paradigma, regimes totalitários tentaram controlar e monitorar o acesso de seus cidadãos à web, desenvolvendo ou adquirindo tecnologias de censura e de vigilância da internet. Ao mesmo tempo, uma variedade de ferramentas de violação desses filtros foi desenvolvida para ajudar os usuários a contornarem o filtro da internet acessando sites bloqueados através de intermediários não-bloqueados (os chamados proxies). O artigo de Dan Boneh ([Recent Ideas for Circumventing Internet Filtering][2]) dá um ótimo resumo sobre novas e velhas técnicas para construir essas ferramentas.

No coração de todos os métodos de violação existe o seguinte dilema: Para fazer a ferramenta disponível ao público, os endereços de proxy precisam ser comunicados para os usuários. Isso, no entanto, permite que as autoridades obtenham esses endereços (fingindo serem usuários legítimos) e aí bloqueiem todo o tráfego nesses endereços específicos. Ter vários proxies de curta duração alivia o problema, mas a questão permanece: Existe algum método algorítmico esperto para distribuir proxies que diminua o número de proxies necessários para fornecer acesso à internet sem filtro?

#### O problema de distribuição de proxy

Vamos começar definindo um modelo teórico simples para este problema. Nós gostaríamos de distribuir um conjunto de _m_ proxies para uma população de _n_ usuários: _k_ deles são adversários (agentes da censura) e o restante (_n-k_) são usuários legítimos. Nós não sabemos as identidades dos adversários, mas podemos assumir que _k << n_. Na verdade, para simplicidade, pense em _k_ como uma constante, enquanto _n_ cresce ao infinito.

Se um proxy é dado a um adversário, ele pode comprometer o proxy, tornando-o inutilizável para os outros usuários. Uma vez que um proxy é comprometido, nós ficamos sabendo e podemos distribuir outros proxies para os usuários afetados. Nossa meta é garantir que todo usuário legítimo tenha pelo menos um proxy não-comprometido. A questão é: qual é o menor _m_ com o qual conseguimos fornecer essa garantia?

Claramente, o problema pode ser resolvido com _n_ proxies dando pra cada usuário um proxy diferente. Na verdade, podemos fazer muito melhor usando um algoritmo de busca binária: Comece dividindo os usuários em duas caixas e dê pra cada caixa o seu proxy. Uma vez que um proxy é comprometido, divida sua caixa correspondente pela metade e dê para cada uma das metades um proxy. Continue fazendo isso enquanto existe apenas um usuário na caixa. É fácil ver que esse método usa no máximo O(log(n)) proxies. Uma divisão cuidadosa dos usuários em caixas rende uma solução com no máximo \\(k(1+log_2(n/k))\\) proxies.

Podemos resolver o problema com menos de O(log(n)) proxies? Talvez surpreendentemente, nós podemos fazer um pouco melhor. Há um algoritmo randomizado de distribuição de proxies que usa no máximo O(log(n)/loglog(n)) proxies. Um argumento simples de entropia mostra que isso é assintoticamente ótimo para um _k_ constante.

#### Distribuição de proxies via redes de confiança

Uma forma comum de construir uma base de usuários num país sob censura é através de relações pessoais de confiança. O sistema começa com poucos usuários confiáveis e então cada usuário confiável pode convidar novos usuários em quem ele confia para o sistema. Dessa forma, o conjunto de usuários cresce como uma rede de confiança: uma árvore enraizada na qual o conjunto de usuários confiáveis inicial é filho da raiz e arestas indicam relações de confiança.

Usar uma rede de confiança dificulta que um adversário se infiltre na base de usuários. No entanto, o problema é que uma vez que a rede é infiltrada, o adversário pode convidar novos adversários para a rede. Para levar isso em conta, nós modificamos a formulação do problema como segue: em vez de exigir que um pequeno número de usuários seja adversário, nós assumimos que um pequeno número de usuários e todos os seus descendentes na rede são adversários. Uma forma alternativa de formular esse problema é considerar redes de confiança capacitadas e assumir que o menor corte da raiz para todos os adversários é no máximo um pequeno número _k_.

O problema de distribuição de proxy em redes de confiança está ainda sem solução em geral. Temos resultados parciais para pequenos _k_ e no caso capacitado. Os algoritmos são não-triviais e precisam olhar para a estrutura da rede de confiança.

#### Conclusão

O objetivo desse exercício era convencer o leitor de que existe um problema teórico interessante e desafiante no âmago das tecnologias de violação de censura. Modelos e algoritmos para esse problema estão muito próximos dos que são usados na prática e, logo, há potencial para pesquisa nessa área que pode ter um impacto real nas vidas de milhões de pessoas vivendo sob opressão.

* * *

\* **Mohammad Mahdian** é um pesquisador senior do Yahoo Research Lab em Santa Clara, CA. É bacharel em Engenharia da Computação pela Universidade de Tecnologia de Sharif, mestre em Ciência da Computação pela Universidade de Toronto e PhD em Matemática pelo MIT. Seus interesses de pesquisa atuais incluem projeto de algoritmos, economia algorítmica e aplicações em publicidade online e redes sociais.

{{< figure src="/wp-content/uploads/2011/12/18.2_Cover_crop.jpg" title="Capa da XRDS" >}}

Este texto foi publicado em inglês na última edição da [XRDS][4] (revista da ACM para estudantes), cujo [tema][5] é **Ciência da Computação a serviço da democracia**. No site do autor, há o [artigo “Fighting censorship with algorithms” completo em PDF][6] disponível para download gratuito. Ainda não li, mas parece interessante.

 [1]: https://i2.wp.com/tiagomadeira.com/wp-content/uploads/2011/12/18.2_Mahdian_med.jpg
 [2]: http://dl.acm.org/citation.cfm?id=2043250
 [3]: https://i2.wp.com/tiagomadeira.com/wp-content/uploads/2011/12/18.2_Cover_crop.jpg
 [4]: http://xrds.acm.org/
 [5]: http://xrds.acm.org/images/DLImages/18.2_Cover_crop.jpg
 [6]: http://www.mahdian.org/censorship.pdf

