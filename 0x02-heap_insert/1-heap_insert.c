#include "binary_trees.h"

/**
 * get_size - get the size of a tree
 * @root: root of tree
 * Return: size of the tree
 */
size_t get_size(heap_t *root)
{
	return (root ? 1 + get_size(root->left) + get_size(root->right) : 0);
}

/**
 * get_next_parent - return parent of next node to be inserted
 * @root: root of the tree
 * @n: half of the size of the tree
 * Return: pointer to next parent node
 */
heap_t *get_next_parent(heap_t *root, size_t n)
{
	if (n < 2)
		return (root);
	if (n % 2)
		return (get_next_parent(root, n / 2)->right);
	else
		return (get_next_parent(root, n / 2)->left);
}

/**
 * assign_parent - set a parent's childrens' parent properly
 * @node: parent node
 */
void assign_parent(heap_t *node)
{
	if (node->left)
		node->left->parent = node;
	if (node->right)
		node->right->parent = node;
}

/**
 * bubble - raise a node to it's proper position in a max-heap
 * @node: node to move in max-heap
 * Return: 1 if node moves to the top, else 0
 */
int bubble(heap_t *node)
{
	heap_t *temp = NULL, *parent = NULL;

	parent = node->parent;
	while (parent && node->n > parent->n)
	{
		if (node == parent->left)
		{
			temp = parent->right;
			parent->right = node->right;
			parent->left = node->left;
			node->right = temp;
			node->left = parent;
		}
		else
		{
			temp = parent->left;
			parent->right = node->right;
			parent->left = node->left;
			node->right = parent;
			node->left = temp;
		}
		node->parent = parent->parent;
		if (parent->parent)
		{
			if (parent->parent->left == parent)
				parent->parent->left = node;
			else
				parent->parent->right = node;
		}
		parent->parent = node;
		if (temp)
			temp->parent = node;
		assign_parent(parent);

		parent = node->parent;
	}
	return (!parent);
}

/**
 * heap_insert - insert a node into a max-heap
 * @root: pointer to top of max-heap
 * @value: value to insert
 * Return: pointer to newly created node, else NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int new_root = 0;
	heap_t *new = NULL, *temp = NULL;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new = binary_tree_node(NULL, value);
		*root = new;
	}
	else
	{
		temp = get_next_parent(*root, (get_size(*root) + 1) / 2);
		new = binary_tree_node(temp, value);
		if (temp->left)
			temp->right = new;
		else
			temp->left = new;
	}

	if (new)
		new_root = bubble(new);
	if (new_root)
		*root = new;
	return (new);
}
