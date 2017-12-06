//Jogo do 7

#include <stdio.h>

int main() {
	int total, total2, recebido, enviado, i;

	total=0;
	i=1;
	printf("\n*** info: Jogo do Sete\n");
	printf("*** info: Desafio sugerido por Vavá.\n");
	printf("*** info: Algoritmo criado/implementado por Tiago Madeira.[0m\n\n");
	printf("*** info: REGRAS DO JOGO\n");
	printf("1. Na primeira jogada, o primeiro jogador escolhe um número no conjunto A={1,2,3,4,5,6,7} e diz.\n");
	printf("2. As pessoas jogam alternadamente.\n");
	printf("3. Cada pessoa ao jogar, escolhe um elemento de A, soma-o ao número dito pela pessoa anterior e diz.\n");
	printf("4. Ganha quem disser o número 63.\n\n");
	printf("Tiago fala: Você pode começar, mas se fizer besteira pode ter certeza de que eu ganharei! =)\n");
	printf("\n*** info: Início de jogo.\n");
	while (total<63) {
		printf("Você fala: ");
		scanf("%d", &total2);
		recebido=total2-total;
		if (recebido>7||recebido<1) {
			printf("Tiago fala: Seu ladrão! Não quero mais jogar com você! =(\n");
			break;
		}
		total=total2;
		if (total==63) {
			printf("*** info: Fim de jogo.\n*** info: Você ganhou.\n");
			printf("\nTiago fala: Muito bem. Apelou pois contra meu algoritmo é necessário, mas\nTiago fala: pelo menos parece ter entendido a lógica do jogo.\n");
			break;
		} else {
			enviado=(total+1)%8;
			if (enviado!=0) {
				total+=8-enviado;
			} else {
				if (i>7) {
					i=1;
				}
				total+=i;
				i+=2;
			}
			printf("Tiago fala: %d\n", total);
			if (total==63) {
				printf("*** info: Fim de jogo.\n*** info: Você perdeu.\n");
				printf("\nTiago fala: Eu já sabia... =D\n");
			}
		}
	}
	printf("\n");
}
