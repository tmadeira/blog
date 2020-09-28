//Transmissão de Energia - OBI2005
#include <stdio.h>
#define NMAX 101

int g[NMAX][NMAX], achou[NMAX], n, achados;

void acha(int x) {
	int i;

	achou[x]=1;
	achados++;
	for (i=1; i<=n; i++) {
		if (g[x][i]&&!achou[i]) {
			g[x][i]=0;
			g[i][x]=0;
			acha(i);
		}
	}
}

int main() {
	int e, i, j, x, y, teste=1;

	while (scanf("%d %d", &n, &e)&&n) {
		achados=0;
		for (i=1; i<=n; i++) {
			achou[i]=0;
			for (j=1; j<=n; j++) {
				g[i][j]=0;
			}
		}
	
		for (i=1; i<=e; i++) {
			scanf("%d %d", &x, &y);
			g[x][y]=1;
			g[y][x]=1;
		}
	
		acha(1);
	
		printf("Teste %d\n", teste++);
		if (achados==n) {
			printf("normal");
		} else {
			printf("falha");
		}
		printf("\n\n");
	}

	return 0;
}
