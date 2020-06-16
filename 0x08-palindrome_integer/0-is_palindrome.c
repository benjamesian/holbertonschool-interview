#include "palindrome.h"

int is_palindrome(unsigned long n)
{
	unsigned long a = n, b = 0;

	while (a)
	{
		b = b * 10 + (a % 10);
		a /= 10;
	}

	a = n;
	while (a)
	{
		if (a % 10 != b % 10)
			return (0);
		a /= 10;
		b /= 10;
	}

	return (!b);
}
