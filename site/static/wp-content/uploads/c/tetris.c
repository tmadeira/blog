//Tetris - OBI2003
#include <stdio.h>
#include <values.h>
#include <string.h>
#define JMAX 1001
#define LMAX 16

int main() {
	int teste=1, j, i, k, l, res[JMAX], nres[JMAX], temp, menor, maior, jogada[13], o, ordem[JMAX];
	char nome[JMAX][LMAX], strtmp[LMAX];
	int pos[JMAX], pon[JMAX], posicaoigual[JMAX], primeiraposicao[JMAX];
	char nom[JMAX][LMAX];

	while (scanf("%d", &j)==1 && j!=0) {
		for (i=0; i<j; i++) {
			res[i]=0;
			nres[i]=0;
			scanf("%s", nome[i]);
			for (k=0; k<12; k++) {
				scanf("%d", &jogada[k]);
				res[i]+=jogada[k];
				nres[i]+=jogada[k];
			}
			menor=MAXINT;
			maior=0;
			for (k=0; k<12; k++) {
				if (jogada[k]>maior) {
					maior=jogada[k];
				}
				if (jogada[k]<menor) {
					menor=jogada[k];
				}
			}

			res[i]-=maior;
			res[i]-=menor;
			
		}

		for (i=0; i<j; i++) {
			posicaoigual[i]=0;
			maior=0;
			for (k=0; k<j; k++) {
				if (nres[k]>maior) {
					maior=res[k];
					o=k;
				}
			}
			ordem[i]=o;
			strcpy(nom[i],nome[o]);
			nres[o]=0;
		}

		for (i=0; i<j; i++) {
			pon[i]=res[ordem[i]];
			if (i==0) {
				pos[i]=1;
			} else {
				if (pon[i]==pon[i-1]) {
					pos[i]=pos[i-1];
					posicaoigual[pos[i]]++;
				} else {
					primeiraposicao[i+1]=i;
					pos[i]=i+1;
				}
			}
		}

		for (i=0; i<pos[j-1]; i++) {
			if (posicaoigual[i]) {
				for (l=primeiraposicao[i]; l<primeiraposicao[i]+posicaoigual[i]-1; l++) {
					if (!(strcmp(nom[l], nom[l+1])<0)) {
						strcpy(strtmp,nom[l+1]);
						strcpy(nom[l+1],nom[l]);
						strcpy(nom[l],strtmp);
					}
				}
			}
		}

		printf("Teste %d\n", teste++);
		for (i=0; i<j; i++) {
			printf("%d %d %s\n", pos[i], pon[i], nom[i]);
		}
		printf("\n");
	}
}
