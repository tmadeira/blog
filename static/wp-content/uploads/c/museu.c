//Museu - OBI2006
#include <stdio.h>
#include <values.h>

#define SMAX 1001

int salas;
int g[SMAX][SMAX], resultado, marc[SMAX], tempo[SMAX];

void dfs(int v, int soma) {
	int w;

	if (v==1&&marc[v]&&soma<resultado) {
		resultado=soma;
	} else {
		soma+=tempo[v];
		for (w=1; w<=salas; w++) {
			if (g[v][w]&&(w==1||!marc[w])) {
				marc[w]=v;
				dfs(w, soma+g[v][w]);
				marc[w]=0;
			}
		}
	}
}

int main() {
	int i, j, x, y, z;
	int corredores;

	resultado=MAXINT;
	scanf("%d %d", &salas, &corredores);
	for (i=1; i<=salas; i++) {
		scanf("%d", &tempo[i]);
		marc[i]=0;
		for (j=1; j<=salas; j++) {
			g[i][j]=0;
		}
	}
	for (i=1; i<=corredores; i++) {
		scanf("%d %d %d", &x, &y, &z);
		g[x][y]=z;
	}

	dfs(1, 0);

	printf("%d\n", resultado);
	
	return 0;
}

