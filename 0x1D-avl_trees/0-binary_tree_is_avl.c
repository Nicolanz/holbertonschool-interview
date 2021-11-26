#include "binary_trees.h"
/**
 * max - max of 2 values
 * @x: x variable
 * @y: y variable
 * Return: max value
 */
int max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

/**
 * height - height the binary tree
 * @node: pointer to the node
 * Return: heigh of the tree
 */
int height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + max(height(node->left), height(node->right)));
}

/**
 * binary_tree_is_avl - check for correct AVL trees
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is valid AVL tree
 *
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lh;
	int rh;

	if (tree == NULL)
		return (1);
	lh = height(tree->left);
	rh = height(tree->right);
	if (abs(lh - rh) <= 1 && AVL(tree->left) && AVL(tree->right))
		return (1);
	return (0);
}
