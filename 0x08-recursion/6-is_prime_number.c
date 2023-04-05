#include "main.h"
/**
 * is_prime_number - return if the number is prime
 * @n: integer
 * REturn: trueif the num is prime
 */
int is_prime_number(int n)
{
	int start = n / 2;

	if (n <= 1)
		return (0);
	return (is_prime(n, start));
}
/**
 * is_prime - return the 1 if n is prime
 * @n: integer to check
 * @start: number to start checking
 * Return:if n is prime
 */
int is_prime(int n, int start)
{
	if (start <= 1)
		return (1);
	else if (n % start == 0)
		return (0);
	return (is_prime(n, start - 1));
}
