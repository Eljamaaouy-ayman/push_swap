#include "push_swap.h"


void sa(numbers **list_nbr)
{
    numbers *first;
    numbers *second;

    if(*list_nbr && (*list_nbr)->next)
    {
        first = *list_nbr;
        second = (*list_nbr)->next;

        first->next = second->next;
        second->next = first;
        *list_nbr = second;
    }
}
void ss(numbers **list_a, numbers **list_b)
{
    sa(list_a);
    sa(list_b);
}
void pa(numbers **list_a, numbers **list_b)
{
    numbers *first;

    if(*list_b)
    {
        first = *list_b;
        *list_b = (*list_b)->next;
        first->next = *list_a;
        *list_a = first;
    }
}
void ra(numbers **list_a)
{
    numbers *first;
    numbers *ptr;

    if(!(*list_a) || !(*list_a)->next)
        return ;
    first = *list_a;
    *list_a = first->next;
    first->next = NULL;
    ptr = *list_a;
    ptr->next->next = first;
    // printf("%d, %d, %d", ptr->number, ptr->next->number, ptr->next->next->number);
}
void rr(numbers **list_a, numbers **list_b)
{
    ra(list_a);
    ra(list_b);
}
void rra(numbers **list_a)
{
    numbers *ptr;
    numbers *ptr2;

    if(!(*list_a) || !(*list_a)->next)
        return ;
    ptr = *list_a;
    while((ptr)->next != NULL)
    {
        ptr2 = ptr;
        ptr = ptr->next;
    }
    ptr2->next = NULL;
    ptr->next = *list_a;
    *list_a = ptr;
}
void rrr(numbers **list_a, numbers **list_b)
{
    rra(list_a);
    rra(list_b);
}
