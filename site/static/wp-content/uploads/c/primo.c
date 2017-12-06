//Primos
#include <stdio.h>

int main(int argc, char *argv[]) {
	int i, x;
	long int n;

	if (!argv[1]) {
		printf("Digite um valor para o número que deseja testar: ");
		scanf("%d", &n);
	} else {
		n=atoi(argv[1]);
	}

	x=2;

	for (i=0; i<=5; i++) {
		if (i*i<n) {
			x=i;
		}
	}

	printf("Testando número %d...\n", n);

	for (i=2; i<n/x; i++) {
		if (!(n%i)) {
 			i=n+1;
			printf("%d não é primo.\n", n);
		}
	}

	if (i==n/x) {
		printf("%d é primo.\n", n);
	}

	return 0;
}
