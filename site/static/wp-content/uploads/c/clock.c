//What time is it? - USACO Training Gateway 2005

//Eu boiei animalmente nesse programa. Era um programa super simples,
//eu fiz um monte de coisa inútil. Depois que vi a solução do site no
//Analysis, quase resolvi não pôr aqui, mas coloquei pensando:
//"Bom, isso é pra mostrar como a gente pode pensar errado..."
//Não conhecia algumas funções usadas no site, como a toupper. Usei
//um monte de função que não precisava...
//Ah, sem comentários! :S

/*
ID: contato1
PROG: clock
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char string[100], string2[100];

char *num(int n) {
	if (n>12)
		n-=12;
	if (n==1)
		return "one";
	if (n==2)
		return "two";
	if (n==3)
		return "three";
	if (n==4)
		return "four";
	if (n==5)
		return "five";
	if (n==6)
		return "six";
	if (n==7)
		return "seven";
	if (n==8)
		return "eight";
	if (n==9)
		return "nine";
	if (n==10)
		return "ten";
	if (n==11)
		return "eleven";
	if (n==12)
		return "twelve";
	return "ERROR! num";
}

void pm2(char *str) {
	char coisa[100];
	strcpy(coisa, str);
	coisa[0]-=32;

	strcpy(string, coisa);
}

char *pm(char *str) {
	pm2(str);
	return string;
}

char *dminuto(int n) {
	char str[100];
	sprintf(str, "%d", n);
	if (str[0]=='2')
		return "twenty";
	if (str[0]=='3')
		return "thirty";
	if (str[0]=='4')
		return "forty";
	if (str[0]=='5')
		return "fifty";
}

char *no(int n) {
	while (n>10) {
		n-=10;
	}
	return num(n);
}

char *minuto(int n) {
	char str[100];
	if (n<13) {
		return num(n);
	}
	if (n<20) {
		if (n==13)
			return "thirteen";
		if (n==14)
			return "fourteen";
		if (n==15)
			return "fifteen";
		if (n==16)
			return "sixteen";
		if (n==17)
			return "seventeen";
		if (n==18)
			return "eighteen";
		if (n==19)
			return "nineteen";
	}
	sprintf(str, "%d", n);
	if (str[1]=='0') {
		return dminuto(n);
	} else {
		sprintf(string2, "%s-%s", dminuto(n), no(n));
		return string2;
	}
}

int main() {
	int hora, minutos;
	FILE *in=fopen("clock.in", "r");
	FILE *out=fopen("clock.out", "w");

	fscanf(in, "%d:%d", &hora, &minutos);
	fclose(in);
	
	if (!minutos) {
		fprintf(out, "%s o'clock", pm(num(hora)));
	} else if (minutos==15) {
		fprintf(out, "Quarter past %s", num(hora));
	} else if (minutos==45) {
		fprintf(out, "Quarter to %s", num(hora+1));
	} else if (minutos<45) {
		fprintf(out, "%s %s", pm(num(hora)), minuto(minutos));
	} else {
		fprintf(out, "%s to %s", pm(minuto(60-minutos)), num(hora+1));
	}

	fprintf(out, "\n");
	
	fclose(out);
	return 0;
}

