#include "sandpiles.h"
/**
 * print_grid - Prints grid
 * @grid: grid
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
 * ckeckGrid - checks grid
 * @grid1: grid
 * Return: bool value
 */
bool ckeckGrid(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
				return (false);
		}
	}
	return (true);
}
/**
 * subtractCorners - Function to suctract corners
 * @grid1: grid
 */
void subtractCorners(int grid1[3][3])
{
	if (grid1[0][0] >= 4)
	{
		grid1[0][0] -= 4;
		grid1[0][1] += 1;
		grid1[1][0] += 1;
	}
	if (grid1[0][2] >= 4)
	{
		grid1[0][2] -= 4;
		grid1[0][1] += 1;
		grid1[1][2] += 1;
	}
	if (grid1[2][0] >= 4)
	{
		grid1[2][0] -= 4;
		grid1[1][0] += 1;
		grid1[2][1] += 1;
	}
	if (grid1[2][2] >= 4)
	{
		grid1[2][2] -= 4;
		grid1[1][2] += 1;
		grid1[2][1] += 1;
	}
}
/**
 * subtractCentralCorners - Function to subtract central corners
 * @grid1: grid1
 */
void subtractCentralCorners(int grid1[3][3])
{
	if (grid1[0][1] >= 4)
	{
		grid1[0][1] -= 4;
		grid1[1][1] += 1;
		grid1[0][0] += 1;
		grid1[0][2] += 1;
	}
	if (grid1[1][0] >= 4)
	{
		grid1[1][0] -= 4;
		grid1[1][1] += 1;
		grid1[0][0] += 1;
		grid1[2][0] += 1;
	}
	if (grid1[1][2] >= 4)
	{
		grid1[1][2] -= 4;
		grid1[1][1] += 1;
		grid1[0][2] += 1;
		grid1[2][2] += 1;
	}
	if (grid1[2][1] >= 4)
	{
		grid1[2][1] -= 4;
		grid1[1][1] += 1;
		grid1[2][0] += 1;
		grid1[2][2] += 1;
	}
}
/**
 * sandpiles_sum -  Stable sums
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	bool ans;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	ans = ckeckGrid(grid1);
	if (ans == false)
	{
		while (ans != true)
		{
			printf("=\n");
			print_grid(grid1);
			if (grid1[1][1] >= 4)
			{
				grid1[1][1] -= 4;
				grid1[0][1] += 1;
				grid1[1][0] += 1;
				grid1[1][2] += 1;
				grid1[2][1] += 1;
			}
			if (grid1[0][0] >= 4 || grid1[0][2] >= 4 || grid1[2][0]
			    >= 4 || grid1[2][2] >= 4)
				subtractCorners(grid1);
			if (grid1[0][1] >= 4 || grid1[1][0] >= 4 || grid1[1][2]
			    >= 4 || grid1[2][1] >= 4)
				subtractCentralCorners(grid1);
			ans = ckeckGrid(grid1);
		}
	}
}
