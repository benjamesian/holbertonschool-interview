#include "menger.h"
#include <math.h>
#include <stdio.h>

/**
 * helper - check if a position in a 2D menger sponge should be filled or not
 * @row: row position in sponge
 * @col: col position in sponge
 * Return: 1 if position should be filled, else 0
 */
int helper(int row, int col)
{
	while (row && col)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (0);
		row /= 3;
		col /= 3;
	}

	return (1);
}

/**
 * menger - draw a 2D menger sponge
 * @level: level of the menger sponge
 */
void menger(int level)
{
	int size = (int) pow(3, level), row, col;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			printf(helper(row, col) ? "#" : " ");
		printf("\n");
	}
}
