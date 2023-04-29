#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning
 * of a listint_t list.
 * @head: A pointer to the address of the
 * head of the listint_t list.
 * @n: The integer for the new node to contain.
 * Return: If the function fails - NULL.
 * Otherwise - the address of the new element.
 * Owner by Sherif Elsaka
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;

	*head = new_node;

	return (new_node);
}
