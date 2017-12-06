//Macaco-prego - OBI2000
#include <stdio.h>
#define NMAX 10001

int main() {
	int k, l, teste=1, coordx1, coordx2, coordy1, coordy2, j, n, x1[NMAX], y1[NMAX], x2[NMAX], y2[NMAX], i, m[NMAX*2][NMAX*2], x1e, x2e, y1e, y2e;

	while (scanf("%d", &n)==1 && n!=0) {
		x1e=10001;
		x2e=-10001;
		y1e=-10001;
		y2e=10001;
		for (i=0; i<n; i++) {
			scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
			x1[i]+=10000;
			x2[i]+=10000;
			y1[i]+=10000;
			y2[i]+=10000;
			if (x1[i]<x1e) {
				x1e=x1[i];
			}
			if (x2[i]>x2e) {
				x2e=x2[i];
			}
			if (y1[i]>y1e) {
				y1e=y1[i];
			}
			if (y2[i]<y2e) {
				y2e=y2[i];
			}
		}
		for (i=x1e; i<=x2e; i++) {
			for (j=y2e; j<=y1e; j++) {
				m[i][j]=0;
			}
		}
		for (i=0; i<n; i++) {
			for (k=x1[i]; k<=x2[i]; k++) {
				for (l=y2[i]; l<=y1[i]; l++) {
					m[k][l]++;
				}
			}
		}
		coordx1=-10001;
		coordy1=-10001;
		coordx2=-10001;
		coordy2=-10001;
		for (i=x1e; i<=x2e; i++) {
			for (j=y2e; j<=y1e; j++) {
				if (m[i][j]==n) {
					if (m[i-1][j]!=n && m[i][j+1]!=n) {
						coordx1=i;
						coordy1=j;
					}
					if (m[i+1][j]!=n && m[i][j-1]!=n) {
						coordx2=i;
						coordy2=j;
					}
				}
			}
		}
		printf("Teste %d\n", teste++);
		if (coordx1!=-10001) {
			printf("%d %d %d %d\n\n", coordx1-10000, coordy1-10000, coordx2-10000, coordy2-10000);
		} else {
			printf("nenhum\n\n");
		}
	}
}
