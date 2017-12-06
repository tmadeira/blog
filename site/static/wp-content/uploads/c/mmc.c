//Fun��o para calcular o MMC

#include <stdio.h>

int mmc(int *num, int ntermos) {
	int i, maior=0, a, j, c;

	//Descobrindo o maior n�mero
	for (i=0; i<ntermos; i++) {
		if (num[i]>maior) {
			maior=num[i];
		}
	}

	for (i=1; c!=1; i++) {
		c=1;
		a=maior*i;
		//Verificando se o maior n�mero vezes o i atual � divis�vel por todos n�meros do conjunto
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

	//Recebe n�mero de termos
	printf("Quantos termos? ");
	scanf("%d", &nt);

	//Recebe n�meros
	for (i=0; i<nt; i++) {
		printf("%d: ", i+1);
		scanf("%d", &n[i]);
	}

	//Chama a fun��o e imprime o resultado
	printf("\nResultado: %d\n", mmc(n, nt));

	return 0;
}
