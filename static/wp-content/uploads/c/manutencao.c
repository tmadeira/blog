//Manutenção
#include <stdio.h>
#define NMAX 401

int g[NMAX][NMAX], marc[NMAX], n;

int funcao(int v) {
	int i;

	for (i=1; i<=n; i++) {
		if (g[v][i] && !marc[i]) {
			marc[i]=1;
			funcao(i);
		}
	}

}

int main() {
	int i, j, m, teste=1, x, y, erros, erro, start;

	while (scanf("%d %d", &n, &m)==2 && n!=0) {

		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) {
				g[i][j]=0;
			}
		}

		for (i=0; i<m; i++) {
			scanf("%d %d", &x, &y);
			g[x][y]=1;
			g[y][x]=1;
		}

		printf("Teste %d\n", teste++);

		erros=0;
		for (i=1; i<=n; i++) {
			erro=0;
			marc[i]=1;
			if (i!=1) {
				start=1;
			} else {
				start=n;
			}
			funcao(start);
			for (j=1; j<=n; j++) {
				if (!marc[j]) {
					erro=1;
				}
				marc[j]=0;
			}
			if (erro) {
				printf("%d ", i);
				erros++;
			}
		}
		
		if (!erros) {
			printf("nenhum");
		}

		printf("\n\n");

	}
}
