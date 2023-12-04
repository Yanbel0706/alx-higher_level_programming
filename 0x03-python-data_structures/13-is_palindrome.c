#include "lists.h"

/**
 ** reverse_list - a function  reversing a singly linked list.
 ** @head: pointer to the first node in the list
 ** Return: pointer to the first node of  a reversed linked list.
 **/
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *cur = head, *next;

	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return (prev);
}


/**
 ** is_palindrome - checks if a singly linked list is a palindrome.
 ** @head: the first node of the singly linked list
 ** Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 **/
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *sec_half,
			 	*prev_slow = *head;
	int is_pal = 1;
	if (*head == NULL || (*head)->next == NULL)
	{
		return (1);
	}
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}
	if (fast != NULL)
	{
		slow = slow->next;
	}
	sec_half = reverse_list(slow);
	slow = *head;
	fast = sec_half;
	while (sec_half != NULL)
	{
		if (slow->n != sec_half->n)
		{
			is_pal = 0;
			break;
															}
		slow = slow->next;
		sec_half = sec_half->next;
	}
	prev_slow->next = reverse_list(fast);
	return (is_pal);
}
