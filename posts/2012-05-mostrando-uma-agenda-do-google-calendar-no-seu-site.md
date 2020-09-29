---
title: Mostrando uma agenda do Google Calendar no seu site
type: post
date: 2012-05-06T06:14:07+00:00
url: /2012/05/mostrando-uma-agenda-do-google-calendar-no-seu-site/
featured_image: /wp-content/uploads/2012/05/cal.jpg
categorias:
  - Códigos aleatórios
  - Dicas
tags:
  - agenda
  - códigos
  - dicas
  - feed
  - google
  - google agenda
  - google calendar
  - howto
  - php
  - rss
  - scripts
  - wordpress
  - xml
---

Escrito em PHP. Pode ser usado no tema do seu WordPress. Requer CURL. Faz cache do calendário para não ter que baixá-lo sempre que alguém entra no seu site. Desenvolvido para um site que vai sair nos próximos dias. Use, modifique e distribua como quiser. (Não me responsabilizo por qualquer problema. Fiz pra um caso específico. A checagem de erros é meio porca.)

```php
<?php
date_default_timezone_set('America/Sao_Paulo');
$events = Array();
$dom = new DOMDocument();

$file = "cached_calendar.xml";

$last = -1;
if (file_exists($file)) {
    $last = filemtime($file);
}
// Mude 3600 para o tempo (em segundos) que você quiser que o cache expire
if (time() - $last > 3600) {
    $fp = fopen($file, "w+");
    if (!$fp) {
        die();
    }
    // Substitua o e-mail do calendário do Google CodeJam pelo e-mail do seu calendário (público)
    $ch = curl_init("https://www.google.com/calendar/feeds/" .
      "google.com_jqv7qt9iifsaj94cuknckrabd8%40group.calendar.google.com/public/full");
    curl_setopt($ch, CURLOPT_TIMEOUT, 50);
    curl_setopt($ch, CURLOPT_FILE, $fp);
    curl_exec($ch);
    curl_close($ch);
    fclose($fp);
}

$dom->load($file);
$feed = $dom->getElementsByTagName("feed");
$entries = $feed->item(0)->getElementsByTagName("entry");
foreach ($entries as $entry) {
    $children = $entry->getElementsByTagName("*");
    $day = "";
    $start = "";
    $end = "";
    foreach ($children as $child) {
        switch ($child->tagName) {
        case "title":
            $title = $child->nodeValue;
            break;
        case "gd:when":
            if ($child->hasAttribute("startTime")) {
                $st = strtotime($child->getAttribute("startTime"));
                $time_to_sort = $st;
                $day = date_i18n("l, d/M", $st);
                $start = date("H:i", $st);
            }
            if ($child->hasAttribute("endTime")) {
                $et = strtotime($child->getAttribute("endTime"));
                $end = date("H:i", $et);
            }
            break;
        }
    }
    if ($title != "" && $day != "") {
        $events[] = Array(
            "time_to_sort" => $time_to_sort,
            "day" => $day,
            "start" => $start,
            "end" => $end,
            "title" => $title
        );
    }
}
function cmp($a, $b) {
    $a = $a["time_to_sort"];
    $b = $b["time_to_sort"];
    if ($a == $b) {
        return strcmp($a["title"], $b["title"]);
    }
    return ($a < $b) ? -1 : 1;
}
usort($events, "cmp");

$n = count($events);
if ($n > 0) {
    $lastDay = "";
    for ($i = 0; $i < $n; $i++) {
        $day = $events[$i]['day'];
        $title = $events[$i]['title'];
        $start = $events[$i]['start'];
        $end = $events[$i]['end'];
        if ($lastDay != $day) {
            if ($i != 0) {
                echo "</ul>\n\n";
            }
            echo "<h3 class="day"><span>$day</span></h3>\n";
            echo "<ul>\n";
          }
          echo "\t<li>\n";
            if ($start != "") {
                // Você pode modificar aqui para mostrar o horário de término ($end).
                echo "tt<span class="time">{$start}</span>\n";
            }
            echo "\t\t<strong>{$title}</strong>\n";
            echo "\t</li>\n";
          $lastDay = $day;
      }
      echo "</ul>\n";
} else {
    echo "<p>Nenhum evento cadastrado.</p>\n";
}
?>
```
