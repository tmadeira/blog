//Saldo de Gols - OBI2000
#include <stdio.h>
#define NMAX 10001
int main() {
	int n, teste=1, pro, contra, saldo[NMAX], res[NMAX][NMAX], i, j, out1, out2, maior, dif;

	while (scanf("%d", &n)==1 && n!=0) {
		for (i=1; i<=n; i++) {
			scanf("%d %d", &pro, &contra);
			saldo[i]=pro-contra;
		}

		for (i=0; i<=n; i++) {
			for (j=i; j<=n; j++) {
				if (j==i) {
					res[i][j]=saldo[j];
				} else {
					res[i][j]=res[i][j-1]+saldo[j];
				}
			}
		}

		maior=-1;
		dif=-1;
		for (i=1; i<=n; i++) {
			for (j=i; j<=n; j++) {
				if (res[i][j]>maior) {
					maior=res[i][j];
					dif=j-i;
					out1=i;
					out2=j;
				} else if (res[i][j]==maior && j-i>dif) {
					maior=res[i][j];
					dif=j-i;
					out1=i;
					out2=j;
				}
			}
		}

		printf("Teste %d\n", teste++);
		if (maior==-1) {
			printf("nenhum\n\n");
		} else {
			printf("%d %d\n\n", out1, out2);
		}

	}
}
