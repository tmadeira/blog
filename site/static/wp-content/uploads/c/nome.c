//Permutações de nomes com 10 letras
//Programa feito pra zuar o Cosme... hehehe
#include <stdio.h>

main() {
int i, j, k, l, m, n, o, p, q, r;

for (i='a'; i<='z'; i++) {
for (j='a'; j<='z'; j++) {
for (k='a'; k<='z'; k++) {
for (l='a'; l<='z'; l++) {
for (m='a'; m<='z'; m++) {
for (n='a'; n<='z'; n++) {
for (o='a'; o<='z'; o++) {
for (p='a'; p<='z'; p++) {
for (q='a'; q<='z'; q++) {
for (r='a'; r<='z'; r++) {
printf("%c%c%c%c%c%c%c%c%c%c\n", i, j, k, l, m, n, o, p, q, r);
}
}
}
}
}
}
}
}
}
}

return 0;
}
	
