#include <stdlib.h>
#include <stdio.h>

/**
 * should_topple - check if a sandpile is not stable
 * @grid: sandpile to check
 *
 * Return: 0 if sandpile is stable, else 1
 */
int should_topple(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}

	return (0);
}

/**
 * print_grid - print a 3 by 3 grid of integers
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_grids - add two 3 by 3 grids of integers together
 * @grid1: addend
 * @grid2: addend
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int col, row;

	for (col = 0; col < 3; col++)
	{
		for (row = 0; row < 3; row++)
		{
			grid1[col][row] += grid2[col][row];
		}
	}
}

/**
 * topple - topple a sandpile
 * @grid: sandpile to topple
 */
void topple(int grid[3][3])
{
	int temp[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0}};
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1;
				if (j > 0)
					temp[i][j - 1] += 1;
				if (i < 2)
					temp[i + 1][j] += 1;
				if (j < 2)
					temp[i][j + 1] += 1;
			}
		}
	}

	add_grids(grid, temp);
}

/**
 * sandpiles_sum - add two sandpiles together and print results between topples
 * @grid1: first sandpile (will contain result)
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grids(grid1, grid2);

	while (should_topple(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
