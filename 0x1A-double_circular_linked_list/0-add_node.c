#include "list.h"

/**
 * add_node_end - Add node at the end of double circular linked list
 * @list: Pointer to the head
 * @str: value of str
 *
 * Return: new linked node
 */
List *add_node_end(List **list, char *str)
{

	List *new = malloc(sizeof(List));

	if (new == NULL)
		return (NULL);

	new->str = str;

	if (*list == NULL)
	{
		new->next = new->prev = new;
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
 * add_node_begin - Add node at the begin of double circular linked list
 * @list: Pointer to the head
 * @str: value of str
 *
 * Return: new linked node
 */
List *add_node_begin(List **list, char *str)
{

	List *new = malloc(sizeof(List));

	if (new == NULL)
		return (NULL);

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
