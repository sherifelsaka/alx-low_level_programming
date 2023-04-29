#include "lists.h"

/**
 * looped_listint_count - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 * Owner by Sherif Elsaka
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *slow, *fast;
	size_t count = 0;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			do {
				count++;
				slow = slow->next;
				fast = fast->next->next;
			} while (slow != fast);

			count = 1;

			while (slow->next != fast)
			{
				count++;
				slow = slow->next;
			}

			return (count);
		}
	}

	return (0);
}

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
