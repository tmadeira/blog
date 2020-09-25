//MDC (M�ximo Divisor Comum) entre dois n�meros
#include <stdio.h>

int mdc(int x, int y) {
	int i, menor;

	if (x<y) {
		menor=x;
	} else {
		menor=y;
	}

	for (i=menor; i>=1; i--) {
		if (!(x%i)&&!(y%i)) {
			return i;
		}
	}

	return 0;
}

int main() {
	int x, y;

	printf("Digite o primeiro n�mero: ");
	scanf("%d", &x);
	printf("Digite o segundo n�mero: ");
	scanf("%d", &y);

	printf("MDC ( %d , %d ) = %d\n", x, y, mdc(x,y));
}
