#include "lists.h"

/**
 * find_listint_loop - checks for a cycle in a linked list
 * @head: linked list
 * Return: 1 if there is a cycle in the list else 0
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (slow);
	}

	return (NULL);
}
