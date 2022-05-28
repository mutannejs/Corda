#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "corda.h"

int tamanhoString(char string[]) {

	int tam = 0;

	while (string[tam] != '\0')
		tam++;

	return tam+1;
}

void liberaString(int qtdStrings, ...) {

	va_list ap;
	va_start(ap, qtdStrings);

	for (int i = 0; i < qtdStrings; i++) {
		char **str = va_arg(ap, char**);
		free(*str);
		*str = NULL;
	}

	va_end(ap);
}

int concatenaString(int qtdStrings, char **str1, ...) {

	string s;
	s = criaPilha();

	va_list ap;
	va_start(ap, str1);

	for (int i = 0; i < qtdStrings; i++) {
		char *str = va_arg(ap, char*);
		char c = str[0];
		for (int i = 1; c != '\0'; i++) {
			adicionaPilha(&s, c);
			c = str[i];
		}
	}
	adicionaPilha(&s, '\0');

	va_end(ap);

	*str1 = retornaString(&s);

	destroiPilha(&s);

	return s.tam;
}

int copiaString(char **str1, char *str2, int ini, int fim) {

	string s;
	char c = 'a';

	s = criaPilha();
	if (fim == 0) {
		for (int i = ini; c != '\0'; i++) {
			c = str2[i];
			adicionaPilha(&s, c);
		}
	}
	else {
		for (int i = ini; i <= fim && c != '\0'; i++) {
			c = str2[i];
			adicionaPilha(&s, c);
		}
		if (c != '\0')
			adicionaPilha(&s, '\0');
	}

	*str1 = retornaString(&s);

	destroiPilha(&s);

	return s.tam;
}

int leString(char **pont) {

	string s;
	char c;

	s = criaPilha();
	c = getchar();
	while (c != '\n') {
		adicionaPilha(&s, c);
		c = getchar();
	}
	adicionaPilha(&s, '\0');

	*pont = retornaString(&s);

	destroiPilha(&s);

	return s.tam;
}

char* retornaString(string *s) {
	char *c = (char*) malloc(sizeof(char)*s->tam);
	for (int i = 0; i < s->tam; i++) {
		c[i] = s->string[i];
	}
	return c;
}

void limpaBuffer() {
	char c;
	c = getchar();
	while (c != '\n' && c != EOF) {
		c = getchar();
	}
}



/* Funções da Pilha */
string criaPilha() {
	string s;
	char *c = (char*) malloc(sizeof(char)*10);
	s.string = c;
	s.tam = 0;
	s.max = 10;
	return s;
}

void adicionaPilha(string *s, char c) {
	if (s->tam == s->max)
		aumentaPilha(s);
	s->string[s->tam] = c;
	s->tam = s->tam + 1;
}

void aumentaPilha(string *s) {
	char *c = (char*) malloc(sizeof(char)*s->max*2);
	for (int i = 0; i < s->tam; i++) {
		c[i] = s->string[i];
	}
	free(s->string);
	s->string = c;
	s->max = s->max * 2;
}

void destroiPilha(string *s) {
	free(s->string);
}
