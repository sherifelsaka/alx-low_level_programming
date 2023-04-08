#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiply 2 num
 * @argc: num of argument
 * @argv: array argument
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	int m;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		m = (atoi(argv[1]) * atoi(argv[2]));
		printf("%d\n", m);
	}
	return (0);
}
