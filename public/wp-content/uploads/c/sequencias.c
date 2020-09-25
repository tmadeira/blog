//Sequências - OBI1999

#include <stdio.h>

int main() {
	char car, inutil;
	int v[3], teste=1;

	v[0]=0;
	v[1]=0;
	v[2]=0;
	while (scanf("%c", &car)) {
		if (car!='#') {
			if (v[2]==2) {
				v[2]=0;
			}
			//printf("%d%d%d\n", v[0], v[1], v[2]);
			v[0]=v[1];
			v[1]=v[2];
			if (car=='0') {
				v[2]=0;
			} else if (car=='1') {
				v[2]=1;
			} else {
				v[2]=2;
			}
		} else {
			if (v[2]==2) {
				break;
			} else {
				printf("Teste %d\n", teste++);
				if (!v[2]&&!v[1]) {
					printf("sim");
				} else {
					printf("nao");
				}
				printf("\n\n");
				v[0]=0;
				v[1]=0;
				v[2]=0;
			}
		}
	}
}
