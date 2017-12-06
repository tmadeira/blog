//Number Triangles - USACO Training Gateway
//No início, tinha feito uma função recursiva. Não passou no tempo.
//Depois de 30min pensando, cheguei a conclusão de que é mais fácil
//ver a maior soma até cada ponto. Já fiz isso na hora em que
//acontece a entrada. Passou brincando nos testes com milésimos
//desprezíveis. =)

/*
ID: contato1
PROG: numtri
LANG: C
*/

#include <stdio.h>
#define LMAX 1001
 
int main() {
	int n, triangulo[LMAX][LMAX], maior=0;
	int i, j;
	FILE *in=fopen("numtri.in", "r");
	FILE *out=fopen("numtri.out", "w");

	fscanf(in, "%d", &n);
	for (i=1; i<=n; i++) {
		for (j=1; j<=i; j++) {
			fscanf(in, "%d", &triangulo[i][j]);
			if (triangulo[i-1][j-1]>triangulo[i-1][j]) {
				triangulo[i][j]+=triangulo[i-1][j-1];
			} else {
				triangulo[i][j]+=triangulo[i-1][j];
			}
		}
	}
	fclose(in);

	for (i=1; i<=n; i++) {
		if (triangulo[n][i]>maior) {
			maior=triangulo[n][i];
		}
	}
 
	fprintf(out, "%d\n", maior);
	fclose(out);
}
