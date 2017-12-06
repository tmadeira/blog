//Prime Palindromes - USACO Training Gateway
//Tiago Madeira (c)

//Agora eu sei que dá pra fazer com custo bem menor,
//mas esse aí rolou na boa com 0.05 segundos.

/*
ID: contato1
PROG: pprime
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int eh_primo(long int num) {
	int i;
	
	for (i=3; i*i<=num; i+=2) {
		if (!(num%i)) {
			return 0;
		}
	}

	return 1;
}

int main() {
	int i, j, k, l, cont=0;
	long int numero, min, max, v[10000];

	FILE *in=fopen("pprime.in", "r");
	FILE *out=fopen("pprime.out", "w");
	fscanf(in, "%d %d", &min, &max);
	fclose(in);

	v[cont++]=5;
	v[cont++]=7;
	for (i=1; i<=9; i+=2) {
		numero=i*10+i;
		if (eh_primo(numero)) {
			v[cont++]=numero;
		}
	}
	for (i=1; i<=9; i+=2) {
		for (j=0; j<=9; j++) {
			numero=i*100+j*10+i;
			if (eh_primo(numero)) {
				v[cont++]=numero;
			}
		}
	}
	for (i=1; i<=9; i+=2) {
		for (j=0; j<=9; j++) {
			for (k=0; k<=9; k++) {
				numero=i*10000+j*1000+k*100+j*10+i;
				if (eh_primo(numero)) {
					v[cont++]=numero;
				}
			}
		}
	}
	for (i=1; i<=9; i+=2) {
		if (i==5) {
			i=7;
		}
		for (j=0; j<=9; j++) {
			for (k=0; k<=9; k++) {
				for (l=0; l<=9; l++) {
					numero=i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
					if (eh_primo(numero)) {
						v[cont++]=numero;
					}
				}
			}
		}
	}
	for (i=0; i<cont; i++) {
		if (v[i]>=min&&v[i]<=max) {
			fprintf(out, "%d\n", v[i]);
		} else if (v[i]>max) {
			fclose(out);
			return 0;
		}
	}
	fclose(out);
	return 0;
}
