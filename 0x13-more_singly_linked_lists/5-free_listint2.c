#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: A pointer to the address of the head of the listint_t list.
 * Description: Sets the head to NULL.
 * Owner by Sherif Elsaka
 */
void free_listint2(listint_t **head)
{
	if (head == NULL)
		return;

	while (*head != NULL)
	{
		listint_t *tmp = (*head)->next;

		free(*head);
		*head = tmp;
	}

	*head = NULL;
}
