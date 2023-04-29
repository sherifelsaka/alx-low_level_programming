#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list.
 * @head: A pointer to the address of the head of the listint_t list.
 * Return: If the linked list is empty - 0.
 * Owner by Sherif Elsaka
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp = *head;
	int ret = (*head)->n;

	if (head == NULL || *head == NULL)

		return (0);

	*head = (*head)->next;
	free(tmp);

	return (ret);
}
