//Função para calcular o MMC

#include <stdio.h>

int mmc(int *num, int ntermos) {
	int i, maior=0, a, j, c;

	//Descobrindo o maior número
	for (i=0; i<ntermos; i++) {
		if (num[i]>maior) {
			maior=num[i];
		}
	}

	for (i=1; c!=1; i++) {
		c=1;
		a=maior*i;
		//Verificando se o maior número vezes o i atual é divisível por todos números do conjunto
		for (j=0; j<ntermos; j++) {
			if (a%num[j]) {
				c=0;
			}
		}
	}

	return maior*(i-1); //Retornando resultado
}

int main() {
	int n[1001], nt, i;

	//Recebe número de termos
	printf("Quantos termos? ");
	scanf("%d", &nt);

	//Recebe números
	for (i=0; i<nt; i++) {
		printf("%d: ", i+1);
		scanf("%d", &n[i]);
	}

	//Chama a função e imprime o resultado
	printf("\nResultado: %d\n", mmc(n, nt));

	return 0;
}
