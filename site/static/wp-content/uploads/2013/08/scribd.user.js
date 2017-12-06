// ==UserScript==
// @name Suppress Scribd Paywall
// @include http://*.scribd.com/doc/*
// @require http://code.jquery.com/jquery-2.0.3.min.js
// ==/UserScript==

(function($) {
    $(document).ready(function() {
        window.setInterval(function(){$(".absimg").css("opacity", "1")}, 1000);
        $(".autogen_class_views_read_show_page_blur_promo").on("click", function(e) { $(this).hide(); });
    });
})(jQuery);

