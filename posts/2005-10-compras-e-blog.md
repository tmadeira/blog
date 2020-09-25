---
title: Compras e Blog
type: post
date: 2005-10-09T23:42:28+00:00
excerpt: Pedi meu presente de "Dia das Crianças"!
url: /2005/10/compras-e-blog/
categorias:
  - Cotidiano
tags:
  - bbcodes
  - c
  - computação
  - estatísticas
  - expressões regulares
  - geshi
  - linuxmall
  - programação
  - regex
  - sockets

---
Hoje, no Linuxmall, comprei um pequeno livro chamado **Invasão de Redes: Ataques e Defesas** e foi escrito por Tiago José Pereira Nogueira. Nunca vi nada desse cara, ninguém me recomendou esse livro e não conheço ninguém que já tenha lido ou comentado alguma coisa sobre ele. É um livro que parece ser novo e me deu vontade de comprar porque sempre quis saber trabalhar com redes no C. Ele aborda tópicos interessantes, como sockets e conexões, port scanners, DDoS, entre outras coisas. <small>Só tô explicando pra vocês não pensarem que eu comprei porque decidi virar um cracker maligno invasor de redes… :lol:</small> Aproveitei o frete pra comprar também um novo adesivo pro laptop, um [Tux grande][1] (de 11x13cm – eu medi antes pra ver se ficava legal no laptop) que custou R$ 2,00. A compra deve chegar quinta-feira. A propósito, alguém já ouviu falar de E-Sedex? Parece ser legal… Barato e rápido! Pedi essa compra com ele pra testar. Faz tanto tempo que não compro na internet que eu fico por fora dessas novidades!

Vou aproveitar o post pra postar os códigos que eu estou fazendo pra interpretação de BBCodes e estatísticas do blog que eu, o Hélio e o Gustavo começamos a desenvolver semana passada e queremos acabar até no máximo o final de novembro (pretendemos acabar perto do dia 15/11).

#### Expressões Regulares

```php
<?php
/* A parte de regex de códigos precisa do GeSHi Highlighter. Includando-o... */
include("geshi.php");

/* Essa classe serve para ser usada com "extends", ela sozinha "não é nada". */
class Regex {

    /* Função que interpreta emoticons */
    function Emoticons() {
        $origem=Array(":)", ":(", ":D", ":P", ":O", ":S", ":lol:", ":blink:");
        $destino=Array("feliz.gif", "triste.gif", "sorriso.gif", "lingua.gif", "espantado.gif", "confuso.gif", "riso.gif", "confuso.gif");
        // EM DESENVOLVIMENTO!
    }

    /* Função que interpreta BBCodes...
     * Totalmente desenvolvida por mim. (nem parece de tão linda, né?) */
    function InterpretaBBCodes() {
        /* Vamos começar pelos [codes], porque só o que tá fora deles deve ser
           interpretado depois. */

        preg_match_all("/[code language=([a-z]+)](.*)[/code]/sU", $this->texto, $matches_com_linguagens);
        preg_match_all("/[code](.*)[/code]/sU", $this->texto, $matches_sem_linguagens);

        /* - A parte dos códigos é $matches_com_linguagens[$i][2] e $matches_sem_linguages[$i][1].
               - A parte que diz em que linguagem os códigos $matches_com_linguagens[$i][2] foi escrita
              é $matches_com_linguagens[$i][1].
           - Para facilitar os códigos abaixo, vou trocar matches_com_linguagens para mcl e
           matches_sem_linguagens para msl. Só não fiz em cima pra quem tá de fora entender o que
           eu tô fazendo nessa parte do código. ;)
        */

        $mcl=$matches_com_linguagens;
        $msl=$matches_sem_linguagens;

        $con=0;
        for ($i=0; $i<sizeof ($mcl[0]); $i++) {
            $g=new GeSHi($mcl[2][$i], $mcl[1][$i], "./geshi/");
            $geshi_mcl[$i]=$g->parse_code();
            $mcl_md5[$i]=md5(time()*$con++);
            $this->texto=str_replace($mcl[0][$i], $mcl_md5[$i], $this->texto);
        }
        for ($i=0; $i</sizeof><sizeof ($msl[0]); $i++) {
            /* Aqui, vocês vão perguntar: "Por que passar no GeSHi, se não sei highlightear essa linguagem?
               A resposta é que o GeSHi não só highlighta, mas formata o código de forma que ele fique
               legível (por exemplo, troca < por &lt. */
            $g=new GeSHi($msl[1][$i], "", "./geshi/");
            $geshi_msl[$i]=$g->parse_code();
            $msl_md5[$i]=md5(time()*$con++);
            $this->texto=str_replace($msl[0][$i], $msl_md5[$i], $this->texto);
        }

        /* Beleza, agora precisamos sempre lembrar de não highlightear o que estiver entre
           E também não podemos deixar nada fora dos padrões XHTML Strict. */

        $this->texto=str_replace("&", "&", $this->texto);
        $this->texto=str_replace("< ", "<", $this->texto);
        $this->texto=str_replace(">", ">", $this->texto);
        $this->texto=str_replace(""", """, $this->texto);

        // Aqui tá o meu "nl2br" semântico! =)
        $this->texto="<p>".$this->texto."</p>";
        $this->texto=preg_replace("/\n\n\n*/", "<p>", $this->texto);
              /* </p><p></p> vazios não são semânticos. Mas estive pensando depois de fazer isso e acho que
                  algumas pessoas podem querer dar um grande espaço entre os <p>, por isso estou
                  pensando em fazer uma ER que a cada n a mais de dois n's adicione 10px ao
                  margin-bottom do último </p><p>. O que vocês acham? */
        $this->texto=preg_replace("/\n/", "<br />\n", $this->texto);
        $this->texto=preg_replace("/</p></p><p>/", " </p>\n<p>", $this->texto);

        // Formatação básica (negrito, itálico, sublinhado, cores, cabeçalhos)
        $this->texto=preg_replace("/[b](.*)[/b]/sU", "<strong>\1</strong>", $this->texto);
        $this->texto=preg_replace("/[i](.*)[/i]/sU", "<em>\1</em>", $this->texto);
        $this->texto=preg_replace("/[u](.*)[/u]/sU", "<span style="text-decoration:underline;">\1</span>", $this->texto);
        $this->texto=preg_replace("/[color=([^]]+)](.*)[/color]/sU", "<span style="color:\1;">\2</span>", $this->texto);
        $this->texto=preg_replace("/[h([1-6])](.*)[/h\1]/sU", "<h \1>\2< /h\1>n", $this->texto);

        // Citações
        $this->texto=preg_replace("/[quote](.*)[/quote]/sU", "<q>\1</q>n", $this->texto);
        $this->texto=preg_replace("/[quote=([^]]+)](.*)[/quote]/sU", "<q>\2</q>n<cite>\1</cite>", $this->texto);

        // URLs
        $this->texto=preg_replace("/([^\"/=]])(www.[^[:blank:]\"< ]+)/", "\1<a href=\"http://\2\">\2", $this->texto);
        $this->texto=preg_replace("/([^\"=]])(http://[^[:blank:]\"< ]+)/", "\1<a href=\"\2\">\2", $this->texto);

        $this->texto=preg_replace("/[url]([^\"]*)[/url]/sU", "<a href=\"\1\">\1</a>", $this->texto);
        $this->texto=preg_replace("/[url=([^[:blank:]\"]+)[[:blank:]]+title=([^]\"]+)](.*)[/url]/sU", "<a href=\"\1\" title=\"\2\">\3</a>", $this->texto);
        $this->texto=preg_replace("/[url=([^\]\"]+)](.*)[/url]/sU", "<a href=\"\1\">\2</a>", $this->texto);

        preg_match_all("/<a href=\"([^\"]+)\">/U", $this->texto, $matches);

        for ($i=0; $i<count ($matches[0]); $i++) {
            $parse=parse_url($matches[1][$i]);
            $dominio=$parse["host"];
            $this->texto=str_replace($matches[0][$i], "<a href="".$matches[1][$i]."" title="Link Externo: $dominio">", $this->texto);
        }

        // Imagens
        $this->texto=preg_replace("/[img=([^]]+)]([^\"]*)[/img]/U", "<img src=\"\2\" alt=\"\1\" />", $this->texto);
        $this->texto=preg_replace("/[img]([^\"]*)[/img]/U", "<img src=\"\1\" alt=\"Imagem: \2\" />", $this->texto);

        // Listas
        $this->texto=preg_replace("/[list](.*)[/list]/sU", "<ul>\1</ul>", $this->texto);
        $this->texto=preg_replace("/[li](.*)[/li]/sU", "<li><p>\1</p></li>", $this->texto);

        // Limpando besteiras... Alguém tem alguma idéia melhor do que esse FOR feio?
        for ($count=0; $count<10; $count++) {
            $this->texto=preg_replace("/<br /></li>/", "", $this->texto);
            $this->texto=preg_replace("/<ul><br />/", "</ul><ul>", $this->texto);
              $this->texto=preg_replace("/< (/?)li><br />/", "< \1li>",  $this->texto);
              $this->texto=preg_replace("/<q><br />/", "</q><q>", $this->texto);
              $this->texto=preg_replace("/< /q><br />/", "</q>", $this->texto);
          }

          // Emoticons
          // $this->Emoticons();

          /* Lembram que o código tinha sido transformado em md5s com o tempo, pros
             bbcodes não entrarem em ação dentro deles? Então vamos transformar de
             volta em códigos agora... */

          for ($i=0; $i<sizeof ($mcl[0]); $i++) {
              $this->texto=str_replace($mcl_md5[$i], $geshi_mcl[$i], $this->texto);
          }

          for ($i=0; $i</sizeof><sizeof ($msl[0]); $i++) {
              $this->texto=str_replace($msl_md5[$i], $geshi_msl[$i], $this->texto);
          }

          // Limpando as besteiras que não precisam ser repetidas (e coloquei depois dos codes porque
          // aqui corrijo o negócio com os <pre>s.
          $this->texto=preg_replace("/<p>[[:blank:]]*<pre>(.*)< /pre>[[:blank:]]*< /p>/sU", "<\/pre><pre>\1<\/pre>", $this->texto);
          $this->texto=preg_replace("/</p><p>[[:blank:]]*<ul>(.*)< /ul>[[:blank:]]*< /p>/sU", "</ul><ul>\1</ul>", $this->texto);
          $this->texto=preg_replace("/</p><p>[[:blank:]]*<h (.)>(.*)< /h\1>[[:blank:]]*< /p>/sU", "</h><h \1>\2</h>", $this->texto);
          $this->texto=preg_replace("/< ([^>]+)>[[:blank:]]?< /\1>/", "", $this->texto);

          // E pra finalizar, o mais mala de todos... =)
          $this->texto.="\n";
      }
  }
  ?>
```

Tá bem comentado e queria pedir pra quem puder, dar uma testada com ele (coloquem uns BBCodes errados e coisas que vocês acham que eu não iria prever). Aí embaixo então a parte das estatísticas, para as quais estou usando um pouco do código do Shortstat. Ela tá assim por enquanto:

#### Estatísticas

```php
<?php
class Estatisticas {
    var $ip, $pais, $codigopais, $referer, $url, $dominio, $res, $useragent, $navegador, $versaonavegador, $plataforma, $unixtime;

    /* Função que descobre o IP real do visitante
     * Copiada de: www.foo.com.br
     */
    function IpReal() {
        if (getenv("HTTP_CLIENT_IP") && strcasecmp(getenv("HTTP_CLIENT_IP"), "desconhecido")) {
            $ip=getenv("HTTP_CLIENT_IP");
        } else if (getenv("HTTP_X_FORWARDED_FOR") && strcasecmp(getenv("HTTP_X_FORWARDED_FOR"), "desconhecido")) {
            $ip=getenv("HTTP_X_FORWARDED_FOR");
        } else if (getenv("REMOTE_ADDR") && strcasecmp(getenv("REMOTE_ADDR"), "desconhecido")) {
            $ip=getenv("REMOTE_ADDR");
        } else if (isset($_SERVER['REMOTE_ADDR']) && $_SERVER['REMOTE_ADDR'] && strcasecmp($_SERVER['REMOTE_ADDR'], "desconhecido")) {
            $ip=$_SERVER['REMOTE_ADDR'];
        } else {
            $ip="desconhecido";
        }

        return $ip;
    }

    /* Função para descobrir navegador, sistema operacional, etc. com base no User Agent.
     * "SI_parseUserAgent()" do Shortstat, levemente modificada.
     */
    function ParseUserAgent($ua) {
        $plataforma="Desconhecida";
        $navegador="Desconhecido";
        $versao="";

        if (eregi("Win", $ua)) {
            $plataforma="Windows";
        } else if (eregi("Mac", $ua)) {
            $plataforma="Macintosh";
        } else if (eregi("Linux", $ua)) {
            $plataforma="Linux";
        } else if (eregi("W3C", $ua)) {
            $plataforma="W3C Validator";
            $navegador="W3C Validator";
            $versao="-";
        } else if (eregi("Googlebot", $ua)) {
            $plataforma="Googlebot";
        } else if (eregi("msnbot", $ua)) {
            $plataforma="MSNBot";
        } else if (eregi("Cynthia", $ua)) {
            $plataforma="Cynthia";
            $navegador="Cynthia";
            $versao="0";
        }

        if (eregi("Mozilla/4", $ua)&&!eregi("compatible", $ua)) {
            $navegador="Netscape";
            eregi('Mozilla/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Mozilla/5", $ua)||eregi("Gecko", $ua)) {
            $navegador="Mozilla";
            eregi('rv(:| )([[:digit:].]+)', $ua, $b);
            $versao=$b[2];
        }
        if (eregi("Safari", $ua)) {
            $navegador="Safari";
            $plataforma="Macintosh";
            eregi('Safari/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("iCab", $ua)) {
            $navegador="iCab";
            eregi('iCab/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Firefox", $ua)) {
            $navegador="Firefox";
            eregi('Firefox/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Firebird", $ua)) {
            $navegador="Firebird";
            eregi('Firebird/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Phoenix", $ua)) {
            $navegador="Phoenix";
            eregi('Phoenix/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Camino", $ua)) {
            $navegador="Camino";
            eregi('Camino/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Chimera", $ua)) {
            $navegador="Chimera";
            eregi('Chimera/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Netscape", $ua)) {
            $navegador="Netscape";
            eregi('Netscape[0-9]?/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("MSIE", $ua)) {
            $navegador="Internet Explorer";
            eregi('MSIE ([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Opera", $ua)) {
            $navegador="Opera";
            eregi('Opera( |/)([[:digit:].]+)', $ua, $b);
            $versao=$b[2];
        }
        if (eregi("OmniWeb", $ua)) {
            $navegador="OmniWeb";
            eregi('OmniWeb/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }
        if (eregi("Konqueror", $ua)) {
            $navegador="Konqueror";
            $plataforma="Linux";
            eregi('Konqueror/([[:digit:].]+', $ua, $b);
            $versao=$b[1];
        }
        if (eregi('Crawl', $ua) || eregi('bot', $ua) || eregi('slurp', $ua) || eregi('spider', $ua)) {
            $navegador="Crawler/Search Engine";
            $versao="-";
        }
        if (eregi('Lynx', $ua)) {
            $navegador="Lynx";
            eregi('Lynx/([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
            $plataforma="Linux";
        }
        if (eregi('Links', $ua)) {
            $navegador="Links";
            eregi('(([[:digit:].]+)', $ua, $b);
            $versao=$b[1];
        }

        $array=Array($navegador, $versao, $plataforma);
        return $array;
    }

    /* Função para determinar o país do visitante
     * "SI_determineCountry()", do Shortstat, bem modificada por mim.
     */
    function DeterminarPais($ip) {
        global $BASE;
        $ip=sprintf("%u", ip2long($ip));

        $db=new $BASE['TYPE'];
        $db->Conecta();
        $db->Query("SELECT nome, codigo FROM ".$BASE['TABELA_PAISES']." WHERE ip_from < = $ip AND ip_to >= $ip");
        $array=$db->FetchRow();

        $db->Desconecta();

        /* Agora um monte de linhas por causa da incompetência do PHP 5.0.5... Hehehe... */
        $tmp1=preg_replace("/([A-ZxC0-xDF])/e", "chr(ord('\1')+32)", $array[0]);
        $tmp2=ucwords($tmp1);
        $array[0]=trim($tmp2);

        return $array;
    }

    /* Função para "increase stats"
     * O arquivo "inc.stats.php" do Shortstat, bem modificado por mim.
     */
    function IncStats() {
        global $BASE;
        $this->ip=$this->IpReal();
        list($this->pais, $this->codigopais)=$this->DeterminarPais($this->ip);
        $this->referer=$_SERVER["HTTP_REFERER"];
        $this->url=parse_url($this->referer);
        $this->dominio=eregi_replace("^www", "", $this->url["host"]);
        $this->resource=$_SERVER["REQUEST_URI"];
        $this->useragent=$_SERVER["HTTP_USER_AGENT"];
        list($this->navegador, $this->versaonavegador, $this->plataforma)=ParseUserAgent($this->useragent);
        $this->unixtime=time();

        $db=new $BASE['TYPE'];
        $db->Conecta();
        $db->Query("INSERT INTO ".$BASE['TABELA_ESTATISTICAS']." (ip, pais, codigopais, dominio,
        referer, resource, useragent, plataforma, navegador, versao, unixtime) VALUES ('{$this->ip}',
        '{$this->pais}', '{$this->codigopais}', '{$this->dominio}', '{$this->referer}', '{$this->resource}',
        '{$this->useragent}', '{$this->plataforma}', '{$this->navegador}', '{$this->versaonavegador}',
        '{$this->unixtime}')");
        $db->Desconecta();
    }
}
?>
```

Bom... Esses dois códigos estão em desenvolvimento ainda, mas acho que com o tempo vão melhorando. Tem umas coisas na parte de Regex que eu queria tornar mais simples mas ainda não descobri como! :blink: Quem quiser sugerir, sinta-se a vontade.

 [1]: http://www.linuxmall.com.br/index.php?product_id=656

