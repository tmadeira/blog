//Proteja sua Senha
#include <stdio.h>

int main() {
	int teste=1, j, res[7], n, letra[7][10], l[6][3], i, cont, le;
	char c, in;

	while (scanf("%d", &n) == 1 && n!=0) {
		for (i=1; i<=6; i++) {
			for (j=0; j<=9; j++) {
				letra[i][j]=0;
			}
		}
		for (cont=1; cont<=n; cont++) {
			for (i=1; i<=5; i++) {
				scanf("%d %d", &l[i][1], &l[i][2]);
			}
			for (i=1; i<=6; i++) {
				scanf("%c%c", &in, &c);
				if (c=='A') {
					le=1;
				} else if (c=='B') {
					le=2;
				} else if (c=='C') {
					le=3;
				} else if (c=='D') {
					le=4;
				} else if (c=='E') {
					le=5;
				}

				letra[i][l[le][1]]++;
				letra[i][l[le][2]]++;
			}
		}
		
		for (i=1; i<=6; i++) {
			for (j=0; j<=9; j++) {
				if (letra[i][j]==n) {
					res[i]=j;
				}
			}
		}

		printf("Teste %d\n", teste++);
		for (i=1; i<=5; i++) {
			printf("%d ", res[i]);
		}
		printf("%d\n\n", res[6]);
	}
}
