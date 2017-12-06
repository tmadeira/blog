//Torres de Hanói, implementando
#include <stdio.h>
int cont=0;

int hanoi(int n, int o, int i, int d) {
	if (n==1) {
		printf("%d -> %d\n", o, d);
	} else {
		hanoi(n-1, o, d, i);
		printf("%d -> %d\n", o, d);
		hanoi(n-1, i, o, d);
	}
	cont++;
}

int main() {
	int n;
	printf("Digite o número de pinos: ");
	scanf("%d", &n);
	hanoi(n, 1, 2, 3);
	printf("Total de Vezes: %d\n", cont);
}
