#include "lists.h"

/**
 * add_nodeint_end - Adds a new node
 * @head: A pointer to the address
 * @n: The integer for the new node to contain.
 * Return: If the function fails
 * Owner by Sherif Elsaka
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *new_node = malloc(sizeof(*new_node));
	listint_t *last_node = *head;

	if (head == NULL)
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}

	while (last_node->next != NULL)
		last_node = last_node->next;

	last_node->next = new_node;

	return (*head);
}
