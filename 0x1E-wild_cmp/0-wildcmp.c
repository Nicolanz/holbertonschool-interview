#include "holberton.h"
/**
 * my_wildcmp - Function to compare two strings
 * @p: pattern
 * @s: string
 * Return: true if identical or false if not
 */
bool my_wildcmp(char *p, char *s)
{
	if (*p == '\0' && *s == '\0')
		return (true);

	if (*p == *s)
		return (my_wildcmp(p + 1, s +  1));

	if (*p == '*')
	{
		return (my_wildcmp(p + 1, s) || my_wildcmp(p, s +  1));
	}
	return (false);
}

/**
 * wildcmp - Function to compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if identical or 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	bool ans = my_wildcmp(s2, s1);

	if (ans == true)
	{
		return (1);
	}
	return (0);
}
