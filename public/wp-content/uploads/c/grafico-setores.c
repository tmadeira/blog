//Gerador de Gráficos em Setores
#include <stdio.h>
#define NMAX 1001

int main() {
	int n, i;
	float valor[NMAX], vt;
	char rotulo[NMAX][50];

	printf("Qual o número de valores? ");
	scanf("%d", &n);

	vt=0;
	for (i=1; i<=n; i++) {
		printf("Rótulo (%2d): ", i);
		scanf("%s", rotulo[i]);
		printf("Valor  (%2d): ", i);
		scanf("%f", &valor[i]);
		vt+=valor[i];
	}

	printf("\nResultados:\n(graus que devem ser usados na confecção do gráfico)\n");
	for (i=1; i<=n; i++) {
		printf("%s: %.2f graus\n", rotulo[i], valor[i]*360/vt);
	}
}
