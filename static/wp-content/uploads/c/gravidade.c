//Cálculo da Força da Gravidade

#include <stdio.h>

long double potencia(float base, int expoente) {
	long double res;
	int i;

	res=base;
	if (expoente==0) {
		return 1;
	} else {
		if (expoente>0) {
			for (i=1; i<expoente; i++) {
				res*=base;
			}
		} else {
			for (i=1; i>expoente; i--) {
				res/=base;
			}
		}
	}
	return res;
}

int main() {
	long double m1, m2, d12, resultado, g=6.7;
	int expoente;
	
	printf("---\n");
	printf("Cálculo da Força da Gravidade\n");
	printf("Programa escrito por Tiago Madeira para facilitar as aulas de física\n");
	printf("---\n\n");
	printf("m1\n");
	printf("Valor sem notação: ");
	scanf("%Lf", &m1);
	printf("Expoente do 10: ");
	scanf("%d", &expoente);
	m1*=potencia(10, expoente);
	printf("m2\n");
	printf("Valor sem notação: ");
	scanf("%Lf", &m2);
	printf("Expoente do 10: ");
	scanf("%d", &expoente);
	printf("%d\n", expoente);
	m2*=potencia(10, expoente);
	printf("d12\n");
	printf("Valor sem notação: ");
	scanf("%Lf", &d12);
	printf("Expoente do 10: ");
	scanf("%d", &expoente);
	d12*=potencia(10, expoente);
	
	resultado=g*((m1*m2)/(d12*d12));
	expoente=-11;

	while (resultado>10) {
		resultado/=10;
		expoente++;
	}

	while (resultado<0) {
		resultado*=10;
		expoente--;
	}
	printf("\n---\nResultado: %.2Lf . 10 ^ %d\n", resultado, expoente);

	return 0;
}
