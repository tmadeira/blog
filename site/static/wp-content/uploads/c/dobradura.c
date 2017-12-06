//Dobradura - OBI2002
#include <stdio.h>

int funcao(int n) {
	if (n==0) {
		return 2;
	} else {
		return funcao(n-1)+funcao(n-1)-1;
	}
}

int main() {
	int n, res, teste=1;

	while (scanf("%d", &n)&&n!=-1) {
		res=funcao(n);
		res*=res;
		printf("Teste %d\n%d\n\n", teste++, res);
	}
}
