# Corda
API em C para manipular strings sem conhecimento prévio do tamanho máximo delas. Esta API pode sofrer mudanças diversas. **Alternativa:** Para uso semelhante, pode-se usar a biblioteca buffer.h e string.h.

### int leString(char **pont)
Essa função lê uma string da entrada padrão.

Deve ser passado como argumento o endereço de um ponteiro char que deverá apontar para a string lida.

Retorna um inteiro com o tamanho da string (contando também o \0).

Exemplo:

`int tamString;`

`char *string;`

`tamString = leString(&string);`

### void limpaBuffer()
Essa função limpa o buffer do teclado. Deve ser usada antes de chamar leString() se anteriormente foi usada alguma função para leitura do teclado, e esta por sua vez deixe o \n no buffer. Não é necessário usar entre duas chamadas de leString().

Exemplo:

`scanf("%s", stringScanf);`

`limpaBuffer();`

`leString(&string);`

### int tamanhoString(char string[])
Essa função retorna o tamanho de uma string.

Deve ser passado como argumento a string que deseja saber o tamanho. Pode ser passada qualquer string, não necessariamente uma string obtida usando as funções dessa API.

Retorna um inteiro com o tamanho da string (contando também o \n).

Exemplo:

`int tam = tamanhoString("quantasLetras?");`

`//tam será igual a 15`

### int copiaString(char **str1, char *str2, int ini, int fim)
Essa função copia parte de uma string.

Deve ser passado como primeiro argumento o endereço de um ponteiro char que deverá apontar para a cópia da string, como segundo argumento a string que será copiada, como terceiro argumento um inteiro com a posição inicial que deve ser iniciada a cópia, e como quarto argumento um inteiro com a última posição a ser feita a cópia (caso deva ser copiado até o fim, colocar 0).

Retorna um inteiro com o tamanho da cópia (contando também o \0).

Exemplo:

`int tamString;`

`char *copia, text[] = "naoCopiar-Text-NaoCopiar";`

`tamString = copiaString(&copia, text, 10, 13);`

`//tamString é igual a 5 e a string de cópia é igual a "Text"`

### int concatenaString(int qtdStrings, char **str1, ...)
Essa função concatena strings.

Deve ser passado como primeiro argumento um inteiro indicando quantas strings vão ser concatenadas, como segundo argumento o endereço de um ponteiro char que deverá apontar para a string final já concatenada (o conteúdo inicial dela não fará parte da string final, dê preferência a usar um ponteiro ainda não utilizado), os próximos argumentos devem ser as strings que serão concatenadas.

Retorna um inteiro com o tamanho da string final (contando também o \0).

Exemplo:

`int tamString;`

`char *stringFinal, inicio[] = "essa string ", fim[] = "strings concatenadas";`

`tamString = concatenaString(3, &stringFinal, inicio, "sao varias ", fim);`

`//o conteúdo da stringFinal é "essa string são várias strings concatenadas"`

### void liberaString(int qtdStrings, ...)
Essa função desaloca as strings criadas a partir desta API. Deve ser usada sempre que a string não for mais utilizada pelo programa, ou caso a mesma variável seja usada para guardar outra string.

Deve ser passado como primeiro argumento um inteiro indicando quantas strings (criadas usando essa API) devem ser desalocadas, os próximos argumentos devem ser os endereços das strings. Os ponteiros passam a apontar para NULL.

Exemplo:

`leString(&str1);`

`leString(&str2);`

`liberaString(2, &str1, &str2);`
