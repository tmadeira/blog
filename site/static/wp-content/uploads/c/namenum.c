//Name That Number - USACO Training Gateway 2006

/*
ID: contato1
PROG: namenum
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define NMAX 8
#define NLMAX 3
#define LMAX 13

int c=0, co=0, f=0;
int l[NMAX][NLMAX];
char old[LMAX], string[LMAX], numeros[LMAX], d[10000][LMAX];
char p[LMAX];
FILE *out;

int ctoi(char c) {
	return c-48;
}

void permuta(int n) {
	int i;
	int nu=ctoi(numeros[n]);

	if (n<c) {
		for (i=0; i<=2; i++) {
//			printf("[%d][%d] %c\n", nu, i, l[nu][i]);
			p[n]=l[nu][i];
			permuta(n+1);
		}
	} else {
		for (i=0; i<co; i++) {
			if (!strcmp(p, d[i])) {
				fprintf(out, "%s\n", p);
				f=1;
			}
		}
	}
}

main() {
	// Variáveis do Main
	int n, i, j, v, pot=1;
	
	// Abrindo arquivos...
	FILE *in=fopen("namenum.in", "r");
	FILE *dic=fopen("dict.txt", "r");
	out=fopen("namenum.out", "w");
	
	// Segundo as regras do programa...
	// Convertendo os caracteres para ASCII
	l[0][0]=65; l[0][1]=66; l[0][2]=67; l[1][0]=68; l[1][1]=69; l[1][2]=70; l[2][0]=71; l[2][1]=72; l[2][2]=73; l[3][0]=74; l[3][1]=75; l[3][2]=76; l[4][0]=77; l[4][1]=78; l[4][2]=79; l[5][0]=80; l[5][1]=82; l[5][2]=83; l[6][0]=84; l[6][1]=85; l[6][2]=86; l[7][0]=87; l[7][1]=88; l[7][2]=89;

	// Entrada
	fscanf(in, "%s", string);
	fclose(in);

	c=strlen(string);
	for (i=0; i<c; i++) {
		numeros[i]=string[i]-2;
	}

	i=0;
	do {
		fscanf(dic, "%s", string);
		if (!strcmp(old, string)) {
			break;
		}
		if (strlen(string)==c) {
			strcpy(d[i++], string);
//			printf("%s\n", string);
		}
		strcpy(old, string);
	} while (1);
	co=i;

	permuta(0);

	if (!f) {
		fprintf(out, "NONE\n");
	}
	
	fclose(dic);
	fclose(out);
	return 0;
}

