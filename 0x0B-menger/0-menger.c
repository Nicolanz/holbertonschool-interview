#include "menger.h"
/**
 * power - Function to get the pow of a number
 * @numero: number to get the power
 * @potencia: pow of the number
 * Return: the power of a number
 */
int power(int numero, int potencia)
{
	int i;
	int pow = 1;

	for (i = potencia; i > 0; i--)
	{
		pow *= numero;
		potencia--;
	}
	return (pow);
}

/**
 * menger - Draws a menger sponge
 * @level: Level of the sponge
 *
 */
void menger(int level)
{

	int my_level;
	int i = 0;
	int j = 0;

	if (level == 0)
	{
		printf("#\n");
	}
	else if (level < 0)
	{
		/* Unimplemented at the moment */
	}
	else
	{
		my_level = power(3, level);
		for (i = 0; i < my_level; i++)
		{
			for (j = 0; j < my_level; j++)
			{
				if ((i  >= my_level / 3 && i < (my_level - my_level / 3)) &&
				    (j  >= my_level / 3 && j < (my_level - my_level / 3)))
				{
					printf(" ");
				}
				else
				{
					printf("#");
				}
			}
			printf("\n");
		}
	}
}
