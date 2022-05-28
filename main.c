#include <stdio.h>
#include "corda.h"

int main() {

	int tamString;
	char *string, *copia, *stringFinal;
	char text[] = "naoCopiar-Text-NaoCopiar";
	char inicio[] = "essa string ", fim[] = "strings concatenadas";

	char testeLB[11];
	printf("Teste de limpaBuffer() - escreva algo com menos que 10 letras:\n");
	scanf("%s", testeLB);
	limpaBuffer();

	printf("Teste de tamanhoString():\n");
	tamString = tamanhoString(testeLB);
	printf("tamString: %d\n", tamString);

	printf("\nTeste de leString() - escreva alguma coisa:\n");
	tamString = leString(&string);
	printf("tam:%d string:%s\n", tamString, string);

	printf("Teste de tamanhoString():\n");
	tamString = tamanhoString(string);
	printf("tamString: %d\n", tamString);
	
	printf("\nTeste de copiaString() - meio:\n");
	tamString = copiaString(&copia, text, 10, 13);
	printf("tam:%d string:%s\n", tamString, copia);
	
	printf("\nTeste de copiaString() - início:\n");
	tamString = copiaString(&copia, text, 0, 8);
	printf("tam:%d string:%s\n", tamString, copia);
	
	printf("\nTeste de copiaString() - fim:\n");
	tamString = copiaString(&copia, text, 15, 0);
	printf("tam:%d string:%s\n", tamString, copia);
	
	printf("\nTeste de concatenaString():\n");
	tamString = concatenaString(3, &stringFinal, inicio, "sao varias ", fim);
	printf("tam:%d string:%s\n", tamString, stringFinal);
	
	liberaString(3, &string, &copia, &stringFinal);

	return 0;
}
