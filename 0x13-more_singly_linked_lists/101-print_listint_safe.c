#include "lists.h"

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 * Owner by Sherif Elsaka
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head->next;
	fast = (head->next)->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
		{
			size_t count = 1;

			slow = slow->next;

			while (slow != fast)
			{
				count++;
				slow = slow->next;
			}

			return (count);
		}

		slow = slow->next;
		fast = (fast->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: Pointer to the head of the list
 * Return: The number of nodes in the list
 * Owner by Sherif Elsaka
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current, *next;
	size_t count = 0;

	if (head == NULL)
		return (0);

	current = head;

	while (current != NULL)
	{
		next = current->next;
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		if (next >= current)
		{
			printf("-> [%p] %d\n", (void *)next, next->n);
			fprintf(stderr, "Error: linked list has a loop\n");
			exit(98);
		}

		current = next;
	}

	return (count);
}
