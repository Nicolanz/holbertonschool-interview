#include "binary_trees.h"
/**
 * sorted_array_to_avl - Creates array from AVL
 * @array: array
 * @size: size
 * Return: newtreenode
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t i = 0;
	binary_tree_t *newTreeNode;

	while (i < size)
	{
		newTreeNode = malloc(sizeof(binary_tree_t));

		if (newTreeNode == NULL)
			return (NULL);

		newTreeNode->parent = NULL;
		newTreeNode->n = array[i];
		newTreeNode->left = NULL;
		newTreeNode->right = NULL;
		i++;
	}
	return (newTreeNode);
}
