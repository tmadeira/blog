//Quermesse - OBI2000
#include <stdio.h>
#define NMAX 10000

int main() {
	int n, teste=1, ingresso[NMAX], i, vencedor;

	while (scanf("%d", &n) == 1 && n!=0) {
		for (i=1; i<=n; i++) {
			scanf("%d", &ingresso[i]);
			if (ingresso[i]==i) {
				vencedor=i;
			}
		}
		printf("Teste %d\n%d\n\n", teste++, vencedor);
	}
}
