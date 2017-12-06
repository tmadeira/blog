//Restaurante - OBI1999

#include <stdio.h>
#define NMAX 5001

int main() {
	int e[NMAX], s[NMAX], n, i, teste=1, pessoas;

	while (scanf("%d", &n)&&n) {
		for (i=0; i<n; i++) {
			scanf("%d", &s[i]);
		}
		for (i=0; i<n; i++) {
			scanf("%d", &e[i]);
		}
		pessoas=0;
		for (i=0; i<n; i++) {
			if (e[i]>s[n-i-1]&&(n-i)>pessoas) {
				pessoas=n-i;
			}
		}
		
		printf("Teste %d\npessoas: %d\n\n", teste++, pessoas);
	}
}
