#include <stdio.h>
#include "main.h"
/**
 * main - print all argument
 * @argc: num of argument
 * @argv: array of argument
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
