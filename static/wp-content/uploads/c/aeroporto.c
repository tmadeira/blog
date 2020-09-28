//Aeroporto - OBI2002

#include <stdio.h>
#define AMAX 101

int main() {
	int a, v, i, teste=1, maior, t[AMAX], orig, dest, o;

	while (scanf("%d %d", &a, &v)&&a!=0) {
		
		maior=0;
		
		for (i=1; i<=a; i++) {
			t[i]=0;
		}
		
		// ENTRADA
		for (i=1; i<=v; i++) {
			scanf("%d %d", &orig, &dest);
			t[orig]++;
			t[dest]++;
		}
		
		// CÁLCULOS
		for (i=1; i<=a; i++) {
			if (t[i]>=maior) {
				maior=t[i];
				o=i;
			}
		}

		// SAÍDA
		printf("Teste %d\n", teste++);
		for (i=1; i<=a; i++) {
			if (i!=o) {
				if (t[i]==maior) {
					printf("%d ", i);
				}
			}
		}

		printf("%d\n\n", o);
	}

	return 0;
}
