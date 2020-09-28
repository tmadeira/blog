//Sorvete - OBI2001
#include <stdio.h>
#define PMAX 10001

int main() {
	int p, s, u, v, i, j, inicio, vetor[PMAX], teste=1;

	while (scanf("%d %d", &p, &s) && p!=0) {
		for (i=0; i<=p; i++) {
			vetor[i]=0;
		}
		for (i=0; i<s; i++) {
			scanf("%d %d", &u, &v);
			for (j=u; j<v; j++) {
				vetor[j]=1;
			}
		}
		printf("Teste %d\n", teste++);
		for (i=0; i<=p; i++) {
			if (vetor[i]==1 && vetor[i-1]==0 && i!=0) {
				inicio=i;
			}
			if (vetor[i]==1 && i==0) {
				inicio=i;
			}
			if (vetor[i]==0 && vetor[i-1]==1) {
				printf("%d %d\n", inicio, i);
			}
		}
		printf("\n");
	}
}
