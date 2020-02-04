#include <stdlib.h>
#include "sort.h"
/**
* swap - function to swap two nodes
* @nodeL: Node
* @nodeR: Node
* Return: Void
*/
void swap(listint_t *nodeL, listint_t *nodeR)
{
listint_t *conL, *conR;

if (nodeL->prev)
	nodeL->prev->next = nodeR;
if (nodeR->next)
	nodeR->next->prev = nodeL;
conL = nodeL->prev;
conR = nodeR->next;
nodeR->prev = conL;
nodeR->next = nodeL;
nodeL->prev = nodeR;
nodeL->next = conR;
}
/**
* insertion_sort_list - sort an array
* @list: The double pointer to the head
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
listint_t *tmp1;

	if (!list)
		return;

	tmp1 = (*list)->next;

	while (tmp1)
	{
		while (tmp1->prev && (tmp1->n < (tmp1->prev)->n))
		{
			swap(tmp1->prev, tmp1);
			if (tmp1->prev == NULL)
				*list = tmp1;
			print_list(*list);
		}
	tmp1 = tmp1->next;
	}
}
