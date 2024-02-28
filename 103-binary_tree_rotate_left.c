#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: root node of the tree to rotate
 * Return: new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *piv, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	piv = tree->right;
	tmp = piv->left;
	piv->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = piv;
	piv->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = piv;
		else
			tmp->right = piv;
	}

	return (piv);
}
