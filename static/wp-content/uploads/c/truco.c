//Truco - OBI2006
#include <stdio.h>

int main() {
	int n;
	int i, j;
	int a[4], b[4];
	int tadalberto, tbernardete;
	int adalberto, bernardete;

	scanf("%d", &n);
	adalberto=0;
	bernardete=0;

	for (i=0; i<n; i++) {
		tadalberto=0;
		tbernardete=0;
		scanf("%d %d %d %d %d %d", &a[1], &a[2], &a[3], &b[1], &b[2], &b[3]);
		for (j=1; j<=3; j++) {
			// Tornando as cartas "comparáveis"...
			if (a[j]==12) {
				a[j]=8;
			} else if (a[j]==11) {
				a[j]=9;
			} else if (a[j]==13) {
				a[j]=10;
			}

			if (b[j]==12) {
				b[j]=8;
			} else if (b[j]==11) {
				b[j]=9;
			} else if (b[j]==13) {
				b[j]=10;
			}

			if (a[j]<4) {
				a[j]+=10;
			}
			if (b[j]<4) {
				b[j]+=10;
			}
	
			if (a[j]>=b[j]) {
				tadalberto++;
			} else {
				tbernardete++;
			}
		}
		if (tadalberto>tbernardete) {
			adalberto++;
		} else {
			bernardete++;
		}
	}

	printf("%d %d\n", adalberto, bernardete);
	
	return 0;
}

