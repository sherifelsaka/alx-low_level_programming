#include "lists.h"

/**
 * looped_listint_len - Counts the number of
 * unique nodes in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 * Owner by Sherif Elsaka
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise = head;
	const listint_t *hare = head;
	size_t count = 1;

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
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 * Return: The number of nodes in the list.
 * Owner by Sherif Elsaka
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const size_t len = looped_listint_len(head);

	if (head == NULL)
		return (0);

	while (head != NULL && (len == 0 || count < len))
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		count++;
	}

	if (len > 0)
		printf("-> [%p] %d\n", (void *)head, head->n);

	return (count);
}
