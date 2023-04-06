#include <stdio.h>
#include "main.h"
/**
 * main - print the number of argument
 * @argc: number of argument
 * @argv: array the argument
 * Return: Always 0.
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
