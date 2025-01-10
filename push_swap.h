#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>


typedef struct n_struct{
    int             number;
    struct n_struct *next;
}               numbers;

int	ft_atoi(const char *str);
void sa(numbers **list_nbr);
void ss(numbers **list_a, numbers **list_b);
void pa(numbers **list_a, numbers **list_b);
void ra(numbers **list_a);
void rr(numbers **list_a, numbers **list_b);
void rra(numbers **list_a);
void rrr(numbers **list_a, numbers **list_b);


#endif