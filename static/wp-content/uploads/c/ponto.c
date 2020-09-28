//Descobrir se um ponto está dentro ou fora de um polígono
//Colocando em prática algoritmos geométricos

#include <stdio.h>

//Determinei que o número máximo de coordenadas vai ser 1000. Mas se quiser
//aumentar, fique a vontade.
#define CMAX 1001

float xi[CMAX], yi[CMAX], x, y, xu, yu, a, b;
int n, contx, conty, res=0;

int main() {
	int i;

	printf("Digite a coordenada do ponto que você deseja descobrir se está dentro ou fora do polígono: ");
	scanf("%f %f", &x, &y);

	printf("Digite o número de vértices do polígono: ");
	scanf("%d", &n);

	for (i=0; i<n; i++) {
		printf("Digite as coordenadas do %do. vértice: ", i+1);
		scanf("%f %f", &xi[i], &yi[i]);
	}

	printf("\nAguarde o programa pensar um pouco...\n\n");

	for (i=0; i<n; i++) {
		if (i==n-1) {
			yu=yi[0];
			xu=xi[0];
		} else {
			yu=yi[i+1];
			xu=xi[i+1];
		}
		if ((xi[i]>x||xu>x)&&((yi[i]>y&&y>yu)||(yu>y&&y>yi[i]))) {
			a=(yi[i]-yu)/(xi[i]-xu);
			b=yi[i]-xi[i]*a;
			if (a*x+b>y) {
				res++;
			}
		}
	}

	if (res%2) {
		printf("Tá dentro!\n");
	} else {
		printf("Tá fora!\n");
	}

}

