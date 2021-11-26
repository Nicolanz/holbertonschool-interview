#include "binary_trees.h"
/**
 * max - max of 2 values
 * @a: a variable
 * @b: b variable
 * Return: max value
 */
int max(int a, int b)
{
	return ((a >= b) ? a : b);
}

/**
 * height - height of the tree
 * @tree: pointer to the node
 * Return: heigh of the tree
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * check_avl - check for correct AVL trees
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is valid AVL tree
 *
 */
int check_avl(const binary_tree_t *tree)
{
	int lh;
	int rh;

	if (tree == NULL)
		return (1);
	lh = height(tree->left);
	rh = height(tree->right);
	if (abs(lh - rh) <= 1 && check_avl(tree->left) == 1 &&
	    check_avl(tree->right) == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - check for correct AVL trees
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is valid AVL tree
 *
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_avl(tree));
}
