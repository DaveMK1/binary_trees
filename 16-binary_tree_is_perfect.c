#include "binary_trees.h"

int check_perfection_recursive(const binary_tree_t *tree,
                size_t terminal_depth, size_t level);
size_t calculate_depth(const binary_tree_t *tree);
const binary_tree_t *get_terminal_node(const binary_tree_t *tree);
unsigned char is_terminal(const binary_tree_t *node);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * check_perfection_recursive - checks if binary tree is perfect recursively
 * @tree: root node of the tree to check
 * @terminal_depth: depth of one terminal node in the binary tree
 * @level: Level of current node
 * Return: If the tree is perfect, 1, otherwise 0
 */
int check_perfection_recursive(const binary_tree_t *tree,
		size_t terminal_depth, size_t level)
{
	if (is_terminal(tree))
		return (level == terminal_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (check_perfection_recursive(tree->left, terminal_depth, level + 1) &&
		check_perfection_recursive(tree->right, terminal_depth, level + 1));
}

/**
 * calculate_depth - Returns the depth of a given node
 * @tree: tree node to measure the depth of
 * Return: depth of node
 */
size_t calculate_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + calculate_depth(tree->parent) : 0);
}

/**
 * get_terminal_node - Returns a node of a binary tree.
 * @tree: root node of the tree to find a leaf in
 *
 * Return: first encountered leaf
 */
const binary_tree_t *get_terminal_node(const binary_tree_t *tree)
{
	if (is_terminal(tree) == 1)
		return (tree);
	return (tree->left ? get_terminal_node(tree->left) :
			get_terminal_node(tree->right));
}

/**
 * is_terminal - checks if a node is a terminal node of a binary tree
 * @node: node to check
 * Return: If the node is a terminal node, 1, otherwise, 0
 */
unsigned char is_terminal(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to check
 * Return: 0 if the tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_perfection_recursive(tree,
				calculate_depth(get_terminal_node(tree)), 0));
}
