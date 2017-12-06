//Duende Perdido - OBI2005
#include <stdio.h>
#include <values.h>
#define NMAX 102

int menor=MAXINT, p[NMAX][NMAX], custo[NMAX][NMAX];

int duende(int x, int y, int cus, int ox, int oy) {

	if (p[x][y]==1||p[x][y]==3) {
		if (cus<custo[x][y]) {
			custo[x][y]=cus;
			if ((x!=ox||y+1!=oy)&&p[x][y+1]!=-1) {
				duende(x, y+1, cus+1, x, y);
			}
			if ((x+1!=ox||y!=oy)&&p[x+1][y]!=-1) {
				duende(x+1, y, cus+1, x, y);
			}
			if ((x!=ox||y-1!=oy)&&p[x][y-1]!=-1) {
				duende(x, y-1, cus+1, x, y);
			}
			if ((x-1!=ox||y!=oy)&&p[x-1][y]!=-1) {
				duende(x-1, y, cus+1, x, y);
			}
		}
	}
	if (p[x][y]==0) {
		if (cus<custo[x][y]) {
			custo[x][y]=cus;
		}
		if (custo[x][y]<menor) {
			menor=custo[x][y];
		}
	}
}

int main() {
	int n, m, ix, iy, i, j;

	scanf("%d %d", &n, &m);

	for (i=0; i<=n+1; i++) {
		for (j=0; j<=m+1; j++) {
			p[i][j]=-1;
			custo[i][j]=MAXINT;
		}
	}

	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			scanf("%d", &p[i][j]);
			if (p[i][j]==3) {
				ix=i;
				iy=j;
			}
		}
	}

	duende(ix, iy, 0, 0, 0);

	printf("%d\n", menor);

	return 0;
}
