---
title: De volta à resolução de problemas
type: post
date: 2005-09-16T19:33:06+00:00
excerpt: 'Depois de umas férias de uns dois meses, hoje resolvi um problema lógico do USACO Training Gateway: Superprime Rib.'
url: /2005/09/de-volta-a-resolucao-de-problemas/
categorias:
  - Cotidiano
tags:
  - c
  - códigos
  - freelances
  - linux
  - meetweb
  - mysql
  - php
  - primos
  - slackware
  - superprime rib
  - usaco
  - xdirectfb

---

![Resultado do Superprime Rib](https://farm1.staticflickr.com/26/44020730_e9246b13ef_o.png)

Hoje, depois de umas férias de dois meses, resolvi um problema lógico do **USACO Training Gateway**: o **Superprime Rib** é um problema bem simples em que precisa-se determinar os primos de N dígitos (com N máximo = 8 ) que, tirando o último dígito, continuam sendo primos. A solução é trivial, uma função recursiva bastante simples que se auto-explica no meu código:

```c
//Superprime Rib - USACO Training Gateway - 2005

/*
ID: contato1
PROG: sprime
LANG: C
*/

#include <stdio.h>
#define NMAX 9
#define INFINITO 100000

int primos[NMAX][INFINITO], cont[NMAX];

int eh_primo(long int num) {
	int i;

	if (num==1||(!(num%2)&&num!=2)) {
		return 0;
	}

	for (i=3; i*i<=num; i+=2) {
		if (!(num%i)) {
			return 0;
		}
	}

	return 1;
}

void funcao(int n) {
	int i, j, num;

	cont[n]=0;

	if (n>1) {
		funcao(n-1);

		for (i=0; i<cont[n-1]; i++) {
			for (j=1; j<=9; j+=2) {
				num=primos[n-1][i]*10+j;
				if (eh_primo(num)) {
					primos[n][cont[n]++]=num;
				}
			}
		}
	} else {
		primos[1][0]=2;
		primos[1][1]=3;
		primos[1][2]=5;
		primos[1][3]=7;
		cont[1]=4;
	}
}

int main() {
	int n, i;

	FILE *in=fopen("sprime.in", "r");
	FILE *out=fopen("sprime.out", "w");
	fscanf(in, "%d", &n);
	fclose(in);

	funcao(n);

	for (i=0; i<cont[n]; i++) {
		fprintf(out, "%d\n", primos[n][i]);
	}
	fclose(out);

	return 0;
}
```

O problema passou de segunda porque na primeira, por falta de hábito, eu tinha colocado **scanf** e **printf** ao invés de usar o sistema da USACO onde deve-se usar arquivos de entrada e saída.

Agora para eu ir para a seção 2 do _USACO Training Gateway_ falta só o programa **Checker Challenge**, que parece ser complicado.

Instalei os pacotes do Slackware 10.2, que saiu essa semana, no laptop. Não tem nenhuma grande mudança, mas é sempre bom estar com os programas atualizados...

O Paulo Matias (Thotypous) me convidou para fazer parte da equipe de desenvolvimento da distro **Guaranix**, consertando alguns bugs do XDirectFB ([que eu citei aqui][2]). Acho que irei pegar um trabalho com a Meetweb também (o Hugo Dias, para quem eu fiz o serviço da **Coalizão Antituberculose** me convidou) e estou acabando o site do Colégio Salesiano, que é totalmente administrável em PHP e usa um banco de dados MySql. Ele deve sair semana que vem...

Dia 24 é a segunda fase da **Olimpíada Regional de Matemática**. Essa semana fiz a folhinha de treinamento e dos seis problemas, consegui fazer cinco (na verdade, alguns problemas - ou todos - eram repetidos do ano anterior e por isso fica mais fácil, porque eu já lembrava o caminho).

 [1]: http://www.flickr.com/photos/tiago/44020730/ "Resultado do Problema"
 [2]: /2005/08/linux-xdirectfb-e-wine/

