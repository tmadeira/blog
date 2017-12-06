// ==UserScript==                                                                                      
// @name Permite copiar textos da Folha                                                                
// @include http://*.folha.uol.com.br/*                                                                
// ==/UserScript==                                                                                     
                                                                                                       
window.onload = function() {                                                                           
    all = document.querySelectorAll("*");                                                              
    fn = function(e) {                                                                                 
        e.stopPropagation();                                                                           
        return true;                                                                                   
    }                                                                                                  
    for (var i = 0; i < all.length; i++) {                                                             
        all[i].oncut = fn;                                                                             
        all[i].oncopy = fn;                                                                            
        all[i].onpaste = fn;                                                                           
    }                                                                                                  
}
