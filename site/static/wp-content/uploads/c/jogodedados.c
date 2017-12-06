//Jogo de Dados

#include <stdio.h>
#define JMAX 11

int main() {
	int teste=1, j, q, t1, t2, t3, pos[JMAX], anula[JMAX], d1, d2, ja, i, vencedor;
	int numerodejogadas;

	while (scanf("%d %d", &j, &q) == 2 && j!=0) {
		scanf("%d %d %d", &t1, &t2, &t3);
		ja=1;
		vencedor=0;
		q++;
		for (i=1; i<=j; i++) {
			pos[i]=0;
			anula[i]=0;
		}
		scanf("%d", &numerodejogadas);
		while (!vencedor) {
			if (anula[ja]==1) {
				anula[ja]=0;
			} else {
				scanf("%d %d", &d1, &d2);
				pos[ja]+=d1+d2;
				if (pos[ja]==t1 || pos[ja]==t2 || pos[ja]==t3) {
					pos[ja]=0;
					anula[ja]=1;
				}
				if (pos[ja]>=q) {
					vencedor=ja;
				}
			}
			ja++;
			if (ja>j) {
				ja-=j;
			}
		}

		printf("Teste %d\n%d\n\n", teste++, vencedor);
	}
}
