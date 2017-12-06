//Cofrinhos da Vó Vitória - OBI2003

#include <stdio.h>

int main() {
	int n, i, teste=1, dj, dz, tj, tz;

	while (scanf("%d", &n)==1 && n!=0) {
		printf("Teste %d\n", teste++);
		tz=0;
		tj=0;
		for (i=0; i<n; i++) {
			scanf("%d %d", &dj, &dz);
			tz+=dz;
			tj+=dj;
			printf("%d\n", tj-tz);
		}
		printf("\n");
	}
}
