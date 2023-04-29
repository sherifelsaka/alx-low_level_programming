#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t list.
 * @head: A pointer to the address of the head of the list_t list.
 * Return: A pointer to the first node of the reversed list.
 * Owner by Sherif Elsaka
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next;

	if (current == NULL)
		return (NULL);

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;

	return (*head);
}
