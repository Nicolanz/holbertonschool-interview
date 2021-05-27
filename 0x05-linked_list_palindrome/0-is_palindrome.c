#include "lists.h"
/**
 * is_palindrome - Checks if a linked list is palindrome
 * @head: pointer to the head node
 * Return: True if palindorme or false if not palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *tmp = *head;
	int i, j = 0;
	int arr[10000];

	if (*head == NULL)
	{
		return (0);
	}
	while (tmp != NULL)
	{
		arr[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	tmp = *head;
	j = i;
	i--;
	while (i >= 0)
	{
		if (tmp->n != arr[i])
		{
			return (0);
		}
		if (i < j / 2)
		{
			return (1);
		}
		tmp = tmp->next;
		i--;
	}
	return (1);
}
