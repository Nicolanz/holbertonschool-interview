#include "search.h"
/**
* linear_skip - Linear skip function to look for a value
* @list: linked list to check
* @value: value
*
* Return: the new list
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node;
	skiplist_t *tmp;

	node = list;

	if (node == NULL)
		return (NULL);

	while (node->express)
	{
		tmp = node->express;
		printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);

		if (value <= tmp->n)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, tmp->index);
			break;
		}
		node = tmp;
		if (!node->express)
		{
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, tmp->index);
		}
	}

	while (node != tmp)
	{
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	return (NULL);
}
