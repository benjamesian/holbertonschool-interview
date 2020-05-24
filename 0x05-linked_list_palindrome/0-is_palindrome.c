#include "lists.h"

/**
 * helper - check if a singly linked list is a palindrome
 * @pfront: pointer to a node in the list
 * @back: pointer to a node further along in the list
 * Return: 0 if not a palindrome, 2 if a palindome, 1 if still checking
 */
int helper(listint_t **pfront, listint_t *back)
{
	int result;
	listint_t *front;

	if (back->next)
	{
		result = helper(pfront, back->next);
		if (result == 0)
			return (0);
		else if (result == 1)
			return (1);
	}

	front = *pfront;
	if (front->n == back->n)
	{
		if (front == back || front->next == back)
			return (1);
		*pfront = front->next;
		return (2);
	}

	return (0);
}

/**
 * is_palindrome - check if a linked list is a palindrome
 * @head: first node in linked list
 * Return: 0 is the list is not a palindrome, else 1
 */
int is_palindrome(listint_t **head)
{
	listint_t *p;

	if (head == NULL || *head == NULL)
		return (1);

	p = *head;
	return (helper(&p, p));
}
