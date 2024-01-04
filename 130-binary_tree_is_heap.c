#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree
 * is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap,
 * 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete_heap(tree) && is_heap(tree, INT_MIN));
}

/**
 * is_complete_heap - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (is_complete_heap(tree->left) && is_complete_heap(tree->right))
		return (binary_tree_size(tree->left) == binary_tree_size(tree->right));

	return (0);
}

/**
 * is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 * @max: The maximum value encountered so far.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int is_heap(const binary_tree_t *tree, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= max)
		return (0);

	return (is_heap(tree->left, tree->n) && is_heap(tree->right, tree->n));
}
