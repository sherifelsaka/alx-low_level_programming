#include "lists.h"

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
