//Morro Acima, Morro Abaixo
#include <stdio.h>
#define NMAX 201

int total, n, m, g[NMAX][NMAX], alt[NMAX];

int funcao(int v, int dir, int tot) {
	int i, achou=0;

	if (dir==2) {
		achou=1;
	}

	for (i=1; i<=n; i++) {
		if (g[v][i]) {
			if (dir==1) {
				if (alt[i]>=alt[v]) {
					funcao(i, 1, tot+g[v][i]);
					achou=1;
				}
			} else {
				if (alt[i]<=alt[v]) {
					funcao(i, 2, tot+g[v][i]);
				}
			}
		}
	}

	if (!achou) {
		for (i=1; i<=n; i++) {
			if (g[v][i]) {
				if (alt[i]<=alt[v]) {
					funcao(i, 2, tot+g[v][i]);
				}
			}
		}
	}

	if (tot>total) {
		total=tot;
	}
}

int main() {
	int k, l, d, i, j, teste=1;

	while (scanf("%d %d", &n, &m)&&n) {
		total=0;
		for (i=1; i<=n; i++) {
			scanf("%d", &alt[i]);
			for (j=1; j<=n; j++) {
				g[i][j]=0;
			}
		}
		for (i=1; i<=m; i++) {
			scanf("%d %d %d", &k, &l, &d);
			g[k][l]=d;
			g[l][k]=d;
		}
		funcao(1, 1, 0);

		printf("Teste %d\n%d\n\n", teste++, total);
		
	}
}
