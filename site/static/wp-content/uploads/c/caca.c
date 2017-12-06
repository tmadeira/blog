//Caça ao Tesouro - OBI2002
#include <stdio.h>
#define NMAX 101
int res, valor[NMAX], n;

int funcao(int loop, int x, int y) {

	if (loop<n) {
		funcao(loop+1, x+valor[loop], y);
		funcao(loop+1, x, y+valor[loop]);
	} else {
		if (x==y) {
			res=1;
		}
	}
}


int main() {
	int teste=1, x, y, i;

	while (scanf("%d %d %d", &x, &y, &n)==3 && n!=0) {
		res=0;
		for (i=0; i<n; i++) {
			scanf("%d", &valor[i]);
		}
		funcao(0, x, y);
		printf("Teste %d\n", teste++);
		if (res) {
			printf("S\n\n");
		} else {
			printf("N\n\n");
		}
	}
}

