//Par ou Ímpar?

#include <stdio.h>
#define LMAX 11

int main() {
	char jogador[3][LMAX];
	int n, jogada[3], teste=1, i;

	while (scanf("%d", &n)&&n) {
		scanf("%s", jogador[1]);
		scanf("%s", jogador[2]);
		printf("Teste %d\n", teste++);
		for (i=1; i<=n; i++) {
			scanf("%d %d", &jogada[1], &jogada[2]);
			if ((jogada[1]+jogada[2])%2) {
				printf("%s", jogador[2]);
			} else {
				printf("%s", jogador[1]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
