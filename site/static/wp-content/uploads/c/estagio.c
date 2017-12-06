//Estágio - OBI2003
#include <stdio.h>
#define AMAX 1001

int main() {
	int n, i, teste=1, a[AMAX], no[AMAX], maior;

	while (scanf("%d", &n) == 1 && n!=0) {
		maior=0;
		for (i=0; i<n; i++) {
			scanf("%d %d", &a[i], &no[i]);
			if (no[i]>=maior) {
				maior=no[i];
			}
		}
		printf("Turma %d\n", teste++);
		for (i=0; i<n; i++) {
			if (no[i]==maior) {
				printf("%d ", a[i]);
			}
		}
		printf("\n\n");
	}
}
