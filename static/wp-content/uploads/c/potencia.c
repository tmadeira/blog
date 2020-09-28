//Potência, cálculo com base e expoente
#include <stdio.h>
#include <math.h>

int potencia(int n, int x) {
	int i, res=n;
	for (i=1; i<x; i++) {
		res*=n;
	}
	return res;
}

int main() {
	int n, x;

	printf("Digite o número que você quer potencializar. ");
	scanf("%d", &n);
	printf("Digite o expoente. ");
	scanf("%d", &x);

	printf("%d\n", potencia(n, x));
}
