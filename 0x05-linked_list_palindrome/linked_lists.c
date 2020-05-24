#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num_nodes = 0;

	while (h != NULL)
	{
		num_nodes++;
		printf("%i\n", h->n);
		h = h->next;
	}

	return (num_nodes);
}

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to pointer to first node of listint_t list
 * @n: integer to be included in the new node
 * Return: address of the new element or NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *current;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	current = *head;
	if (!current)
		*head = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}

	return (new);
}

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
}
