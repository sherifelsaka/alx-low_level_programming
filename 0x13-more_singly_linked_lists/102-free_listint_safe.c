#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *tortoise = NULL, *hare = NULL;
	size_t nodes = 0;

	if (head == NULL || head->next == NULL)
	return (nodes);

	tortoise = head->next;
	hare = head->next->next;

	while (hare != NULL && hare->next != NULL)
	{
		if (tortoise == hare)
		{
			nodes = 1;
			tortoise = tortoise->next;

			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			}

			tortoise = head;

			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			return (nodes);
		}

		tortoise = tortoise->next;
		hare = hare->next->next;
	}

	return (nodes);
}

/**
 * free_listint_safe - Frees a listint_t list safely (ie.
 * can free lists containing loops)
 * @h: A pointer to the address of
 * the head of the listint_t list.
 * Return: The size of the list that was freed.
 * Description: The function sets the head to NULL.
 * Owner by Sherif Elsaka
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0, i = 0;
	listint_t *current = NULL, *tmp = NULL;

	nodes = looped_listint_count(*h);

	if (nodes > 0)
	{
		for (i = 0; i < nodes; i++)
		{
			current = *h;
			*h = (*h)->next;
			free(current);
		}
	}
	else
	{
		while (*h != NULL)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			nodes++;
		}
	}

	*h = NULL;

	return (nodes);
}
