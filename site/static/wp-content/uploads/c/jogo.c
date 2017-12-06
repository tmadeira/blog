//Jogo de Búzios

#include <stdio.h>

#define NMAX 15001

int main() {
	int n, k, b[NMAX], i, saiu, pj, j, t, teste=1;

	while (scanf("%d %d", &n, &k)&&n) {
		for (i=1; i<=n; i++) {
			b[i]=1;
		}
		b[k]=2;
		saiu=0;
		j=1;
		t=1;
		while (saiu<n-1) {
			pj=0;
//			printf("j=%d\n", j);
			for (i=j+1; i<n+j-1; i++) {
				if (i>n) {
					pj=i-n;
				} else {
					pj=i;
				}
//				printf("pj=%d\n", pj);
				if (b[pj]>0&&j!=pj) {
//					printf("escolhe %d\n", pj);
					i=n+j;
					if (t%2) {
						b[j]-=1;
						b[pj]+=1;
//						printf("%d deu 1 pra %d\n", j, pj);
					} else {
						b[j]-=2;
						b[pj]+=2;
//						printf("%d deu 2 pra %d\n", j, pj);
					}
				}
			}
			if (b[j]<1) {
				saiu+=1;
			}
			j=pj;
			t++;
		}
		printf("Teste %d\n", teste++);
		printf("turnos: %d\n", t-1);
		for (i=1; i<=n; i++) {
			if (b[i]) {
				printf("vencedor: %d\n\n", i);
			}
		}
	}
}
