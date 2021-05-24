#include "lists.h"
/**
 * addNode - Adds node to the head of the linked list
 * @new: Pointer to the new linked list
 * @n: value of the node
 * Return: The new node
 */
listint_t *addNode(listint_t **new, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = *new;
	*new = newnode;
	return (newnode);
}
/**
 * is_palindrome - Checks if a linked list is palindrome
 * @head: pointer to the head node
 * Return: True if palindorme or false if not palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *tmp = *head;
	listint_t *new = NULL;
	listint_t *tmp_two, *new_two;

	if (tmp == NULL)
	{
		return (0);
	}
	else if (tmp->next == NULL)
	{
		return (1);
	}
	while (tmp->next != NULL)
	{
		addNode(&new, tmp->n);
		tmp = tmp->next;
		if (tmp->next == NULL)
		{
			addNode(&new, tmp->n);
		}
	}
	tmp_two = *head;
	new_two = new;
	while (new_two->next != NULL && tmp_two->next != NULL)
	{
		if (new_two->n != tmp_two->n)
		{
			return (0);
		}
		new_two = new_two->next;
		tmp_two = tmp_two->next;
		if (new_two->next == NULL && tmp_two->next == NULL)
		{
			if (new_two->n != tmp_two->n)
			{
				return (0);
			}
		}
	}
	return (1);
}
