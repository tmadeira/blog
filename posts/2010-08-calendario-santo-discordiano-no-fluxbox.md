---
title: Calendário santo-discordiano no Fluxbox
type: post
date: 2010-08-29T03:00:55+00:00
url: /2010/08/calendario-santo-discordiano-no-fluxbox/
featured_image: /wp-content/uploads/2010/08/eris.jpg
categorias:
  - Códigos aleatórios
  - Software Livre
tags:
  - ddate
  - discordianismo
  - fluxbox
  - fnord
  - linux
  - x
---

Acabei de implementar o [calendário santo-discordiano][1] no Fluxbox 1.1.1 (última versão).

**Link para download do código:** [fluxbox-ddate-1.1.1-0.tar.bz2][2]

Se você usa **Arch Linux**, não precisa baixar e compilar manualmente. Basta usar o pkgbuild que o [Rev. Beraldo][3] fez para o AUR: [aur.archlinux.org/packages.php?ID=40364][4].

Se você usa **Gentoo**, não precisa baixar e compilar manualmente. Basta colocar o ebuild que eu fiz num overlay: [fluxbox-ddate no Gentoo][5].

<small>Versões compiladas .deb, .rpm, .tgz etc. e <del>ebuilds</del>, <del>pkgbuilds</del> etc. são bem vindos! Me passem que eu coloco um link aqui!</small>

### Como baixar e descompactar

Como você faria com qualquer outro pacote .tar.bz2…

```bash
$ wget https://tiagomadeira.com/wp-content/uploads/2010/08/fluxbox-ddate-1.1.1-0.tar.bz2
$ tar xjvf fluxbox-ddate-1.1.1-0.tar.bz2
$ cd fluxbox-ddate-1.1.1-0
```

### Como compilar

Versão simples:

```bash
$ ./configure
$ make
$ make install
```

Versão complicada:

```bash
$ export CFLAGS=-O2 -march=native -msse4.1
$ export CXXFLAGS=$CFLAGS
$ ./configure --prefix=/usr --build=x86_64-pc-linux-gnu --host=x86_64-pc-linux-gnu \
  --enable-nls --disable-xinerama --enable-xft --disable-gnome --enable-imlib2 \
  --enable-slit --enable-toolbar --sysconfdir=/etc/X11/fluxbox
$ make -j3
$ make install
```

Encontre seu meio termo (ou use a simples) e divirta-se!

### Como iniciar um Fluxbox

Inicie o X e peça pra ele abrir a versão que você compilou do Fluxbox da seguinte maneira:

```bash
$ startx /usr/local/bin/fluxbox -- :1
```

(Lembre-se de mudar /usr/local para o `--prefix` que usou no ./configure)

Esta linha funciona dentro de uma sessão do X (abre outra), por causa do `-- :1`.

### Como usar a data discordiana

Clique com a tecla direita no relógio do seu Fluxbox e **Edit clock format**. Se você usar um formato de data convencional, do falso calendário (como deve estar usando no momento), nada de especial acontecerá. O segredo está no **|fnord|**.

Quando você coloca um **|fnord|** no formato, o Fluxbox interpretará tudo que veio antes como formato de data discordiano.

<small>(Para escolher o formato de data ideal, você pode digitar <strong>man ddate</strong> num terminal.)</small>

_Exemplos de uso:_

- Formato: **%c** → Saída: **Sat 28 Aug 2010 11:50:26 PM BRT**
- Formato: **%e of %B of %Y|fnord|** → Saída: **21st of Bureaucracy of 3176**
- Formato: **%d %b %Y|fnord|, %H:%M:%S** → Saída: **21 Bcy 3176, 23:50:26**
- Formato: **%.|fnord|** → Saída: **All Hail Discordia!**

### Dúvidas, sugestões?

Contate a glândula pineal.

### Como funciona o código?

O Fluxbox usa a função `strftime` para formatar a data do relógio. Isso acontece na linha 274 do arquivo src/ClockTool.cc. Modifiquei este trecho do código adicionando cerca de 23 linhas que separam a string do formato de data no **|fnord|** e passam o que vem antes dele como parâmetro para uma chamada de sistema pro `ddate` (sim, de fato pra próxima versão é melhor copiar o código do ddate ou reimplementar pra não ter este overhead) e o que vem depois continua indo pro `strftime`.

Ficou assim:

```cpp
char s[255], u[255];
strcpy(s, m_timeformat->c_str());
char *t = strstr(s, "|fnord|");
time_string_len = 0;
if (t != NULL) {
	*t = '�';
	sprintf(u, "ddate +'%s'", s);
	FILE *ddate = popen(u, "r");
	if (fgets(time_string, 255, ddate)) {
		time_string_len = strlen(time_string);
		time_string[--time_string_len] = '�';
		fclose(ddate);
	}
	t+= 7;
} else {
	t = s;
}
time_string_len+= strftime(&time_string[time_string_len], 255 - time_string_len, t, time_type);
```

### Known bugs

1. Colocar ‘ (aspas simples) no lado esquerdo do |fnord| faz com que a data discordiana não apareça.
2. Requer [util-linux-ng][6] e faz uma chamada de sistema ao _ddate_ uma vez por segundo.
3. Não trabalha ainda com [horas métricas][7].
4. _… me informe se achar mais algum!_

### Screenshots

![Screenshot 1](/wp-content/uploads/2010/08/a1.png)

![Screenshot 2](/wp-content/uploads/2010/08/b.png)

![Screenshot 3](/wp-content/uploads/2010/08/c.png)

[1]: http://www.cabaladada.org/discordiapedia/Calend%C3%A1rio_Santo-Discordiano
[2]: /wp-content/uploads/2010/08/fluxbox-ddate-1.1.1-0.tar.bz2
[3]: http://www.cabaladada.org/
[4]: http://aur.archlinux.org/packages.php?ID=40364
[5]: /2010/08/fluxbox-ddate-no-gentoo/
[6]: http://www.kernel.org/pub/linux/utils/util-linux-ng/
[7]: http://www.cabaladada.org/discordiapedia/Horas_M%C3%A9tricas
