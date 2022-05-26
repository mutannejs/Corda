#ifndef IMPUT_H
#define IMPUT_H

/*	Desaloca strings
- Deve ser passado como primeiro argumento um inteiro indicando quantas strings (criadas usando essa API) devem ser desalocadas, os próximos argumentos devem ser o endereço das strings
Ex:	leString(&str1);
	leString(&str2);
	liberaString(&str1, &str2);		//os ponteiros passam a apontar para NULL*/
void liberaString(int qtdStrings, ...);

/*	Concatena strings
- Deve ser passado como primeiro argumento um inteiro indicando quantas strings vão ser concatenadas, como segundo argumento o endereço do ponteiro char onde deve ser armazenado a string final já concatenada (o conteudo inicial dela não fará parte da string final, de preferência usar um ponteiro ainda não utilizado), os próximos argumentos devem ser as strings que serão concatenadas
- Retorna um inteiro com o tamanho da string final (contando também o \0)
Ex:	int tamString;
	char *stringFinal, inicio[] = "essa string ", fim[] = "strings concatenadas";
	tamString = concatenaString(3, &stringFinal, inicio, "são várias ", fim);		//stringFinal = "essa string são várias strings concatenadas"
*/
int concatenaString(int qtdStrings, char **str1, ...);


/*	Copia uma string
- Deve ser passado como primeiro argumento o endereço do ponteiro char onde deve ser armazenado a copia da string, como segundo argumento a string que será copiada, como terceiro argumento um inteiro com a posição inicial que deve ser iniciada a copia, e como quarto argumento um inteiro com a última posição a ser feita a copia (caso deva ser copiado até o fim, colocar 0)
- Retorna um inteiro com o tamanho da copia (contando também o \0)
Ex:	int tamString;
	char *copia, text[] = "naoCopiar-Text-NaoCopiar";
	tamString = copiaString(&copia, text, 10, 13);		//copia = "Text"
*/
int copiaString(char **str1, char *str2, int ini, int fim);


/*	Lê uma string da entrada padrão
- Deve ser passado como argumento o endereço do ponteiro char onde deve ser armazenado a string
- Retorna um inteiro com o tamanho da string (contando também o \0)
Ex:	int tamString;
	char *string;
	tamString = leString(&string);
*/
int leString(char **pont);

/*	Limpa o buffer do teclado
Essa função ou qualquer outra forma de limpar o buffer do teclado deve ser usada antes de chamar leString, isso se alguma outra função de leitura do teclado (que deixe o \n no buffer do teclado) ser usada antes
*/
void limpaBuffer();

// --- Estruturas e funções internas da API ---
typedef struct string {
	char *string;
	int tam, max;
} string;

char* retornaString(string *s);
string criaPilha();
void adicionaPilha(string *s, char c);
void aumentaPilha(string *s);
void destroiPilha(string *s);
// --------------------------------------------

#endif
