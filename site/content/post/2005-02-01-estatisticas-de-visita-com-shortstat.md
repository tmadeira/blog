---
title: Estatísticas de Visita com Shortstat
type: post
date: 2005-02-01T13:59:57+00:00
excerpt: Comecei a usar o Shortstat para acompanhar as estatísticas do meu site. Ele é muito bom, mas tive alguns probleminhas com ele. Aqui explico soluções legais para estes problemas.
url: /2005/02/estatisticas-de-visita-com-shortstat/
categorias:
  - Dicas
  - Metablogagem
tags:
  - apache
  - mysql
  - php
  - shortstat
  - web

---
Comecei a usar o Shortstat para acompanhar as estatísticas do site. Porém, tive alguns problemas com ele (não exatamente problemas, mas coisas que eu acho melhor mudar). Exemplos:

  * As estatísticas de browser e sistema são contadas por hit… Eu acho muito mais sensato contar por visita (única), pois algumas pessoas contam vários hits (exemplo: eu) e daí as minhas estatísticas estavam dizendo que 80% dos visitantes usavam Linux!
  * Os webcrawlers e alguns browsers são registrados como sistema operacional desconhecido

Já que o sistema é feito em PHP, achei legal consertar estes problemas e até traduzir e colocar uma bandeira do lado dos países. emoticon Vou postar aqui um passo-a-passo de instalação e esas configuração do Shortstat para quem precisar. Achei ele um ótimo sistema de estatísticas (código super simples e bem direto) e tem tudo que eu preciso. :)

#### Introdução

O Shortstat é um programa de estatísticas da ShaunInman escrito em PHP que usa um banco de dados MySql para incluir os registros. O funcionamento é bastante simples. Em cada página, eu uso um include para um arquivo que conta visita e existe um arquivo que conta as estatísticas. Estou partindo do princípio que você já tem PHP e MySql configurados num servidor web.

#### Download

O download do programa .zip pode ser feito aqui:

<http://www.shauninman.com/downloads/shortstat_v036b.zip>

No Linux, use o comando **unzip shortstat_v036b.zip** para descompactar.

No Windows, use um programa como WinZip ou WinRar (ou o descompactador do Windows XP).

#### Arquivos Descompactados

  * configuration.php – Configuração do banco de dados
  * functions.php – Funções do programa (toda a parte de PHP)
  * inc.stats.php – Arquivo que deve ser incluído em cada página do site pra contar visita
  * index.php – Página onde se vê as estatísticas
  * styles.css – Estilos (css) da página index.php

E ainda tem os arquivos de instalação (que poderão ser deletados logo que acabar a instalação).

#### IP dos Países

O Shortstat vem com um arquivo de 2mb (\_ip-to-country.txt) que tem um banco de dados com ip de vários países e outro php (\_ip-to-country.php) que serve para instalar o suporte ao “ip-to-country”. Depois de instalar o Shortstat normal, nós vamos instalar também para saber de onde são os visitanets do site.

#### Instalação

Para instalar o Shortstat, edite o arquivo configuration.php colocando nas variáveis:

```php
<?php
$SI_db['server']="servidor_do_mysql";
$SI_db['username']="username_do_mysql";
$SI_db['password']="senha_do_mysql";
$SI_db['database']="nome_do_banco_de_dados";
$tz_offset=seu_fuso_horario;
$shortstat=true;
?>
```

E rode o script de instalação (_install.php) no seu browser. Ele irá criar as tabelas no seu banco de dados. Daí basta acrescentar:

```php
<?php @include_once("diretorio_do_shortstat/inc.stats.php"); ?>
```

… no início de cada arquivo que você quer que sejam contadas as estatísticas.

Antes de instalar o ip-to-country, eu criei uma coluna chamada codigopais no banco de dados MySql e modifiquei o arquivo functions.php criando uma função chamada **verCodigoPais**:

```php
<?php
function verCodigoPais($ip) {
       if (!SI_isIPtoCountryInstalled()) return '';
       global $SI_tables;
       $ip = sprintf("%u",ip2long($ip));

       $query="SELECT country_code2 AS codigo FROM $SI_tables[countries] WHERE ip_from <= $ip AND ip_to >= $ip";
       if ($result=mysql_query($query)) {
              if ($r = mysql_fetch_array($result)) {
                     return $r['codigo'];
              }
       }
}
?>
```

No arquivo **inc.stats.php**, depois de atribuir um valor para a variável **$ip**, coloquei:

```php
<?php
$cd     = verCodigoPais($ip);
?>
```

… e depois de colocar valor em todas as variáveis alterei a $query para:

```php
<?php
$query = "INSERT INTO $SI_tables[stats] (remote_ip, country, codigopais,
domain, referer, resource, user_agent, platform, browser, version, dt)
VALUES ('$ip', '$cntry', '$cd', '$domain', '$ref', '$res', '$ua', '$br[platform]',
'$br[browser]', '$br[version]', $dt)";
?>
```

(a única mudança foi a adição da variável cd – que contém o código do país – no campo codigopais do banco de dados)

Agora basta imprimir a bandeira do país… Para isso, no arquivo functions.php alterei a função **SI_getCountries**:

```php
<?php
function SI_getCountries() {
       global $SI_tables,$_SERVER;

       $query = "SELECT country, codigopais, COUNT(distinct(remote_ip)) AS 'total'
                       FROM $SI_tables[stats]
                       WHERE country!=''
                       GROUP BY country
                       ORDER BY total DESC";

       if ($result = mysql_query($query)) {
              $ul  = "<table cellpadding="0" cellspacing="0" border="0">n";
              $ul .= "t

<tr>
  <th>
    Country
  </th>

  <th class="last">
    Visits
  </th>
</tr>n";
              $i=0;
              while ($r = mysql_fetch_array($result)) {
                     if ($i < 36) {
                            $url = parse_url($r[referer]);
                            $ul .= "t

<tr>
  <td>
    <img src="http://ip-to-country.webhosting.info/flag/?type=3&cc2=$r[codigopais]" alt="$r[codigopais]" /> $r[country]
  </td>

  <td class="last">
    $r[total]
  </td>
</tr>n";
                            $i++;
                            }
                     }
              $ul .= "</table>";
              }
       return $ul;
}
?>
```

(note que a imagem é buscada direto do servidor do ip-to-country)

Então, agora é só instalar o ip-to-country, mas o arquivo de instalação só está servindo para colocar o nome do país no banco de dados (não o código). Basta modificar o arquivo **_ip-to-country.php**, alterando:

```php
<?php
echo "<p>Mapping existing IPs to countries.</p>";
// Match existing ips to countries
$query = "SELECT id,remote_ip FROM $SI_tables[stats] WHERE country=''";
if ($result = mysql_query($query)) {
   while ($r = mysql_fetch_array($result)) {
      $country = SI_determineCountry($r[remote_ip]);
      $query = "UPDATE $SI_tables[stats] SET country='$country' WHERE id=$r[id]";
      mysql_query($query);
   }
}
?>
```

… para…

```php
<?php
echo "<p>Mapping existing IPs to countries.</p>";
// Match existing ips to countries
$query = "SELECT id,remote_ip FROM $SI_tables[stats] WHERE country=''";
if ($result = mysql_query($query)) {
   while ($r = mysql_fetch_array($result)) {
      $country = SI_determineCountry($r[remote_ip]);
      $cd = verCodigoPais($r[remote_ip]);
      $query = "UPDATE $SI_tables[stats] SET country='$country' AND codigopais='$cd' WHERE id=$r[id]";
      mysql_query($query);
   }
}
?>
```

Daí é só rodar o arquivo _ip-to-country.php e o ip-to-country estará funcionando junto com o shortstat com bandeira do lado do país! :)

#### Estatísticas por visitas, não por hits

Eu alterei a função **SI_getPlatforms** por:

```php
<?php
function SI_getPlatforms() {
       global $SI_tables;
       $th = SI_getUniqueHits();
       $query = "SELECT platform, COUNT(distinct(remote_ip)) AS 'total'
                       FROM $SI_tables[stats]
                       GROUP BY platform
                       ORDER BY total DESC";
       if ($result = mysql_query($query)) {
              $ul  = "<table cellpadding="0" cellspacing="0" border="0">n";
              $ul .= "t

<tr>
  <th>
    Platform
  </th>

  <th class="last">
    %
  </th>
</tr>n";
              while ($r = mysql_fetch_array($result)) {
                     $ul .= "t

<tr>
  <td>
    $r[platform]
  </td>

  <td class="last">
    ".number_format(($r[total]/$th)*100)."%
  </td>
</tr>n";
                     }
              $ul .= "</table>";
              }
       return $ul;
}
?>
```

A mudança foi o count usar distinct(remote_ip) e o $th ter o valor dos hits únicos (daí a porcentagem é contada a partir deles). A mudança na função **SI_getBrowsers** é semelhante:

```php
<?php
function SI_getBrowsers() {
       global $SI_tables;
       $th = SI_getUniqueHits();
       $query = "SELECT browser, version, COUNT(distinct(remote_ip)) AS 'total'
                       FROM $SI_tables[stats]
                       WHERE browser != 'Indeterminable'
                       GROUP BY browser, version
                       ORDER BY total DESC";
       if ($result = mysql_query($query)) {
              $ul  = "<table cellpadding="0" cellspacing="0" border="0">n";
              $ul .= "t

<tr>
  <th>
    Browser
  </th>

  <th>
    Version
  </th>

  <th class="last">
    %
  </th>
</tr>n";
              while ($r = mysql_fetch_array($result)) {
                     $p = number_format(($r[total]/$th)*100);
                     // $p = ($p==0)?"<1":$p;
                     if ($p>=1) {
                            $ul .= "t

<tr>
  <td>
    $r[browser]
  </td>

  <td>
    $r[version]
  </td>

  <td class="last">
    $p%
  </td>
</tr>n";
                            }
                     }
              $ul .= "</table>";
              }
       return $ul;
}
?>
```

#### Conclusão

Assim temos um Shortstat configurado para as minhas necessidades. Eu gosto assim, mas por ser um sistema de código bastante simples em PHP você pode configurar mais o que quiser. Eu traduzi (é só modificar as coisas no index.php) também (não tem uma grande utilidade, mas não custa…)

Espero que tenham gostado do “artigo” e qualquer dúvida ou crítica, postem um comentário ou enviem um e-mail.
