//Palíndrome
#include <stdio.h>
#define NMAX 2001

char v[NMAX];
int n, res;

int funcao(int min, int max) {
	int i, refaz;

	refaz=0;
	for (i=min; i<=max; i++) {
		//printf("Analisando %d com %d...\n", i, max-i);
		if (v[i]!=v[max-i+min]) {
			refaz=1;
			break;
		}
	}

	if (refaz) {
		//printf("Chamando função de %d para %d.\n", min, max-1);
		funcao(min, max-1);
	} else {
		//printf("De %d a %d existe um palindromo.\n", min, max);
		res++;
		if (max!=n-1) {
			//printf("Chamando função de %d para %d.\n", max+1, n-1);
			funcao(max+1, n-1);
		}
	}
}

int main() {
	int teste=1, i;
	char in;

	while (scanf("%d", &n)==1 && n!=0) {
		scanf("%c", &in);
		for (i=0; i<n; i++) {
			scanf("%c", &v[i]);
		}
		scanf("%c", &in);
		
		res=0;
		funcao(0, n-1);

		printf("Teste %d\n%d\n\n", teste++, res);
	}
}
