//Trem ou Caminhão? - OBI1999
#include <stdio.h>

int main() {
	int peso, teste=1;
	float caminhao[2], trem[2];

	while (scanf("%d", &peso)&&peso) {
		printf("Teste %d\n", teste++);
		scanf("%f %f %f %f", &caminhao[0], &caminhao[1], &trem[0], &trem[1]);
		if (caminhao[0]+caminhao[1]*peso<trem[0]+trem[1]*peso-1) {
			printf("envie por caminhao");
		} else {
			printf("envie por trem");
		}
		printf("\n\n");
	}
}
