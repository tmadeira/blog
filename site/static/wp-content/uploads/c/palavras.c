//Palavras Cruzadas - OBI1999

#include <stdio.h>
#define NMAX 102

int nu[NMAX][NMAX], proximonumero;
char mt[NMAX][NMAX];

int numera(i, j) {
	if (!nu[i][j]) {
		nu[i][j]=proximonumero++;
		//printf("É numerada a coordenada %d %d com %d.\n", i, j, nu[i][j]);
	}
}

int main() {
	int n, m, i, j, k, teste=1, vertical, horizontal;
	char enter;

	while (scanf("%d %d", &n, &m)&&n) {
		//imprime o número do teste
		printf("Teste %d\n", teste++);
		//zera as matrizes
		for (i=0; i<=n+1; i++) {
			for (j=0; j<=m+1; j++) {
				mt[i][j]='*';
				nu[i][j]=0;
			}
		}
		//pega o enter
		scanf("%c", &enter);
		//pega os chars e coloca na matriz
		for (i=1; i<=n; i++) {
			for (j=1; j<=m; j++) {
				scanf("%c", &mt[i][j]);
			}
			scanf("%c", &enter);
		}
		//define o proximo numero pra 1
		proximonumero=1;
		vertical=0;
		horizontal=0;
		//numera a matriz
		for (i=1; i<=n; i++) {
			for (j=1; j<=m; j++) {
				if (mt[i][j]!='*') {
					if (mt[i][j-1]=='*'&&mt[i][j+1]!='*') {
						numera(i, j);
						horizontal=1;
					}
					if (mt[i-1][j]=='*'&&mt[i+1][j]!='*') {
						numera(i, j);
						vertical=1;
					}
				}
			}
		}
		//imprime palavras horizontais
		if (horizontal) {
			printf("Horizontais:\n");
			for (i=1; i<=n; i++) {
				for (j=1; j<=m; j++) {
					if (mt[i][j]!='*'&&mt[i][j-1]=='*'&&mt[i][j+1]!='*') {
						printf("  %d. ", nu[i][j]);
						for (k=j; mt[i][k]!='*'; k++) {
						       printf("%c", mt[i][k]);
						}
				 		printf("\n");
					}
				}
			}
		}

		//imprime palavras verticais
		if (vertical) {
			printf("Verticais:\n");
			for (i=1; i<=n; i++) {
				for (j=1; j<=m; j++) {
					if (mt[i][j]!='*'&&mt[i-1][j]=='*'&&mt[i+1][j]!='*') {
					       printf("  %d. ", nu[i][j]);
					       for (k=i; mt[k][j]!='*'; k++) {
						       printf("%c", mt[k][j]);
					       }
					       printf("\n");
					}
				}
			}
		}

		//enter
		printf("\n");
	}
}
