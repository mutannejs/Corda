#include <stdio.h>
#include "corda.h"

int main() {

	int tamString;
	char *string, *copia, *stringFinal;
	char text[] = "naoCopiar-Text-NaoCopiar", inicio[] = "essa string ", fim[] = "strings concatenadas";

	tamString = leString(&string);
	printf("tam:%d string:%s\n", tamString, string);
	
	tamString = copiaString(&copia, text, 10, 13);
	printf("tam:%d string:%s\n", tamString, copia);
	
	tamString = concatenaString(3, &stringFinal, inicio, "são várias ", fim);
	printf("tam:%d string:%s\n", tamString, stringFinal);
	
	liberaString(3, &string, &copia, &stringFinal);

	return 0;
}
