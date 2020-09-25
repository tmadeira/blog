//Genoma

#include <stdio.h>
#define PMAX 15001
#define TMAX 15001

int main() {
	char inutil;
	int cont, temp, np, nt, teste=1, res[PMAX], tot, i, j, p[PMAX], t[TMAX];

	while (scanf("%d %d", &np, &nt) == 2 && np!=0) {
		scanf("%c", &inutil);
		for (i=1; i<=np; i++) {
			scanf("%c", &p[i]);
		}

		scanf("%c", &inutil);

		for (i=1; i<=nt; i++) {
			scanf("%c", &t[i]);
		}

		printf("Teste %d\n", teste++);

		cont=0;
		for (i=0; i<nt-1; i++) {
			tot=0;
			for (j=1; j<=np; j++) {
				if (p[j]==t[i+j]) {
					tot++;
				}
			}
			if (tot==np) {
				res[cont]=i+1;
				cont++;
			}
		}	

		printf("ocorrencia direta: ");
		for (i=0; i<cont-1; i++) {
			printf("%d ", res[i]);
		}
		printf("%d\n", res[cont-1]);

		for (i=1; i<=np; i++) {
			if (p[i]=='A') { p[i]='T'; }
			else if (p[i]=='T') { p[i]='A'; }
			else if (p[i]=='G') { p[i]='C'; }
			else if (p[i]=='C') { p[i]='G'; }
		}

		for (i=1; i<=np/2; i++) {
			if (!(np%2 && i==np/2)) {
			temp=p[i];
			p[i]=p[np-i+1];
			p[np-i+1]=temp;
			}
		}

		cont=0;
		for (i=0; i<nt; i++) {
			tot=0;
			for (j=1; j<=np; j++) {
				if (p[j]==t[i+j]) {
					tot++;
				}
			}
			if (tot==np) {
				res[cont]=i+1;
				cont++;
			}
		}	

		printf("ocorrencia complementar invertida: ");
		for (i=0; i<cont-1; i++) {
			printf("%d ", res[i]);
		}
		printf("%d\n", res[cont-1]);
	}
}
