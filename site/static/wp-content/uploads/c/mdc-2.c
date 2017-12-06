//MDC (Máximo Divisor Comum) entre dois números
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

	printf("Digite o primeiro número: ");
	scanf("%d", &x);
	printf("Digite o segundo número: ");
	scanf("%d", &y);

	printf("MDC ( %d , %d ) = %d\n", x, y, mdc(x,y));
}
