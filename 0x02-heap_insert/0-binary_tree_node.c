#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = calloc(1, sizeof(*new));

	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;

	return (new);
}
