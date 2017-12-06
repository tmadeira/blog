//Rede Ótica - OBI2000
#include <stdio.h>
#define NMAX 101

int marc[NMAX], g[NMAX][NMAX], n, pri;

int funcao(int v, int pred, int custo) {
	register int i;
	marc[v]=1;
	custo+=g[pred][v];
	for (i=1; i<=n; i++) {
		if (g[v][i] && pred!=i) {
			if (marc[i]) {
				printf("existe ciclo entre %d, %d e %d\n", v, i, pred);
				printf("custo comecando de %d eh %d\n\n", pri, custo);
			} else {
				funcao(i, v, custo);
			}
		}
	}
	marc[v]=0;
}

int main() {
	int m, x, y, z;
	register int i, j;
	int teste=1;

	while (scanf("%d %d", &n, &m) && n!=0) {
		for (i=1; i<=n; i++) {
			marc[i]=0;
			for (j=1; j<=n; j++) {
				g[i][j]=0;
			}
		}
		for (i=0; i<m; i++) {
			scanf("%d %d %d", &x, &y, &z);
			g[x][y]=z;
			g[y][x]=z;
		}
		for (i=1; i<=n; i++) {
			pri=i;
			printf("Executando função com %d\n", i);
			funcao(i, 0, 0);
		}
	}
}
