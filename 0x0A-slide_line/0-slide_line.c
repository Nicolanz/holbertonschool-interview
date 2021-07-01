#include "slide_line.h"
/**
 * slide_left - Slides array to the left
 * @line: Pointer to arr of integers
 * @size: Size of the array
 */
void slide_left(int *line, size_t size)
{
	size_t i = 0;
	size_t tmp = 0;

	for (i = 0; i <= size - 1; i++)
	{
		if (line[i] != 0 && i != size - 1)
		{
			for (tmp = i + 1; line[tmp] != line[i]; tmp++)
			{
				if (tmp == size - 1 || line[tmp] == line[i])
				{
					break;
				}
			}
			if (line[i] == line[tmp])
			{
				line[i] += line[tmp];
				line[tmp] = 0;
			}
		}
	}

	for (i = 0; i <= size - 1; i++)
	{
		if (line[i] == 0 && i != size - 1)
		{
			for (tmp = i + 1; line[tmp] <= 0; tmp++)
			{
				if (tmp == size - 1)
				{
					break;
				}
			}
			if (line[tmp] > 0)
			{
				line[i] = line[tmp];
				line[tmp] = 0;
			}
		}
	}
}

/**
 * slide_right - Slides array to the right
 * @line: Pointer to arr of integers
 * @size: Size of the array
 */
void slide_right(int *line, size_t size)
{
	int i = 0;
	int tmp = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0 && i != 0)
		{
			for (tmp = i - 1; line[tmp] != line[i]; tmp--)
			{
				if (tmp == 0 || line[tmp] == line[i])
				{
					break;
				}
			}
			if (line[i] == line[tmp])
			{
				line[i] += line[tmp];
				line[tmp] = 0;
			}
		}
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0 && i != 0)
		{
			for (tmp = i - 1; line[tmp] <= 0; tmp--)
			{
				if (tmp == 0)
				{
					break;
				}
			}
			if (line[tmp] > 0)
			{
				line[i] = line[tmp];
				line[tmp] = 0;
			}
		}
	}
}

/**
 * slide_line - Slides and merges identical numbers of array
 * @line: Pointer to array of integers
 * @size: Size of the array
 * @direction: direction of the merged arrays
 * Return: 1 upon sucess or 0 if fails
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else
		return (0);
	return (1);
}
