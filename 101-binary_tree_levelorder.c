#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	size_t front = 0, rear = 0;

	if (!queue)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		func(current->n);

		if (current->left)
			queue[rear++] = current->left;

		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
}

