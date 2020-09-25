//Meteoros - OBI2001
#include <stdio.h>

int main() {
	int x1, y1, x2, y2, i, teste=1, n, x, y, total;

	while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4 && (x1!=0||y1!=0||x2!=0||y2!=0)) {
		scanf("%d", &n);
		total=0;
		for (i=0; i<n; i++) {
			scanf("%d %d", &x, &y);
			if (x>=x1 && y<=y1 && x<=x2 && y>=y2) {
				total++;
			}
		}
		printf("Teste %d\n%d\n\n", teste++, total);
	}
}
