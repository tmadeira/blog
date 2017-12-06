//Imagens
#include <stdio.h>
#define MMAX 51
#define NMAX 81

int main() {
	int m, n, i, j, posicao[MMAX][NMAX], resultado, teste=1;
	char temp;

	while (scanf("%d %d", &m, &n) == 2 && m!=0) {
		scanf("%c", &temp);
		resultado=0;
		for (i=1; i<=m; i++) {
			for (j=1; j<=n; j++) {
				scanf("%c", &temp);
				if (temp!='0') {
					if (!posicao[i-1][j] && !posicao[i][j-1] && !posicao[i-1][j-1] && !posicao[i-1][j+1]) {
						resultado++;
					}
					posicao[i][j]=1;
				} else {
					posicao[i][j]=0;
				}
			}
			scanf("%c", &temp);
		}

		printf("Teste %d\nNumero de construcoes: %d\n", teste++, resultado);

	}
}
