#ifndef IMPUT_H
#define IMPUT_H

typedef struct string {
	char *string;
	int tam, max;
} string;

int concatenaString(int qtdstrings, char **str1, ...);

int copiaString(char **str1, char *str2, int num);

int leString(char **pont);//retorna o tamanho da string(contando também o \0), e guarda no ponteiro passado como argumento a string lida da estrada padrão

char* retornaString(string *s);
string criaPilha();
void adicionaPilha(string *s, char c);
void aumentaPilha(string *s);
void destroiPilha(string *s);

#endif
