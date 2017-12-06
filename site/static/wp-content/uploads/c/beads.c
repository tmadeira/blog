//Broken Necklace - USACO Training Gateway
/*
ID: contato1
PROG: beads
*/
#include <stdio.h>

int main() {
	int n, nti, neck[351], i, e, v, j, ti, tj, maior, tot;
	char c;

	FILE *in = fopen("beads.in", "r");
	fscanf(in, "%d", &n);
	fscanf(in, "%c", &c);
	for (i=1; i<=n; i++) {
		fscanf(in, "%c", &c);
		if (c=='w') {
			neck[i]=0;
		} else if (c=='b') {
			neck[i]=1;
		} else if (c=='r') {
			neck[i]=2;
		}
	}
	fclose(in);
	
	maior=0;
	for (i=1; i<=n; i++) {
		ti=i;
		nti=neck[ti];
		if (!neck[ti]) {
			nti=neck[ti+1];
		}
		tot=0;
		v=0;
		for (j=i; j<n+i; j++) {
			if (j>n) {
				tj=j-n;
			} else {
				tj=j;
			}
			if (neck[tj]==nti || !neck[tj]) {
				tot++;
			} else {
				if (!v) {
					ti=tj;
					nti=neck[ti];
					v=1;
				} else {
					break;
				}
				tot++;
			}
		}
		if (tot>maior) {
			maior=tot;
			e=i;
		}
	}

	FILE *out = fopen("beads.out", "w");
	fprintf(out, "%d\n", maior);
	fclose(out);
}
