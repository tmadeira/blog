//Triângulo
#include <stdio.h>
#define LMAX 101

int n, triangulo[LMAX][LMAX], cont=0, res[LMAX*LMAX];

int funcao(int soma, int lvl, int pos) {
	if (lvl==n) {
		res[cont]=soma;
		cont++;
		return(0);
	} else {
		soma+=triangulo[lvl+1][pos];
		funcao(soma,lvl+1,pos);
		soma-=triangulo[lvl+1][pos];
		soma+=triangulo[lvl+1][pos+1];
		funcao(soma,lvl+1,pos+1);
		soma-=triangulo[lvl+1][pos+1];
	}
}

int main() {
	int i, j, saida, maior=0;

	scanf("%d", &n);

	for (i=1; i<=n; i++) {
		for (j=1; j<=i; j++) {
			scanf("%d", &triangulo[i][j]);
		}
	}

	funcao(triangulo[1][1],1,1);

	for (i=0; i<cont; i++) {
		if (res[i]>maior) {
			maior=res[i];
		}
	}

	printf("%d\n", maior);
}
