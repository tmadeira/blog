---
title: Novos problemas lógicos da OBI99 resolvidos!
type: post
date: 2005-02-08T23:49:43+00:00
excerpt: Peguei a prova da OBI 99 com apenas seis problemas, porque já resolvi 2 há algum tempo sem perceber, com o objetivo de treinar um pouco para a OBI desse ano.
url: /2005/02/novos-problemas-logicos-da-obi99-resolvidos/
categorias:
  - Cotidiano
tags:
  - algoritmos
  - c
  - códigos
  - obi
  - olimpíadas
  - problemas
  - programação

---
Baixei a prova da OBI99. Ao invés de ficar demorando nos difíceis, resolvi procurar os mais fáceis mas tentar fazer mais para não ter que pensar muito pois estava meio cansado. A prova de 1999 é muito boa. Os códigos que é preciso fazer pra maioria dos problemas são bastante simples, mas exigem bastante lógica. Precisa parar pra pensar mesmo…

Bom… Resolvi os três que achei mais fácil lendo o enunciado (depois farei o resto):

### Trem ou Caminhão?

```c
//Trem ou Caminhão? - OBI1999
#include <stdio.h>

int main() {
	int peso, teste=1;
	float caminhao[2], trem[2];

	while (scanf("%d", &peso)&&peso) {
		printf("Teste %d\n", teste++);
		scanf("%f %f %f %f", &caminhao[0], &caminhao[1], &trem[0], &trem[1]);
		if (caminhao[0]+caminhao[1]*peso<trem[0]+trem[1]*peso-1) {
			printf("envie por caminhao");
		} else {
			printf("envie por trem");
		}
		printf("\n\n");
	}
}
```

### Restaurante

```c
//Restaurante - OBI1999

#include <stdio.h>
#define NMAX 5001

int main() {
	int e[NMAX], s[NMAX], n, i, teste=1, pessoas;

	while (scanf("%d", &n)&&n) {
		for (i=0; i<n; i++) {
			scanf("%d", &s[i]);
		}
		for (i=0; i<n; i++) {
			scanf("%d", &e[i]);
		}
		pessoas=0;
		for (i=0; i<n; i++) {
			if (e[i]>s[n-i-1]&&(n-i)>pessoas) {
				pessoas=n-i;
			}
		}

		printf("Teste %d\npessoas: %d\n\n", teste++, pessoas);
	}
}
```

### Sequências

```c
//Sequências - OBI1999

#include <stdio.h>

int main() {
	char car, inutil;
	int v[3], teste=1;

	v[0]=0;
	v[1]=0;
	v[2]=0;
	while (scanf("%c", &car)) {
		if (car!='#') {
			if (v[2]==2) {
				v[2]=0;
			}
			//printf("%d%d%d\n", v[0], v[1], v[2]);
			v[0]=v[1];
			v[1]=v[2];
			if (car=='0') {
				v[2]=0;
			} else if (car=='1') {
				v[2]=1;
			} else {
				v[2]=2;
			}
		} else {
			if (v[2]==2) {
				break;
			} else {
				printf("Teste %d\n", teste++);
				if (!v[2]&&!v[1]) {
					printf("sim");
				} else {
					printf("nao");
				}
				printf("\n\n");
				v[0]=0;
				v[1]=0;
				v[2]=0;
			}
		}
	}
}
```

Não usei a entrada e a saída em arquivos como foi usado naquele ano, pois é uma coisa que não vale a pena perder tempo fazendo (não que seja complexo, mas só é ruim e mais demorado ficar escrevendo fscanf ao invés de scanf). Já coloquei a solução dos três na área de scripts e depois colocarei os outros três.

Já fiz a prova das OBIs de 2000 a 2004, e acho que não teve antes de 1999, então essa seria a última prova. Acho que ela tá bem difícil em relação as novas (o que é estranho, pois a partir de 2002 o nível foi aumentando).

O problema Palavras Cruzadas é muito interessante. Eu cheguei a começar a fazer mas ficou um código muito complicado e desisti (depois eu faço).

Fiquei com saudade da simplicidade do meu Slackware e formatei novamente minha partição Linux! Tirei o Debian e já estou configurando o Slackware. Dessa vez não vou compilar o Kernel 2.6 nem atualizar algumas coisas como KDE, Gnome, etc. pois da outra vez meu sistema acabou ficando "instável". O Slackware 10.1 saiu e já estou pegando download (via bittorrent) para depois instalar. Parece estar bem bom... Várias coisas atualizadas! Só espero que seja estável...

Minhas aulas começam segunda-feira e minha banda (Zibian) vai fazer um show no meio da aula. Hoje ensaiamos e tá ficando legal (embora ainda não esteja bom pra tocar segunda). Já fiz um layout básico no TeX para meus cadernos, configurei Vim, Bash, Firefox, aMSN, etc. no Slack além de trocar splash do KDE, wallpaper, screensaver, configurar o X, LiLo, etc. Já tô ficando acostumado em configurar Linux de forma rápida por causa de tanta formatação... :lol:

_OBS.: Acabei de constatar que meu site é o segundo resultado no Google quando se procura por "tableless" em português. :) Está atrás apenas de www.tableless.com.br._

