#include "main.h"
/**
 * _strlen_recursion - print the length of string
 * @s: string that will be printed
 * Return: the length
 */
int _strlen_recursion(char *s)
{
	if (s[0] != '\0')
		return (1 + _strlen_recursion(s + 1));
	return (0);
}
/**
 * pal_checker - check if s is palindrome
 * @s: string address
 * @i: left
 * @j: right
 * Return: if s is palindrome
 */
int pal_checker(char *s, int i, int j)
{
	if (s[i] == s[j])
		if (i > j / 2)
			return (1);
		else
			return (pal_checker(s, i + 1, j - 1));
	else
		return (0);
}
/**
 * is_palindrome - check if s is palindrome
 * @s: base address for string
 * Return: if n is prime
 */
int is_palindrome(char *s)
{
	return (pal_checker(s, 0, _strlen_recursion(s) - 1));
}
