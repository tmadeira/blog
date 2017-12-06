//Ambulância

#include <stdio.h>
#define NMAX 101

int g[NMAX][NMAX];
int n;

int funcao(int v, int l, int *m, int *numpred) {
	int i, j=0, val[NMAX];
	
	for (i=1; i<=n; i++) {
		if (i!=v && !m[i] && g[v][i]) {
			val[j]=i;
			j++;
		}
	}

	for (i=1; i<=l; i++) {
		printf("%d ", numpred[i]);
	}
	if (l!=0) {
		printf("%d\n", v);
	}
	
	for (i=0; i<j; i++) {
		m[val[i]]=1;
		numpred[l+1]=v;
		funcao(val[i], l+1, m, numpred);
		m[val[i]]=0;
	}
}

int main() {
	int teste=1, i, j, x, y, m[NMAX], numpred[NMAX];

	while (scanf("%d", &n) == 1 && n!=0) {

		for (i=1; i<NMAX; i++) {
			m[i]=0;
			numpred[i]=0;
			for (j=1; j<NMAX; j++) {
				g[i][j]=0;
			}
		}

		m[1]=1;
		
		while (scanf("%d %d", &x, &y) == 2 && x!=0) {
			g[x][y]=1;
		}

		printf("Teste %d\n", teste++);
		funcao(1, 0, m, numpred);
		printf("\n");
		
	}
}
