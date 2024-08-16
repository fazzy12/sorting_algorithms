#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        next_node = current->next;
        temp = current->prev;

        while (temp != NULL && current->n < temp->n)
        {
            if (temp->prev != NULL)
                temp->prev->next = current;
            if (current->next != NULL)
                current->next->prev = temp;

            temp->next = current->next;
            current->prev = temp->prev;
            temp->prev = current;
            current->next = temp;

            if (current->prev == NULL)
                *list = current;
            else
                current->prev->next = current;

            print_list(*list);
            temp = current->prev;
        }
        current = next_node;
    }
}
