#include "lists.h"

/**
 * _realloc_ptr_listint - Reallocates memory for an array of pointers
 * to the nodes in a linked list.
 * @list: The old list to append.
 * @size: Size of the new list (always one more than the old list).
 * @new_node: New node to add to the list.
 * Return: Pointer to the new list.
 * Owner By Sherif Elsaka
 */
const listint_t **_realloc_ptr_listint(const listint_t **list,
		size_t size, const listint_t *new_node)
{
	const listint_t **new_list = malloc(size * sizeof(listint_t *));
	size_t i = 0;

	if (new_list == NULL)
	{
		free(list);
		exit(98);
	}

	for (; i < size - 1; i++)
		new_list[i] = list[i];

	new_list[size - 1] = new_node;
	free(list);

	return (new_list);
}

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the start of the list.
 * Return: The number of nodes in the list.
 * Owner By Sherif Elsaka
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t **visited_nodes = NULL;
	size_t num_nodes = 0;
	size_t i = 0;

	while (head != NULL)
	{
		for (; i < num_nodes; i++)
		{
			if (head == visited_nodes[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(visited_nodes);
				return (num_nodes);
			}
		}

		num_nodes++;
		visited_nodes = _realloc_ptr_listint(visited_nodes, num_nodes, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}

	free(visited_nodes);

	return (num_nodes);
}
