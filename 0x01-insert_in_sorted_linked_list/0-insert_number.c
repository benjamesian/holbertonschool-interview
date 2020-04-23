#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - insert a node into a sorted linked list
 * @head: pointer to list
 * @number: value to insert
 * Return: address of inserted node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new = NULL, *temp = NULL;

    if (!head)
        return (NULL);

    new = malloc(sizeof(*new));
    if (!new)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (!*head)
        *head = new;
    else if (number < (*head)->n)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        temp = *head;
        while (temp->next && temp->next->n < number)
            temp = temp->next;
        new->next = temp->next;
        temp->next = new;
    }

    return (new);
}
