//Festa Junina
#include <stdio.h>
#define NMAX 21

int soma, a[NMAX][NMAX], n, marc[NMAX];

int funcao(int v) {
	int i;
	marc[v]=1;
	soma++;
	for (i=1; i<=n; i++) {
		if (!a[v][i]) {
//			printf("marcando %d, porque !a[%d][%d]\n", i, v, i);
			marc[i]=1;
		}
	}
	for (i=1; i<=n; i++) {
		if (a[v][i] && !marc[i]) {
//			printf("já que %d é amigo de %d, funcao(%d)\n", v, i, i);
			funcao(i);
		}
	}

}

int main() {
	int teste=1, c, i, j, res;

	while (scanf("%d", &n) == 1 && n!=0) {
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) {
				a[i][j]=1;
			}
		}
		for (i=1; i<=n; i++) {
			while (scanf("%d", &c) == 1 && c!=0) {
				a[i][c]=0;
				a[c][i]=0;
//				printf("O %d não gosta do %d.\n", i, c);
			}
		}
		res=0;
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) {
				marc[j]=0;
			}
			soma=0;
//			printf("##########\nExecutando f(%d)\n##########\n", i);
			funcao(i);
//			printf("Soma(%d)=%d\n", i, soma);
			if (soma>res) {
//				printf("soma (%d) é maior que res (%d)\n", soma, res);
				res=soma;
			}
		}
		printf("Teste %d\n%d\n\n", teste++, res);
	}
}
