#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: Pointer to the head of the list
 * Return: The size of the list that was freed
 * Owner by Sherif Elsaka
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t size = 0;

	if (h == NULL || *h == NULL)
		return (0);

	for (current = *h; current != NULL; current = next)
	{
		next = current->next;
		free(current);
		size++;

		if (next >= current)
			break;
	}

	*h = NULL;

	return (size);
}
