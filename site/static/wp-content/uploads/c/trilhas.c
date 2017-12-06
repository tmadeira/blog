//Trilhas - OBI2005
#include <stdio.h>
#include <values.h>
#define NMAX 102
#define MMAX 1001

int main() {
	int campeao, n, m[NMAX], a[NMAX][MMAX], saida=0, i, j, parou, subir[NMAX], descer[NMAX], menor=MAXINT;

	scanf("%d", &n);
	for (i=1; i<=n; i++) {
		scanf("%d", &m[i]);
		for (j=1; j<=m[i]; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	//Primeiro vamos ver se precisa haver esforço de subida
	for (i=1; i<=n; i++) {
		parou=0;
		for (j=1; j<=m[i]; j++) {
			//printf("%d %d\n", i, j);
			if (a[i][j]>a[i][j+1]&&j!=m[i]) {
				parou=1;
				//printf("parou!\n");
				j=m[i];
			}
		}
		if (!parou) {
			//Então vamos parar por aí...
			printf("%d\n", i);
			return 0;
		}
	}

	//A mesma coisa ao contrário
	for (i=1; i<=n; i++) {
		parou=0;
		for (j=m[i]; j>=1; j--) {
			//printf("%d %d\n", i, j);
			if (a[i][j]>a[i][j-1]&&j!=1) {
				parou=1;
				//printf("parou!\n");
				j=1;
			}
		}
		if (!parou) {
			//Então vamos parar por aí...
			printf("%d\n", i);
			return 0;
		}
	}

	//Não deu...
	//Vamos contar quantos metros vamos ter que subir (ou descer=subir ao contrário)
	for (i=1; i<=n; i++) {
		descer[i]=0;
		subir[i]=0;
		for (j=1; j<=m[i]; j++) {
			if (a[i][j]>a[i][j+1]) {
				descer[i]+=(a[i][j]-a[i][j+1]);
			} else {
				subir[i]+=(a[i][j+1]-a[i][j]);
			}
		}
	}

	//E quem sobe ou desce menos?
	for (i=1; i<=n; i++) {
		if (subir[i]<menor) {
			menor=subir[i];
		}
		if (descer[i]<menor) {
			menor=descer[i];
		}
	}

	//Mas peraí... Temos que ver o primeiro na ordem de identificação!
	for (i=1; i<=n; i++) {
		if (subir[i]==menor||descer[i]==menor) {
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}
