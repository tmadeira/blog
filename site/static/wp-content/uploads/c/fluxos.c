//Fluxos em rede 1, durante curso na Unicamp
#include <stdio.h>
#define NMAX 1001

//Objetivo: Descobrir o tamanho da colecao maxima de caminhos
//orientados de s a t e disjunto nas arestas e imprimir os
//caminhos.

// N é o número de vértices
// M é o número de arestas
// S é de onde sai
// T é onde precisa chegar
// As M linhas são arestas de X a Y

int g[NMAX][NMAX], f[NMAX][NMAX], marc[NMAX], pai[NMAX], n, t;

int bp(int v, int p) {
	int i;

	pai[v]=p;
	marc[v]=1;

	if (f[v][p]) {
		f[v][p]=0;
	} else if (v!=p) {
		f[p][v]=1;
	}

	if (v!=t) {	
		for (i=1; i<=n; i++) {
			if (!marc[i]&&g[v][i]) {
				bp(i, v);
			}
		}
	}
}

int bp2(int v) {
	int i;

	printf("%d ", v);
	
	if (v!=t) {
		for (i=1; i<=n; i++) {
			if (f[v][i]) {
				f[v][i]=0;
				bp2(i);
				i=n+1;
			}
		}
	}
}

int main() {
	int m, k, x, y, i, j, s;

	while (scanf("%d %d", &n, &m)&&n) {
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) {
				g[i][j]=0;
				f[i][j]=0;
			}
		}
		scanf("%d %d", &s, &t);
		for (i=0; i<m; i++) {
			scanf("%d %d", &x, &y);
			g[x][y]=1;
		}
		k=0;
		do {
			for (i=1; i<=n; i++) {
				marc[i]=0;
				pai[i]=0;
			}
			bp(s, s);
			if (marc[t]) {
				k++;
				i=t;
				while (pai[i]!=i) {
					g[pai[i]][i]=0;
					g[i][pai[i]]=1;
					i=pai[i];
				}
			}
		} while (marc[t]);
		printf("Podem existir no máximo %d caminhos de %d a %d usando arestas disjuntas.\n\n", k, s, t);

		printf("Os caminhos são:\n");
		for (i=1; i<=k; i++) {
			bp2(s);
			printf("\n");
		}
	}
}


