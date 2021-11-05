#include "list.h"
#include <stdio.h>

/**
 * add_node_begin - Adds a new node to the end of a double circular linked list
 * @list: double circular linked list
 * @str: value of the node
 * Return: new linked node
 */

List *add_node_end(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	if (!*list)
	{
		new->str = str;
		new->prev = new;
		new->next = new;
		*list = new;
	}
	else
	{
		List *tmp = (*list)->prev;

		new->str = str;
		new->next = *list;
		(*list)->prev = new;
		new->prev = tmp;
		tmp->next = new;
	}
	return (new);
}

/**
 * add_node_begin - Adds a new node to the beg of a double circular linked list
 * @list: double circular linked list
 * @str: value of the node
 * Return: new linked node
 */

List *add_node_begin(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	if (!*list)
	{
		new->str = str;
		new->prev = new;
		new->next = new;
		*list = new;
	}
	else
	{
		List *tmp = (*list)->prev;

		new->str = str;
		new->next = *list;
		new->prev = tmp;
		tmp->next = new;
		(*list)->prev = new;
		*list = new;
	}
	return (new);
}
