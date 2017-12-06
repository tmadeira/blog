//Jogo de Búzios

#include <stdio.h>
#define NMAX 15001

int main() {
	int teste=1, n, k, turnos, ultimo, t, saiu, existe[NMAX], jj, j, ic, i, b[NMAX];

	while (scanf("%d %d", &n, &k)&&n) {
		saiu=0;
		t=1;
		j=1;
		for (i=1; i<=n; i++) {
			existe[i]=1;
			b[i]=1;
			if (i==k) {
				b[i]=2;
			}
		}
		while (saiu!=n) {
			printf("%d\n", j);
			jj=0;
			for (i=j+1; !jj; i++) {
				if (i<=n) {
					ic=i;
				} else if (i-n<j) {
					ic=i-n;
				} else {
					jj=1;
				}
				if (existe[ic]) {
					if (t%2) {
						b[j]-=1;
						b[ic]+=1;
					} else {
						b[j]-=2;
						b[ic]+=2;
					}
					jj=1;
				}
				if (b[j]<1) {
					existe[j]=0;
					saiu++;
					if (saiu==n) {
						ultimo=j;
						turnos=t;
					}
				}
			}
			j=ic;
			t++;
		}

		printf("Teste %d\nturnos: %d\nvencedor: %d\n\n", teste++, turnos, ultimo);
	}
}
