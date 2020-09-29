---
title: Mudanças no Site e Código do Blog
type: post
date: 2005-09-25T20:29:39+00:00
excerpt: Ultimamente fiz várias alterações no site. Depois de conhecer POO, refiz quase todas as páginas e deixei tudo um pouco mais leve e fácil para alterações futuras...
url: /2005/09/mudancas-no-site-e-codigo-do-blog/
categorias:
  - Metablogagem
tags:
  - códigos
  - computação
  - geshi
  - html
  - php
  - site
---

<p><strong>Atenção: os códigos desta postagem, além de inúteis, estão com muitos erros de sintaxe. Foram convertidos entre várias plataformas de blog e perderam muita coisa. Estão guardados aqui apenas para registro.</strong></p>

Ultimamente fiz várias alterações no site. Refiz quase que todas as páginas e deixei tudo um pouco mais leve e mais fácil para mudar depois. :D Depois de conhecer a POO, me viciei nela no final de semana e converti meu site inteiro para classes. E agora, que seu script tá um pouco melhor organizado, vou colocar aqui para quem quiser copiar, usar alguma idéia, saber como eu estou indo em POO, ver as besteiras que eu faço enquanto programo, etc. :lol: resolvi disponibilizar todo o código de meu blog aqui.

Já que meu blog tem alguns bugs (_known bugs_ de pouca importância, como o caso de se alguém escreve CHARESPC no meio de um comentário ele deve criar um _&;_), peço somente que ninguém destrua-o sabendo disso. Se alguém descobrir algum bug, pode me enviar um e-mail que ficarei bastante grato. :)

Já que não passei a sessão de administração para POO não vou publicá-la aqui, mas depois de resolver alguns bugzinhos pretendo disponibilizar o código completo, inclusive com um arquivo de instalação que cria as tabelas no banco de dados, para todos poderem usar um sisteminha de blog simples e prático (só que acho que vai ser algo mais voltado a programadores, porque tem vantagens como o uso do GeSHi, e desvantagens como eu publicar todos os posts escrevendo em **HTML** – isso mesmo, até os & que eu escrevo são & que são & \*e um loop infinito pela frente). Hmmm, aliás, quem quiser me ajudar a fazer parte desse projeto para tornar o meu blog um software livre, sinta-se livre para me mandar um e-mail também. :p

Então, uma última observação é que eu substituí todos os _<code_ (note a ausência do > ) por _tag code_ e todos os _</code>_ por _tag /code_, porque senão minhas expressões regulares do código dariam bug (quer saber por que? Então leia os códigos!)

#### Funções e classes _“includadas”_ em todos os arquivos {#funcoes_e_classes}

```php
<?php
session_start();

// Syntax Highlight - GeSHi
if (!class_exists(GeSHi)) {
	include("geshi.php");
}

// Objeto de conexão do MySql
class MySql {
	var $host="servidor";
	var $usuario="usuario";
	var $senha="senha";
	var $db="bancodedados";
	var $conexao;

	function conecta() {
		$this->conexao=mysql_connect($this->host, $this->usuario, $this->senha);
		mysql_select_db($this->db);
	}

	function desconecta() {
		mysql_close($this->conexao);
	}
}

// Classe com as funções de expressões regulares
class Regex {
	function Replace($o, $d, $t, $codes=0) {
		for ($i=0; $i<sizeof($o); $i++) {
			$o[$i]=str_replace('(', '(', $o[$i]);
			$o[$i]=str_replace(')', ')', $o[$i]);
			$t=eregi_replace($o[$i], $d[$i], $t);
		}
		if ($codes==1) {
			$t="tag /code".$t."tag code";
		} else if ($codes==2) {
			$t.="tag code";
		} else if ($codes==3) {
			$t="tag /code".$t;
		}
		return $t;
	}

	function Emoticons() {
		$o[0]=":)";
		$d[0]="feliz";
		$o[1]=":(";
		$d[1]="triste";
		$o[2]=":o";
		$d[2]="bocaaberta";
		$o[3]=":p";
		$d[3]="lingua";
		$o[4]=":angry:";
		$d[4]="raiva";
		$o[5]=":s";
		$d[5]="confuso";
		$o[6]=":blink:";
		$d[6]="inacreditavel";
		$o[7]=";)";
		$d[7]="piscando";
		$o[8]=":lol:";
		$d[8]="rindo";
		$o[9]=":d";
		$d[9]="sorriso";
		$o[10]=":unsure:";
		$d[10]="semgraca";

		for ($i=0; $i<sizeof($d); $i++) {
			$d[$i]="<img src="/emoticon/".$d[$i].".gif" alt="".$o[$i]."" />";
		}

		if (!ereg("tag code", $texto)) {
			$this->texto=$this->Replace($o, $d, $this->texto);
		} else {
			preg_match_all("/</code>(.+)tag code/sU", $this->texto, $mat1);
			for ($i=0; $i<sizeof($mat1[1]); $i++) {
				$this->texto=str_replace($mat1[1][$i], $this->Replace($o, $d, $mat1[1][$i]), $this->texto);
			}
			preg_match("/^(.+)tag code/sU", $this->texto, $mat2);
			$texto=str_replace($mat2[1], $this->Replace($o, $d, $mat2[1]), $this->texto);
			$rev=strrev($this->texto); //Tenho medo do PHP5.0.5
			preg_match("/^(.+)>edoc/</sU", $rev, $mat3); //Nossa, que código louco!
			$rev=strrev($mat3[1]); //Repito... Tenho medo do PHP5.0.5
			$this->texto=str_replace($rev, $this->Replace($o, $d, $rev), $this->texto); //Agora fuck PHP5.0.5!
		}
	}

	function GeshiHighlight($codigo, $linguagem) {
		$geshi=new GeSHi($codigo, $linguagem, "./geshi/");
		return $geshi->parse_code();
	}

	function Codigos() {
		preg_match_all("/tag code class=\"(.*)\">(.*)</code>/sU",
			$this->texto,
			$matches);
		for ($i=0; $i<sizeof($matches[1]); $i++) {
			$g=$this->GeshiHighlight($matches[2][$i], $matches[1][$i]);
			if (eregi("MSIE", $_SERVER["HTTP_USER_AGENT"])) {
				$g=ereg_replace("<pre>", "<pre class="alturamaxima">", $g);
			}
			$this->texto=str_replace($matches[0][$i],
				$g,
				$this->texto);
		}
	}

	function QuebraLinha() {
		$this->texto=nl2br($this->texto);
	}
}

// Objeto "Artigo"
class Artigo extends Regex {
	var $id;
	var $data;
	var $permalink;
	var $titulo;
	var $texto;
	var $comentarios;

	function Artigo($identificacao) {
		$this->id=$identificacao;

		$mysql=new MySql();
		$mysql->conecta();

		$query_post=mysql_query("SELECT data, permalink, titulo, texto FROM artigos WHERE id='{$this->id}'");
		$post=mysql_fetch_row($query_post);
		$this->data=date("d/m/Y", $post[0]);
		$this->permalink=$post[1];
		$this->titulo=$post[2];
		$this->texto=$post[3];

		$query_comentarios=mysql_query("SELECT count(id) FROM comentario WHERE idpost='{$this->id}'");
		$comentarios=mysql_fetch_row($query_comentarios);
		$this->comentarios=$comentarios[0];

		$mysql->desconecta();
	}

	function AppendGoogleAds($ads) {
		$this->texto.="nn".$ads;
	}

	function Mostra() {
		echo "<h2><a href=\"/post/{$this-?PHPSESSID=9ec34c96b02b3755051aa682d1e02001>permalink}\">{$this->titulo}</a></h2>\n";
		echo $this->texto."\n";
		echo "<h5>{$this->data} ";
    echo "<a href=\"/post/{$this-?PHPSESSID=9ec34c96b02b3755051aa682d1e02001>permalink}\" class=\"permalink\">permalink</a> ";
    echo "<a href=\"/post/{$this-?PHPSESSID=9ec34c96b02b3755051aa682d1e02001>permalink}#comentarios\" class=\"comentarios\">";
    echo "{$this->comentarios} comentário(s)</a></h5>\n";
	}

	function MostraComentarios() {
		if ($_POST["comenta"]&&(!$_SESSION["comentario"]||time()-30>$_SESSION["comentario"])) {
			$_SESSION["comentario"]=time();
			EscreveComentario($_POST["nome"], $_POST["email"], $_POST["texto"], $this->id);
		}
		$comentarios=new Comentarios($this->id);
		$comentarios->Mostra();
	}
}

// Objeto Artigos (serve para pegar vários artigos sem eu precisar fazer nada nas outras páginas)
class Artigos {
	var $id;
	var $titulo;
	var $texto;
	var $permalink;
	var $data;
	var $comentarios;

	function Artigos($n=20, $start=0, $emoticons=0, $codigos=0, $mostrar=0, $comentarios=0) {
		$mysql=new MySql();
		$mysql->conecta();
		$query=mysql_query("SELECT id FROM artigos ORDER BY data DESC, id DESC LIMIT $start,$n");
		$mysql->desconecta();
		for ($i=0; $array=mysql_fetch_array($query); $i++) {
			$artigo=new Artigo($array["id"]);
			if ($emoticons) {
				$artigo->Emoticons();
			}
			if ($codigos) {
				$artigo->Codigos();
			}
			if ($mostrar) {
				$artigo->Mostra();
			}
			if ($comentarios) {
				$artigo->MostraComentarios();
			}
			$this->id[$i]=$array["id"];
			$this->titulo[$i]=$artigo->titulo;
			$this->texto[$i]=$artigo->texto;
			$this->permalink[$i]=$artigo->permalink;
			$this->comentarios[$i]=$artigo->comentarios;
			$this->data[$i]=$artigo->data;
		}
	}
}

// Objeto Comentário
class Comentario extends Regex {
	var $id;
	var $data;
	var $nome;
	var $email;
	var $ip;
	var $useragent;
	var $texto;
	var $numero;

	function Comentario($identificacao, $numero) {
		$this->id=$identificacao;
		$this->numero=$numero;

		$mysql=new MySql();
		$mysql->conecta();

		$query=mysql_query("SELECT data, nome, email, ip, useragent, texto FROM comentario WHERE id='{$this->id}'");
		$comentario=mysql_fetch_row($query);

		$this->data=date("d/m/Y", $comentario[0]);
		$this->nome=$comentario[1];
		if ($_SESSION["tiagomadeira"]) {
			$this->email="</small> <span style=\"font-size:10px;\"><br />";
			if ($comentario[2]) $this->email.="<strong>E-mail:</strong> ".$comentario[2]."<br />n";
			if ($comentario[3]) $this->ip="<strong>IP:</strong> ".$comentario[3]."<br />n";
			if ($comentario[4]) $this->useragent="<strong>User Agent:</strong> ".$comentario[4];
			$this->useragent.="</span>";
		} else {
			$this->email="</small>";
		}
		$this->texto=$comentario[5];

		$mysql->desconecta();
	}

	function CharEspc($pos) {
		if ($pos==1) {
			$this->texto=preg_replace("/&([^;]+);/sU", "CHARESPC\1/CHARESPC", $this->texto);
		} else if ($pos==2) {
			$this->texto=preg_replace("/CHARESPC(.+)/CHARESPC/sU", "&\1;", $this->texto);
		}
	}

	function Mostra() {
		echo "<div class=\"comentario\" id=\"com{$this->id}\">\n";
    echo "\t <h4><a href=\"?PHPSESSID=9ec34c96b02b3755051aa682d1e02001#com{$this->id}\">#{$this->numero}</a> | ";
    echo "{$this->nome} ";
    echo "<small>{$this->data}{$this->email}{$this->ip}{$this->useragent}</h4>\n";
    echo "<p>{$this->texto}</p>";
    echo "</div>\n";
  }
}

// Objeto Comentários
class Comentarios {
  var $idpost;
  var $ids;
  var $tamanho;

  function Comentarios($idpost) {
    $this->idpost=$idpost;

    $mysql=new MySql();
    $mysql->conecta();

    $query=mysql_query("SELECT id FROM comentario WHERE idpost='{$this->idpost}' ORDER BY data ASC, id ASC");
    for ($i=1; $array=mysql_fetch_array($query); $i++) {
      $this->ids[$i]=$array["id"];
    }

    $this->tamanho=$i;
    $mysql->desconecta();
  }

  function Mostra() {
    echo "<h3 id="comentarios">Comentários</h3>\n";
    for ($i=1; $i<$this->tamanho; $i++) {
      $comentario=new Comentario($this->ids[$i], $i);
      $comentario->CharEspc(1);
      $comentario->Emoticons();
      $comentario->CharEspc(2);
      $comentario->QuebraLinha();
      $comentario->Mostra();
    }

    if ($this->tamanho <= 1) {
      echo "<p>Nenhum comentário cadastrado.</p>\n";
    }

    FormularioComentario($this->idpost);
  }
}

// Função para descobrir IP do visitante
function PegaIP() {
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

  return($ip);
}

// Função que escreve o formulário para envio de comentário
function FormularioComentario($idpost) {
  $mysql=new MySql();
  $mysql->conecta();
  $query=mysql_query("SELECT permalink FROM artigos WHERE id='$idpost'");
  $row=mysql_fetch_row($query);
  $permalink=$row[0];
  $mysql->desconecta();
?>

<h3>
  Escreva um comentário
</h3>

<?php
}

// Função que cadastra um comentário
function EscreveComentario($nome, $email, $texto, $idpost) {
$ip=PegaIP();
$useragent=$_SERVER["HTTP_USER_AGENT"];
$nome=purifica($nome);
$email=purifica($email);
$texto=purifica($texto);
$data=time();
$mysql=new MySql();
$mysql->conecta();
  mysql_query("INSERT INTO comentario (id, idpost, nome, email, texto, data, ip, useragent) VALUES
    ('', '$idpost', '$nome', '$email', '$texto', '$data', '$ip', '$useragent')") or die(mysql_error());
  $mysql->desconecta();
  $email=($email)?$email:"contato@tiagomadeira.net";
  $mensagem="No post de id $idpost, o $nome ($email) comentou em ".date("d/m/Y", $time)." dizendo:";
  $mensagem.="nn";
  $mensagem.="$texto";
  mail("contato@tiagomadeira.net", "[tiagomadeira.net] Novo Comentário!", "$mensagem", "From: $nome <$email>");
}

// Função que cria escreve o título das seções
function titulo($titulo) {
  $tit="$titulo [tiagomadeira.net]";
  echo "n";
}

// Função para purificar os comentários depois do envio
function purifica($texto) {
  $t=ereg_replace("&", "&", $texto);
  $t=ereg_replace("%", "%", $t);
  $t=ereg_replace("<", "<", $t);
  $t=ereg_replace(">", ">", $t);
  $t=ereg_replace("[", "[", $t);
  $t=ereg_replace("]", "]", $t);
  $t=ereg_replace(""", """, $t);
  return $t;
}

// Função para editar artigos
function pra_textarea($texto) {
  $texto=ereg_replace("&", "&", $texto);
  $texto=ereg_replace("<", "<", $texto);
  $texto=ereg_replace(">", ">", $texto);
  $texto=ereg_replace(""", """, $texto);
  return $texto;
}
?>
```

E os arquivos que usam essas funções e classes...

#### /artigos (ou /blog)

```php
<?php
  $artigosporpagina=10; //Artigos Por Página
  $p=($_GET["pg"])?$_GET["pg"]:1; //Página Atual

  $mysql=new MySql();
  $mysql->conecta();
  $query=mysql_query("SELECT count(id) FROM artigos");
  $row=mysql_fetch_row($query);
  $np=ceil($row[0]/$artigosporpagina);
  $mysql->desconecta();

  $paginacao="";
  for ($i=1; $i<=$np; $i++) {
    $paginacao.="<a href="/artigos/$i"";
    if ($i==$p) $paginacao.=" style="font-weight:bold; color:#c00;"";
    $paginacao.=">$i</a> ";
  }
  $paginacao="\n\n<p style=\"text-align:center;\"><span style=\"color:#aaa; font-size:11px;\">";
  $paginacao.="Ir para página:</span> $paginacao</p>\n\n";

  echo $paginacao;

  $artigos=new Artigos($artigosporpagina, ($p-1)*$artigosporpagina);
  echo " <ul>\n";
  for ($i=0; $i<count($artigos->id); $i++) {
      echo "<li><a href=\"{$artigos->permalink[$i]}\">{$artigos->titulo[$i]}</a><br />";
      echo "<small>{$artigos->data[$i]} ";
      echo "<a class=\"comentarios\" href=\"/post/{$artigos->permalink[$i]}#comentarios\">{$artigos->comentarios[$i]} comentário(s)</a>";
      if ($_SESSION["tiagomadeira"]) {
        echo " <a href="/admin-edita&id={$artigos->id[$i]}">[editar]</a>";
        echo " <a href="/admin-exclui&id={$artigos->id[$i]}">[excluir]</a>";
      }
      echo "</small></li>\n";
  }
  echo "</ul>n";
  echo $paginacao;
?>
```

#### / (ou /ultimos)

```php
<?php
	$artigos=new Artigos(5, 0, 1, 1, 1);
?>
```

#### Para finalizar... .htaccess

```apache
RewriteEngine On

#Diretórios
RewriteRule ^link/?$ http://tableless.tiagomadeira.net
RewriteRule ^post/?$ http://tableless.tiagomadeira.net/blog
RewriteRule ^script/?$ http://tableless.tiagomadeira.net/scripts
RewriteRule ^downloadscript/?$ http://tableless.tiagomadeira.net/scripts

#Blog: A grande excessão
RewriteRule ^blog/([0-9]+)$ http://tableless.tiagomadeira.net/index.php?l=blog&pg=$1
RewriteRule ^/link/blog/([0-9]+)$ http://tableless.tiagomadeira.net/index.php?l=blog&pg=$1
RewriteRule ^artigos/([0-9]+)$ http://tableless.tiagomadeira.net/index.php?l=blog&pg=$1
RewriteRule ^/link/artigos/([0-9]+)$ http://tableless.tiagomadeira.net/index.php?l=blog&pg=$1

#Links
RewriteRule ^link/(.+)$ http://tableless.tiagomadeira.net/index.php?l=$1
RewriteRule ^([^/.]+)$ http://tableless.tiagomadeira.net/index.php?l=$1

#Posts
RewriteRule ^post/([0-9]+)$ http://tableless.tiagomadeira.net/index.php?l=artigo&id=$1
RewriteRule ^post/(.+)$ http://tableless.tiagomadeira.net/index.php?l=artigo&permalink=$1

#Scripts
RewriteRule ^script/(.+)$ http://tableless.tiagomadeira.net/index.php?l=script&script=$1
RewriteRule ^downloadscript/(.+)$ http://tableless.tiagomadeira.net/downloadscript.php?script=$1

#Feeds
RewriteRule ^feed.rss$ http://tableless.tiagomadeira.net/rss.php
RewriteRule ^rss.xml$ http://tableless.tiagomadeira.net/rss.php
RewriteRule ^index.rss$ http://tableless.tiagomadeira.net/rss.php
RewriteRule ^sitemap.xml$ http://tableless.tiagomadeira.net/sitemap.php
```
