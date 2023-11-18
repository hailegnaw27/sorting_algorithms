#include "sort.h"

/**
 * insertion_sort_list - Applies the insertion sort algorithm on a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr = *list, *tmp = NULL;

    if (!list || !(*list) || !(*list)->next)
        return;

    curr = curr->next;
    while (curr != NULL)
    {
        tmp = curr;
        curr = curr->next;

        while (tmp->prev && tmp->prev->n > tmp->n)
        {
            tmp->prev->next = tmp->next;
            if (tmp->next)
                tmp->next->prev = tmp->prev;
            tmp->next = tmp->prev;
            tmp->prev = tmp->next->prev;
            tmp->next->prev = tmp;

            if (tmp->prev == NULL)
                *list = tmp;
            else
                tmp->prev->next = tmp;

            print_list(*list);
        }
    }
}
