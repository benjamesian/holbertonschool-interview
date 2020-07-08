#include "slide_line.h"

/**
 * shift_zeros - shift non-zero numbers in an array over the zeros
 * @line: array of integers
 * @size: size of array
 * @direction: direction to shift integers in array
 */
void shift_zeros(int *line, size_t size, int direction)
{
	size_t i = 0, j = (direction == SLIDE_LEFT) ? 0 : size - 1;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
			{
				line[j] = line[i];
				j++;
			}
		}
		for (; j < size; j++)
			line[j] = 0;
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size - 1; i < size; i--)
		{
			if (line[i] != 0)
			{
				line[j] = line[i];
				j--;
			}
		}
		for (; j < size; j--)
			line[j] = 0;
	}
}

/**
 * merge_line - merge duplicate neighbors in an array
 * @line: array of integers
 * @size: size of array
 * @direction: direction to merge integers in array
 */
void merge_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] && line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] && line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
		}
	}

	shift_zeros(line, size, direction);
}

/**
 * slide_line - merge duplicate neighbors in an array and slide over zeros
 * @line: array of integers
 * @size: size of array
 * @direction: direction to merge/slide integers in array
 * Return: 1
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);

	shift_zeros(line, size, direction);
	merge_line(line, size, direction);

	return (1);
}
