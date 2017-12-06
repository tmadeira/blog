//Supermercado - OBI2003
#include <stdio.h>
#define SMAX 2001

int main() {
	//entrada
	int s, x, y;
	//loops
	int i, j, k, l;
	//desenvolvimento
	int g[SMAX][SMAX];
	int extreme_min_x, extreme_max_x, extreme_min_y, extreme_max_y;
	int menor, temp;
	//saida
	int teste=1, xmenor, ymenor;

	while (scanf("%d", &s)==1 && s!=0) {
		for (i=0; i<SMAX; i++) {
			for (j=0; j<SMAX; j++) {
				g[i][j]=0;
			}
		}

		extreme_min_x=2001;
		extreme_max_x=-1;
		extreme_min_y=2001;
		extreme_max_y=-1;
		for (i=1; i<=s; i++) {
			scanf("%d %d", &x, &y);
			x+=1000;
			y+=1000;
			g[x][y]=1;

			if (x<extreme_min_x) {
				extreme_min_x=x;
			}
			if (x>extreme_max_x) {
				extreme_max_x=x;
			}
			if (y<extreme_min_y) {
				extreme_min_y=y;
			}
			if (y>extreme_max_y) {
				extreme_max_y=y;
			}
		}

		menor=2001;
		for (i=extreme_min_x; i<=extreme_max_x; i++) {
			for (j=extreme_min_y; j<=extreme_max_y; j++) {
				temp=0;
				for (k=extreme_min_x; k<=extreme_max_x; k++) {
					for (l=extreme_min_y; l<=extreme_max_y; l++) {
						if (g[k][l]) {
							if (k>=i && l>=j) {
								temp+=(k-i)+(l-j);
							} else if (k<=i && l<=j) {
								temp+=(i-k)+(j-l);
							} else if (k<=i && l>j) {
								temp+=(i-k)+(l-j);
							} else if (k>i && l<=j) {
								temp+=(k-i)+(j-l);
							} else {
								printf("Erro fatal.\n");
							}
						}
					}
				}
				if (temp<menor) {
					menor=temp;
					xmenor=i;
					ymenor=j;
				}
			}
		}
		printf("Teste %d\n%d %d\n\n", teste++, xmenor-1000, ymenor-1000);
	}
}
