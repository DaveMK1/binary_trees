/**
 * binary_tree_is_leaf - checks if a node is a leaf
 *
 * @node: node to check
 *
 * Return: 0 if the node is a leaf, otherwise 1
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (1);

	return (0);
}
