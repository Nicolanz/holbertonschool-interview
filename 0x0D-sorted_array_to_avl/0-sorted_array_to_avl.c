#include "binary_trees.h"
/**
 * newnode - Creates new nodes
 * @value: value
 * Return: newnode
 */
avl_t *newnode(int value)
{
	avl_t *newTreeNode;

	newTreeNode = malloc(sizeof(avl_t));
	if (newTreeNode == NULL)
	{
		return (NULL);
	}
	else
	{
		newTreeNode->n = value;
		newTreeNode->parent = NULL;
		newTreeNode->left = NULL;
		newTreeNode->right = NULL;
		return (newTreeNode);
	}
}
/**
 * createTree - Function to create a tree
 * @array: array
 * @start: Start
 * @end: End
 * Return: newnode
 */
avl_t *createTree(int *array, int start, int end)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;
	avl_t *root = newnode(array[mid]);

	root->left = createTree(array, start, mid - 1);

	root->right = createTree(array, mid + 1, end);

	return (root);
}

/**
 * sorted_array_to_avl - Creates array from AVL
 * @array: array
 * @size: size
 * Return: newtreenode
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	avl_t *root = createTree(array, start, end);

	return (root);
}

