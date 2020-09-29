---
title: Palavras Cruzadas (OBI99)
type: post
date: 2005-02-18T12:25:51+00:00
excerpt: Acabei de resolver o problema Palavras Cruzadas, até agora o mais difícil da OBI de 1999.
url: /2005/02/palavras-cruzadas-obi99/
categorias:
  - Cotidiano
tags:
  - c
  - códigos
  - obi
  - olimpíadas
  - palavras cruzadas
  - problemas
  - programação
---

Acabei de resolver o problema **Palavras Cruzadas**; até agora foi o mais difícil da OBI 1999 (ainda que fácil se comparado a problemas de outras OBIs mais recentes, como Rede Ótica e Orkut):

<div>
  <h4>
    Palavras Cruzadas
  </h4>

  <p>
    O conhecido passatempo de palavras cruzadas é composto por uma grade retangular de quadrados branos e pretos e duas listas de definições. Uma das listas de definições é para palavras escritas da esquerda para a direita nos quadrados brancos (nas linhas) e a outra lista é para palavras que devem ser escritas de cima para baixo nos quadrados brancos (nas colunas). Uma palavra é uma sequência de dois ou mais caracteres do alfabeto. para resolver um jogo de palavras cruzadas, as palavras correspondentes às definições devem ser escritas nos quadrados brancos da grade.
  </p>

  <p>
    […]
  </p>

  <h4>
    Tarefa
  </h4>

  <p>
    Sua tarefa é escrever um programa que recebe como entrada vários jogos de palavras cruzadas resolvidas e produz as listas de palavras verticais e horizontais que constituem as soluções.
  </p>
</div>

Na outra vez que eu tinha tentado fazer foi difícil, mas dessa vez foi tranquilo. Bom… O algoritmo tá bem simples e já coloquei na seção de scripts. Gostei do programa, a saída é bem bonita. :lol:

```c
//Palavras Cruzadas - OBI1999

#include <stdio.h>
#define NMAX 102

int nu[NMAX][NMAX], proximonumero;
char mt[NMAX][NMAX];

int numera(i, j) {
	if (!nu[i][j]) {
		nu[i][j]=proximonumero++;
		//printf("É numerada a coordenada %d %d com %d.\n", i, j, nu[i][j]);
	}
}

int main() {
	int n, m, i, j, k, teste=1, vertical, horizontal;
	char enter;

	while (scanf("%d %d", &n, &m)&&n) {
		//imprime o número do teste
		printf("Teste %d\n", teste++);
		//zera as matrizes
		for (i=0; i<=n+1; i++) {
			for (j=0; j<=m+1; j++) {
				mt[i][j]='*';
				nu[i][j]=0;
			}
		}
		//pega o enter
		scanf("%c", &enter);
		//pega os chars e coloca na matriz
		for (i=1; i<=n; i++) {
			for (j=1; j<=m; j++) {
				scanf("%c", &mt[i][j]);
			}
			scanf("%c", &enter);
		}
		//define o proximo numero pra 1
		proximonumero=1;
		vertical=0;
		horizontal=0;
		//numera a matriz
		for (i=1; i<=n; i++) {
			for (j=1; j<=m; j++) {
				if (mt[i][j]!='*') {
					if (mt[i][j-1]=='*'&&mt[i][j+1]!='*') {
						numera(i, j);
						horizontal=1;
					}
					if (mt[i-1][j]=='*'&&mt[i+1][j]!='*') {
						numera(i, j);
						vertical=1;
					}
				}
			}
		}
		//imprime palavras horizontais
		if (horizontal) {
			printf("Horizontais:\n");
			for (i=1; i<=n; i++) {
				for (j=1; j<=m; j++) {
					if (mt[i][j]!='*'&&mt[i][j-1]=='*'&&mt[i][j+1]!='*') {
						printf("  %d. ", nu[i][j]);
						for (k=j; mt[i][k]!='*'; k++) {
						       printf("%c", mt[i][k]);
						}
				 		printf("\n");
					}
				}
			}
		}

		//imprime palavras verticais
		if (vertical) {
			printf("Verticais:\n");
			for (i=1; i<=n; i++) {
				for (j=1; j<=m; j++) {
					if (mt[i][j]!='*'&&mt[i-1][j]=='*'&&mt[i+1][j]!='*') {
					       printf("  %d. ", nu[i][j]);
					       for (k=i; mt[k][j]!='*'; k++) {
						       printf("%c", mt[k][j]);
					       }
					       printf("\n");
					}
				}
			}
		}

		//enter
		printf("\n");
	}
}
```

Estive utilizando o **screen** e Lynx, Tmsnc, etc. por um tempo. É muito bom, bastante leve. É uma ótima opção para computadores lentos ou pra quem não quer perder tempo abrindo modo gráfico (se bem que se for pra ir na internet, ainda vale mais a pena abrir um Fluxbox ou algo do tipo). Bom... Uma vantagem também é já usar Mutt e Tmsnc normalmente. Aliás, o TMSNC tá muito bom! Saiu essa semana o 0.2.0b com algumas novidades legais como sons de login, mensagens, etc.

Já passou uma semana de aula... É meio corrido e não dá muito tempo pra programar, mas acabo estudando TeX durante a aula para escrever os cadernos. O treino de vôlei vai começar esta semana e ainda não falei com o Vavá sobre o treino para as olimpíadas de matemática.

Consegui convencer dois amigos a usarem Firefox mostrando o meu post sobre o Fotolog.net e espero que este artigo da falha ajude a mostrar para as pessoas que o Internet Explorer é muito vulnerável. Já enviei também um e-mail ao administrador do Fotolog.net falando do [bug][1].

No mais, nada...

[1]: /2005/02/falha-no-fotolognet/
