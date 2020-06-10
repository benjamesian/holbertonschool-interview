#include "lists.h"

/**
 * check_cycle - checks for a cycle in a linked list
 * @list: linked list
 * Return: 1 if there is a cycle in the list else 0
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *fast = list;

	if (!list)
		return (0);

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}

	return (0);
}
