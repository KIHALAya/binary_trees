#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (_helper(array, 0, size - 1, NULL));
}

/**
 * _helper - Recursive helper function for array to AVL conversion.
 * @array: A pointer to the first element of the array.
 * @start: The starting index of the current subarray.
 * @end: The ending index of the current subarray.
 * @parent: A pointer to the parent node.
 *
 * Return: A pointer to the root node of the current subtree.
 */
avl_t *_helper(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *new_node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new_node = binary_tree_node(parent, array[mid]);
	if (new_node == NULL)
		return (NULL);

	new_node->left = _helper(array, start, mid - 1, new_node);
	new_node->right = _helper(array, mid + 1, end, new_node);

	return (new_node);
}

