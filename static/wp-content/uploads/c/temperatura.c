//Temperatura Lunar - OBI2002

#include <stdio.h>
#define NMAX 10001

int main() {
	int n, maior, menor, total, i, j, m, medida[NMAX], teste=1;

	while (scanf("%d %d", &n, &m) == 2 && n!=0) {
		for (i=0; i<n; i++) {
			scanf("%d", &medida[i]);
		}
		maior=-201;
		menor=201;
		for (i=0; i<=n-m; i++) {
			total=0;
			for (j=0; j<m; j++) {
				total+=medida[i+j];
			}
			total/=m;
			if (total<menor) {
				menor=total;
			}
			if (total>maior) {
				maior=total;
			}
		}

		printf("Teste %d\n%d %d\n\n", teste++, menor, maior);
	}
}
