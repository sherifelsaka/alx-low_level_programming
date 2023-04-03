#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
void print_chessboard(char (*a)[8]);
void print_diagsums(int *a, int size);
void set_string(char **s, char *accept);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_memset(char *s, char b, unsigned int n);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
char *_strpbrk(char *s, char *accept);
int _putchar(char c);
unsigned int _strspn(char *s, char *accept);
#endif
