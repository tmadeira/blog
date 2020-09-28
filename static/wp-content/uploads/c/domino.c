//Dominó - OBI2001
#include <stdio.h>

int g[7][7], gr[7], m[7];

int funcao(int v) {
	int i;

	m[v]=1;
	for (i=0; i<7; i++) {
		if (g[v][i]&&!m[i]) {
			funcao(i);
		}
	}
}

int main() {
	int n, i, j, x, y, imp, excfn, teste=1, ehconexo;

	while (scanf("%d", &n) && n!=0) {
		for (i=0; i<7; i++) {
			m[i]=0;
			for (j=0; j<7; j++) {
				g[i][j]=0;
			}
		}

		for (i=0; i<n; i++) {
			scanf("%d %d", &x, &y);
			g[x][y]=1;
			g[y][x]=1;
			gr[x]++;
			gr[y]++;
		}

		imp=0;
		excfn=0;
		for (i=0; i<7; i++) {
			if (gr[i]%2) {
				imp++;
			}
			if (gr[i]&&!excfn) {
				excfn=1;
				funcao(i);
			}
		}

		ehconexo=1;

		for (i=0; i<7; i++) {
			if (gr[i]&&!m[i]) {
				ehconexo=0;
			}
		}

		printf("Teste %d\n", teste++);

		if (imp>2||!ehconexo) {
			printf("nao\n\n");
		} else {
			printf("sim\n\n");
		}
	}
}
