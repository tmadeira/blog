//Escada Perfeita - OBI2006
#include <stdio.h>
#define PMAX 10001

int main() {
	int i, j;
	int n;
	int soma=0;
	int a, b;
	int pilha[PMAX];
	int moves=0;
	int movimentos=0;

	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%d", &pilha[i]);
		soma+=pilha[i];
	}

	b=(((2*soma)/n)+(n-1))/2;
	a=1+b-n;

	for (i=0; i<n; i++) {
		moves+=(pilha[i]-(i+a));
		if (pilha[i]>i+a) {
			movimentos+=(pilha[i]-(i+a));
		}
	}

	if (moves!=0) {
		printf("-1\n");
	} else {
		printf("%d\n", movimentos);
	}

	return 0;
}

