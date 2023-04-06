#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - add positive num
 * @argc: num of argument
 * @argv: array of argument
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
