#include "palindrome.h"
/**
 * countDigits - Function to count the digits of an ulint
 * @n: number to evaluate
 * Return: num of digits
 *
 */

int countDigits(unsigned long n)
{
	unsigned long num = n;
	int count = 0;

	do {
		count++;
		num = num / 10;
	} while (num != 0);

	return (count);
}
/**
 * is_palindrome - Function to check if an ul int in palindrome
 * @n: number to evaluate
 *
 * Return: 1 if true or false if false
 */
int is_palindrome(unsigned long n)
{
	int num = 0;
	int i = 0;
	char str[100000];

	num = countDigits(n) - 1;
	sprintf(str, "%ld", n);

	while (num != 0)
	{
		if (str[i] != str[num])
		{
			return (0);
		}
		i++;
		num--;
	}
	return (1);
}
