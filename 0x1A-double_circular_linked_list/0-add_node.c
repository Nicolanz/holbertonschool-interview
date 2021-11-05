#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_end(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL || !(list))
	{
		return (NULL);
	}
	new->str = str;

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	List *last = (*list)->prev;

	new->next = *list;
	(*list)->prev = new;
	new->prev = last;
	last->next = new;

	return (new);
}

/**
 * add_node_begin - Adds a new node to the beginning of a
 *					double circular linked list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_begin(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL || !(list))
	{
		return (NULL);
	}

	new->str = str;

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	List *last = (*list)->prev;

	new->next = *list;
	new->prev = last;
	last->next = (*list)->prev = new;
	*list = new;

	return (new);
}
