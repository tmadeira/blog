---
title: Universidade de São Paulo de São Paulo
type: post
date: 2009-06-02T14:19:17+00:00
url: /2009/06/universidade-de-sao-paulo-de-sao-paulo/
sociableoff:
  - 'false'
categorias:
  - Pensamentos aleatórios
tags:
  - fuvest
  - São Paulo
  - universidade
  - usp
  - vestibular

---
Eu gostaria de confirmar algo que percebia na USP. Após dois minutos de código…

```bash
for i in 1 2 3 4; do
    lynx -dump "http://www.fuvest.br/vest2009/chamada${i}/62389${i}09.stm" | grep '^[0-9]' | sed -e 's/ .*//' >> numb
done

numbers=`cat numb`
for i in $numbers; do
    lynx -dump "http://www.fuvest.br/scripts/chama.asp?valor=$i&x=0&y=0&anofuv=2009&cham=4&warn=undefined&last=S" > /tmp/rg
    nome=`cat /tmp/rg | grep 'Nome:' | sed -e 's/.*:[[:blank:]]*//g'`
    rg=`cat /tmp/rg | grep 'Identidade:' | sed -e 's/.*:[[:blank:]]*//g'`
    echo -e "$rgt$nome"
done
```

… a **dura realidade**:

Das 106 pessoas que foram convocadas para a matrícula no Bacharelado em Ciência da Computação do IME-USP, temos, por estado:

  * **São Paulo:** 100
  * **Santa Catarina:** 1 (eu)
  * **Pernambuco:** 1
  * **Mato Grosso:** 1
  * **Bahia:** 1
  * **Minas Gerais:** 1
  * **Distrito Federal:** 1

{{<figure src="https://farm4.static.flickr.com/3352/3474503026_2652267fd1.jpg" title="Mapa do Brasil (crédito: thejourney1972/flickr)" >}}

Estou ainda sendo bondoso ao assumir que as pessoas dos outros estados moravam realmente nos outros estados (a família já não havia se mudado para cá).

O que nos leva rapidamente a concluir o porquê de as redondezas da USP não terem tantos estudantes como deveriam (ou como o distrito de Barão Geraldo em Campinas ou as redondezas paradisíacas da UFSC em Floripa)

Além disso, são dados suficientes para eu entender por quê não havia _nenhum_ bar frequentado por estudantes aqui perto passando São Paulo e Cruzeiro…

Enfim, os dados explicam muita coisa. Só não explicam por quê a FUVEST não faz provas nos outros estados… ou a USP gosta de só ter paulistas na graduação?

