#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *p = list;

	if (!list)
		return (NULL);

	while ((p = p->express))
	{
		printf("Value checked at index [%li] = [%i]\n",
		       p->index, p->n);
		if (p->n >= value)
			break;
		list = p;

		if (!p->express)
		{
			while (p->next)
				p = p->next;
			break;
		}
	}
	printf("Value found between indexes [%li] and [%li]\n",
	       list->index, p->index);
	while (list != p->express)
	{
		printf("Value checked at index [%li] = [%i]\n",
		       list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
