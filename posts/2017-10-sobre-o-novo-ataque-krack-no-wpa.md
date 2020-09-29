---
title: Sobre o novo ataque (KRACK) no WPA
type: post
date: 2017-10-17T12:07:50+00:00
url: /2017/10/sobre-o-novo-ataque-krack-no-wpa/
categorias:
  - Pensamentos aleatórios
tags:
  - criptografia
  - internet
  - krack
  - redes
  - segurança
  - wifi
  - wpa
---

O interessante [ataque KRACK][1] mostra uma falha grave no WPA, protocolo de segurança para redes sem fio usado em toda parte — e que segue sendo o mais seguro que temos disponível, mesmo depois desse ataque.

Bruce Schneier [definiu][2] o ataque como brilhante: “embora a vulnerabilidade seja óbvia depois que alguém aponta pra ela, por mais de 10 anos ninguém percebeu”.

É bom que a mídia nacional e internacional tenha dado destaque para a descoberta. Ajuda na pressão para que o problema seja consertado mais rápido. Porém, me parecem sensacionalistas as notícias que falam coisas como [“a partir de hoje, não existe rede wifi segura”][3]. Além da manchete, a chamada dessa matéria é um exagero: “Vulnerabilidades no principal padrão de segurança de wifi utilizado hoje, o WPA2, tornam sua criptografia e medidas de segurança praticamente inúteis.”

Pelo pouco que li, não é o fim do mundo. Listo alguns motivos:

1. A maioria das redes wifi já não é segura. Usam chaves fracas que podem ser descobertas por meio de ataques de força bruta. E quem tem a chave já consegue descriptografar o tráfego com tranquilidade. Pra não falar de redes sem chave, usadas em aeroportos e outros lugares públicos, que já não têm nenhuma segurança. Usar Wi-Fi apenas em lugares com autenticação por certificados no lugar de senhas compartilhadas tem que ser pré-requisito para considerar esse ataque o fim do mundo. É por isso que Nicholas Weaver [conclui][4] que só quem deve se preocupar são as empresas que usam tais padrões mais seguros. Pra elas houve uma mudança maior, de fato.
2. A falha pode ser corrigida do lado do cliente. A Microsoft e a Apple já lançaram patches para corrigir seus sistemas operacionais, diversos patches já existem também para Linux e o Google se comprometeu a lançar um patch para Android nas próximas semanas. Ou seja, basta instalar uma atualização no seu sistema operacional (uma boa prática de segurança) para estar livre da vulnerabilidade (e aí talvez escrevam novas matérias dizendo “a partir de hoje, as redes wifi voltam a ser seguras”?). Como diz o próprio site do KRACK, _“Do we now need WPA3? No, luckily implementations can be patched in a backwards-compatible manner.”_
3. Como diz o resumo do artigo em que a falha é apresentada: _“The impact depends on the handshake being attacked, and the data-confidentiality protocol in use. Simplified, against AES-CCMP an adversary can replay and decrypt (but not forge) packets. This makes it possible to hijack TCP streams and inject malicious data into them. Against WPA-TKIP and GCMP the impact is catastrophic: packets can be replayed, decrypted, and forged. Because GCMP uses the same authentication key in both communication directions, it is especially affected.”_ Ou seja, mudando a configuração do WPA no seu roteador você pode obter um pouco mais de segurança.
4. Como a vulnerabilidade exige que o atacante esteja fisicamente no mesmo lugar que você, não vai haver um ataque em massa como o ransomware que comprometeu centenas de milhares de máquinas no mundo inteiro. Por algumas semanas (até os seu sistema operacional estar atualizado), pessoas perto de você que implementem o ataque descrito no artigo poderão ver seu tráfego \*não criptografado\* (mas elas provavelmente já podiam, pelo item 1).
5. A ênfase no “não criptografado” do item acima se deve ao fato de que a maioria do tráfego na web hoje é criptografado usando TLS (https). Tal tráfego não está sujeito a interceptação. É verdade que no [vídeo do ataque][5] o pesquisador usa o [sslstrip][6] para interceptar esse tráfego. Mas creio que seja justo dizer, ao menos, que quando você vê um cadeadinho e um “https” na barra de endereço do seu navegador seu tráfego segue sendo seguro. [No mais, usar extensões como [HTTPS Everywhere][7] segue sendo uma ótima recomendação.]
6. Medidas de segurança não se tornaram inúteis. Usar uma VPN segura em lugares públicos (ou mesmo privados), por exemplo, segue sendo uma boa prática que protege seu tráfego.

Por fim, parece bom aproveitar o momento pra dizer que a maioria das redes sem fio não são seguras e que é bom se preocupar com a segurança delas. Usar WPA com certificados segue sendo a melhor opção pra quem se preocupa com isso; como é difícil e quase ninguém configura isso na sua casa, usar WPA com uma senha grande e difícil é uma alternativa razoável.

(No seu computador também há a opção de usar os bons e velhos cabos de rede, que são uma beleza: mais seguros, mais rápidos e perdem menos pacotes)

[1]: https://www.krackattacks.com/
[2]: https://www.schneier.com/blog/archives/2017/10/new_krack_attac.html
[3]: https://www.vice.com/pt_br/article/qvjgdm/wifi-wpa2-krack
[4]: https://www.lawfareblog.com/dont-worry-about-krack
[5]: https://www.youtube.com/watch?v=Oh4WURZoR98
[6]: https://moxie.org/software/sslstrip/
[7]: https://www.eff.org/https-everywhere
