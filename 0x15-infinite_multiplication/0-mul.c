#include "holberton.h"

/**
 * error - function to return an error
 */
void error(void)
{
	_putchar(*"E");
	_putchar(*"r");
	_putchar(*"r");
	_putchar(*"o");
	_putchar(*"r");
	_putchar(*"\n");
	exit(98);
}

/**
 * main - Program to make large muls
 * @argc: argc len of args array
 * @argv: array of args
 * Return: Large mul
 *
 */

int main(int argc, char *argv[])
{

	if (argc < 3 || argc > 3)
	{
		error();
	}

	unsigned long long int first = atoi(argv[1]);
	unsigned long long int second = atoi(argv[2]);
	unsigned long long result = first * second;

	printf("%lld\n", result);
	return (0);
}
