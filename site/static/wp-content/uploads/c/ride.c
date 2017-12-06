//Your Ride is Here - USACO Training Gateway
/*
ID: contato1
PROG: ride
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CMAX 6

main() {
	char comet[CMAX], group[CMAX];
	int com=1, gro=1, i;
	
	FILE *in = fopen("ride.in", "r");
	fscanf(in,"%s",comet);
	fscanf(in,"%s",group);
	fclose(in);

	for (i=0; i<strlen(comet); i++) {
		com = com * (comet[i]-64);
	}

	for (i=0; i<strlen(group); i++) {
		gro = gro * (group[i]-64);
	}
	
	FILE *out = fopen("ride.out", "w");
	if (com % 47 == gro % 47) { fprintf(out, "GO\n"); } else { fprintf(out, "STAY\n"); }
	fclose(out);

	exit(0);
}
