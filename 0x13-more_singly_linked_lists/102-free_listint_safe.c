#include "lists.h"

/**
 * looped_listint_count - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 * Owner By Sherif Elsaka
 */
size_t looped_listint_count(listint_t *head)
{
	size_t count = 1;
	listint_t *tortoise = head;
	listint_t *hare = head;

	if (head == NULL || head->next == NULL)
	return (0);

	do {
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (hare == NULL || hare->next == NULL)
			return (0);

	} while (tortoise != hare);

	tortoise = tortoise->next;

	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		count++;
	}

	return (count);
}

/**
 * free_listint_safe - Frees a listint_t list safely (i.e.
 * can free lists containing loops)
 * @h: A pointer to the address of the head of the listint_t list.
 * Return: The size of the list that was freed.
 * Description: The function sets the head to NULL.
 * Owner By Sherif Elsaka
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	const size_t len = looped_listint_count(*h);

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL && (len == 0 || count < len))
	{
		listint_t *tmp = (*h)->next;

		free(*h);
		*h = tmp;
		count++;
	}

	*h = NULL;

	return (count);
}
