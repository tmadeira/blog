//Graph Connectivity - UVA - durante Curso da OBI

#include <stdio.h>
#include <string.h>
#include <values.h>

#define LM 100

int l[LM][LM], max, c[LM], marc[LM], part[LM], pc;

int bp(int v, int pai) {
	int i, w;

	marc[v]=1;
	part[pc++]=v;

	for (i=0; i<c[v]; i++) {
		w=l[v][i];
		if (!marc[w]) {
			bp(w, v);
		}
	}
}

int main() {
	int n, n1, n2, menor;
	int i, cont, j; // Loops
	int resultado=0, menores[LM], diferente; // Final e saÃda

	scanf("%d\n\n", &n);
	printf("NÃºúme %d\n", n);

	for (cont=0; cont<n; cont++) {
		memset(c, 0, sizeof(c));
		memset(part, 0, sizeof(part));
		scanf("%[A-Z]\n", &max);
		max-=64;
		printf("MAX %d\n", max);

		while (1) {
			scanf("%1[A-Z\n]", &n1);
			if (n1<65) {
				break;
			}
			scanf("%1[A-Z]\n", &n2);
			printf("%c %c = %d %d\n", n1, n2, n1, n2);
			n1-=65;
			n2-=65;
			l[n1][c[n1]++]=n2;
			l[n2][c[n2]++]=n1;
		}

		resultado=0;

		for (i=0; i<max; i++) {
			memset(marc, 0, sizeof(marc));
			pc=0;
			menor=MAXINT;
			bp(i, -1);
			for (j=0; j<pc; j++) {
				if (part[j]<menor) {
					menor=part[j];
				}
			}
			diferente=1;
			for (j=0; j<resultado; j++) {
				if (menor==menores[j]) {
					diferente=0;
					j=resultado;
				}
			}
			if (diferente) {
				menores[resultado++]=menor;
			}
		}

		printf("%d\n", resultado);
	}

	return 0;
}
