#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if no uncle is found
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	binary_tree_t *grandparent = node->parent->parent;

	if (grandparent->left && grandparent->left != node->parent)
		return (grandparent->left);

	if (grandparent->right && grandparent->right != node->parent)
		return (grandparent->right);

	return (NULL);
}

