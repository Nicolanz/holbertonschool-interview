#include "lists.h"
/**
 * insert_node - Inserts node in singly linled list
 * @head: Pointer to the head of the list
 * @number: Value of the new node
 * Return: new node or NULL if it fails
 *
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *tmp;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	tmp = *head;
	if (tmp == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	if (tmp->n >= new->n)
	{
		new->next = tmp;
		*head = new;
		return (new);
	}
	if (tmp->next == NULL)
	{
		new->next = NULL;
		tmp->next = new;
		return (new);
	}
	while (tmp->next->n <= new->n)
	{
		if (tmp->next->next == NULL)
		{
			tmp = tmp->next;
			new->next = NULL;
			tmp->next = new;
			return (new);
		}
		tmp = tmp->next;
	}
	new->next = tmp->next;
	tmp->next = new;
	return (new);
}
