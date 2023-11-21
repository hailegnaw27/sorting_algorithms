#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: The doubly linked list
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
    listint_t *tmp_prev, *tmp_next;

    tmp_prev = (*node1)->prev;
    tmp_next = (*node2)->next;

    if (tmp_prev)
        tmp_prev->next = (*node2);
    else
        *list = (*node2);
    if (tmp_next)
        tmp_next->prev = (*node1);

    (*node1)->prev = (*node2);
    (*node2)->next = (*node1);

    (*node1)->next = tmp_next;
    (*node2)->prev = tmp_prev;
}

/**
 * cocktail_sort_list - Applies the cocktail shaker sort algorithm on a doubly linked list
 * @list: The doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current;

    if (!list || !(*list) || !(*list)->next)
        return;

    while (swapped)
    {
        swapped = 0;

        for (current = *list; current->next; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &(current->next));
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        for (; current->prev; current = current->prev)
        {
            if (current->prev->n > current->n)
            {
                swap_nodes(list, &(current->prev), &current);
                print_list(*list);
                swapped = 1;
            }
        }
    }
}
