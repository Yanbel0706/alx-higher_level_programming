#include "lists.h"

/**
 ** insert_node - a function  inserting a number
 ** into a sorted singly linked list
 ** @head: a pointer the head of the linked list.
 ** @number: the number to insert.
 ** Return: NULL if failure
 ** On success - a pointer to the new node.
 **/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *new_n;

	new_n = malloc(sizeof(listint_t));
	if (new_n == NULL)
		return (NULL);
	new_n->n = number;
	if (node == NULL || node->n >= number)
	{
		new_n->next = node;
		*head = new_n;
		return (new_n);
	}
	while (node && node->next && node->next->n < number)
		node = node->next;
	new_n->next = node->next;
	node->next = new_n;
	return (new_n);
}
