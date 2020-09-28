//Insertion Sort, praticando

#include <stdio.h>

int main(void) {
	int j, i, key, v[11];

	for (j=2; j<12; j++) {
		printf("Entre com o %do. valor: ", j-1);
		scanf("%d", &key);
		i=j-1;
		while (i>0 && v[i]>key) {
			v[i+1]=v[i];
			i-=1;
		}
		v[i+1]=key;
	}
	
	printf("\nResultado:\n");
	
	for (i=1; i<=10; i++) {
		printf("%do. valor: %d\n", i, v[i]);
	}
}
