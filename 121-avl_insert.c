#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&(*tree)->left, value);
		if (binary_tree_balance(*tree) == 2)
		{
			if (value < (*tree)->left->n)
				node = binary_tree_rotate_right(*tree);
			else
			{
				(*tree)->left = binary_tree_rotate_left((*tree)->left);
				node = binary_tree_rotate_right(*tree);
			}
		}
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&(*tree)->right, value);
		if (binary_tree_balance(*tree) == -2)
		{
			if (value > (*tree)->right->n)
				node = binary_tree_rotate_left(*tree);
			else
			{
				(*tree)->right = binary_tree_rotate_right((*tree)->right);
				node = binary_tree_rotate_left(*tree);
			}
		}
	}

	if (!node)
		return (*tree);

	if (!(*tree)->parent)
		*tree = node;

	return (node);
}

