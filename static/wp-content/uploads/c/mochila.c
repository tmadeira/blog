// Problema Bin�rio da Mochila
// Outubro / 2005
// Tiago Madeira (c) tiagomadeira.net

// Complexidade: O(nW) - pseudo-polinomial

// Vari�veis...
//
// n: N�mero de itens
// W: Peso m�ximo que a mochila aguenta
// w[i]: Peso do item "i"
// c[i]: Valor do item "i"
// z[k][d]: Valor m�ximo que a mochila pode carregar considerando N elementos e com peso W
// z[n][W]: Valor m�ximo que a mochila pode carregar considerando todos elementos e peso m�ximo;
// 	    solu��o do problema. (retorno da fun��o)

#include <stdio.h>

#define NMAX 1001

int mochila(int c[], int w[], int W, int n) {
	int d, k, z[n+1][W+1];

	for (d=0; d<=k; d++) {
		z[0][d]=0;
	}

	for (k=1; k<=n; k++) {
		for (d=1; d<=W; d++) {
			z[k][d]=z[k-1][d];
			if (w[k]<=d && c[k]+z[k-1][d-w[k]]>z[k][d]) {
				z[k][d]=c[k]+z[k-1][d-w[k]];
			}
		}
	}

	return z[n][W];
}

int main() {
	int n, W, c[NMAX], w[NMAX], i;

	printf("N�mero de itens: ");
	scanf("%d", &n);

	printf("Peso m�ximo: ");
	scanf("%d", &W);

	for (i=1; i<=n; i++) {
		printf("Peso do item %d: ", i);
		scanf("%d", &w[i]);
		printf("Valor do item %d: ", i);
		scanf("%d", &c[i]);
	}

	printf("O m�ximo valor que voc� pode transportar � %d.\n", mochila(c, w, W, n));
	return 0;
}

