//Resolvendo o KBruch
//Termos: 2, Máximo denominador comum: 10, Operações: Adição/Subtração

#include <stdio.h>

int mmc(int a, int b) {
	int i, t, c=1;

	if (a>b) {
		t=b;
		b=a;
		a=t;
	}

	i=b;

	while (i%a) {
		i=b*c;
		c++;
	}

	return i;
}

int main() {
	int n1, d1, n2, d2, rn1, rn2, d, res, i;
	char sinal;

	while (scanf("%d/%d%c%d/%d", &n1, &d1, &sinal, &n2, &d2)) {
		//determinando denominador comum
		if (d1==d2) {
			rn1=n1;
			rn2=n2;
			if (n1==n2&&sinal=='-') {
				d=1;
			} else {
				d=d1;
			}
		} else {
			d=mmc(d1, d2);
			rn1=d/d1*n1;
			rn2=d/d2*n2;
		}
		//fazendo a conta
		if (sinal=='+') {
			res=rn1+rn2;
		} else {
			res=rn1-rn2;
		}

		//simplificando a fração
		for (i=2; i<=d; i++) {
			if (!(res%i)&&!(d%i)) {
				res/=i;
				d/=i;
				i=2;
			}
		}
		printf("Resultado: %d/%d\n\n", res, d);
	}
}
