#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds
 * the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node,
 * or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	binary_tree_t *ancestor;

	while (first)
	{
		ancestor = (binary_tree_t *)second;

		while (ancestor)
		{
			if (ancestor == first)
				return ((binary_tree_t *)ancestor);

			ancestor = ancestor->parent;
		}

		first = first->parent;
	}

	return (NULL);
}

