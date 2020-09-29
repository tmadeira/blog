// ==UserScript==
// @name Copiador de fotos UOL
// @description Torna mais fácil copiar fotos de álbuns da UOL
// @author  Tiago Madeira <contato@tiagomadeira.com>
// @include http*://*.uol.com.br/album/*
// @version 0.9
// ==/UserScript==

(function () {
  window.onload = function () {
    document.getElementById("setaEsq").style.width = "50px";
    document.getElementById("setaDir").style.width = "50px";
  };
})();
