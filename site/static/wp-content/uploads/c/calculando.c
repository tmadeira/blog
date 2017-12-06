//Calculando - OBI2001

#include <stdio.h>
#define MMAX 101

int main() {
	unsigned int teste=1, m, n[MMAX];
	int res, i;
	char s[MMAX];

	while (scanf("%d", &m)==1 && m!=0) {
		for (i=0; i<m; i++) {
			scanf("%d%c", &n[i], &s[i]);
		}

		res=n[0];

		for (i=0; i<m-1; i++) {
			if (s[i]=='+') {
				res+=n[i+1];
			} else {
				res-=n[i+1];
			}
		}
		printf("Teste %d\n%d\n\n", teste++, res);
	}
}
