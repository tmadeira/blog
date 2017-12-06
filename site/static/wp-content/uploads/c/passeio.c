//Passeio de Bicicleta

#include <stdio.h>
#include <values.h>
#define PMAX 151

int ligacao[PMAX][PMAX], p, i, altitude[PMAX], marc[PMAX], resultado;

int funcao(int loc) {
	int menor=MAXINT, nloc, j;
	if (loc!=i) {
		resultado++;
	}
	for (j=1; j<=p; j++) {
		if (ligacao[loc][j]>0) {
			if (ligacao[loc][j]<menor) {
				menor=ligacao[loc][j];
				nloc=j;
			}
		}
	}
	if (menor<MAXINT) {
		marc[loc]=1;
		funcao(nloc);
	}
}

int main() {
	int l, l1, l2, j, teste=1;

	while (scanf("%d %d %d", &p, &l, &i) == 3 && p!=0) {
		for (j=1; j<=p; j++) {
			scanf("%d", &altitude[j]);
		}
		for (j=1; j<=l; j++) {
			scanf("%d %d", &l1, &l2);
			ligacao[l1][l2]=altitude[l1]-altitude[l2];
		}

		resultado=0;
		funcao(i);

		printf("Teste %d\n%d\n\n", teste++, resultado);
	}
}
