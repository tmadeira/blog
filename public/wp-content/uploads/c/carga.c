//Carga Pesada
#include <stdio.h>
#define NMAX 101

int g[NMAX][NMAX], x, y, n, maior;

int funcao(int v, int p, int ma) {
	int i, me;
	for (i=1; i<=n; i++) {
		if (g[v][i]&&i!=p) {
			if (i==y) {
				if (g[v][i]<ma) {
					me=g[v][i];
				} else {
					me=ma;
				}
				if (me>maior) {
					maior=me;
				}
			} else {
				if (g[v][i]<ma) {
					me=g[v][i];
				}
				funcao(i, v, me);
			}
		}
	}
}

int main() {
	int a, b, c;
	int i, j;
	int teste=1;

	while (scanf("%d %d", &x, &y)&&x) {
		n=0;
		for (i=1; i<=100; i++) {
			for (j=1; j<=100; j++) {
				g[i][j]=0;
			}
		}
		while (scanf("%d %d %d", &a, &b, &c)&&(a||b||c)) {
			if (a>n) {
				n=a;
			}
			if (b>n) {
				n=b;
			}
			g[a][b]=c;
		}
		maior=0;
		funcao(x, 0, 51);
		printf("Teste %d\naltura maxima: %d\n\n", teste++, maior);
	}
}
