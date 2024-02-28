#include "binary_trees.h"
#include "9-binary_tree_height.c"

void perform_on_level(const binary_tree_t *tree, size_t level, void (*func)(int))

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: root node of the tree to traverse
 * @func: function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, j;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (j = 1; j <= height; j++)
		binary_tree_level(tree, j, func);
}

/**
 * perform_on_level - perform a function on a specific level of a binary tree
 * @tree: pointer to the root of the tree
 * @level: level of the tree to perform a function on
 * @func: function to perform
 */
void perform_on_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		perform_on_level(tree->left, level - 1, func);
		perform_on_level(tree->right, level - 1, func);
	}
}
