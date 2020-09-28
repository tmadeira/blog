//LCS - Longest Common Subsequence
//Programação Dinâmica - MSC - Maior Subcadeia Comum

#include <stdio.h>
#define SMAX 1001
#define DIAGONAL 1
#define LADO 2
#define CIMA 3


//n = tamanho de x
//m = tamanho de y

int c[SMAX][SMAX], b[SMAX][SMAX], n, m;
char x[SMAX], y[SMAX];

int lcs_recupera(int i, int j) {
	if (i==0||j==0) {
		return 0;
	}
	if (b[i][j]==DIAGONAL) {
		lcs_recupera(i-1, j-1);
		printf("%c", x[i]);
	} else if (b[i][j]==CIMA) {
		lcs_recupera(i-1, j);
	} else {
		lcs_recupera(i, j-1);
	}
}

int main() {
	int i, j;


	printf("LCS - Longest Common Subsequence\nPor Tiago Madeira\n\n");
	printf("Digite o tamanho da string X: ");
	scanf("%d", &m);
	printf("Digite o tamanho da string Y: ");
	scanf("%d", &n);

	scanf("%*c");
	printf("Digite a string X: ");
	for (i=1; i<=m; i++) {
		scanf("%c", &x[i]);
		c[i][0]=0;
	}
	scanf("%*c");
	printf("Digite a string Y: ");
	for (i=1; i<=n; i++) {
		scanf("%c", &y[i]);
		c[0][i]=0;
	}

	printf("\nPrograma raciocinando...\n");
	for (i=1; i<=m; i++) {
		for (j=1; j<=n; j++) {
			if (x[i]==y[j]) {
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=DIAGONAL;
			} else {
				if (c[i][j-1]>c[i-1][j]) {
					c[i][j]=c[i][j-1];
					b[i][j]=LADO;
				} else {
					c[i][j]=c[i-1][j];
					b[i][j]=CIMA;
				}
			}
		}
	}

/*	printf("\nMATRIX C\n");
	for (i=1; i<=m; i++) {
		for (j=1; j<=n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	printf("\nMATRIX B\n");
	for (i=1; i<=m; i++) {
		for (j=1; j<=n; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
*/

	lcs_recupera(m, n);
	printf("\n");
}

