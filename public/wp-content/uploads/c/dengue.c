//Dengue - OBI2001

#include <stdio.h>
#include <values.h>
#define NMAX 101

int caminhada[NMAX][NMAX], n, g[NMAX][NMAX], marc[NMAX], lugar;

int funcao(int i, int l) {
	int j;
	for (j=1; j<=n; j++) {
		if (g[i][j] && !marc[j]) {
			marc[i]=1;
			funcao(j, l+1);
			marc[i]=0;
		}
	}
	caminhada[lugar][i]=l;
}

int main() {
	int vencedor, menor, res, soma, i, j, teste=1, x, y;

	while (scanf("%d", &n) == 1 && n!=0) {
		for (i=1; i<=n; i++) {
			marc[i]=0;
			for (j=1; j<=n; j++) {
				g[i][j]=0;
				caminhada[i][j]=0;
			}
		}

		for (i=1; i<n; i++) {
			scanf("%d %d", &x, &y);
			g[x][y]=1;
			g[y][x]=1;
		}

		menor=MAXINT;
		
		for (i=1; i<=n; i++) {
			lugar=i;
			funcao(i, 0);
			soma=0;
			for (j=1; j<=n; j++) {
				soma+=caminhada[i][j];
			}
			if (soma<menor) {
				res=lugar;
				menor=soma;
			}
		}

		printf("Teste %d\n%d\n\n", teste++, res);

	}
}
