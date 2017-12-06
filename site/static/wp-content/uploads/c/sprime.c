//Superprime Rib - USACO Training Gateway - 2005

/*
ID: contato1
PROG: sprime
LANG: C
*/

#include <stdio.h>
#define NMAX 9
#define INFINITO 100000

int primos[NMAX][INFINITO], cont[NMAX];

int eh_primo(long int num) {
	int i;

	if (num==1||(!(num%2)&&num!=2)) {
		return 0;
	}

	for (i=3; i*i<=num; i+=2) {
		if (!(num%i)) {
			return 0;
		}
	}

	return 1;
}

void funcao(int n) {
	int i, j, num;

	cont[n]=0;

	if (n>1) {
		funcao(n-1);

		for (i=0; i<cont[n-1]; i++) {
			for (j=1; j<=9; j+=2) {
				num=primos[n-1][i]*10+j;
				if (eh_primo(num)) {
					primos[n][cont[n]++]=num;
				}
			}
		}
	} else {
		primos[1][0]=2;
		primos[1][1]=3;
		primos[1][2]=5;
		primos[1][3]=7;
		cont[1]=4;
	}
}

int main() {
	int n, i;

	FILE *in=fopen("sprime.in", "r");
	FILE *out=fopen("sprime.out", "w");
	fscanf(in, "%d", &n);
	fclose(in);

	funcao(n);

	for (i=0; i<cont[n]; i++) {
		fprintf(out, "%d\n", primos[n][i]);
	}
	fclose(out);

	return 0;
}


