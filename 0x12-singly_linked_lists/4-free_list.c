#include "lists.h"

/**
 * free_list - Frees a linked list.
 * @head: A pointer to the head of the linked list.
 * Return: void.
 * Owner by Sherif Elsaka
 */
void free_list(list_t *head)
{
	list_t *current, *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}
