//Vovô no Guiness
#include <stdio.h>
#define JMAX 101

int main() {
	int ndj, ndl, p, pont[JMAX], maior, i, j;

	while (scanf("%d %d", &ndl, &ndj)&&ndl&&ndj) {
		for (i=1; i<=100; i++) {
			pont[i]=0;
		}
		maior=0;
		for (i=0; i<ndl; i++) {
			for (j=0; j<ndj; j++) {
				scanf("%d", &p);
				pont[p]++;
				if (pont[p]>maior) {
					maior=pont[p];
				}
			}
		}
		for (i=1; i<=100; i++) {
			if (pont[i]==maior) {
				pont[i]=0;
			}
		}
		maior=0;
		for (i=1; i<=100; i++) {
			if (pont[i]>maior) {
				maior=pont[i];
			}
		}
		for (i=1; i<=100; i++) {
			if (pont[i]==maior) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
}
