// Problema Binário da Mochila
// Outubro / 2005
// Tiago Madeira (c) tiagomadeira.net

// Complexidade: O(nW) - pseudo-polinomial

// Variáveis...
//
// n: Número de itens
// W: Peso máximo que a mochila aguenta
// w[i]: Peso do item "i"
// c[i]: Valor do item "i"
// z[k][d]: Valor máximo que a mochila pode carregar considerando N elementos e com peso W
// z[n][W]: Valor máximo que a mochila pode carregar considerando todos elementos e peso máximo;
// 	    solução do problema. (retorno da função)

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

	printf("Número de itens: ");
	scanf("%d", &n);

	printf("Peso máximo: ");
	scanf("%d", &W);

	for (i=1; i<=n; i++) {
		printf("Peso do item %d: ", i);
		scanf("%d", &w[i]);
		printf("Valor do item %d: ", i);
		scanf("%d", &c[i]);
	}

	printf("O máximo valor que você pode transportar é %d.\n", mochila(c, w, W, n));
	return 0;
}

