//Batuíra

#include <stdio.h>
#include <values.h>

#define NMAX 101

int g[NMAX][NMAX], n, res[NMAX], j=0;

int funcao(int v, int l, int t, int *m) {
	int i;

	if (v==n) {
		res[j]=t;
		j++;
	} else {
		for (i=1; i<=n; i++) {
			if (g[v][i] && !m[i]) {
				m[v]=1;
				funcao(i, l+1, t+g[v][i], m);
				m[v]=0;
			}
		}
	}
}
	

int main() {
	int teste=1, menor, z, y, x, i, m[NMAX];

	while (scanf("%d", &n) == 1 && n!=0) {
		while (scanf("%d %d %d", &x, &y, &z) == 3 && x!=0) {
			g[x][y]=z;
			g[y][x]=z;
		}
		
		for (i=1; i<=n; i++) {
			m[i]=0;
		}

		funcao(1, 0, 0, m);

		menor=MAXINT;
		for (i=0; i<j; i++) {
			if (res[i]<menor) {
				menor=res[i];
			}
		}

		printf("Teste %d\n%d\n\n", teste++, menor);
	}
}
