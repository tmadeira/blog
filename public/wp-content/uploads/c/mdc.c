//MDC (Máximo Divisor Comum)
#include <stdio.h>
#include <values.h>

#define NMAX 101

int mdc(int *n, int tam) {
	int i, menor, desista, j;

	menor=MAXINT;
	for (i=0; i<tam; i++) {
		if (n[i]<menor) {
			menor=n[i];
		}
	}

	for (i=menor; i>=1; i--) {
		desista=0;
		for (j=0; j<tam; j++) {
			if (n[j]%i) {
				desista=1;
				j=tam;
			}
		}
		if (!desista) {
			return i;
		}
	}

}

int main() {
	int n[NMAX], tam, i;

	printf("Digite o número de termos: ");
	scanf("%d", &tam);
	for (i=0; i<tam; i++) {
		printf("%do. número: ", i+1);
		scanf("%d", &n[i]);
	}

	printf("MDC = %d\n", mdc(n,tam));
}
