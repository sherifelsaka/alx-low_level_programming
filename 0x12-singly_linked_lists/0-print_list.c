#include "lists.h"

/**
 * print_list - Prints all the elements of a linked list.
 * @h: A pointer to the head of the linked list.
 * Return: The number of nodes in the linked list.
 * Owner by Sherif Elsaka
 */
size_t print_list(const list_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);

		node_count++;
		h = h->next;
	}

	return (node_count);
}
