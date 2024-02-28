#include "binary_trees.h"

levelorder_queue_t *create_queue_node(binary_tree_t *node);
void destroy_queue(levelorder_queue_t *head);
void enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void dequeue(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_queue_node - Creates a new levelorder_queue_t node
 * @node: node for the new node to contain
 * Return: NULL on error; Pointer to new node otherwise
 */
levelorder_queue_t *create_queue_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * destroy_queue - Frees a levelorder_queue_t queue
 * @head: head of the queue
 */
void destroy_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * enqueue  - pushes a node to the back of a levelorder_queue_t queue
 *
 * @node: binary tree node to print and push.
 * @head: head of the queue
 * @tail: tail of the queue
 */
void enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_queue_node(node);
	if (new == NULL)
	{
		destroy_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * dequeue - pops the head of levelorder_queue_t queue
 *
 * @head: head of the queue
 */
void dequeue(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: root node of the tree to check.
 * Return: 0 if the tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_queue_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				destroy_queue(head);
				return (0);
			}
			enqueue(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				destroy_queue(head);
				return (0);
			}
			enqueue(head->node->right, head, &tail);
		}
		else
			flag = 1;
		dequeue(&head);
	}
	return (1);
}
