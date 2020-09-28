//Bits Trocados - OBI2000

#include <stdio.h>

int main() {
	int n, teste=1, d50, d10, d5;

	while (scanf("%d", &n) == 1 && n!=0) {
		d50=n/50;
		n%=50;
		d10=n/10;
		n%=10;
		d5=n/5;
		n%=5;
		printf("Teste %d\n%d %d %d %d\n\n", teste++, d50, d10, d5, n);
	}
}
