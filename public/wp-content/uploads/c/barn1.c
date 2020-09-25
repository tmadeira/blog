//Barn Repair - USACO Training Gateway

/*
ID: contato1
PROG: barn1
LANG: C
*/

#include <stdio.h>
#include <values.h>
#define NMAX 201

int m, s, c, n[NMAX], cont[NMAX], co[NMAX], v[NMAX], contagem=0;

void maiores() {
	int i, j, maior, vencedor;

	v[0]=0;
	cont[0]=MININT;
	for (i=1; i<=m; i++) {
		maior=MININT;
		for (j=1; j<=s; j++) {
			if (cont[j]>maior) {
				maior=cont[j];
				vencedor=j;
			}
		}
		for (j=i-1; j>=0&&vencedor<v[j]; j--) {
			v[j+1]=v[j];
		}
		v[j+1]=vencedor;
		cont[vencedor]=MININT;
//		printf("%d\n", vencedor);
	}

}
	
int main() {
	int i, j, nu, ate;
	FILE *in=fopen("barn1.in", "r");
	FILE *out=fopen("barn1.out", "w");

	//Zerando vetores
	n[0]=1;
	for (i=1; i<NMAX; i++) {
		n[i]=0;
		cont[i]=0;
		co[i]=0;
	}

	//Entrada
	fscanf(in, "%d %d %d", &m, &s, &c);
	for (i=1; i<=c; i++) {
		fscanf(in, "%d", &nu);
		n[nu]=1;
	}
	fclose(in);

	//Desenvolvimento
	for (i=0; i<=s; i++) {
		ate=i;
		for (j=i+1; j<=s; j++) {
			if (n[i]&&!n[j]) {
				cont[i]++;
			} else {
				ate=j;
				j=s;
			}
		}
		co[i]=cont[i];
	}
	if (n[s]) cont[s]=MAXINT;

	maiores(m);

	for (i=1; i<=m; i++) {
		contagem+=v[i]-(co[v[i-1]]+v[i-1]);
		//printf("%d\n", contagem);
		
	}

	//Saída
	fprintf(out, "%d\n", contagem);
	fclose(out);

	return 0;
}
