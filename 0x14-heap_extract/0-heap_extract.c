#include "binary_trees.h"

/**
 * _binary_tree_size - get the size of a binary tree
 * @tree: tree to find the size of
 *
 * Return: size of the tree.
 */
size_t _binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 +
			_binary_tree_size(tree->left) +
			_binary_tree_size(tree->right));
}

/**
 * find_last - find path to node at size
 * @root: root node
 * @size: size of tree
 *
 * Return: node at size
 */
heap_t *find_last(heap_t *root, size_t size)
{
	if (size < 2)
		return (root);
	if (size % 2)
		return (find_last(root, size / 2)->right);
	return (find_last(root, size / 2)->left);
}

/**
 * sink - value at root down to where it belongs
 * @root: node in max heap
 */
void sink(heap_t *root)
{
	heap_t *next = NULL;
	int temp;

	if (root->left && root->right)
	{
		if (root->left->n > root->right->n && root->n < root->left->n)
			next = root->left;
		else if (root->n < root->right->n)
			next = root->right;
	}
	else if (root->left && root->n < root->left->n)
		next = root->left;
	else if (root->right && root->n < root->right->n)
		next = root->right;
	if (!next)
		return;
	temp = root->n;
	root->n = next->n;
	next->n = temp;
	sink(next);
}

/**
 * heap_extract - remove the maximal element in the heap
 * @root: root node of the heap
 *
 * Return: value of maximal element or 0
 */
int heap_extract(heap_t **root)
{
	heap_t *p, *last;
	size_t size;
	int out = 0;

	if (!root || !*root)
		return (0);
	p = *root;
	out = p->n;
	size = _binary_tree_size(p);
	last = find_last(p, size);
	if (last != p)
	{
		p->n = last->n;
		if (last == last->parent->left)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
		sink(p);
	}
	else
		*root = NULL;
	free(last);
	return (out);
}
