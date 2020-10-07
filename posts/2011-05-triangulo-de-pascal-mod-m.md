---
title: Triângulo de Pascal mod m
date: 2011-05-01T17:05:09+00:00
url: /2011/05/triangulo-de-pascal-mod-m/
tags:
  - c
  - códigos
  - matemática
  - mod
  - programação
  - triângulo de pascal
---

_Este post possui intencionalmente apenas imagens e códigos._

![Uso do programa que gera triângulo de Pascal mod m](/wp-content/uploads/2011/05/screenshot.png)

![Triângulo de Pascal mod 2](/wp-content/uploads/2011/05/mod21.png)

![Triângulo de Pascal mod 3](/wp-content/uploads/2011/05/mod3.png)

![Triângulo de Pascal mod 5](/wp-content/uploads/2011/05/mod5.png)

![Triângulo de Pascal mod 7](/wp-content/uploads/2011/05/mod7.png)

![Triângulo de Pascal mod 12](/wp-content/uploads/2011/05/mod121.png)

![Triângulo de Pascal mod 23](/wp-content/uploads/2011/05/mod23.png)

### Código-fonte (com alguns bugs inofensivos — procure XXX)

```c
/* pascal -- generate colored Pascal's triangles in XPM format

   Copyright (C) 2011 Tiago Madeira <madeira@ime.usp.br>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You can read a copy of the GNU General Public License at
   http://www.gnu.org/licenses/gpl-3.0.txt */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <math.h>

#define DEFMOD 2
#define DEFSIZE 300
#define DEFPADDING 8

int mod = DEFMOD;
int size = DEFSIZE;
int padding = DEFPADDING;

char makecolors[6][4] = {
	"001", "010", "100", "110", "101", "001"
};

struct option longopts[] = {
	{"help", 0, 0, 'h'},
	{"padding", 1, 0, 'p'},
	{"size", 1, 0, 's'},
	{"mod", 1, 0, 'm'},
	{0, 0, 0, 0}
};

char *program_name;

void try_help() {
	fprintf(stderr, "Try `%s --help' for more information.\n", program_name);
}

void help() {
	printf("Usage: %s [OPTION]... [FILE]\n", program_name);
	printf("Generate colored Pascal's triangles (XPM format).\n\n");
	printf("Mandatory arguments to long options are mandatory for short options too.\n\n");
	printf("  -h, --help        print this help\n");
	printf("  -m, --mod=M       paint with different colors numbers mod M\n");
	printf("  -p, --padding=SZ  image padding (margin) in pixels\n\n");
	printf("  -s, --size=SZ     generate SZ lines of Pascal's triangle\n\n");
	printf("With no FILE, or when FILE is -, write to standard output.\n\n");
	printf("Report bugs to <madeira@ime.usp.br>.\n");
}

int baselog(int n, int base) {
	return ceil(log(n) / log(base));
}

void *xmalloc(size_t size) {
	void *x = malloc(size);
	if (x == NULL) {
		fprintf(stderr, "There is no enough memory to allocate.\n");
		exit(3);
	}
	return x;
}

int main(int argc, char **argv) {
	int optc, tofile;
	int i, j;
	int width, height, chars;
	char **color, rgb[7];
	int one, pos;
	int *pascal;
	char *line;

	program_name = argv[0];
	while ((optc = getopt_long(argc, argv, "hm:p:s:", longopts, (int *)0)) != -1) {
		switch (optc) {
		case 'h':
			help();
			return 0;
		case 'm':
			mod = atoi(optarg);
			if (mod > 48) { /* XXX */
				fprintf(stderr, "At the moment, this program supports only mod <= 48 (color generation limit).\n");
				return 4;
			}
			if (mod > 26) { /* XXX */
				fprintf(stderr, "At the moment, this program supports only mod <= 26 (bad implementation limit).\n");
				return 5;
			}
			break;
		case 'p':
			padding = atoi(optarg);
			break;
		case 's':
			size = atoi(optarg);
			break;
		default:
			try_help();
			return 1;
		}
	}
	if (optind < argc && strcmp("-", argv[optind])) {
		if (freopen(argv[optind], "w", stdout) == NULL) {
			fprintf(stderr, "Can't open `%s' for writing.\n", argv[optind]);
			return 2;
		}
		tofile = 1;
	} else {
		tofile = 0;
	}

	printf("static char *a_xpm[] = {\n");
	width = size * 2 + padding * 2;
	height = size * 2 + padding * 2;
	chars = baselog(mod, 26);
	printf(""%d %d %d %d",\n", width, height, mod + 1, chars);
	color = xmalloc(sizeof(color[0]) * (mod+1));
	rgb[6] = '�';

	printf("\"");
	color[mod] = xmalloc(sizeof(color[mod][0]) * (chars + 1));
	for (j = 0; j < chars; j++) {
		color[mod][j] = ' ';
	}
	color[mod][chars] = '�';
	printf("%s c #000000\",\n", color[mod]);

	for (i = 0; i < mod; i++) {
		color[i] = xmalloc(sizeof(color[i][0]) * (chars + 1));
		if (i == 0) {
			for (j = 0; j < chars; j++) {
				color[i][j] = 'a';
			}
			color[i][chars] = '�';
		} else {
			strcpy(color[i], color[i-1]);
			for (j = chars-1; j >= 0; j--) {
				if (color[i][j] == 'z') {
					color[i][j] = 'a';
				} else {
					color[i][j]++;
					break;
				}
			}
		}
		one = 255 / pow(2, i / 6);
		sprintf(rgb, "%02x%02x%02x", makecolors[i%6][0] == '1' ? one : 0,
				makecolors[i%6][1] == '1' ? one : 0, makecolors[i%6][2] == '1' ? one : 0);
		printf("\"%s c #%s\",\n", color[i], rgb);
	}

	line = xmalloc(sizeof(line[0]) * (width+1));
	pascal = xmalloc(sizeof(pascal[0]) * size);

	line[width] = '�';
	for (j = 0; j < width; j++) {
		line[j] = ' ';
	}
	for (i = 0; i < padding; i++) {
		printf("\"%s\",\n", line);
	}

	memset(pascal, 0, sizeof(pascal[0]) * size);
	pascal[0] = 1;

	for (i = 0; i < size; i++) {
		for (j = i; j >= 0; j--) {
			if (j != 0) {
				pascal[j] = (pascal[j-1] + pascal[j]) % mod;
			}
			pos = padding + 2*j + (size - 1 - i);
			/* XXX a implementacao de line ficou toda errada e so estou pegando
			 * o primeiro caractere de color aqui. precisa ser reescrito. */
			line[pos] = line[pos+1] = *color[pascal[j]];
		}
		printf("\"%s\",\n\"%s\"%s\n", line, line, i == size-1 && !padding ? "" : ",");
	}

	line[width] = '�';
	for (j = 0; j < width; j++) {
		line[j] = ' ';
	}
	for (i = 0; i < padding; i++) {
		printf("\"%s\"%s\n", line, i == padding-1 ? "" : ",");
	}
	printf("};\n");

	if (tofile) {
		fclose(stdout);
	}
	return 0;
}
```

<a href='/wp-content/uploads/2011/05/pascal.c' title='Program written in C for generating colored Pascal Triangles mod M'>(Download -- 5kb)</a>
