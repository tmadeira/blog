//Pirâmide
#include <stdio.h>
#define NMAX 5001

int main() {
	int n, x[NMAX], y[NMAX], tot[NMAX], i, j, total, teste=1;

	while (scanf("%d", &n)&&n) {
		for (i=1; i<=n; i++) {
			tot[i]=0;
		}
		for (i=1; i<=n; i++) {
			scanf("%d %d", &x[i], &y[i]);
			for (j=1; j<i; j++) {
				if ((x[j]<=x[i]&&y[j]<=y[i])||(x[j]<=y[i]&&y[j]<=x[i])) {
					tot[i]++;
				}
				if ((x[i]<=x[j]&&y[i]<=y[j])||(x[i]<=y[j]&&y[i]<=x[j])) {
					tot[j]++;
				}
			}
		}
		total=-1;
		for (i=1; i<=n; i++) {
			if (tot[i]>total) {
				total=tot[i];
			}
		}
		printf("Teste %d\n%d\n\n", teste++, total+1);
	}
}
