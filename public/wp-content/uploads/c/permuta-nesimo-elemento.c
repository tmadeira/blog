//Descobrindo o n-ésimo elemento de uma permutação
#include <stdio.h>
#define NMAX 10

int fatorial(int n) {
	int i, res=1;

	for (i=2; i<=n; i++) {
		res*=i;
	}

	return res;
}

int descobre(int x, int resto) {
	int i, n=x, a;
	char pos[NMAX];

	for (i=0; i<=x; i++) {
		pos[i]=i+65;
	}

	for (; x>=0; x--) {
		a=resto/fatorial(x);
		resto%=fatorial(x);
		printf("%c ", pos[a]);
		for (i=a; i<=n; i++) {
			pos[i]=pos[i+1];
		}
	}
	printf("\n");
}

int main() {
	int n, p;

	printf("Número de elementos da permutação (máximo: 9): ");
	scanf("%d", &n);
	printf("Posição que você quer: ");
	scanf("%d", &p);
	descobre(n-1, p-1);
}
