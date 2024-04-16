#include "sort.h"

/**
 * swap - swaps two nodes
 * @head: head of the list
 * @nd1: first node to sort
 * @nd2: second node to sort
 */
void swap(listint_t **head, listint_t *nd1, listint_t *nd2)
{
	listint_t *prev, *next;

	prev = nd1->prev;
	next = nd2->next;

	if (prev != NULL)
		prev->next = nd2;
	else
		*head = nd2;
	nd1->prev = nd2;
	nd1->next = next;
	nd2->prev = prev;
	nd2->next = nd1;
	if (next)
		next->prev = nd1;
}
/**
 * cocktail_sort_list - sorts a list using the cocktail sort
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int flag = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap(list, head, head->next);
				print_list(*list);
				flag = 1;
				head = head->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap(list, head->prev, head);
				print_list(*list);
				flag = 1;
				head = head->next;
			}
		}
	} while (flag == 1);
}
