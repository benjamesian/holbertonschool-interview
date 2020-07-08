#include "slide_line.h"

/**
 * shift_zeros - shift non-zero numbers in an array over the zeros
 * @line: array of integers
 * @size: size of array
 * @direction: direction to shift integers in array
 * Return: 1 if shift took place, else 0
 */
int shift_zeros(int *line, size_t size, int direction)
{
	int shifted = 0;
	size_t i = 0, j = (direction == SLIDE_LEFT) ? 0 : size - 1;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
			{
				line[j] = line[i];
				if (i != j)
					shifted = 1;
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
				if (i != j)
					shifted = 1;
				j--;
			}
		}
		for (; j < size; j--)
			line[j] = 0;
	}

	return (shifted);
}

/**
 * merge_line_helper - merge duplicate neighbors in an array
 * @line: array of integers
 * @size: size of array
 * @direction: direction to merge integers in array
 * Return: 1 if merge took place, else 0
 */
int merge_line_helper(int *line, size_t size, int direction)
{
	int merged = 0;
	size_t i;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] && line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
				merged = 1;
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
				merged = 1;
			}
		}
	}

	if (merged)
		shift_zeros(line, size, direction);

	return (merged);
}

/**
 * merge_line - merge duplicate neighbors in an array
 * @line: array of integers
 * @size: size of array
 * @direction: direction to merge integers in array
 * Return: 1 if merge took place, else 0
 */
int merge_line(int *line, size_t size, int direction)
{
	int merged = 0;

	if (merge_line_helper(line, size, direction))
		merged = 1;

	return (merged);
}

/**
 * slide_line - merge duplicate neighbors in an array and slide over zeros
 * @line: array of integers
 * @size: size of array
 * @direction: direction to merge/slide integers in array
 * Return: 1 if merge or slide took place, else 0
 */
int slide_line(int *line, size_t size, int direction)
{
	int shifted = shift_zeros(line, size, direction);
	int merged = merge_line(line, size, direction);

	return (shifted || merged);
}
