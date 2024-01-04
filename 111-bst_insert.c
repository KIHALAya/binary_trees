#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	return (bst_insert_recursive(tree, NULL, value));
}

/**
 * bst_insert_recursive - Recursively inserts a value
 * in a Binary Search Tree
 * @tree: Double pointer to the current root node of the BST
 * @parent: Pointer to the parent node of the current root node
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert_recursive(bst_t **tree, bst_t *parent, int value)
{
	if (!(*tree))
	{
		*tree = binary_tree_node(parent, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		return (bst_insert_recursive(&((*tree)->left), *tree, value));

	if (value > (*tree)->n)
		return (bst_insert_recursive(&((*tree)->right), *tree, value));

	return (NULL);
}

