//Pedágio - OBI2002

#include <stdio.h>
#include <values.h>
#define CMAX 51
int p, c, g[CMAX][CMAX], marc[CMAX], cont, res[CMAX];

int funcao(int v, int l) {
	int i;
	if (l!=0) {
		res[v]=1;
	}
	if (l<p) {
		for (i=1; i<=c; i++) {
			if (v!=i && !marc[i] && g[v][i]) {
				marc[v]=1;
				funcao(i, l+1);
				marc[v]=0;
			}
		}
	}
}

int main() {
	int e, l, x, y, teste=1, i, j, menor, menori, resul[CMAX];

	while (scanf("%d %d %d %d", &c, &e, &l, &p)&&c!=0) {

		for (i=1; i<=c; i++) {
			marc[i]=0;
			res[i]=0;
			for (j=1; j<=c; j++) {
				g[i][j]=0;
			}
		}
		
		for (i=1; i<=e; i++) {
			scanf("%d %d", &x, &y);
			g[x][y]=1;
			g[y][x]=1;
		}
		
		cont=0;
		
		funcao(l, 0);

		printf("Teste %d\n", teste++);

		for (i=1; i<=c; i++) {
			if (res[i]) {
				printf("%d ", i);
			}
		}
		printf("\n\n");

	}
}
