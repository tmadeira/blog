//MMC do jeito que as pessoas tiram geralmente

#include <stdio.h>
int res[10000], co=0;

int mmc(int *n, int nt) {
	int i, k, dv, at;

	for (i=0; i<nt-1; i++) {
		printf("%d, ", n[i]);
	}
	printf("%d | ", n[nt-1]);

	dv=0;
	for (i=2; !dv&&at!=nt; i++) {
		dv=0;
		at=0;
		for (k=0; k<nt; k++) {
			if (!(n[k]%i)) {
				dv=1;
				n[k]/=i;
			} else if (n[k]==1) {
				at+=1;
			}
		}
		if (dv) {
			printf("%d\n", i);
			res[co++]=i--;
		}
	}

	if (at==nt) {
		return 1;
	} else {
		return i*mmc(n, nt);
	}
}

int main(void) {
	int n[1001], nt, i, resultado;

	printf("MMC - Mínimo Múltiplo Comum\n");
	printf("http://tableless.tiagomadeira.net/script/mmc-comum.c\n\n");
	
	printf("Este programa calcula o MMC de vários termos inteiros que você especifica.\n");
	printf("Foi criado por Tiago Madeira usando um algoritmo semelhante ao que os professores\n");
	printf("de matemática ensinam nas escolas.\n\n");

	printf("De quantos números você quer calcular o MMC? ");
	scanf("%d", &nt);
	for (i=0; i<nt; i++) {
		printf("Digite o %d. número: ", i+1);
		scanf("%d", &n[i]);
	}
	printf("\n");

	printf("Para você calcular o MMC de vários termos, basta você ir dividindo eles por primos\n");
	printf("até todos se tornarem o número 1 (um). O programa faz isto exatamente como você\n");
	printf("faria. Acompanhe o cálculo abaixo:\n\n");

	resultado=mmc(n, nt);
	printf("X\n\n", resultado);
	for (i=0; i<co-1; i++) {
		printf("%d . ", res[i]);
	}
	printf("%d = %d\n", res[co-1], resultado);

	printf("Ou seja, o menor número que é divisível por todos os números que você colocou é\n");
	printf("este. Isto tem grandes utilidades e uma delas (talvez a mais utilizada) é fazer\n");
	printf("cálculos com frações de denominadores diferentes.\n\n");

	printf("Observação: Este cálculo é a maneira com que as pessoas costumam aprender, mas\n");
	printf("desenvolvi um outro programa que (além de falar menos) tem um custo menor\n");
	printf("(calcula de forma mais rápida). Ele está disponível em\n");
	printf("http://tableless.tiagomadeira.net/script/mmc.c\n");

	return 0;
}
