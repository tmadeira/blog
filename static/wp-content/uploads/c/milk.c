//Mixing Milk - USACO Training Gateway

/*
ID: contato1
PROG: milk
LANG: C
*/

#include <stdio.h>
#include <values.h>
#define MMAX 5001

int main() {
	long int n, m, p[MMAX], a[MMAX];
	long int quantidade=0, preco=0, cara, menor;
	int i;
	FILE *in=fopen("milk.in", "r");
	FILE *out=fopen("milk.out", "w");

	fscanf(in, "%d %d", &n, &m);
	for (i=1; i<=m; i++) {
		fscanf(in, "%d %d", &p[i], &a[i]);
	}
	fclose(in);

	while (quantidade<n) {
		menor=MAXINT;
		for (i=1; i<=m; i++) {
			if (p[i]<menor) {
				menor=p[i];
				cara=i;
			}
		}
		while (a[cara]>n-quantidade) {
			a[cara]--;
		}
		quantidade+=a[cara];
		preco+=p[cara]*a[cara];
		p[cara]=MAXINT;
	}

	fprintf(out, "%d\n", preco);

	fclose(out);
	return 0;
}

