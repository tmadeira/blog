//Jogo de Cartas - OBI2006
#include <stdio.h>
#define NMAX 100001

int main() {
	int n;
	int proximo;
	int rodadas=0;
	int compra[NMAX];
	int i, j, tamanhoDaCompra;

	scanf("%d", &n);
	tamanhoDaCompra=n;

	for (i=0; i<n; i++) {
		scanf("%d", &compra[i]);
	}

	proximo=1;
	while (proximo<=n) {
		for (i=0; i<tamanhoDaCompra; i++) {
			if (compra[i]==proximo) {
				for (j=i; j<tamanhoDaCompra; j++) {
					compra[j]=compra[j+1];
				}
				tamanhoDaCompra--;
				proximo++;
				i--;
			}
		}
		rodadas++;
	}

	printf("%d\n", rodadas);
	
	return 0;
}

