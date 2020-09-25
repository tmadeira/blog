//Número de Erdos - OBI2003
#include <stdio.h>
#include <string.h>
#define AUTMAX 101
#define LETMAX 20

int naut, lvl[AUTMAX], g[AUTMAX][AUTMAX];

int busca(int vertice, int level) {
	int i;
	for (i=1; i<naut; i++) {
		if (g[vertice][i]) {
			if (lvl[i]>level+1) {
				lvl[i]=level+1;
				busca(i, level+1);
			}
		}
	}

}

int main() {
	int teste=1, n, i, j, contn, id[AUTMAX], contla, ehnovo, autid, idsart[AUTMAX], contidsart, conta, menor, menorid;
	char autor[LETMAX], autores[AUTMAX][LETMAX], c, enter, sobrenome[AUTMAX][LETMAX];

	while (scanf("%d", &n) == 1 && n!=0) {
		scanf("%c", &enter);
		for (i=0; i<AUTMAX; i++) {
			for (j=0; j<AUTMAX; j++) {
				g[i][j]=0;
			}
		}
		strcpy(autores[0], "P. Erdos");
		naut=1;
		for (contn=0; contn<n; contn++) {
			contidsart=0;
			do {
				for (i=0; i<LETMAX; i++) {
					autor[i]=NULL;
				}
				scanf("%c", &autor[0]);
				scanf("%c", &autor[1]);
				scanf("%c", &c);
				contla=2;

				do {
					autor[contla]=c;
					contla++;
					scanf("%c", &c);
				} while (c!=',' && c!='.');

				scanf("%c", &enter);
			
				ehnovo=1;
				for (i=0; i<naut; i++) {
					if (!strcmp(autor,autores[i])) {
						autid=i;
						ehnovo=0;
					}
				}

				if (ehnovo) {
					strcpy(autores[naut],autor);
					autid=naut;
					naut++;
				}

				for (i=0; i<contidsart; i++) {
					g[autid][idsart[i]]=1;
					g[idsart[i]][autid]=1;
				}

				idsart[contidsart]=autid;
				lvl[autid]=200;
				contidsart++;

			} while (c!='.');
		}

		busca(0,0);

		for (i=1; i<naut; i++) {
			conta=3;
			while (autores[i][conta]!='\0') {
				sobrenome[i][conta-3]=autores[i][conta];
				conta++;
			}
		}

		for (i=1; i<naut; i++) {
			menor=-10000;
			for (j=1; j<naut; j++) {
				if (strcmp("Tiago", sobrenome[j])>menor) {
					menor=strcmp("Tiago", sobrenome[j]);
					menorid=j;
				} else if (strcmp("Tiago", sobrenome[j])==menor) {
					if (strcmp(autores[j], autores[menorid])<0) {
						menorid=j;
					}
				}
			}
			strcpy(sobrenome[menorid], "Zzzzzzzzzzzzzzzzz");
			id[i]=menorid;
		}

		printf("Teste %d\n", teste++);
		for (i=1; i<naut; i++) {
			printf("%s: ", autores[id[i]]);
			if (lvl[id[i]]==200) {
				printf("infinito\n");
			} else {
				printf("%d\n", lvl[id[i]]);
			}
		}
		printf("\n");
	}
}
