#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiply 2 num
 * @argc: num of argument
 * @argv: array argument
 * Return: always 0.
 */
int main(int argc, char **argv)
{
	int x, y;

	if (argc < 3)
	{
		printf("error\n");
		return (1);
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	printf("%d\n", x * y);

	return (0);
}
