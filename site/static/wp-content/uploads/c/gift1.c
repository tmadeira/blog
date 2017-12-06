//Greedy Gift Givers - USACO Training Gateway
/*
ID: contato1
PROG: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NPMAX 10
#define NMAX 14

main() {
	int i, j, con, np, money, ptw, div, g[NPMAX]; //ptw=people that win, g=gasto
	char p[NPMAX][NMAX], giver[NMAX], pqg[NMAX];

	FILE *in = fopen("gift1.in", "r");
	fscanf(in,"%d",&np);
	for (i=0; i<np; i++) {
		fscanf(in,"%s",p[i]);
		g[i]=0;
	}

	
	for (con=0; con<np; con++) {
		fscanf(in,"%s",giver);
		fscanf(in, "%d %d", &money, &ptw);
		if (ptw!=0) {
		div=money/ptw;
		money=div*ptw;
		for (i=0; i<np; i++) {
			if (strcmp(giver,p[i])==0) {
				g[i]-=money;
			}
		}

		for (i=0; i<ptw; i++) {
			fscanf(in,"%s",pqg);
			for (j=0; j<np; j++) {
				if (strcmp(pqg,p[j])==0) {
					g[j]+=div;
				}
			}
		}
		}
		
	}
	fclose(in);

	FILE *out = fopen("gift1.out", "w");
	for (i=0; i<np; i++) {
		fprintf(out,"%s %d\n",p[i],g[i]);
	}
	fclose(out);
	
	exit(0);
}	
