#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at
 * a given index of a listint_t list.
 * @head: A pointer to the address of the head of the listint_t list.
 * @index: The index of the node to be deleted - indices start at 0.
 * Return: On success - 1.
 * Owner by Sherif Elsaka
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev = NULL, *current = *head;
	unsigned int i;

	if (current == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	for (i = 0; i < index && current != NULL; i++)
	{
		prev = current;
		current = current->next;
	}

	if (i < index || current == NULL)
		return (-1);

	prev->next = current->next;
	free(current);

	return (1);
}
