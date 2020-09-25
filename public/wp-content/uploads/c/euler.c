//Número de Euler
#include <stdio.h>
#include <math.h>

float potencia(float n, int expoente) {
	int i;
	float res;

	res=n;
	for (i=1; i<expoente; i++) {
		res=res*n;
	}

	return(res);
}

float funcao(float n) {
	float x, res;

	x=1+1/n;
	res=potencia(x,n);

	return(res);
}

int main() {
	int n, i;

	for (i=1; i<=2000000; i++) {
		printf("%f\n", funcao(i));
	}
}
