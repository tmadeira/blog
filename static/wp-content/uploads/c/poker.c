//Mini-poker - OBI2005
#include <stdio.h>

int pontuacao(int c[]) {
	//Regra I
	if (c[1]==c[2]-1&&c[2]==c[3]-1&&c[3]==c[4]-1&&c[4]==c[5]-1) {
		return 200+c[1];
	}

	//Regra II
	if (c[1]==c[4]||c[2]==c[5]) {
		return 180+c[2];
	}

	//Regra III
	if ((c[1]==c[3]&&c[4]==c[5])||(c[3]==c[5]&&c[1]==c[2])) {
		return 160+c[3];
	}

	//Regra IV
	if (c[1]==c[3]||c[2]==c[4]||c[3]==c[5]) {
		return 140+c[3];
	}

	//Regra V
	if ((c[1]==c[2]&&c[4]==c[5])) {
		if (c[1]>c[4]) {
			return 3*c[1]+2*c[4]+20;
		} else {
			return 3*c[4]+2*c[1]+20;
		}
	}
	if ((c[1]==c[2]&&c[3]==c[4])) {
		if (c[1]>c[3]) {
			return 3*c[1]+2*c[3]+20;
		} else {
			return 3*c[3]+2*c[1]+20;
		}
	}
	if ((c[2]==c[3]&&c[4]==c[5])) {
		if (c[2]>c[4]) {
			return 3*c[2]+2*c[4]+20;
		} else {
			return 3*c[4]+2*c[2]+20;
		}
	}

	//Regra VI
	if (c[1]==c[2]||c[2]==c[3]) {
		return c[2];
	}
	if (c[3]==c[4]||c[4]==c[5]) {
		return c[4];
	}
	
	//Regra VII
	return 0;
}

int main() {
	int n, teste, c[6], carta, i, j;

	scanf("%d", &n);
	for (teste=1; teste<=n; teste++) {
		//Pega os valores e faz um Insertion Sort
		for (i=1; i<=5; i++) {
			scanf("%d", &carta);
			for (j=i-1; j>0&&c[j]>carta; j--) {
				c[j+1]=c[j];
			}
			c[j+1]=carta;
		}
		
		printf("Teste %d\n%d\n\n", teste, pontuacao(c));
	}

	return 0;
}



