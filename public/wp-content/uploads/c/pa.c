//Aplicar as fórmulas das PAs

//Progressão Aritmética
//Programa desenvolvido por Tiago Madeira (c) 2005.

#include <stdio.h>
#define MAX 1000001

long double a[MAX], s[MAX];

int main() {
	long double r;
	int n;

	printf("Primeiro termo da PA: ");
	scanf("%Lf", &a[1]);
	printf("Razão da PA: ");
	scanf("%Lf", &r);

	//Eu podia fazer só pros que vão ser usados, mas não sei porquê, deu vontade de fazer assim... =)
	printf("\nAguarde o problema raciocinar tudo que ele tem para raciocinar...\n");
	for (n=2; n<MAX; n++) {
		a[n]=a[1]+r*(n-1);
		s[n]=(a[1]+a[n])*n/2;
	}
	
	printf("\nE agora, digite números para o programa dizer A e S dele.\n");
	do {
		printf("Número: ");
		scanf("%d", &n);
		if (!n) {
			break;
		}
		printf("Número na posição N = %.Lf\nSoma de 1 a N = %.Lf\n\n", a[n], s[n]);
	} while (n);

}

