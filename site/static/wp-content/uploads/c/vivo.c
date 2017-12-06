//Vivo ou Morto - OBI2005
#include <stdio.h>
//Não sei qual o número máximo de jogadores!
#define NMAX 101

int main() {
	int jogador[NMAX], njogadores, nrodadas, i, j, k, vivos, ordem, fez;

	scanf("%d %d", &njogadores, &nrodadas);
	for (i=1; i<=njogadores; i++) {
		scanf("%d", &jogador[i]);
	}
	for (i=1; i<=nrodadas; i++) {
		scanf("%d %d", &vivos, &ordem);
		for (j=1; j<=vivos; j++) {
			scanf("%d", &fez);
			if (fez!=ordem) {
				jogador[j]=0;
			}
		}
		for (j=1; j<=vivos; j++) {
			if (!jogador[j]) {
				for (k=j; k<vivos; k++) {
					jogador[k]=jogador[k+1];
				}
			}
		}
	}
	printf("%d\n", jogador[1]);
}
