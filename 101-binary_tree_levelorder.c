#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_height - measures the height of a binary tree from a given node
 *
 * @tree: tree to measure
 *
 * Return: 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((lef > rig) ? lef : rig);
	}

	return (0);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
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
		perform_on_level(tree, j, func);
}

/**
 * perform_on_level - perform a function on a specific level of a binary tree
 * @tree: pointer to the root of the tree
 * @level: level of the tree to perform a function on
 * @func: function to perform
 */
void perform_on_level(const binary_tree_t *tree, size_t level,
		void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		perform_on_level(tree->left, level - 1, func);
		perform_on_level(tree->right, level - 1, func);
	}
}
