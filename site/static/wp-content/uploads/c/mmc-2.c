//MMC - M�nimo M�ltiplo Comum, para dois n�meros

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

int mmc(int x, int y) {
	return x*y/mdc(x,y);
}

int main() {
	int x, y;

	printf("Primeiro n�mero: ");
	scanf("%d", &x);
	printf("Segundo n�mero: ");
	scanf("%d", &y);

	printf("MMC (%d, %d): %d\n", x, y, mmc(x,y));
}
