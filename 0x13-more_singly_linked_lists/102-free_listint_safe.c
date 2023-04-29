#include "lists.h"

/**
 * looped_listint_count - Counts the number of
 * unique nodes in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 * Owner by Sherif Elsaka
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			size_t count = 1;

			fast = fast->next;

			while (slow != fast)
			{
				count++;
				fast = fast->next;
			}

			return (count);
		}
	}

	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely
 * (i.e. can free lists containing loops)
 * @h: A pointer to the address of the head of the listint_t list.
 * Return: The size of the list that was freed.
 * Description: The function sets the head to NULL.
 * Owner By Sherif Elsaka
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0, nodes = looped_listint_count(*h);
	listint_t *current = *h, *temp;

	if (*h == NULL)
		return (count);

	if (nodes > 0)
	{
		while (count < nodes)
		{
			temp = current;
			current = current->next;
			free(temp);
			count++;
		}

		*h = NULL;
		return (count);
	}

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
		count++;

		if (current >= temp)
			break;
	}

	*h = NULL;
	return (count);
}
