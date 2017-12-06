---
title: Userscript para remover usuários de grupos do Facebook
type: post
date: 2011-12-27T16:58:39+00:00
url: /2011/12/userscript-para-remover-usuarios-de-grupos-do-facebook/
categories:
  - Códigos aleatórios
tags:
  - bug
  - códigos
  - facebook
  - greasemonkey
  - grupos
  - javascript
  - scripts
  - userscript

---
Já faz algum tempo que o Facebook tem um bug nas listas de membros dos grupos. As listas não mostram todos os membros do grupo. Mais: os membros que não aparecem na lista nem mesmo podem ser encontrados pelo formulário de busca de nomes. Quando você é administrador de um grupo, isso pode ser um grande inconveniente, porque na interface padrão do Facebook a lista de membros é o único lugar onde é possível excluir usuários de um grupo. Ou seja, os usuários que não aparecem lá são indeletáveis!

{{< figure src="/wp-content/uploads/2011/12/fb1.png" title="Só ali na lista de membros aparece esses X para excluir os membros do grupo." >}}

Há alguns meses, escrevi um _user script_ para o [GreaseMonkey][1] (extensão para o Firefox que permite que você crie esses pequenos scripts para serem rodados em páginas específicas) que busca ajudar os administradores de grupos a removerem esses membros fantasmas.

Não havia publicado até agora por vergonha (o script é bem feio, tanto o código como o resultado). Porém, acho que não pretendo perfumá-lo tão cedo, então resolvi liberá-lo aqui até pra inspirar quem quiser fazer coisas mais bonitas.

O funcionamento dele é muito simples: quando você entra num grupo (sendo ou não administrador — porque nem distingui isso no código), ele cria botões **X** do lado dos links para os perfis dos usuários que estão nessa página (e só nesses — outra coisa que nem me preocupei no script). Se você for administrador do grupo em questão, quando clica no **X** o Facebook abre aquela caixa perguntando se você quer mesmo excluir o membro em questão (e se quer baní-lo permanentemente).

{{< figure src="/wp-content/uploads/2011/12/fb2.png" title="Com o script, tem X em todo o lugar! (até onde não deve… hehe)" >}}

Sem mais enrolação, eis aqui **o código** para (des-)apreciação e aprimoramentos _(por favor! :))_:

```javascript
// ==UserScript==
// @name Remove users from Facebook groups
// @description Remove usuarios que postam no grupo sem precisar procurar na lista de membros
// @author  Tiago Madeira <madeira@juntos.org.br>
// @include http*://www.facebook.com/groups/*
// @version 1.32
// ==/UserScript==

(function(){
    var as = document.getElementsByTagName("a");
    var gid = "";

    for (var i = 0; i < as.length; i++) {
        var a = as[i];
        var hovercard = a.getAttribute("data-hovercard");
        if (hovercard != null && hovercard != "") {
            uid = hovercard.replace(/.*id=/, '');
            if (gid != "") {
                var button = '<a class="mhm auxiliaryButton closeButton uiCloseButton" ' +
                    'title="Remove" rel="dialog-post" ' +
                    'href="/ajax/groups/members/remove.php?group_id=' + gid + '&uid=' + uid + '"></a>';
                a.innerHTML = a.innerHTML + " " + button;
            }
        }
        var pattern = new RegExp("(^| )groupsCleanProfilePic( |$)");
        if (pattern.test(a.className)) {
            gid = a.getAttribute("href").replace(/.*id=/, '');
        }
    }
})();
```

Ou o **link direto para download (ou instalação no GreaseMonkey)**:

<p style="text-align:center; font-size:1.4em;">
  <a href="/wp-content/uploads/2011/12/fb.group.remove.user.js">fb.group.remove.user.js</a> (1.08kb)
</p>

 [1]: http://www.greasespot.net/

