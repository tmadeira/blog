//Torres de Hanói - OBI2003

#include <stdio.h>

long int potencia(int n, int x) {
	register int i;
	long int res=n;
	for (i=1; i<x; i++) {
		res*=n;
	}
	return res;
}

int main() {
	int n, teste=1;

	while (scanf("%d", &n)==1 && n!=0) {
		printf("Teste %d\n%d\n\n", teste++, potencia(2, n)-1);
	}
}
