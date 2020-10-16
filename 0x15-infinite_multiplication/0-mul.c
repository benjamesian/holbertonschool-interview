#include "holberton.h"

/**
 * multiply - multiply two numbers
 * @n1: multiplicand
 * @n2: multiplicand
 */
void multiply(char *n1, char *n2)
{
	size_t n1_len, n2_len, tmp, len;
	int d1, d2, p;
	int *buffer;

	n1_len = strlen(n1);
	n2_len = strlen(n2);
	tmp = n2_len;
	len = n1_len + n2_len;
	buffer = calloc(len, sizeof(*buffer));

	for (; n1_len > 0; n1_len--)
	{
		d1 = n1[n1_len - 1] - '0';
		p = 0;
		n2_len = tmp;
		for (; n2_len > 0; n2_len--)
		{
			d2 = n2[n2_len - 1] - '0';
			p += buffer[n1_len + n2_len - 1] + (d1 * d2);
			buffer[n1_len + n2_len - 1] = p % 10;
			p /= 10;
		}
		buffer[n1_len - n2_len - 1] += p % 10;
	}

	while (*buffer == 0 && len)
	{
		buffer++;
		len--;
	}
	while (len--)
		printf("%d", *buffer++);
	putchar('\n');
}

/**
 * is_number - check if a string contains only digits
 * @n: string
 * Return: 1 if string contains only digits, else 0
 */
int is_number(char *n)
{
	while (*n && *n <= '9' && *n >= '0')
		n++;
	return (!*n);
}

/**
 * is_zero - check if a string is 0
 * @n: string
 * Return: 1 if string is 0 else 0
 */
int is_zero(char *n)
{
	while (*n)
		if (*n++ != '0')
			return (0);
	return (1);
}

/**
 * main - print product of arguments
 * @argc: number of args
 * @argv: args
 * Return: exit code
 */
int main(int argc, char **argv)
{
	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	if (is_zero(argv[1]) || is_zero(argv[2]))
		printf("0\n");
	else
		multiply(argv[1], argv[2]);

	return (0);
}
