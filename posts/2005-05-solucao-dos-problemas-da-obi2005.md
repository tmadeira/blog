---
title: Solução dos Problemas da OBI2005
type: post
date: 2005-05-18T17:22:05+00:00
excerpt: Agora que as escolas já submeteram as soluções dos problemas da OBI desse ano, resolvi publicar a solução dos quatro problemas da Programação Nível 1 aqui.
url: /2005/05/solucao-dos-problemas-da-obi2005/
categorias:
  - Cotidiano
tags:
  - c
  - campo de minhocas
  - códigos
  - computação
  - duende perdido
  - frota de táxi
  - obi
  - obi 2005
  - olimpíadas
  - problemas
  - programação
  - trilhas

---
Agora que eu acho que todas as escolas já submeteram as soluções dos problemas da Programação Nível 1 da OBI desse ano, estou publicando minhas quatro soluções, em C.

### Frota de Táxi

```c
//Frota de Taxi - OBI2005
#include <stdio.h>

int main() {
	float a, g, ra, rg, al, ga;

	scanf("%f %f %f %f", &a, &g, &ra, &rg);
	al=a/ra;
	ga=g/rg;

	if (al<ga) {
		printf("A\n");
	} else {
		printf("G\n");
	}

	return 0;
}
```

### Campo de Minhocas

```c
//Campo de Minhocas - OBI2005
#include <stdio.h>
#define NMAX 102
#define NMAX 102

int main() {
	int n, m, soma, i, j, matriz[NMAX][NMAX], maior=0;

	scanf("%d %d", &n, &m);

	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}

	for (i=1; i<=n; i++) {
		soma=0;
		for (j=1; j<=m; j++) {
			soma+=matriz[i][j];
		}
		if (soma>maior) {
			maior=soma;
		}
	}

	for (i=1; i<=m; i++) {
		soma=0;
		for (j=1; j<=n; j++) {
			soma+=matriz[j][i];
		}
		if (soma>maior) {
			maior=soma;
		}
	}

	printf("%d\n", maior);

	return 0;
}
```

### Duende Perdido

```c
//Duende Perdido - OBI2005
#include <stdio.h>
#include <values.h>
#define NMAX 102

int menor=MAXINT, p[NMAX][NMAX], custo[NMAX][NMAX];

int duende(int x, int y, int cus, int ox, int oy) {

	if (p[x][y]==1||p[x][y]==3) {
		if (cus<custo[x][y]) {
			custo[x][y]=cus;
			if ((x!=ox||y+1!=oy)&&p[x][y+1]!=-1) {
				duende(x, y+1, cus+1, x, y);
			}
			if ((x+1!=ox||y!=oy)&&p[x+1][y]!=-1) {
				duende(x+1, y, cus+1, x, y);
			}
			if ((x!=ox||y-1!=oy)&&p[x][y-1]!=-1) {
				duende(x, y-1, cus+1, x, y);
			}
			if ((x-1!=ox||y!=oy)&&p[x-1][y]!=-1) {
				duende(x-1, y, cus+1, x, y);
			}
		}
	}
	if (p[x][y]==0) {
		if (cus<custo[x][y]) {
			custo[x][y]=cus;
		}
		if (custo[x][y]<menor) {
			menor=custo[x][y];
		}
	}
}

int main() {
	int n, m, ix, iy, i, j;

	scanf("%d %d", &n, &m);

	for (i=0; i<=n+1; i++) {
		for (j=0; j<=m+1; j++) {
			p[i][j]=-1;
			custo[i][j]=MAXINT;
		}
	}

	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			scanf("%d", &p[i][j]);
			if (p[i][j]==3) {
				ix=i;
				iy=j;
			}
		}
	}

	duende(ix, iy, 0, 0, 0);

	printf("%d\n", menor);

	return 0;
}
```

### Trilhas

```c
//Trilhas - OBI2005
#include <stdio.h>
#include <values.h>
#define NMAX 102
#define MMAX 1001

int main() {
	int campeao, n, m[NMAX], a[NMAX][MMAX], saida=0, i, j, parou, subir[NMAX], descer[NMAX], menor=MAXINT;

	scanf("%d", &n);
	for (i=1; i<=n; i++) {
		scanf("%d", &m[i]);
		for (j=1; j<=m[i]; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	//Primeiro vamos ver se precisa haver esforço de subida
	for (i=1; i<=n; i++) {
		parou=0;
		for (j=1; j<=m[i]; j++) {
			//printf("%d %d\n", i, j);
			if (a[i][j]>a[i][j+1]&&j!=m[i]) {
				parou=1;
				//printf("parou!\n");
				j=m[i];
			}
		}
		if (!parou) {
			//Então vamos parar por aí...
			printf("%d\n", i);
			return 0;
		}
	}

	//A mesma coisa ao contrário
	for (i=1; i<=n; i++) {
		parou=0;
		for (j=m[i]; j>=1; j--) {
			//printf("%d %d\n", i, j);
			if (a[i][j]>a[i][j-1]&&j!=1) {
				parou=1;
				//printf("parou!\n");
				j=1;
			}
		}
		if (!parou) {
			//Então vamos parar por aí...
			printf("%d\n", i);
			return 0;
		}
	}

	//Não deu...
	//Vamos contar quantos metros vamos ter que subir (ou descer=subir ao contrário)
	for (i=1; i<=n; i++) {
		descer[i]=0;
		subir[i]=0;
		for (j=1; j<=m[i]; j++) {
			if (a[i][j]>a[i][j+1]) {
				descer[i]+=(a[i][j]-a[i][j+1]);
			} else {
				subir[i]+=(a[i][j+1]-a[i][j]);
			}
		}
	}

	//E quem sobe ou desce menos?
	for (i=1; i<=n; i++) {
		if (subir[i]<menor) {
			menor=subir[i];
		}
		if (descer[i]<menor) {
			menor=descer[i];
		}
	}

	//Mas peraí... Temos que ver o primeiro na ordem de identificação!
	for (i=1; i<=n; i++) {
		if (subir[i]==menor||descer[i]==menor) {
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}
```

O último deles (Trilhas) tá meio problemático. Tá fazendo um monte de coisa que não precisava... :S É que deu uns problemas lá na hora e eu tava cansado por causa do Duende e daí tive lag pra interpretar o enunciado e já que o tempo tava acabando por causa de problemas com o computador onde tava fazendo a prova eu fiz de uma maneira bem precária! Acho que ele tá com erros...

O do Duende é o mais interessante. Os outros dois não tiveram muita graça. O Trilhas também era bem fácil, mas inesperadamente o meu cérebro deu um **Segmentation Fault** quando fui fazer ele.

Gostaria que se alguém achasse algum erro em algum dos scripts me avisasse. O pessoal da OBI ainda não divulgou um gabarito pra testar os programas e nem o resultado. Acredito que semana que vem deve sair alguma coisa...

