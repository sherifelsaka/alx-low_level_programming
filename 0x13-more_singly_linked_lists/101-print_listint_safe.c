#include "lists.h"

/**
 * looped_listint_len - Counts the number of unique
 * nodes in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 * Owner By Sherif Elsaka
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;

	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			size_t count = 1;

			hare = hare->next;

			while (tortoise != hare)
			{
				count++;
				hare = hare->next;
			}

			return (count);
		}
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 * Return: The number of nodes in the list.
 * Owner By Sherif Elsaka
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		if (head <= head->next)
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}

		head = head->next;
	}

	return (count);
}
