# Corda
API em C para manipular strings sem conhecimento prévio do tamanho máximo delas

### int leString(char **pont)
Essa função lê uma string da entrada padrão

Deve ser passado como argumento o endereço de um ponteiro char que deverá apontar para a string lida

Retorna um inteiro com o tamanho da string (contando também o \0)

Exemplo:

`int tamString;`

`char *string;`

`tamString = leString(&string);`

### int copiaString(char **str1, char *str2, int ini, int fim)
Essa função copia parte de uma string

Deve ser passado como primeiro argumento o endereço de um ponteiro char que deverá apontar para a copia da string, como segundo argumento a string que será copiada, como terceiro argumento um inteiro com a posição inicial que deve ser iniciada a copia, e como quarto argumento um inteiro com a última posição a ser feita a copia (caso deva ser copiado até o fim, colocar 0)

Retorna um inteiro com o tamanho da copia (contando também o \0)

Exemplo:

`int tamString;`

`char *copia, text[] = "naoCopiar-Text-NaoCopiar";`

`tamString = copiaString(&copia, text, 10, 13);`

`//tamString é igual a 5 e a string de copia é igual a "Text"`

### int concatenaString(int qtdStrings, char **str1, ...)
Essa função concatena strings

Deve ser passado como primeiro argumento um inteiro indicando quantas strings vão ser concatenadas, como segundo argumento o endereço de um ponteiro char que deverá apontar para a string final já concatenada (o conteudo inicial dela não fará parte da string final, dê preferência a usar um ponteiro ainda não utilizado), os próximos argumentos devem ser as strings que serão concatenadas

Retorna um inteiro com o tamanho da string final (contando também o \0)

Exemplo:

`int tamString;`

`char *stringFinal, inicio[] = "essa string ", fim[] = "strings concatenadas";`

`tamString = concatenaString(3, &stringFinal, inicio, "são várias ", fim);`

`//o conteúdo da stringFinal é "essa string são várias strings concatenadas"`


### void liberaString(int qtdStrings, ...)
Essa função desaloca as strings criadas a partir desta API. Deve ser usada sempre que a string não for mais utilizada pelo programa, ou caso a mesma variável seja usada para gurdar outra string

Deve ser passado como primeiro argumento um inteiro indicando quantas strings (criadas usando essa API) devem ser desalocadas, os próximos argumentos devem ser o endereço das strings. Os ponteiros passam a apontar para NULL

Exemplo:

`leString(&str1);`

`leString(&str2);`

`liberaString(2, &str1, &str2);`
