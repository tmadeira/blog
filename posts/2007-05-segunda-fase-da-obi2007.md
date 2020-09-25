---
title: Segunda fase da OBI2007
type: post
date: 2007-05-01T13:38:05+00:00
url: /2007/05/segunda-fase-da-obi2007/
categorias:
  - Cotidiano
tags:
  - c
  - computação
  - labirinto
  - obi
  - obi 2007
  - olimpíadas
  - pizza
  - problemas
  - telemarketing

---
A prova de segunda fase da [Olimpíada Brasileira de Informática][1] aconteceu há duas semanas e eu havia me esquecido de comentar aqui no blog como eu fui. O resultado deve sair amanhã ou depois de amanhã, segundo um dos caras responsáveis pela organização no orkut. Se tudo der certo e Éris quiser eu participarei pela quarta vez do curso de programação e da seletiva para a IOI.

### Telemarketing (OBI2007 – Programação Nível 2 – Segunda Fase)

A solução mais eficiente usa _heaps_. Sem conseguir pensar nesta solução no momento da prova, implementei uma força bruta bem otimizada. Infelizmente, ela tem um pequeno erro que uma alma boa que se apresenta como CEO da Oracle encontrou para mim:

> No seu programa, você faz um “for” que vai de “ultimo” até “n”, armazenando o id do vendedor que vai ficar desocupado primeiro na variável “mt”. Então você faz um “for” de 1 até “ultimo” mudando a variável “mt” apenas quando o vendedor ficar livre antes do “mt”, sendo que, como o id dele é menor, deve atender a ligação caso fique disponível antes ou ao mesmo tempo em que o vendedor “mt” ficar livre. Para resolver isso, fiz um “for” que vai de “ultimo” até 1 usando um “if” com “<=”.

Acredito que receberei no máximo 20/100 pontos.

```c
#include <stdio.h>
#include <values.h>

#define NMAX 1010

int main() {
	int n, l, duracao, c=0, ocupado[NMAX], mt, ligacoes[NMAX], oc;
	int i, j, ultimo;

	scanf("%d %d", &n, &l);

	for (i=1; i<=n; i++) {
		ocupado[i]=0;
		ligacoes[i]=0;
	}

	ocupado[0]=MAXINT;
	ultimo=0;

	for (i=1; i<=l; i++) {
		scanf("%d", &duracao);
		c=0;
		mt=0;
		for (j=ultimo+1; j<=n; j++) {
			if (!ocupado[j]) {
				ocupado[j]=duracao;
				ligacoes[j]++;
				c=1;
				ultimo=j;
				break;
			} else {
				if (ocupado[j]<ocupado[mt]) {
					mt=j;
				}
			}
		}
		if (!c) {
			for (j=1; j<=ultimo; j++) {
				if (ocupado[j]<ocupado[mt]) {
					mt=j;
				}
			}
			oc=ocupado[mt];
			ultimo=0;
			for (j=1; j<=n; j++) {
				ocupado[j]-=oc;
			}
			ocupado[mt]=duracao;
			ligacoes[mt]++;
		}
	}

	for (i=1; i<=n; i++) {
		printf("%d %dn", i, ligacoes[i]);
	}

	return 0;
}
```

### Pizza (OBI2007 - Programação Nível 2 - Segunda Fase)

A solução mais eficiente usa programação dinâmica. A minha solução é uma força bruta, mais simples impossível. O programa está correto, mas não passará em muitos casos de teste por estourar o tempo limite. Espero mais uns 20/100 pontos.

```c
#include <stdio.h>

#define MAX 100010

int main() {
	int n, soma;
	int i, j;
	int k[MAX];
	int maximo=0;

	scanf("%d", &n);
	for (i=1; i<=n; i++) {
		scanf("%d", &k[i]);
		k[i+n]=k[i];
		if (k[i]>maximo) {
			maximo=k[i];
		}
	}

	if (maximo==0) {
		printf("0n");
		return 0;
	}

	for (i=1; i<=n; i++) {
		soma=0;
		if (k[i]>0) {
			for (j=i; j<i+n; j++) {
				soma+=k[j];
				if (soma>maximo) {
					maximo=soma;
				}
			}
		}
	}

	printf("%dn", maximo);

	return 0;
}
```

### Labirinto (OBI2007 - Programação Nível 2 - Segunda Fase)

O único problema que resolvi de maneira eficiente. A solução transforma o problema do labirinto em um grafo e depois chega à solução com uma busca em largura. Nesse eu espero a pontuação máxima, 100/100 pontos.

```c
#include <stdio.h>
#include <values.h>

#define NMAX 55
#define VERTICES 2510

int n, m;
int nivel[VERTICES], vizinhos[VERTICES];
int fila[VERTICES*VERTICES], nvl[VERTICES*VERTICES];
int max[VERTICES];
int grafo[VERTICES][VERTICES];
int saida=MAXINT;

int identificador (int a, int b) {
	return (b+(a-1)*m);
}

int rn (int nivelerrado) {
	while (nivelerrado>9) {
		nivelerrado-=10;
	}
	return nivelerrado;
}

int main() {
	int i, j;
	int idmax, atual, idv;
	int niv, nivv, niva;
	int ini, fim;

	scanf("%d %d", &n, &m);

	idmax=n*m;

	for (i=1; i<=idmax; i++) {
		for (j=1; j<=idmax; j++) {
			grafo[i][j]=0;
		}
		vizinhos[i]=0;
		max[i]=0;
	}

	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			atual=identificador(i, j);
			scanf("%d", &nivel[atual]);
			if (i-1>0) {
				idv=identificador(i-1, j);
				if (idv>0) {
					grafo[atual][vizinhos[atual]++]=idv;
				}
			}
			if (j-1>0) {
				idv=identificador(i, j-1);
				if (idv>0) {
					grafo[atual][vizinhos[atual]++]=idv;
				}
			}
			if (i+1<=n) {
				idv=identificador(i+1, j);
				if (idv<=idmax) {
					grafo[atual][vizinhos[atual]++]=idv;
				}
			}
			if (j+1<=m) {
				idv=identificador(i, j+1);
				if (idv<=idmax) {
					grafo[atual][vizinhos[atual]++]=idv;
				}
			}
			grafo[atual][vizinhos[atual]++]=atual;
		}
	}

	ini=0;
	fim=0;
	nvl[fim]=0;
	fila[fim++]=1;
	while (ini!=fim) {
		niv=nvl[ini];
		if (niv<saida) {
			atual=fila[ini++];
			niva=rn(nivel[atual]+niv);
			if (atual==idmax) {
				if (niv<saida) {
					saida=niv;
				}
			} else {
				for (i=0; i<vizinhos[atual]; i++) {
					idv=grafo[atual][i];
					nivv=rn(nivel[idv]+niv);
					if (nivv<=niva+1&&niv+1>max[idv]) {
						nvl[fim]=niv+1;
						max[idv]=niv+1;
						fila[fim++]=idv;
					}
				}
			}
		} else {
			ini++;
		}
	}

	printf("%dn", saida);
	return 0;
}
```

### Conclusão

O resultado da olimpíada deve sair amanhã ou depois de amanhã e a nota de corte deve ser entre 100 e 150 pontos. Pelos meus cálculos, eu devo ter feito 140 (20+20+100), o que talvez me classifique para a próxima fase. Mais notícias a qualquer momento ;)

 [1]: http://olimpiada.ic.unicamp.br/
