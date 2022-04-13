# Corda
API em C para manipular strings sem conhecimento prévio do tamanho máximo delas

## int leString(char **pont)
Essa função lê uma string da entrada padrão

Deve ser passado como argumento o endereço de um ponteiro char que deverá apontar para a string lida

Retorna um inteiro com o tamanho da string (contando também o \0)

Exemplo de uso:

`int tamString;`

`char *string;`

`tamString = leString(&string);`
