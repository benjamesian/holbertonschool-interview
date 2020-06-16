#include "palindrome.h"

/**
 * is_palindrome - check if a positive integer is a palindrome.
 * @n: a positive integer
 * Return: 1 if n is a palindrome, else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long a = n, b = 0;

	while (a)
	{
		b = b * 10 + (a % 10);
		a /= 10;
	}

	return (b == n);
}
