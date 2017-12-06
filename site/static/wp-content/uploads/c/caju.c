//Colheita de Caju - OBI2006
#include <stdio.h>
#define LMAX 1001

int matriz[LMAX][LMAX];

int main() {
	int linhas, colunas, lmax, cmax;
	int i, j, x, y;
	int soma, res=0;

	scanf("%d %d %d %d", &linhas, &colunas, &lmax, &cmax);

	for (i=1; i<=linhas; i++) {
		for (j=1; j<=colunas; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}

	for (i=1; i<=linhas+1-lmax; i++) {
		for (j=1; j<=colunas+1-cmax; j++) {
			soma=0;
			for (x=i; x<i+lmax; x++) {
				for (y=j; y<j+cmax; y++) {
					soma+=matriz[x][y];
				}
			}
			if (soma>res) {
				res=soma;
			}
		}
	}
	printf("%d\n", res);

	return 0;
}

