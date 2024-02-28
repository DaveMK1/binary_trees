#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: node of the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *x, *y;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	x = first->parent, y = second->parent;
	if (first == y || !x || (!x->parent && y))
		return (binary_trees_ancestor(first, y));
	else if (x == second || !y || (!y->parent && x))
		return (binary_trees_ancestor(x, second));

	return (binary_trees_ancestor(x, y));
}
