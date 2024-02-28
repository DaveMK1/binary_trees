#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: tree to be checked
 * Return: 1 if the tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int right, left;

	right = left = 0;
	if (
		tree == NULL ||
		(tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL)
	)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);
	if (right == 1 && left == 1)
		return (1);

	return (0);
}
