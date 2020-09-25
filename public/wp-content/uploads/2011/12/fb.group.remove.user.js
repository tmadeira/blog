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
                var button = '<a class="mhm auxiliaryButton closeButton uiCloseButton" title="Remove" rel="dialog-post" href="/ajax/groups/members/remove.php?group_id=' + gid + '&uid=' + uid + '"></a>';
                a.innerHTML = a.innerHTML + " " + button;
            }
        }
        var pattern = new RegExp("(^| )groupsCleanProfilePic( |$)");
        if (pattern.test(a.className)) {
            gid = a.getAttribute("href").replace(/.*id=/, '');
        }
    }
})();

