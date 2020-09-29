---
title: Primeiro Lugar na OBI 2005!
type: post
date: 2005-06-17T20:05:32+00:00
excerpt: Para minha surpresa, fiz 395 dos 400 pontos possíveis!
url: /2005/06/primeiro-lugar-na-obi-2005/
categorias:
  - Cotidiano
tags:
  - computação
  - obi
  - obi 2005
  - olimpíadas
  - resultado
---

![Quadro de Mérito OBI2005 Programação Nível 1](https://farm1.staticflickr.com/15/20324573_9a04423e14.jpg)

Esse post é uma edição do **395 pontos!**

Utilizando uns programas Bash que eu fiz, acho que fui o primeiro a ver meu resultado da Olimpíada Brasileira de Informática 2005, seguindo links do Mapa do Conteúdo que foram aparecendo em alguns momentos da tarde do dia 06/06 (e, misteriosamente, sumindo logo após). Para minha surpresa, fiz 395 dos 400 pontos possíveis!

Só errei um teste na prova (o teste 3 da questão Trilhas), o que me garantiu a única medalha de ouro da **Programação Nível 1** e primeiro lugar isolado.

O segundo lugar, de Fortaleza, fez 300 pontos.

Agora vou pra UNICAMP em julho fazer o curso de programação avançada (com tópicos muito legais, que vão acabar com muitas dúvidas minhas – como Programação Dinâmica e Algoritmos Gulosos) disputar uma vaga na IOI na Polônia. Acho difícil conseguir vencer, até porque cinco pessoas gabaritaram a **Programação Nível 2** (ou seis?), mas vou me esforçar para chegar o mais perto possível das quatro vagas.

### Programas em Bash usados para ver o resultado antes do normal

#### Primeiro Programa

```bash
#!/bin/bash

musica="/ntfs/Program Files/MSN Messenger/type.wav"
endereco="http://olimpiada.ic.unicamp.br"

mv ~/.obi ~/.obi-o > /dev/null 2> /dev/null
lynx -source "$endereco" > ~/.obi

if [ "`cat ~/.obi`" = "`cat ~/.obi-o`" ]; then
       echo "34m1mO site da OBI não foi atualizado desde a última vez que o programa foi executado.�m"
else
       echo "31m1mO site da OBI foi atualizado desde a última vez que o programa foi executado!�m"
       play "$musica"
       firefox "$endereco"
fi
```

Este programa verifica quando o site é atualizado. Quando a música tocou, o navegador se abriu e vi que apareceu um novo link (Copy of …)

#### Segundo Programa

```bash
#!/bin/bash
action=""
logurl=""

echo "compet_type=3&school_name=&school_city=&school_state=choose&compet_name=&order=compet_id&batch_size=10000&show=Consulta" \
  | lynx -source -post-data "$action" > .t

grep "MostraLog" .t > .t2 #sim, eu sei que não precisava de tantos arquivos

sed -e 's/<a href="MostraLog?id=(.*)">.*</a>/1/' .t2 > .t3 #tá, eu sei que eu devia ter usado [0-9]+ mas não é necessário

for i in `cat .t3`; do
       printf "34m1mVerificando id $i...�m"
       lynx -dump "$logurl?id=$i" | grep "Total de pontos" > .t4
       pontuacao=`sed -e 's/Total de pontos:  (.*)/1/' .t4`
       echo "$pontuacao"
        # uma coisa que eu devia ter feito aqui é pegar o nome do cara (.t2 | grep $i | sed...)
       if [ -n "$pontuacao" ]; then
              if [ $pontuacao -ge 200 ]; then
                     echo "$i|$pontuacao" >> .ponto #isso aqui é só pra eu ver quem é certinho
              fi
       fi
done
```

Este foi bastante modificado depois e fiz várias versões melhores dele para pegar várias vezes o resultado. Mas esse serve para mostrar a idéia do negócio… ;)

#### Essa conquista em outros sites

- [Rede Salesiana de Escolas][2]
- [DomBosco.net][3]
- [Escol@24Horas.com.br][4]
- [Quadro de Mérito no site da OBI][5]

[2]: http://www.portalsalesianas.com.br/noticiasinst/noticias_fma292.asp
[3]: http://www.dombosco.net/index.asp?SECAO=4&SUBSECAO=16&EDITORIA=379
[4]: http://www4.escola24h.com.br/cf/patio/aco-popup.cfm?ac_codigo=43012&status=55505F5F46
[5]: http://olimpiada.ic.unicamp.br/res_prelim/programacao/FormConsultaClassifProg
