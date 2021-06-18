#include "palindrome.h"
/**
 * is_palindrome - Function to check if a number is palindrome
 * @n: Number to be checked
 *
 * Return: 1 if n is palindrome or 0 if not
 */
int is_palindrome(unsigned long n)
{
	int arr[100000];
	int i = 0;
	int b = 0;
	int num = n;

	arr[i] = num % 10;
	while (arr[i] != '\0')
	{
		i++;
		num = num / 10;
		arr[i] = num % 10;
	}
	i--;
	while (i >= 0)
	{
		if (arr[i] != arr[b])
		{
			return (0);
		}
		b++;
		i--;
	}
	return (1);
}
