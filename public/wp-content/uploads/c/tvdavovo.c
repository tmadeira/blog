//TV da Vovó - OBI2004
#include <stdio.h>
#define NMAX 1001

int main() {
	int teste=1, nm, nn, m, n, matriz[NMAX][NMAX], i, j, x, y, matriznova[NMAX][NMAX], nx, ny;

	while (scanf("%d %d", &m, &n) == 2 && n!=0) {
		for (i=1; i<=m; i++) {
			for (j=1; j<=n; j++) {
				scanf("%d", &matriz[i][j]);
			}
		}
		while (scanf("%d %d", &x, &y) == 2 && (x!=0 || y!=0)) {
			for (i=1; i<=m; i++) {
				for (j=1; j<=n; j++) {
					nx=j+x;
					ny=i-y;
					if (nx>n) {
						nx-=n;
					} else if (nx<1) {
						nx+=n;
					}
					if (ny<1) {
						ny+=m;
					} else if (ny>m) {
						ny-=m;
					}
					matriznova[ny][nx]=matriz[i][j];
				}
			}
			for (i=1; i<=m; i++) {
				for (j=1; j<=n; j++) {
					matriz[i][j]=matriznova[i][j];
				}
			}
			
		}
		printf("Teste %d\n", teste++);
		for (i=1; i<=m; i++) {
			for (j=1; j<n; j++) {
				printf("%d ", matriz[i][j]);
			}
			printf("%d\n", matriz[i][n]);
		}
		printf("\n");
	}
}
