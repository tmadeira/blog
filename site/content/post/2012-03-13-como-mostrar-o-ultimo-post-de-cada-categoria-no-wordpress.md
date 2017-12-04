---
title: Como mostrar o último post de cada categoria no WordPress?
type: post
date: 2012-03-13T06:32:06+00:00
url: /2012/03/como-mostrar-o-ultimo-post-de-cada-categoria-no-wordpress/
featured_image: /wp-content/uploads/2012/01/wordpresssc1.jpg
categories:
  - Códigos aleatórios
  - WordPress
tags:
  - banco de dados
  - códigos
  - join
  - mysql
  - php
  - programação
  - scripts
  - sql
  - wordpress

---
O [WordPress][1] é um dos meus programas preferidos e um dos que mais consome as madrugadas já faz alguns anos. Escrevi inúmeros temas, alguns plugins ([um único genérico o suficiente para ser público][2]) e já modifiquei algumas partes do código (embora hoje seja raro isso ser necessário).

Acho muito simples e me divirto ao programar em PHP para a web (talvez porque eu faça isso há uns dez anos). Gosto muito da forma como o WordPress é escrito e, com efeito, seu lema é **Code is poetry** — _Código é poesia_. Sua documentação e seu código são muito didáticos e foram, assim como seus temas e as tabelas no banco de dados, evoluindo de acordo com o tempo: as atualizações sempre têm novas features e formas mais genéricas e mais elegantes de fazer as coisas.

O WordPress é um software livre usado por [mais de 15% da web][3] (um número incrível!) e tem uma comunidade que produz várias extensões (temas e plugins). Gosto tanto dele que certa vez (no final de 2007) [escrevi um plugin só para ganhar uma camiseta][4] (que é tamanho G e ainda assim uso de vez em quando).

Propaganda e blogagem a parte, me deparei com um problema interessante em um dos sites que administro com ele no último fim de semana (a gente sempre se depara com problemas interessantes no WordPress também): dado uma categoria com várias subcategorias, gostaria de mostrar um link para o último post de cada uma de suas subcategorias na página inicial.

Uma solução trivial seria fazer uma query pedindo os filhos de uma dada categoria (usando a tabela `wp_term_taxonomy`) e uma query por categoria para descobrir seu último post (usando as tabelas `wp_posts` e `wp_term_relationships`). Suponha (até o final desse post) que a categoria-mãe de todas as categorias que eu quero mostrar na página seja a de ID 33. Então, essa solução seria algo como:

```php
<?php
$query = mysql_query("SELECT term_id FROM wp_term_taxonomy
                      WHERE parent = 33 AND taxonomy = 'category'");
while (list($cid) = mysql_fetch_row($query)) {
    $posts_query = mysql_query("SELECT p.ID, p.post_name, p.post_title
                                FROM wp_posts AS p,
                                     wp_term_relationships AS r
                                WHERE p.ID = r.object_ID AND r.term_taxonomy_id = '$cid'
                                ORDER BY p.post_date DESC
                                LIMIT 1");
    if (mysql_num_rows($posts_query)) {
        list($id, $permalink, $title) = mysql_fetch_row($posts_query);
        // Faça o que quiser com o post aqui
    } else {
        echo "A categoria $cid não tem posts.\n";
    }
}
?>
```

Não deve ser difícil de entender, mas dá pra resolver de forma ainda mais simples que essa. O WordPress é fantástico e usar as funções dele próprio é bem mais simples, genérico e resolve o problema. A função [get_categories][5] aceita um monte de parâmetros, mas só precisamos do `child_of`:

```php
<?php
foreach (get_categories('child_of=33') as $cat) {
    list($post) = get_posts("numberposts=1&category={$cat->term_id}");
    // Faça o que quiser com o post aqui
}
?>
```

<small>(quem entrou no post procurando a solução pro problema pode parar por aqui se não for nerd)</small>

Porém, eu queria resolver o problema com uma única query. Achei que seria mais elegante resolver o problema todo no banco de dados sem escrever em PHP e achei que poderia ficar mais rápido. Acho que não ficou mais elegante e não faço ideia se fica mais rápido (fiquei com a impressão de que seja pior porque faço JOIN de quatro tabelas enormes), nem acho que tenha volume de dados (ainda) no site em que implementei isso pra realmente me preocupar, mas me diverti fazendo. Então segue o resultado:

```mysql
SELECT p.ID AS id,
       CASE WHEN (p.post_date > DATE_SUB(CURDATE(), INTERVAL 1 MONTH)) THEN
           p.post_title
       ELSE
           ''
       END AS title,
       GROUP_CONCAT(c.slug) AS cat
FROM wp_posts AS p
INNER JOIN
    (
        SELECT MAX(p.post_date) AS post_date, c.term_ID AS cid, COUNT(p.ID) AS count FROM
            wp_posts AS p,
            wp_term_relationships AS r,
            wp_terms AS c
        WHERE
            p.ID = r.object_ID AND
            c.term_ID = r.term_taxonomy_ID AND
            p.post_status = 'publish' AND
            p.post_type = 'post'
        GROUP BY c.term_id
    ) AS last ON p.post_date = last.post_date
INNER JOIN wp_term_relationships AS r ON p.ID = r.object_ID
INNER JOIN wp_terms AS c ON c.term_id = r.term_taxonomy_ID
INNER JOIN wp_term_taxonomy AS t ON t.term_id = r.term_taxonomy_ID
WHERE
    c.term_id = last.cid
    AND t.parent = 33
    AND t.taxonomy = 'category'
    AND p.post_status = 'publish'
    AND p.post_type = 'post'
    # AND last.count >= 3
GROUP BY p.ID ORDER BY p.post_date DESC, last.count DESC;
```

A query (que na verdade é duas) ordena o resultado por data, retorna o título vazio caso o post seja de mais de um mês atrás, junta as categorias (separando-as por vírgula) se um mesmo post for o último de mais de uma categoria e neste caso ordena as categorias por ordem decrescente de número de posts na mesma.

<small>(A parte comentada seria para caso eu só quisesse mostrar o último post de categorias com três ou mais posts.)</small>

Usei o resultado da query da seguinte forma:

```php
$q = mysql_query($query); // $query é a string com aquele SQLzão
$print_final_li = false;
$first = true;
while ($a = mysql_fetch_array($q, MYSQL_ASSOC)) {
    echo "\t\t<li>\n";
      $permalink = get_permalink($a["id"]);
      $title = $a["title"];
      if ($title == "") {
          $print_final_li = true;
          echo "Veja também: ";
      } else if ($first == true) {
          echo "<a href="$permalink" title="$title">";
          echo get_the_post_thumbnail($a["id"], "home-thumbnail",
                                      Array("title" => get_the_title()));
          echo "</a> ";
          $first = false;
      }
      $cats = explode(",", $a["cat"]);
      foreach ($cats as $low) {
          $up = strtoupper($low);
          echo "<a class="cat" href="http://$low.juntos.org.br/"
                   title="Juntos! $up">$up</a> ";
      }
      if ($print_final_li) break;
      echo "<a class="post" href="$permalink" title="$title">$title</a>";
      echo "</li>\n";
}
while ($a = mysql_fetch_array($q, MYSQL_ASSOC)) {
    $cats = explode(",", $a["cat"]);
    foreach ($cats as $low) {
        $up = strtoupper($low);
        echo "<a class="cat" href="http://$low.juntos.org.br/"
                 title="Juntos! $up">$up</a> ";
    }
}
if ($print_final_li) {
    echo "</li>\n";
}
```

<small>(e se você quiser vê-lo em prática, entre em <a href="http://juntos.org.br/">juntos.org.br</a> e procure por <em>“Juntos pelo Brasil”</em>)</small>

Não ficou bonitinho? Se por um lado gostei da solução, por outro fiquei imaginando que deva ser um SQL tremendamente ingênuo e digno da minha inexperiência com grandes bancos de dados. O que você acha? Consegue pensar numa forma mais simples, mais eficiente e mais elegante de resolver o mesmo problema? Ou ao menos sem subqueries?

Acho que as relações necessárias já ficaram explícitas na query que eu escrevi, mas segue o diagrama do banco de dados do WordPress pra quem precisar:

<a href="http://tiagomadeira.com/2012/03/como-mostrar-o-ultimo-post-de-cada-categoria-no-wordpress/wp3-0-erd-2/" rel="attachment wp-att-1227"><img src="https://i2.wp.com/tiagomadeira.com/wp-content/uploads/2012/03/WP3.0-ERD1-644x650.png?resize=604%2C610" alt="" title="WP3.0-ERD" class="aligncenter size-large wp-image-1227" srcset="https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/03/WP3.0-ERD1.png?resize=644%2C650&ssl=1 644w, https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/03/WP3.0-ERD1.png?resize=150%2C150&ssl=1 150w, https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/03/WP3.0-ERD1.png?resize=297%2C300&ssl=1 297w, https://i0.wp.com/tiagomadeira.com/wp-content/uploads/2012/03/WP3.0-ERD1.png?w=1079&ssl=1 1079w" sizes="(max-width: 604px) 100vw, 604px" data-recalc-dims="1" /></a>

 [1]: http://wordpress.org/
 [2]: http://tiagomadeira.com/2012/01/retrospective/
 [3]: http://w3techs.com/technologies/overview/content_management/all
 [4]: http://www.pblog.com.br/2007/12/03/camisas-do-wordpress-de-graca-quem-vai-querer/
 [5]: https://codex.wordpress.org/Function_Reference/get_categories

