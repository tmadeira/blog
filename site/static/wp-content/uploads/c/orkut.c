//Orkut - OBI2004
#include <stdio.h>
#define NMAX 31
#define LMAX 16

int naofazer, lan[NMAX], n, numerodeamigos, contlistaamigos, k, req[NMAX], teste=1, i, cont, namigo, atual, j, g[NMAX][NMAX], marc[NMAX][NMAX];
char nome[NMAX][LMAX], nomeatual[NMAX][LMAX], amigo[NMAX][LMAX];

int funcao() {
	for (j=1; j<=n; j++) {
		naofazer=0;
		for (i=0; i<contlistaamigos; i++) {
			if (lan[i]==j) {
				naofazer=1;
			}
		}
		
		for (i=0; i<contlistaamigos; i++) {
			if (g[j][lan[i]] && !marc[j][lan[i]]) {
				req[j]--;
				marc[j][lan[i]]=1;
			}
		}

		if (req[j]<=0 && !naofazer) {
			lan[contlistaamigos]=j;
			contlistaamigos++;
		}
	}
}

int main() {
	while (scanf("%d", &n) == 1 && n!=0) {
		contlistaamigos=0;
		for (i=1; i<=n; i++) {
			scanf("%s", nome[i]);
			for (j=1; j<=n; j++) {
				g[i][j]=0;
				marc[i][j]=0;
			}
		}
		for (i=1; i<=n; i++) {
			scanf("%s", nomeatual[i]);
			for (j=1; j<=n; j++) {
				if (!strcmp(nomeatual[i], nome[j])) {
					atual=j;
				}
			}
			scanf("%d", &numerodeamigos);
			req[atual]=numerodeamigos;

			if (numerodeamigos==0) {
				lan[contlistaamigos]=atual;
				contlistaamigos++;
			}
			for (j=1; j<=numerodeamigos; j++) {
				scanf("%s", amigo[j]);
				for (k=1; k<=n; k++) {
					if (!strcmp(amigo[j], nome[k])) {
						namigo=k;
					}
				}
				g[atual][namigo]=1;
			}
		}
		
		for (k=1; k<=n; k++) {
			funcao();
		}

		printf("Teste %d\n", teste++);
		if (contlistaamigos>=n-1) {
			for (i=0; i<contlistaamigos; i++) {
				printf("%s ", nome[lan[i]]);
			}
		} else {
			printf("impossivel");
		}
		printf("\n\n");
	}
}
