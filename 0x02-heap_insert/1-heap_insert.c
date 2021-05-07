#include "binary_trees.h"
/**
 * treeHeight- Height of bt
 * @tmp: Pointer to tmp
 * Return: number
 */
int treeHeight(heap_t *tmp)
{
	int right = 1;
	int left = 1;

	if (tmp == NULL)
	{
		return (0);
	}
	else
	{
		right += treeHeight(tmp->left);
		left += treeHeight(tmp->right);
	}
	if (right >= left)
	{
		return (right);
	}
	else
	{
		return (left);
	}
}

/**
 * getTheLastNode - Gets last node
 * @tmp: tmp var
 * @height: height of bt
 * Return: returns node of binary tree
 *
 */

heap_t getTheLastNode(heap_t *tmp, int height)
{
	if (height == 1)
	{
		return (*tmp);
	}
	else if (height > 1)
	{
		getTheLastNode(tmp->left, height--);
		getTheLastNode(tmp->right, height--);
	}
	return (*tmp);
}
/**
 * heap_insert - Heaps Insert Fucntion
 * @root: root of the bt
 * @value: Value of the bt
 * Return: Return a heat max bt
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newnode;
	heap_t *tmp = *root;
	int height = 0;

	newnode = malloc(sizeof(heap_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = value;
	if (*root == NULL)
	{
		*root = newnode;
		newnode->parent = NULL;
		newnode->left = NULL;
		newnode->right = NULL;
	}
	else
	{
		height = treeHeight(tmp);
		*tmp = getTheLastNode(tmp, height);
		tmp->left = newnode;
		newnode->parent = tmp;
		newnode->left = NULL;
		newnode->right = NULL;
	}
	return (newnode);
}
