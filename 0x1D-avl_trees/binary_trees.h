#ifndef BINARY_TREES
#define BINARY_TREES

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s);
int height(const binary_tree_t *tree);
int max(int x, int y);
void binary_tree_print(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* BINARY_TREES */
